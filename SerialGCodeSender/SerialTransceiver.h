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

    bool openSerialPort(const QString& serialPort, int baudRate);

    void setPrintStarted(bool printIsStarted){ printIsStarted_ = printIsStarted; }
    bool isPrintStarted() const { return  printIsStarted_; }

signals:
    void sendMessage(QString msg);
    void startNextPrintStep();

public slots:
    void setDataQueue(QList<QByteArray> list);
    void sendData();
    void dataReceived();

private:
    bool printIsStarted_{false};
    QSerialPort serialPort_;
    int baudRate_;
    QQueue<QByteArray> dataQueue_;
};

#endif // SERIALTRANSCEIVER_H
