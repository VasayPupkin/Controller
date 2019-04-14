#include <QtSerialPort/QSerialPortInfo>
#include "SerialTransceiver.h"

SerialTransceiver::SerialTransceiver(QObject *parent) : QObject(parent)
{

}

SerialTransceiver::~SerialTransceiver()
{
}

void SerialTransceiver::setupSerialPort(const QString &serialPort, int baudRate)
{
    serialPort_.setPortName(serialPort);
    serialPort_.setBaudRate(baudRate);
    serialPort_.open(QIODevice::ReadWrite);
//    serialPort_.setPort(*serialPortInfo_);
//    baudRate_ = baudRate;
//    serialPort_.setBaudRate(baudRate_);
//    connect(&serialPort_, SIGNAL(readyRead()),SLOT(dataReceived()));
}

void SerialTransceiver::setDataQueue(QList<QByteArray> list)
{
    dataQueue_.fromStdList(list.toStdList());
}

void SerialTransceiver::sendData()
{
    if (!dataQueue_.isEmpty())
        serialPort_.    write(dataQueue_.dequeue());
}

void SerialTransceiver::dataReceived()
{

}
