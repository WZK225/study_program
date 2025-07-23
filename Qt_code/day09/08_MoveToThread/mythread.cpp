#include "mythread.h"

MyThread::MyThread(QObject *parent)
    :QObject(parent)
{

}

MyThread::~MyThread(){

}


void MyThread::doTask(){
    qDebug() << "MyThread id = " << QThread::currentThreadId();

    for(int idx = 1; idx < 10; ++idx){
        qDebug() << "idx = " << idx;
        QThread::sleep(1);
    }
    emit signalQuit();
}
