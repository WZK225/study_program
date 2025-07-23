#include "widget.h"
#include <QPushButton>
#include <QDialog>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(600, 400);

    QDialog *pd1 = new QDialog(this);
    QDialog *pd2 = new QDialog(this);
    pd1->setWindowTitle("PD1");
    pd2->setWindowTitle("PD2");
    pd1->resize(300, 200);
    pd2->resize(300, 200);

    QPushButton *btn1 = new QPushButton("exec", this);
    QPushButton *btn2 = new QPushButton("show", this);
    btn1->move(100, 100);
    btn2->move(100, 200);

    QPushButton *c1 = new QPushButton("exec", pd1);
    QPushButton *d2 = new QPushButton("show", pd2);

    connect(btn1, &QPushButton::clicked, [=]{
        pd1->exec();
        pd2->show();
    });

    connect(btn2, &QPushButton::clicked, [=]{
        pd1->show();
        pd2->exec();
    });
}

Widget::~Widget()
{
}

