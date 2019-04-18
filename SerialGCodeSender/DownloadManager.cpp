#include "DownloadManager.h"

DownloadManager::DownloadManager(QObject *parent) : QObject(parent)
{

}

void DownloadManager::append(const QUrl &url){
    if (downloadQueue_.isEmpty())
        QTimer::singleShot(0, this, SLOT(startNextDownload()));

    downloadQueue_.enqueue(url);
    ++totalCount;
}

void DownloadManager::append(const QStringList &urls){
    for (const QString &urlAsString : urls)
        append(QUrl::fromEncoded(urlAsString.toLocal8Bit()));

    if (downloadQueue_.isEmpty())
        QTimer::singleShot(0, this, SIGNAL(finished()));
}
