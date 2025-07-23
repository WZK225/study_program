#include "widget.h"

#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPicture pic;

    // 创建画家对象
    QPainter pat(&pic);

    // 设置画笔并设置画笔对象
    QPen pen;
    pen.setColor(QColor(Qt::red));
    pat.setPen(pen);

    pat.drawRect(100, 100, 200, 100);
    pat.drawEllipse(200, 200, 200, 100);

    pat.end();  //结束绘图

    pic.save("E:/pic.pic");
}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *event){
    QPicture pic;
    pic.load("E:/pic.pic");

    QPainter pat(this);

    pat.drawPicture(0, 0, pic);
}

