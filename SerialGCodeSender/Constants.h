#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>
#include <QSerialPort>
#include <QCoreApplication>

namespace constants {

namespace fileOperations {
const QString FILE_NAME_IS_EMPTY{"File name is empty."};
const QString FILE_OPEN_ERROR{"File open error."};
const QString FILE_IS_OPEN{"File is open."};
} //fileOperations

namespace serialTransceiver {
const QString PORT_IS_OPEN{"Port is open."};
const QString PORT_IS_NOT_OPEN{"Port isn't open."};
const QString QUEUE_IS_EMPTY{"Queue is empty."};
const QString CMD_IS_SEND{"Cmd is send : "};
const QString DATA_IS_RECIVED{"Data is recieved : "};
} //serialTransceiver

namespace appSettings {
//Global project name, org.name etc.
//const QString SYSTEM_INI_PATH{QCoreApplication::applicationDirPath()};
const QString ORG_NAME{"PrintIt@Co"};
const QString ORG_DOMAIN{"printit.cloud"};
const QString APP_NAME{"GCodeSender"};

//Groups
const QString SERIAL_TRANSCEIVER{"SERIAL_TRANSCEIVER"};
const QString FILE_PARSER{"FILE_PARSER"};
const QString DOWNLOAD_FILE_MANAGER{"DOWNLOAD_FILE_MANAGER"};

//SerialTransceiver
const QString PORT_NAME{"portName"};
const QString BAUD_RATE{"baudRate"};
const QString DATA_BITS{"dataBits"};
const QString FLOW_CONTROL{"flowControl"};
const QString PARITY{"parity"};
const QString STOP_BITS{"stopBits"};

const QString DEFAULT_PORT_NAME{"/dev/ttyUSB0"};
const int DEFAULT_BAUD_RATE{static_cast<int>(QSerialPort::Baud115200)};
const int DEFAULT_DATA_BITS{static_cast<int>(QSerialPort::Data8)};
const int DEFAULT_FLOW_CONTROL{static_cast<int>(QSerialPort::FlowControl::NoFlowControl)};
const int DEFAULT_PARITY{static_cast<int>(QSerialPort::Parity::NoParity)};
const int DEFAULT_STOP_BITS{static_cast<int>(QSerialPort::StopBits::OneStop)};

//File parser

//Download manager
const QString FILE_DOWNLOAD_LINK{"fileDownloadLink"};
const QString DOWNLOADED_FILE_PATH{"downloadedFilePath"};

const QString DEFAULT_FILE_DOWNLOAD_LINK{"http://printit.cloud/test.gcode"};
const QString DEFAULT_DOWNLOADED_FILE_PATH{"/home/oleg/GFodeFile"};//need to resolve this, auto create dir for downloaded files

}

}

#endif // CONSTANTS_H
