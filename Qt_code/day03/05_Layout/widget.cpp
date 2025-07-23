#include "widget.h"

//#include <QPushButton>
//#include <QHBoxLayout>
//#include <QVBoxLayout>
//#include <QGridLayout>

#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(600, 480);

//    QPushButton *btn1 = new QPushButton("按钮1");
//    QPushButton *btn2 = new QPushButton("按钮2");
//    QPushButton *btn3 = new QPushButton("按钮3");
//    QPushButton *btn4 = new QPushButton("按钮4");

    // 水平布局
//    QHBoxLayout *hLayout = new QHBoxLayout;
//    setLayout(hLayout);

//    hLayout->addWidget(btn1);
//    hLayout->addWidget(btn2);
//    hLayout->addWidget(btn3);
//    hLayout->addWidget(btn4);

    // 垂直布局
//    QVBoxLayout *vLayout = new QVBoxLayout;
//    setLayout(vLayout);

//    vLayout->addWidget(btn1);
//    vLayout->addWidget(btn2);
//    vLayout->addWidget(btn3);
//    vLayout->addWidget(btn4);

    // 网格布局
//    QGridLayout *gLayout = new QGridLayout;
//    setLayout(gLayout);

//    gLayout->addWidget(btn1, 0, 1, 1, 2);
//    gLayout->addWidget(btn2, 0, 0, 3, 1);
//    gLayout->addWidget(btn3, 1, 3);
//    gLayout->addWidget(btn4, 2, 2, 1, 2);

    // 表格布局
    QLabel *name = new QLabel("姓名");
    QLabel *age = new QLabel("年龄");
    QLabel *sex = new QLabel("性别");

    QLineEdit *ledit1 = new QLineEdit;
    QLineEdit *ledit2 = new QLineEdit;
    QLineEdit *ledit3 = new QLineEdit;

    QFormLayout *fLayout = new QFormLayout;
    setLayout(fLayout);

    fLayout->addRow(name, ledit1);
    fLayout->addRow(age, ledit2);
    fLayout->addRow(sex, ledit3);

}

Widget::~Widget()
{
}

