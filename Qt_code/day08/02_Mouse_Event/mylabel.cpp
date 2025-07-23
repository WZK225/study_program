#include "mylabel.h"

MyLabel::MyLabel(QLabel *parent)
    :QLabel(parent)
{
    resize(600, 480);

    // 1.在构造函数中安装事件过滤器
    installEventFilter(this);
}

MyLabel::~MyLabel(){

}


// 鼠标进入事件
void MyLabel::enterEvent(QEvent *event){
    Q_UNUSED(event);
    qDebug() << ">>>>鼠标进入了";
}

// 鼠标离开事件
void MyLabel::leaveEvent(QEvent *event){
    Q_UNUSED(event);
    qDebug() << ">>>>鼠标离开了";
}

// 重写鼠标按压事件
void MyLabel::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        qDebug() << "鼠标左键被--按压--了,横坐标x="
                 << event->x() <<",纵坐标y = " << event->y();
    }
}

// 重写鼠标释放事件
void MyLabel::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        qDebug() << "鼠标左键被==释放==了,横坐标x="
                 << event->x() <<",纵坐标y = " << event->y();
    }
}

// 重写鼠标移动事件
void MyLabel::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::RightButton){
        qDebug() << "鼠标左键被**移动**了,横坐标x="
                 << event->x() <<",纵坐标y = " << event->y();
    }
}

// 重写event函数
bool MyLabel::event(QEvent *e){
    if(e->type() == QEvent::MouseMove){
        qDebug() << "event函数拦截了鼠标移动事件";
        return true;
    }else if(e->type() == QEvent::MouseButtonPress){
        qDebug() << "event函数拦截了鼠标按压事件";
        return true;
    }else {
        return QLabel::event(e);
    }

}

// 重写事件过滤函数()事件过滤器
bool MyLabel::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == this)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *ev = static_cast<QMouseEvent *>(event);

            if(ev->button() == Qt::LeftButton){
                qDebug() << "eventFilter 鼠标左键被按压了, 横坐标x = "
                         << ev->x() << ", 纵坐标有y= " << ev->y();
                return true;
            }
        }
    }
    return QLabel::eventFilter(obj, event);
}

