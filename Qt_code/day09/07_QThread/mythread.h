#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class mythread : public QThread
{
    Q_OBJECT
public:
    mythread();
    ~mythread();

    // 继承QThread,并且自己实现run方法
    // 然后在run方法中去模拟耗时任务
    void run() override;
};

#endif // MYTHREAD_H
