#include "widget.h"
#include "taskqueue.h"
#include "producer.h"
#include "consumer.h"

#include <QApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    TaskQueue taskQue(10);

    // 生产者
    Producer *pro = new Producer(taskQue);
    QThread *qTh1 = new QThread;
    pro->moveToThread(qTh1);

    QObject::connect(qTh1, &QThread::started, pro, &Producer::produce);
    QObject::connect(pro, &Producer::signalQuit1, qTh1, &QThread::quit);

    QObject::connect(qTh1, &QThread::finished, pro, &QObject::deleteLater);
    QObject::connect(qTh1, &QThread::finished, qTh1, &QObject::deleteLater);

    // 消费者
    Consumer *con = new Consumer(taskQue);
    QThread *qTh2 = new QThread;
    con->moveToThread(qTh2);

    QObject::connect(qTh2, &QThread::started, con, &Consumer::consume);
    QObject::connect(con, &Consumer::signalQuit2, qTh2, &QThread::quit);

    QObject::connect(qTh2, &QThread::finished, con, &QObject::deleteLater);
    QObject::connect(qTh2, &QThread::finished, qTh2, &QObject::deleteLater);

    QObject::connect(qTh1, &QThread::finished, &a, &QCoreApplication::quit, Qt::QueuedConnection);
    QObject::connect(qTh2, &QThread::finished, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    qTh1->start();
    qTh2->start();

    return a.exec();
}
