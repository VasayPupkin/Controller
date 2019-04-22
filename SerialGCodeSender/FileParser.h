#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QObject>
#include <QFile>
#include <QByteArray>
#include <QList>
#include <QTextStream>



class FileParser : public QObject
{
    Q_OBJECT
public:
    explicit FileParser(QObject *parent = nullptr);

signals:
    void fileOpenError(QString error);
    void fileIsParsed(QList<QByteArray> gCodeByteArray);
    void currentLineIsParsed(QString cmdLine);
    //TODO send to write current cmd to setting

public slots:
    void parseGCodeFile(const QString filePath);
    void setFilePathAndOpen(QString filePath);
    void parseAndSendNextLine();

private:
    QFile gCodeFile_;
    QList<QByteArray> gCodeByteArray_;
    QTextStream gCodeFileStream_;
    const QString separator_{";"};
    int currentLine_{0};
};

#endif // FILEPARSER_H
