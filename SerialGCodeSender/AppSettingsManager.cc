#include "AppSettingsManager.h"
#include "Constants.h"

AppSettingsManager::AppSettingsManager(QObject *parent) : QObject(parent)
{
    QCoreApplication::setOrganizationName("PrintIt@Co");
    QCoreApplication::setOrganizationDomain("printit.cloud");
    QCoreApplication::setApplicationName("GCodeSender");
    appSettings.setSystemIniPath(constants::appSettings::SYSTEM_INI_PATH);
    appSettings.setDefaultFormat(QSettings::NativeFormat);
}

void AppSettingsManager::readSettings()
{

}
