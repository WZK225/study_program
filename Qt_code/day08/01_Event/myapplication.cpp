#include "myapplication.h"

MyApplication::MyApplication(int argc, char *argv[])
    :QApplication(argc, argv)
{

}

bool MyApplication::notify(QObject *receiver, QEvent *event){
    qDebug() << "notify中对所有的事件做了拦截";
    return QApplication::notify(receiver,event);
}
