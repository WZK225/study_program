#include "widget.h"
#include "mythread.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    //创建MyThread的对象
    MyThread *pMyTh = new MyThread;
    //创建QThread的对象
    QThread *qth = new QThread;
    //移交控制权
    pMyTh->moveToThread(qth);

    QObject::connect(qth, &QThread::started, pMyTh, &MyThread::doTask);

    QObject::connect(pMyTh, &MyThread::signalQuit, qth, &QThread::quit);

    QObject::connect(qth, &QThread::finished, pMyTh, &MyThread::deleteLater);
    QObject::connect(qth, &QThread::finished, qth, &QThread::deleteLater);

    QObject::connect(qth, &QThread::finished, []{
        exit(0);
    });

    qth->start();

    return a.exec();
}
