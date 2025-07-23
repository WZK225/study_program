#include "widget.h"
#include <QTreeWidget>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 调整窗口
    setWindowTitle("测试窗口");
    resize(800, 600);

    // 创建QTreeWidget对象
    QTreeWidget *treeWidget = new QTreeWidget(this);
    treeWidget->setHeaderLabel("文件树");
    treeWidget->resize(600, 400);
    treeWidget->move(100, 100);

    // 添加一级子对象
    QTreeWidgetItem *Foler = new QTreeWidgetItem(QStringList() << "Folder 1");
    treeWidget->addTopLevelItem(Foler);

    // 添加二级子对象
    QTreeWidgetItem *file1 = new QTreeWidgetItem(QStringList() << "File1.1");
    QTreeWidgetItem *file2 = new QTreeWidgetItem(QStringList() << "File1.2");
    Foler->addChild(file1);
    Foler->addChild(file2);

    // 添加一级子对象
    QTreeWidgetItem *Foler2 = new QTreeWidgetItem(QStringList() << "Folder 2");
    treeWidget->addTopLevelItem(Foler2);

    // 添加二级子对象
    QTreeWidgetItem *file11 = new QTreeWidgetItem(QStringList() << "File2.1");
    Foler2->addChild(file11);
}

Widget::~Widget()
{
}

