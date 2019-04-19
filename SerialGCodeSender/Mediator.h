#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>
#include <QPointer>

#include "InOutStreamObserver.h"
#include "FileParser.h"
#include "SerialTransceiver.h"
#include "AppSettingsManager.h"
#include "DownloadManager.h"

class Mediator : public QObject
{
    Q_OBJECT
public:
    Mediator(const QString& portName,
             const QString& baudRate,
             const QString& fileName,
             QObject *parent = nullptr);

    void run();

private:
    void createObjects();
    void connectObjects();



signals:
    void sendMessage(QString msg);
    void startPrintProcess();

public slots:

private:
    QString portName_;
    QString baudRate_;
    QString fileName_;

    QPointer<FileParser> fileParser_;
    QPointer<InOutStreamObserver> inOutStream_;
    QPointer<SerialTransceiver> serialTransceiver_;
    QPointer<AppSettingsManager> appSettingsManager_;
    QPointer<DownloadManager> downloadManager_;
};

#endif // MEDIATOR_H
