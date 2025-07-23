#include "widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(800, 600);
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *event)
{
    // 创建绘图对象(也就是绘图器,但是要制定绘图设备)
    QPainter pat(this);

    // 设置画笔
    QPen pen(QColor(255, 0, 0));
    pat.setPen(pen);

    // 设置画刷
    QBrush brush;
    brush.setColor(Qt::cyan);
    brush.setStyle(Qt::CrossPattern);
    pat.setBrush(brush);

    // 绘制直线
    pat.drawLine(0, 0, 100, 100);
    // 绘制矩形
    pat.drawRect(100, 100, 200, 100);
    // 绘制圆形
    pat.drawEllipse(300, 300, 100, 100);
    //绘制椭圆
    pat.drawEllipse(400, 400, 200, 100);
    // 写文字
    pat.drawText(200, 100, "好好学习,整整齐齐");
}

