#include "AppSettingsManager.h"
#include "Constants.h"

AppSettingsManager::AppSettingsManager(QObject *parent) : QObject(parent)
{
//    QCoreApplication::setOrganizationName("PrintIt@Co");
//    QCoreApplication::setOrganizationDomain("printit.cloud");
//    QCoreApplication::setApplicationName("GCodeSender");
//    appSettings.setSystemIniPath(constants::appSettings::SYSTEM_INI_PATH);
    appSettings.setDefaultFormat(QSettings::NativeFormat);
}

void AppSettingsManager::readSettings()
{
    appSettings.beginGroup(constants::appSettings::SERIAL_TRANSCEIVER);
    QString portName = appSettings.value(constants::appSettings::PORT_NAME,constants::appSettings::DEFAULT_PORT_NAME).toString();
    int baudRate = appSettings.value(constants::appSettings::BAUD_RATE, constants::appSettings::DEFAULT_BAUD_RATE).toInt();
    int dataBits = appSettings.value(constants::appSettings::DATA_BITS, constants::appSettings::DEFAULT_DATA_BITS).toInt();
    int flowControl = appSettings.value(constants::appSettings::FLOW_CONTROL, constants::appSettings::DEFAULT_FLOW_CONTROL).toInt();
    int parity = appSettings.value(constants::appSettings::PARITY, constants::appSettings::DEFAULT_PARITY).toInt();
    int stopBits = appSettings.value(constants::appSettings::STOP_BITS, constants::appSettings::DEFAULT_STOP_BITS).toInt();
    appSettings.endGroup();
    auto serialSettingsInfo = std::make_tuple(portName, baudRate, dataBits, flowControl, parity, stopBits);
    emit sendSerialPortInfo(serialSettingsInfo);

    appSettings.beginGroup(constants::appSettings::DOWNLOAD_FILE_MANAGER);
    QString link = appSettings.value(constants::appSettings::FILE_DOWNLOAD_LINK,constants::appSettings::DEFAULT_FILE_DOWNLOAD_LINK).toString();
    QString pathToSave = appSettings.value(constants::appSettings::DOWNLOADED_FILE_PATH,constants::appSettings::DEFAULT_DOWNLOADED_FILE_PATH).toString();
    appSettings.endGroup();
    emit sendDownloadManagerInfo(link, pathToSave);
}

void AppSettingsManager::writeDefaultSetting()
{
    appSettings.beginGroup(constants::appSettings::SERIAL_TRANSCEIVER);
    appSettings.setValue(constants::appSettings::PORT_NAME, constants::appSettings::DEFAULT_PORT_NAME);
    appSettings.setValue(constants::appSettings::BAUD_RATE, constants::appSettings::DEFAULT_BAUD_RATE);
    appSettings.setValue(constants::appSettings::DATA_BITS, constants::appSettings::DEFAULT_DATA_BITS);
    appSettings.setValue(constants::appSettings::FLOW_CONTROL, constants::appSettings::DEFAULT_FLOW_CONTROL);
    appSettings.setValue(constants::appSettings::PARITY, constants::appSettings::DEFAULT_PARITY);
    appSettings.setValue(constants::appSettings::STOP_BITS, constants::appSettings::DEFAULT_STOP_BITS);
    appSettings.endGroup();

    appSettings.beginGroup(constants::appSettings::FILE_PARSER);
    appSettings.endGroup();

    appSettings.beginGroup(constants::appSettings::DOWNLOAD_FILE_MANAGER);
    appSettings.setValue(constants::appSettings::FILE_DOWNLOAD_LINK,constants::appSettings::DEFAULT_FILE_DOWNLOAD_LINK);
    appSettings.setValue(constants::appSettings::DOWNLOADED_FILE_PATH,constants::appSettings::DEFAULT_DOWNLOADED_FILE_PATH);
    appSettings.endGroup();
}
