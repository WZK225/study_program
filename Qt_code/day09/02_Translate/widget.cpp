#include "widget.h"
#include <QPainter>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(1000, 800);
}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter pat(this);
#if 0
    // 第一种方式:可以让画家不同,每次更新要画图的起始位置
    // 设置画笔
    QPen pen;
    pen.setColor(QColor(Qt::red));
    pat.setPen(pen);

    pat.drawRect(10, 10, 200, 100);

    pen.setColor(QColor(Qt::green));
    pat.setPen(pen);

    pat.drawRect(310, 10, 200, 100);

    pen.setColor(QColor(Qt::red));
    pat.setPen(pen);

    pat.drawRect(610, 10, 200, 100);
#endif

#if 0
    // 第二种方法:可以让画家移动,但是图形与画家之间的相对位置保持不变
    // 设置画笔
    QPen pen;
    pen.setColor(QColor(Qt::red));
    pat.setPen(pen);
    pat.drawRect(10, 10, 200, 100);

    pat.translate(300, 0);
    pen.setColor(QColor(Qt::green));
    pat.setPen(pen);

    pat.drawRect(10, 10, 200, 100);

    pat.translate(300, 0);
    pen.setColor(QColor(Qt::red));
    pat.setPen(pen);

    pat.drawRect(10, 10, 200, 100);
#endif

    // 第三种:可以让画家移动,保持画家的状态(画笔的颜色,画家的位置)
    // 设置画笔
    QPen pen;

    pen.setColor(QColor(Qt::red));
    pat.setPen(pen);
    pat.drawRect(10, 10, 200, 100);
    pat.save();//

    pat.translate(300, 0);
    pen.setColor(QColor(Qt::green));
    pat.setPen(pen);

    pat.drawRect(10, 10, 200, 100);
    pat.save();

    pat.restore();
    pat.restore();
    pat.translate(600, 0);
    pat.drawRect(10,10, 200, 100);
}

