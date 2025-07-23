#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // ui->pushButton
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::close);
}

Widget::~Widget()
{
    delete ui;
}

//void Widget::on_pushButton_clicked()
//{
//    qDebug() << "信号与槽的标准操作";
//    qDebug("信号与槽的标准操作");
//    close();
//}
