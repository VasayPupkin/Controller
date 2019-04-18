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

    void append(const QUrl &url);
    void append(const QStringList &urls);
signals:

public slots:
    void finished();

private:
    QQueue<QUrl> downloadQueue_;

    int totalCount{0};
};

#endif // DOWNLOADMANAGER_H
