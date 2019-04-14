#ifndef SERIALTRANSCEIVER_H
#define SERIALTRANSCEIVER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QQueue>

class SerialTransceiver : public QObject
{
    Q_OBJECT
public:
    explicit SerialTransceiver(QObject *parent = nullptr);
    ~SerialTransceiver();

    void setupSerialPort(const QString& serialPort, int baudRate);

signals:

public slots:
    void setDataQueue(QList<QByteArray> list);
    void sendData();
    void dataReceived();

private:
    QSerialPort serialPort_;
    int baudRate_;
    QQueue<QByteArray> dataQueue_;
};

#endif // SERIALTRANSCEIVER_H
