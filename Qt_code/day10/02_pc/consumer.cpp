#include "consumer.h"
#include "taskqueue.h"
#include <QDebug>
#include <QThread>

Consumer::Consumer(TaskQueue & taskqueue, QObject *parnet)
    :QObject(parnet)
    ,taskQue(taskqueue)
{

}

Consumer::~Consumer()
{

}

void Consumer::consume(){
    int cnt = 20;
    while(cnt--){
        int number = taskQue.pop();
        qDebug() << "Consumer consume number = " << number;
        //QThread::sleep(1);
    }
    emit signalQuit2();
}
