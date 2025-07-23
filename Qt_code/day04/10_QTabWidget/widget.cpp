#include "widget.h"
#include <QTabWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(800, 600);

    QTabWidget *tabWid = new QTabWidget(this);
    tabWid->move(100, 100);
    tabWid->resize(600, 400);

    tabWid->setMovable(true);

    tabWid->setTabShape(QTabWidget::Triangular);

    tabWid->setTabsClosable(true);

    tabWid->setTabPosition(QTabWidget::South);

    QWidget *w1 = new QWidget(this);
    QWidget *w2 = new QWidget(this);

    tabWid->addTab(w1, "进程");
    tabWid->addTab(w2, "进程");

    QLabel *label = new QLabel("输入文本框");
    QLineEdit *lineEdit = new QLineEdit;
    QPushButton *btn = new QPushButton("点击按钮");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(btn);
    w1->setLayout(layout);

    connect(btn, &QPushButton::clicked, [=]{
        lineEdit->setText("KGB");
        qDebug() << "打印输入文本框种的内容 : "
                 << lineEdit->text();
    });

    connect(tabWid, &QTabWidget::tabCloseRequested, [=](int idx){
       tabWid->removeTab(idx);
    });

}

Widget::~Widget()
{
}

