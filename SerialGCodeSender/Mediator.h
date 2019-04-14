#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QObject>
#include <QPointer>

#include "InOutStreamObserver.h"
#include "FileParser.h"

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

public slots:

private:
    QString portName_;
    QString baudRate_;
    QString fileName_;

    QPointer<FileParser> fileParser_;
    QPointer<InOutStreamObserver> inOutStream_;
};

#endif // MEDIATOR_H
