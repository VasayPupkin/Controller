#include "InOutStreamObserver.h"

InOutStreamObserver::InOutStreamObserver(QObject *parent) : QObject(parent)
{
    createStreams();
}

InOutStreamObserver::~InOutStreamObserver()
{
    delete in_;
    delete out_;
}

void InOutStreamObserver::createStreams()
{
    in_ = new QTextStream(stdin, QIODevice::ReadOnly);
    out_ = new QTextStream(stdout, QIODevice::WriteOnly);

//    pNot = new QSocketNotifier(STDIN_FILENO, QSocketNotifier::Read, this);
//    connect(pNot, SIGNAL(activated(int)), this, SLOT(printsStdIn()));
//    pNot->setEnabled(true);
}

void InOutStreamObserver::printsStdIn()
{
//    QString str;

//    forever
//    {
//        fd_set stdinfd;
//        FD_ZERO( &stdinfd );
//        FD_SET( STDIN_FILENO, &stdinfd );
//        struct timeval tv;
//        tv.tv_sec = 0;
//        tv.tv_usec = 0;
//        int ready = select( 1, &stdinfd, nullptr, nullptr, &tv );
//        if( ready > 0 )
//        {
//            str += in_->readLine();
//        }
//        else
//        {
//            break;
//        }
//    }
//    printToStdOut(str);

}

void InOutStreamObserver::printToStdOut(QString str)
{
    (*out_) << str << "\n";
    out_->flush();
}
