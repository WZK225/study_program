#include "widget.h"
#include <QDialogButtonBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(600, 480);

    QDialogButtonBox *dbb = new QDialogButtonBox(this);
    dbb->move(100, 100);
    dbb->setOrientation(Qt::Vertical);

    dbb->addButton(QDialogButtonBox::Ok);
    dbb->addButton(QDialogButtonBox::Cancel);
    dbb->addButton("自定义的按钮", QDialogButtonBox::AcceptRole);

}

Widget::~Widget()
{
}

