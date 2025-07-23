#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

void Widget::mousePressEvent(QMouseEvent *event){
    qDebug() << "鼠标按压";
}

bool Widget::event(QEvent *event){
    if(event->type() == QEvent::MouseButtonPress){
        qDebug() << "在event函数中提前处理鼠标按压事件";
                return true;
    }
    return QWidget::event(event);
}

void Widget::keyPressEvent(QKeyEvent *event){
    qDebug() << "键盘按压";
}



Widget::~Widget()
{
}

