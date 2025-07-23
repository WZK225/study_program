#include "mythread.h"
#include <QDebug>

mythread::mythread()
{

}

mythread::~mythread()
{

}

void mythread::run(){
    qDebug() << "mythread id = " << currentThreadId();

    for(int idx = 1; idx < 10; ++idx){
        qDebug() << "idx = " << idx;
        msleep(1000);
    }
}
