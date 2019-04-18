#include <QCoreApplication>
#include <iostream>

#include "Constants.h"
#include "Mediator.h"
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName(constants::appSettings::ORG_NAME);
    QCoreApplication::setOrganizationDomain(constants::appSettings::ORG_DOMAIN);
    QCoreApplication::setApplicationName(constants::appSettings::APP_NAME);

    QCoreApplication a(argc, argv);

    Mediator mediator(argv[1],argv[2],argv[3]);
    mediator.run();

//    cout<<"MFK!!!"<<endl;

    return a.exec();
}
