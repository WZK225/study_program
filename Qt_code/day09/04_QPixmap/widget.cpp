#include "widget.h"

#include <QPainter>
#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPixmap pix(400, 400);
    pix.fill(Qt::white);

    // 创建画家对象
    QPainter pat(&pix);
    // 创建画笔并设置画笔对象
    QPen pen;
    pen.setColor(QColor(Qt::red));
    pat.setPen(pen);

    pat.drawRect(100, 100, 200, 100);

    pix.save("E:/pix.jpg");
}

Widget::~Widget()
{
}

