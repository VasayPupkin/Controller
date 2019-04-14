#ifndef INOUTSTREAMOBSERVER_H
#define INOUTSTREAMOBSERVER_H

#include <QObject>
#include <QTextStream>
#include <QPointer>
#include <QSocketNotifier>

class InOutStreamObserver : public QObject
{
    Q_OBJECT
public:
    explicit InOutStreamObserver(QObject *parent = nullptr);
    ~InOutStreamObserver();

private:
    void createStreams();

signals:

public slots:
    void printsStdIn();
    void printToStdOut(QString str);

private:
    QTextStream *in_{nullptr};
    QTextStream *out_{nullptr};
    QSocketNotifier *pNot{nullptr};
};

#endif // INOUTSTREAMOBSERVER_H
