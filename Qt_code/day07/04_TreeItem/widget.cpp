#include "widget.h"
#include <QTreeWidget>
#include <QDebug>

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

    // 添加三级子对象
    QTreeWidgetItem *file111 = new QTreeWidgetItem(QStringList() << "File1.3");
    file1->addChild(file111);

    // 添加一级子对象
    QTreeWidgetItem *Foler2 = new QTreeWidgetItem(QStringList() << "Folder 2");
    treeWidget->addTopLevelItem(Foler2);

    // 添加二级子对象
    QTreeWidgetItem *file11 = new QTreeWidgetItem(QStringList() << "File2.1");
    Foler2->addChild(file11);

    connect(treeWidget, &QTreeWidget::itemClicked, [=](QTreeWidgetItem *item, int column){
        // 记录路径
        QString path;
        // item的路径追加到末尾
        path.append("/" + item->text(1));
        // 循环向上遍历,将parent的名字加入到path中
        while(item != nullptr){
            path.prepend("/" + item->text(0));
            item = item->parent();
        }
        qDebug() << path;
    });
    // 展开所有的结点
    treeWidget->expandAll();
}

Widget::~Widget()
{
}

