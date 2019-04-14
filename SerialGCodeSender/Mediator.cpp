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
    fileParser_.data()->parseGCodeFile(fileName_);
}

void Mediator::createObjects(){
    fileParser_ = new FileParser();
    inOutStream_ = new InOutStreamObserver();
}

void Mediator::connectObjects(){
    connect(fileParser_.data(), SIGNAL(fileOpenError(QString)),
            inOutStream_.data(), SLOT(printToStdOut(QString)));
}
