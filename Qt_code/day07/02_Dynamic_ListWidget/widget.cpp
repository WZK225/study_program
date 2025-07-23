#include "widget.h"
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 1.创建对象
    QListWidget *listWidget = new QListWidget;
    QPushButton *btn1 = new QPushButton("添加");
    QPushButton *btn2 = new QPushButton("删除");

    // 2.添加功能
//    connect(btn1, &QPushButton::clicked, [=]{
//        static int number = 0;
//        listWidget->addItem("item" + QString::number(number++));
//    });

    // 2.1拓展:添加时,使用消息框提示,并可以手动输入需要添加的内容
    connect(btn1, &QPushButton::clicked, [=]{
        QString name = QInputDialog::getText(this, "添加Item", "请输入需要添加的Item", QLineEdit::Normal, "Item0");
        if(!name.isEmpty()){
            listWidget->addItem(name);
        }
    });

    // 3.删除功能
//    connect(btn2, &QPushButton::clicked, [=]{
//       delete listWidget->takeItem(listWidget->currentRow());
//    });

    // 3.1拓展:删除时,弹出对话框询问,点击确定后删除
    connect(btn2, &QPushButton::clicked, [=]{
        QMessageBox::StandardButton reply = QMessageBox::warning(this, "提示框", "是否删除选中项", QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes){
            delete listWidget->takeItem(listWidget->currentRow());
        }
    });

    // 4.设置布局
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(btn1);
    hLayout->addWidget(btn2);
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(listWidget);
    vLayout->addLayout(hLayout);
    setLayout(vLayout);
}


Widget::~Widget()
{
}

