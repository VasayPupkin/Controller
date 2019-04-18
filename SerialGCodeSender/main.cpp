#include <QCoreApplication>
#include <iostream>

#include "Mediator.h"
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("PrintIt@Co");
    QCoreApplication::setOrganizationDomain("printit.cloud");
    QCoreApplication::setApplicationName("GCodeSender");

    QCoreApplication a(argc, argv);

    Mediator mediator(argv[1],argv[2],argv[3]);
    mediator.run();

//    cout<<"MFK!!!"<<endl;

    return a.exec();
}
