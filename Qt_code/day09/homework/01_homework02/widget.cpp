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
    // 创建画家对象
    QPainter pat(this);
    // 创建画笔
    QPen pen;
    // 设置画笔颜色
    pen.setColor(QColor(Qt::red));
    // 设置画笔宽度
    pen.setWidth(3);
    // 画家设置画笔
    pat.setPen(pen);

    // 创建画刷
    QBrush brush;
    // 设置画刷颜色
    brush.setColor(Qt::green);
    brush.setStyle(Qt::CrossPattern);
    // 画家使用画笔
    pat.setBrush(brush);

    pat.drawRect(10, 10, 100, 100);
    pat.drawEllipse(100, 100, 100, 100);
    pat.drawEllipse(200, 200, 200, 100);
}

