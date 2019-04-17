#ifndef APPSETTINGSMANAGER_H
#define APPSETTINGSMANAGER_H

#include <QObject>
#include <QSettings>

class AppSettingsManager : public QObject
{
    Q_OBJECT
public:
    explicit AppSettingsManager(QObject *parent = nullptr);

signals:
    emit void sendDownloadManagerInfo(QString link, QString pathToSave);

public slots:
    void readSettings();

private:
    QSettings appSettings;
};

#endif // APPSETTINGSMANAGER_H
