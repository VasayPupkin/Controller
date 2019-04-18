#ifndef APPSETTINGSMANAGER_H
#define APPSETTINGSMANAGER_H

#include <tuple>

#include <QObject>
#include <QSettings>

class AppSettingsManager : public QObject
{
    Q_OBJECT
public:
    explicit AppSettingsManager(QObject *parent = nullptr);

signals:
    void sendDownloadManagerInfo(QString link, QString pathToSave);
    void sendFileParserInfo(QString filePath);
    void sendSerialPortInfo(std::tuple<QString,int,int,int,int,int> serialSettings);

public slots:
    void readSettings();
    void writeDefaultSetting();

private:
    QSettings appSettings;
};

#endif // APPSETTINGSMANAGER_H
