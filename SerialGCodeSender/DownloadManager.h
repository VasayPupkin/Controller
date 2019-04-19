#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QtNetwork>
#include <QtCore>
#include <QObject>

class DownloadManager : public QObject
{
    Q_OBJECT
public:
    explicit DownloadManager(QObject *parent = nullptr);

    void doDownload(const QUrl &url);
    static QString saveFileName(const QUrl &url);
    bool saveToDisk(const QString &filename, QIODevice *data);
    static bool isHttpRedirect(QNetworkReply *reply);

signals:
    void sendInfoMsg(QString msg);
    void fileIsDownloaded(QString filePath);

public slots:
    void execute(const QString &linkToFile);
    void downloadFinished(QNetworkReply *reply);
    void sslErrors(const QList<QSslError> &sslErrors);

private:
    QNetworkAccessManager manager_;
    QVector<QNetworkReply *> currentDownloads_;
};

#endif // DOWNLOADMANAGER_H
