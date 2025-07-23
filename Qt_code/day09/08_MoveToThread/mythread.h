#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QDebug>
#include <QThread>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *aprent = nullptr);
    ~MyThread();

    //模拟耗时任务
    void doTask();

signals:
    void signalQuit();  //声明信号
};

#endif // MYTHREAD_H
