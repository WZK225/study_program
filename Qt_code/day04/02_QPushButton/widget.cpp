#include "widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 重置Widget的大小
    resize(600, 480);

    QPushButton *btn = new QPushButton;
    // 指定btn指向的堆对象的父对象
    btn->setParent(this);
    // 移动按钮的位置
    btn->move(100, 100);
    // 重置按钮的大小
    btn->resize(200, 50);
    // 给按键设置文件
    btn->setText("按钮1");
    // 获取文本(获取操作的时候无需加get)
    qDebug() << "按钮的文本信息 = " << btn->text();

    btn->setFlat(false);

    // 信号与槽的使用
    connect(btn, &QPushButton::clicked, [=]{
       qDebug() << btn->text();
       qDebug() << "横坐标 = " << btn->x()
                << "纵坐标 = " << btn->y();
    });

}

Widget::~Widget()
{
}

