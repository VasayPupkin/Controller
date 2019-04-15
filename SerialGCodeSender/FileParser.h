#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QObject>
#include <QFile>
#include <QByteArray>
#include <QList>



class FileParser : public QObject
{
    Q_OBJECT
public:
    explicit FileParser(QObject *parent = nullptr);

signals:
    void fileOpenError(QString error);
    void fileIsParsed(QList<QByteArray> gCodeByteArray);

public slots:
    void parseGCodeFile(const QString filePath);

private:
    QFile gCodeFile_;
    QList<QByteArray> gCodeByteArray_;
    const QString separator_{";"};
};

#endif // FILEPARSER_H
