#include "Constants.h"
#include "Mediator.h"
#include <iostream>

Mediator::Mediator(const QString &portName,
                   const QString &baudRate,
                   const QString &fileName,
                   QObject *parent) :
    portName_(portName),
    baudRate_(baudRate),
    fileName_(fileName),
    QObject(parent)
{
    std::cout<<portName_.toStdString()<<std::endl;
    std::cout<<baudRate_.toStdString()<<std::endl;
    std::cout<<fileName_.toStdString()<<std::endl;

    createObjects();
    connectObjects();
}

void Mediator::run()
{
    //Write/read settings for app
//    appSettingsManager_.data()->writeDefaultSetting();

    //Download file from server, yet constant link
    downloadManager_->execute(constants::appSettings::DEFAULT_FILE_DOWNLOAD_LINK);

    //TODO : check true/false of parseGCodeFile
//    fileParser_.data()->parseGCodeFile(fileName_);

    bool ok = false;
    int baudRate = baudRate_.toInt(&ok);
    if (!ok){
        emit sendMessage("to int not OK!!!\n");
        return;
    }
    if (serialTransceiver_.data()->openSerialPort(portName_,baudRate)){
        serialTransceiver_.data()->startPrintProcess();
        emit startPrintProcess();
    }
}

void Mediator::createObjects(){
    fileParser_ = new FileParser();
    inOutStream_ = new InOutStreamObserver();
    serialTransceiver_ = new SerialTransceiver();
    appSettingsManager_ = new AppSettingsManager();
    downloadManager_ = new DownloadManager();
}

void Mediator::connectObjects(){
    connect(this, SIGNAL(sendMessage(QString)), inOutStream_.data(), SLOT(printToStdOut(QString)));
    //TODO : think about signal races, maybe use direct function call for start
//    connect(this, SIGNAL(startPrintProcess()), serialTransceiver_.data(), SLOT(startPrintProcess()));
    connect(this, SIGNAL(startPrintProcess()), fileParser_.data(), SLOT(parseAndSendNextLine()));

    connect(fileParser_.data(), SIGNAL(fileOpenError(QString)),
            inOutStream_.data(), SLOT(printToStdOut(QString)));
//    connect(fileParser_.data(), SIGNAL(fileIsParsed(QList<QByteArray>)),
//            serialTransceiver_.data(), SLOT(setDataQueue(QList<QByteArray>)));
    connect(fileParser_.data(), SIGNAL(currentLineIsParsed(QString)),
            serialTransceiver_.data(), SLOT(sendCurrentCmd(QString)));

    connect(serialTransceiver_.data(), SIGNAL(sendMessage(QString)),inOutStream_.data(), SLOT(printToStdOut(QString)));
    connect(serialTransceiver_.data(), SIGNAL(startNextPrintStep()), fileParser_.data(), SLOT(parseAndSendNextLine()));

    connect(downloadManager_.data(), SIGNAL(sendInfoMsg(QString)), inOutStream_.data(), SLOT(printToStdOut(QString)));
    connect(downloadManager_.data(), SIGNAL(fileIsDownloaded(QString)), fileParser_.data(), SLOT(setFilePathAndOpen(QString)));
}
