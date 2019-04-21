#include <QtSerialPort/QSerialPortInfo>
#include "SerialTransceiver.h"
#include "Constants.h"

SerialTransceiver::SerialTransceiver(QObject *parent) : QObject(parent)
{

}

SerialTransceiver::~SerialTransceiver()
{
    serialPort_.close();
}

bool SerialTransceiver::openSerialPort(const QString &serialPort, int baudRate)
{
//    QSerialPortInfo portInfo;

    serialPort_.setPortName(serialPort);
    serialPort_.setBaudRate(baudRate);
    if (serialPort_.open(QIODevice::ReadWrite)){
        connect(&serialPort_, &QSerialPort::readyRead, this, &SerialTransceiver::dataReceived);
        emit sendMessage(constants::serialTransceiver::PORT_IS_OPEN);
        return true;
    }
    emit sendMessage(constants::serialTransceiver::PORT_IS_NOT_OPEN);
    return false;
}

void SerialTransceiver::setDataQueue(QList<QByteArray> list)
{
    for(auto element : list){
        dataQueue_.enqueue(element);
    }
//    dataQueue_.fromStdList(list.toStdList());
}

void SerialTransceiver::sendData()
{
    if (!dataQueue_.isEmpty()){
        emit sendMessage(constants::serialTransceiver::CMD_IS_SEND + dataQueue_.head());
        setPrintStarted(true);
        serialPort_.write(dataQueue_.dequeue());
    }
    else{
        emit sendMessage(constants::serialTransceiver::QUEUE_IS_EMPTY);
        setPrintStarted(false);
    }
}

void SerialTransceiver::dataReceived()
{
    QByteArray data = serialPort_.readAll();
    emit sendMessage(constants::serialTransceiver::DATA_IS_RECIVED + data);
    //TODO : if recieved data == ok? then emit startNextPrintStep();
    if (!data.isEmpty() && isPrintStarted()) {
        for (auto i = 0; i < 100000;++i) {

        }
        emit startNextPrintStep();
    }
}
