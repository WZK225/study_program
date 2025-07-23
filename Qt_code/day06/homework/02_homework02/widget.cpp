#include "widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("测试窗口");
    resize(600, 480);

    QPushButton *btn1 = new QPushButton("Toggle", this);
    btn1->move(100, 100);
    btn1->resize(300, 100);
    btn1->setCheckable(true);

    connect(btn1, &QPushButton::toggled, [=](bool checked){
        if(checked){
            btn1->setText("ON");
            btn1->setStyleSheet("background-color: rgb(255, 0, 0);");
        }else{
            btn1->setText("OFF");
            btn1->setStyleSheet("background-color: rgb(0, 255, 0);");
        }
    });

}

Widget::~Widget()
{
}

