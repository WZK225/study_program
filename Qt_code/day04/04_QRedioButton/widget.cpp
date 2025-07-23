#include "widget.h"
#include <QRadioButton>
#include <QVBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 更改窗口的尺寸
    resize(600, 480);

    // 创建QRadioButton对象
    QRadioButton *boy = new QRadioButton("男");
    QRadioButton *girl = new QRadioButton("女");
    QRadioButton *xx = new QRadioButton("未知");

    // 创建布局配置器对象
    QVBoxLayout *layout = new QVBoxLayout;
    // 将按钮部件添加到布局配置器上
    layout->addWidget(boy);
    layout->addWidget(girl);
    layout->addWidget(xx);
    // 设置布局配置器
    setLayout(layout);

    // 使用信号与槽
    connect(boy, &QRadioButton::clicked, [=](bool flag){
        if(flag){
            qDebug() << "男生被选中了";
        }else{
            qDebug() << "男生没有被选中";
        }

        if(boy->isChecked()){
            qDebug() << "也表明男生被选中了";
        }
    });

}

Widget::~Widget()
{
}

