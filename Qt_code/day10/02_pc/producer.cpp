#include "producer.h"
#include "taskqueue.h"
#include <QDebug>
#include <QThread>

Producer::Producer(TaskQueue &taskQueue, QObject *parent)
    :QObject(parent)
    ,taskQue(taskQueue)
{

}

Producer::~Producer()
{

}

void Producer::produce(){
    srand(clock());
    int cnt = 20;
    while(cnt--){
        int number = rand() % 100;
        taskQue.push(number);
        qDebug() << "Producer produce number = " << number;
        //QThread::sleep(1);
    }
    emit signalQuit1();
}

