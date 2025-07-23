#include "widget.h"
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("测试QFileDialog对话框");
    resize(600, 480);

    QPushButton *btn = new QPushButton("QFileDialog按钮", this);
    btn->move(100, 100);
    btn->resize(200, 100);

    connect(btn, &QPushButton::clicked, [=]{
        QString str = QFileDialog::getOpenFileName(this, "打开文件",
         "C:/Users/lili/Desktop", "(*.*)");
        qDebug() << str;
    });

}

Widget::~Widget()
{
}

