#include "widget.h"
#include <QCheckBox>
#include <QDebug>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 调整窗口大小
    resize(600, 480);

    // 创建QCheckBox对象
    QCheckBox *box1 = new QCheckBox("味道可口", this);
    QCheckBox *box2 = new QCheckBox("味道可口", this);
    QCheckBox *box3 = new QCheckBox("味道可口", this);
    // 调整位置
//    box1->move(100, 50);
//    box2->move(100, 100);
//    box3->move(100, 150);

    // 设置布局管理器对象
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(box1);
    layout->addWidget(box2);
    layout->addWidget(box3);
    setLayout(layout);

    // 可以设置三种状态
    box1->setTristate(true);
    // 设置默认的选中状态
    box3->setCheckState(Qt::Checked);

    // 只要状态发生改变信号就会被触发
    connect(box1, &QCheckBox::clicked, [](int state){
        switch(state)
        {
        case Qt::Unchecked:
            qDebug() << "未选中";
        case Qt::PartiallyChecked:
            qDebug() << "待选状态";
        case Qt::Checked:
            qDebug() << "被选中";
        default:
            qDebug() << "未知";
        }
    });
}

Widget::~Widget()
{
}

