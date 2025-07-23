#include "widget.h"
#include <QScrollArea>
#include <QLabel>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(600, 480);

    QScrollArea *sa = new QScrollArea(this);

    QLabel *label = new QLabel("添加图片", this);
    label->setPixmap(QPixmap(":/new/prefix1/linux.png"));

    sa->setWidget(label);
}

Widget::~Widget()
{
}

