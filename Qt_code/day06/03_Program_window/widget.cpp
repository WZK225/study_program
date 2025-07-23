#include "widget.h"
#include <QDialog>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{
}

void Widget::test(){
    QDialog *pd1 = new QDialog;         // 窗口模式
    QDialog *pd2 = new QDialog(this);   // 窗口模式
    QDialog *pd3 = new QDialog;         // 应用程序模式

    pd1->setWindowTitle("PD1");
    pd2->setWindowTitle("PD2");
    pd3->setWindowTitle("PD3");

    QPushButton *btn1 = new QPushButton("winNoPar", this);
    QPushButton *btn2 = new QPushButton("winPar", this);
    btn2->move(150, 0);
    QPushButton *btn3 = new QPushButton("app", this);
    btn3->move(300, 0);
    QPushButton *d = new QPushButton("d", pd1);
    QPushButton * e= new QPushButton("e", pd2);
    pd1->resize(200, 100);
    pd2->resize(200, 100);
    pd3->resize(200, 100);

    connect(btn1, &QPushButton::clicked, [=]{
        pd1->setWindowModality(Qt::WindowModal);
        pd2->show();
    });

    connect(btn2, &QPushButton::clicked, [=]{
       pd2->setWindowModality(Qt::WindowModal);
       pd2->show();
    });

    connect(btn3, &QPushButton::clicked, [=]{
        pd3->setWindowModality(Qt::ApplicationModal);
        pd3->show();
    });

}


