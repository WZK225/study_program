#include "widget.h"

#include <QPainter>
#include <QTimer>
//#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(1000, 800);

    QTimer *tm = new QTimer(this);

    connect(tm, &QTimer::timeout,[=]{
        update();
    });
    tm->start(100);
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *event){

    QPainter pat(this);

    if(m_pos > this->width()){
        m_pos = 0;
    }

    pat.drawPixmap(m_pos, 0, QPixmap(":/duck.gif"));
    m_pos += 10;
}

