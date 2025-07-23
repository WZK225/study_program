#include "widget.h"
#include <QToolButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 重置Widget的大小
    resize(600, 480);

    QToolButton *btn = new QToolButton;
    btn->setParent(this);
    btn->resize(200, 50);
    btn->move(100, 100);
    btn->setIcon(QIcon(":/up.png"));
    btn->setText("butterfly");
    btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    // 信号与槽的使用
    connect(btn, &QToolButton::clicked, [=]{
        qDebug() << btn->text();
        qDebug() << "(" << btn->x() << "," << btn->y() << ")";
    });
}

Widget::~Widget()
{
}

