#include "widget.h"
#include <QStandardItemModel>
#include <QTreeView>
#include <QDebug>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("测试窗口");
    resize(600, 480);

    // 初始化model
    QStandardItemModel *itemMode = new QStandardItemModel(this);
    // 设置水平表头
    itemMode->setHorizontalHeaderLabels(QStringList() << QStringLiteral("编号") << QStringLiteral("初中部|高中部"));

    // 将TreeView控件载入model
    QTreeView *treeView = new QTreeView(this);
    treeView->setModel(itemMode);
//    treeView->resize(400, 300);
//    treeView->move(100, 100);

    // 创建一级结点,将其加入到itemMode中
    QList<QStandardItem *> itemRoot1;

    QStandardItem *itemNum1 = new QStandardItem(QString::number(1));
    QStandardItem *itemMiddleSchool = new QStandardItem("初中部");
    itemRoot1.append(itemNum1);
    itemRoot1.append(itemMiddleSchool);
    itemMode->appendRow(itemRoot1);

    // 添加二级结点, 添加到第一个一级结点
    QList<QStandardItem *> itemChild;

    QStandardItem *itemNum11 = new QStandardItem(QString::number(11));
    QStandardItem *itemFirstGrade = new QStandardItem("一年级");
    itemChild.append(itemNum11);
    itemChild.append(itemFirstGrade);
    itemNum1->appendRow(itemChild);

    // 添加三级结点, 添加到第一个二级结点
    QList<QStandardItem *> itemGrandSon;

    QStandardItem *itemNum111 = new QStandardItem(QString::number(111));
    QStandardItem *itemClassOne  = new QStandardItem("一班");
    itemGrandSon.append(itemNum111);
    itemGrandSon.append(itemClassOne);
    itemNum11->appendRow(itemGrandSon);

    // 添加三级结点, 添加到第一个二级结点
    QList<QStandardItem *> itemGrandSon2;

    QStandardItem *itemNum122 = new QStandardItem(QString::number(122));
    QStandardItem *itemClassTwo  = new QStandardItem("二班");
    itemGrandSon2.append(itemNum122);
    itemGrandSon2.append(itemClassTwo);
    itemNum11->appendRow(itemGrandSon2);

    // 创建一级结点,将其加入到itemMode中
    QList<QStandardItem *> itemRoot2;

    QStandardItem *itemNum2 = new QStandardItem(QString::number(2));
    QStandardItem *itemHighSchool = new QStandardItem("高中部");
    itemRoot2.append(itemNum2);
    itemRoot2.append(itemHighSchool);
    itemMode->appendRow(itemRoot2);

    // 默认展开所有数据
    treeView->expandAll();

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(treeView);
    setLayout(hLayout);
}

Widget::~Widget()
{
}

