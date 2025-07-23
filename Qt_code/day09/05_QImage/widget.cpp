#include "widget.h"

#include <QPainter>
#include <QImage>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(1000, 800);
}

Widget::~Widget()
{
}


void Widget::paintEvent(QPaintEvent *event){
    QImage img;
    img.load(":/mario.gif");

    QPainter pat(this);
    for(int i = 100; i <= 300; ++i){
        for(int j = 100; j <= 300; ++j){
            QRgb value = qRgb(255, 0, 0);
            img.setPixel(i, j, value);
        }
    }
    pat.drawImage(0, 0, img);
}
