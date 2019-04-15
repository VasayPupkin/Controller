#include <QTextStream>
#include "FileParser.h"
#include "Constants.h"

FileParser::FileParser(QObject *parent) : QObject(parent)
{

}

void FileParser::parseGCodeFile(const QString filePath)
{
    if (filePath.isEmpty()) {
        emit fileOpenError(constants::fileOperations::FILE_NAME_IS_EMPTY);
        return;
    }
    gCodeFile_.setFileName(filePath);
    if (gCodeFile_.open(QIODevice::ReadOnly | QIODevice::Text)) {
        gCodeByteArray_.clear();
        QString tmpStr;
        QStringList strList;
        QTextStream stream(&gCodeFile_);
        while (!stream.atEnd()) {
            tmpStr = stream.readLine();
            strList = tmpStr.split(separator_);
            tmpStr = strList[0].trimmed();
            if (!tmpStr.isEmpty())
                gCodeByteArray_.push_back(tmpStr.toStdString().c_str());
        }
        emit fileOpenError(constants::fileOperations::FILE_IS_OPEN);
        emit fileIsParsed(gCodeByteArray_);
        gCodeFile_.close();
    }
    else
        emit fileOpenError(constants::fileOperations::FILE_OPEN_ERROR);
}
