#include "widget.h"
#include <QListWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QStatusBar>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("员工管理系统");
    resize(800, 600);

    // 创建QListWidget显示员工列表
    QListWidget *list = new QListWidget(this);
    list->setFixedHeight(500);
    list->setFixedWidth(400);
    list->addItem("小明");
    list->addItem("小刚");


    QLineEdit *search = new QLineEdit(this);
    search->move(400, 0);
    search->setFixedHeight(70);
    search->setFixedWidth(400);
    search->setPlaceholderText("请输入需要搜索的员工名字");

    QTextEdit *textEdit = new QTextEdit(this);
    textEdit->move(400,70);
    textEdit->setFixedHeight(470);
    textEdit->setFixedWidth(400);
    //text->setText("搜索结果");

    QPushButton *btn1 = new QPushButton("添加",this);
    btn1->move(000, 500);
    btn1->resize(200, 40);
    QPushButton *btn2 = new QPushButton("删除", this);
    btn2->move(200, 500);
    btn2->resize(200, 40);

    // 添加功能
    connect(btn1, &QPushButton::clicked, [=]{
        static int num = 0;

        list->addItem(QString("num%1").arg(num));
        num++;
    });

    // 删除功能
    connect(btn2, &QPushButton::clicked, [=]{
        if(QListWidgetItem * currenItem = list->currentItem()){
            list->takeItem(list->row(currenItem));
        }else{
            qDebug() << "提示,请先选择一个列表项";
        }
    });

    // 搜索功能
    connect(search, &QLineEdit::editingFinished, [=]{
        // 获取list列表的行数
        int row = list->count();
        // 遍历list, 搜索与目标匹配的项目
        for(int i = 0; i < row; ++i){
            QListWidgetItem *item = list->item(i);

            QString text1 = item->text();
            if(text1 == search->text()){
                textEdit->insertPlainText("查询结果:存在该员工--");
                textEdit->insertPlainText(text1);
            }
        }
    });
}

Widget::~Widget()
{
}

