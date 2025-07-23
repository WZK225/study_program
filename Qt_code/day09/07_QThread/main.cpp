#include "widget.h"
#include "mythread.h"

#include <QApplication>
#include <QThread>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    qDebug() << "main Thread id = "
             << QThread::currentThreadId();

    // 创建线程对象--栈对象
    mythread mth;

    // 创建线程对象--堆对象
    //mythread *mth = new mythread;

    QObject::connect(&mth, &mythread::started, [&]{
       qDebug() << "started信号被触发了";
    });

    QObject::connect(&mth, &mythread::finished, [&]{
        w.close();
    });

    mth.start();

    return a.exec();
}
