#include "DownloadManager.h"
#include "Constants.h"

DownloadManager::DownloadManager(QObject *parent) : QObject(parent)
{
    connect(&manager_, SIGNAL(finished(QNetworkReply*)),
            SLOT(downloadFinished(QNetworkReply*)));
}

void DownloadManager::doDownload(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = manager_.get(request);

#if QT_CONFIG(ssl)
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),
            SLOT(sslErrors(QList<QSslError>)));
#endif

    currentDownloads_.append(reply);
}

QString DownloadManager::saveFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "download";

    if (QFile::exists(basename)) {
        // already exists, don't overwrite
        int i = 0;
        basename += '.';
        while (QFile::exists(basename + QString::number(i)))
            ++i;

        basename += QString::number(i);
    }

    return basename;
}

bool DownloadManager::saveToDisk(const QString &filename, QIODevice *data)
{
    QString dirToSave = constants::appSettings::DEFAULT_DOWNLOADED_FILE_PATH;
    if (!QDir(dirToSave).exists())
        QDir().mkdir(dirToSave);
    QFile file(dirToSave + "/" + filename);
    if (!file.open(QIODevice::WriteOnly)) {
        emit sendInfoMsg(QString("Could not open %1 for writing: %2\n")
                         .arg(qPrintable(filename))
                         .arg(qPrintable(file.errorString())));
        return false;
    }

    file.write(data->readAll());
    file.close();

    return true;
}

bool DownloadManager::isHttpRedirect(QNetworkReply *reply)
{
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    return statusCode == 301 || statusCode == 302 || statusCode == 303
           || statusCode == 305 || statusCode == 307 || statusCode == 308;
}

void DownloadManager::execute(const QString &linkToFile)
{
    QUrl url = QUrl::fromEncoded(linkToFile.toLocal8Bit());
    doDownload(url);
}

void DownloadManager::downloadFinished(QNetworkReply *reply)
{
    QUrl url = reply->url();
    if (reply->error()) {
        fprintf(stderr, "Download of %s failed: %s\n",
                url.toEncoded().constData(),
                qPrintable(reply->errorString()));
    } else {
        if (isHttpRedirect(reply)) {
            fputs("Request was redirected.\n", stderr);
        } else {
            QString filename = saveFileName(url);
            if (saveToDisk(filename, reply)) {
                emit fileIsDownloaded(constants::appSettings::DEFAULT_DOWNLOADED_FILE_PATH + "/" + filename);
                emit sendInfoMsg(QString("Download of %1 succeeded (saved to %2)\n")
                                 .arg(url.toEncoded().constData())
                                 .arg(qPrintable(filename)));
            }
        }
    }
}

void DownloadManager::sslErrors(const QList<QSslError> &sslErrors)
{
#if QT_CONFIG(ssl)
    for (const QSslError &error : sslErrors)
        fprintf(stderr, "SSL error: %s\n", qPrintable(error.errorString()));
#else
    Q_UNUSED(sslErrors);
#endif
}
