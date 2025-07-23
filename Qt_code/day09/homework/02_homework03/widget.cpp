#include "widget.h"

#include <QPainter>
#include <QtMath>
#include <QTimer>
#include <QBrush>
#include <QTime>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(600, 600);

    QTimer *tm = new QTimer(this);

    connect(tm, &QTimer::timeout, [=]{
        update();
    });

    tm->start(1000);

    // 获取当前时间
    set_currentTime();

    qDebug() << second;
}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *event){

    // 创建画家
    QPainter pat(this);

    // 设置表盘外框
    QPen pen;
    pen.setColor(QColor(Qt::black));
    pen.setWidth(2);
    pat.setPen(pen);
    QBrush brush;
    brush.setColor(Qt::cyan);
    brush.setStyle(Qt::SolidPattern);
    pat.setBrush(brush);

    pat.translate(300, 300);
    pat.drawEllipse(-200, -200, 400, 400);


    // 设置表盘刻度
    QPen pen_second;
    pen.setColor(QColor(Qt::black));
    pen.setWidth(10);
    pat.setPen(pen_second);
    for(int i = 0; i < 60; ++i){
        pat.drawLine(0, -190, 0, -200);
        pat.rotate(6);
    }
    for(int i = 1; i <= 12; ++i){
        pat.rotate(30);
        pat.drawLine(0, -170, 0, -200);
    }

    // 设置表盘数字
    for(int i = 1; i <= 12; ++i){
        pat.rotate(30);
        pat.drawText(-8, -150, QString::number(i));
    }

    second_move(pat);
    minute_move(pat);
    hour_move(pat);
}

void Widget::set_currentTime(){
    // 需要获取当前时间
    QString time = QTime::currentTime().toString("h:m:s ap");
    QStringList list1 = time.split(" ");
    QStringList list2 = list1[0].split(":");
    second = list2[0].toUInt();
    minute = list2[1].toUInt();
    hour = list2[2].toUInt();
}

void Widget::second_move(QPainter & pat){
    if(second > 360){
        second = 0;
        minute += 6;
    }
    // 设置画笔
    QPen pen;
    pen.setColor(QColor(Qt::red));
    pen.setWidth(3);
    pat.setPen(pen);

    // 画指针
    pat.rotate(second+=6);
    pat.drawLine(0, 0, 0, -160);
}

void Widget::minute_move(QPainter & pat){
    if(minute > 360){
        minute = 0;
        hour += 30;
        hour_move(pat);
    }
    // 设置画笔
    QPen pen;
    pen.setColor(QColor(Qt::green));
    pen.setWidth(6);
    pat.setPen(pen);

    // 画指针
    pat.rotate(minute++);
    pat.drawLine(0, 0, 0, -130);

}


void Widget::hour_move(QPainter & pat){
    if(hour > 12){
        hour = 0;
    }
    // 设置画笔
    QPen pen;
    pen.setColor(QColor(Qt::blue));
    pen.setWidth(9);
    pat.setPen(pen);

    // 画指针
    pat.rotate(hour++);
    pat.drawLine(0, 0, 0, -100);
}
