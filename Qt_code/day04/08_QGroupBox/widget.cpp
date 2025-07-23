#include "widget.h"
#include <QGroupBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(800, 600);

    QGroupBox *boxRadio = new QGroupBox("单选按钮组");

    QRadioButton *radio1 = new QRadioButton("radio1");
    QRadioButton *radio2 = new QRadioButton("radio2");
    QRadioButton *radio3 = new QRadioButton("radio3");

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(radio1);
    vLayout->addWidget(radio2);
    vLayout->addWidget(radio3);
    boxRadio->setLayout(vLayout);

    QGroupBox *boxCheck = new QGroupBox("复选按钮组");

    QCheckBox *check1 = new QCheckBox("check1");
    QCheckBox *check2 = new QCheckBox("check2");
    QCheckBox *check3 = new QCheckBox("check3");

    QVBoxLayout *vLayout2 = new QVBoxLayout;
    vLayout2->addWidget(check1);
    vLayout2->addWidget(check2);
    vLayout2->addWidget(check3);
    boxCheck->setLayout(vLayout2);

    QGroupBox *box3 = new QGroupBox("混合按钮组");
    QRadioButton *radio11 = new QRadioButton("radio11");
    QRadioButton *radio22 = new QRadioButton("radio22");
    QCheckBox *check11 = new QCheckBox("check11");
    QCheckBox *check22 = new QCheckBox("check22");

    QVBoxLayout *vLayout3 = new QVBoxLayout;
    vLayout3->addWidget(check11);
    vLayout3->addWidget(check22);
    vLayout3->addWidget(radio11);
    vLayout3->addWidget(radio22);
    box3->setLayout(vLayout3);

    QGridLayout *gLayout = new QGridLayout;
    gLayout->addWidget(boxRadio, 0, 0);
    gLayout->addWidget(boxCheck, 0, 2);
    gLayout->addWidget(box3, 1, 1);

    setLayout(gLayout);
}

Widget::~Widget()
{
}

