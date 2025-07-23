#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug() << "鼠标按压事件被执行了";
}

//void Widget::mouseDoubleClickEvent(QMouseEvent *event)
//{
//    Q_UNUSED(event);
//    qDebug() << "鼠标==双击按压事件==被执行了";
//}

bool Widget::event(QEvent *event)
{

    if(event->type() == QEvent::MouseButtonPress /*||
       event->type() == QEvent::MouseButtonDblClick*/
            ){
        qDebug() << "在event函数中提前处理鼠标按压事件";
        return true;
    }

    return QWidget::event(event);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
    qDebug() << "key----键盘按压事件被执行了";
}

