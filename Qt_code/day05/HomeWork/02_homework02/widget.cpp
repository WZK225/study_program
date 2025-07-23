#include "widget.h"
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("测试窗口");
    resize(600, 480);

    QPushButton *pbt1 = new QPushButton("Add Item");
    QPushButton *pbt2 = new QPushButton("Remove Selected");

    QListWidget *listWidget = new QListWidget();
    listWidget->addItem("锄禾日当午");
    listWidget->addItem("汗滴禾下土");
    listWidget->addItem("谁知盘中餐");
    listWidget->addItem("粒粒皆辛苦");

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(listWidget);
    vLayout->addWidget(pbt1);
    vLayout->addWidget(pbt2);
    setLayout(vLayout);


    connect(pbt1, &QPushButton::clicked, [=]{
        static int count = 0;
        listWidget->addItem(QString("Item %1").arg(++count));
    });

    connect(pbt2, &QPushButton::clicked, this, [=](){
        if(QListWidgetItem *currentItem = listWidget->currentItem()){
            listWidget->takeItem(listWidget->row(currentItem));
        }else{
            qDebug() <<"提示,请先选择一个列表项";
        }
    });
}

Widget::~Widget()
{
}

