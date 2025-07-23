#include "widget.h"
#include <QTreeWidget>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QTreeWidgetItem>
#include <QDebug>
#include <QMessageBox>
#include <QMenu>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("fileBroswer");
    resize(1000, 800);

    QTreeWidget *treeWidget = new QTreeWidget();
    treeWidget->setHeaderLabel(QString("目录结构"));

    QTreeWidgetItem *tree1 = new QTreeWidgetItem(QStringList() << "Root1");
    QTreeWidgetItem *tree2 = new QTreeWidgetItem(QStringList() << "Root2");

    treeWidget->addTopLevelItem(tree1);
    treeWidget->addTopLevelItem(tree2);

    QTreeWidgetItem *tree11 = new QTreeWidgetItem(QStringList() << "Floder1");
    QTreeWidgetItem *tree12 = new QTreeWidgetItem(QStringList() << "Floder2");
    QTreeWidgetItem *tree111 = new QTreeWidgetItem(QStringList() << "File1");
    tree1->addChild(tree11);
    tree1->addChild(tree12);
    tree11->addChild(tree111);

    QTreeWidgetItem *tree21 = new QTreeWidgetItem(QStringList() << "Floder2");
    tree2->addChild(tree21);

    treeWidget->expandAll();

    QTableWidget *tableWidget = new QTableWidget;
    tableWidget->setColumnCount(3);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "名称" << "父节点" << "Column");
    tableWidget->setRowCount(8);


    // 选中显示文件详细信息
    connect(treeWidget, &QTreeWidget::itemClicked, [=](QTreeWidgetItem *item, int column){
        static int row = 0;
        QStringList plist;

        plist << item->text(column);
        plist << item->parent()->text(column);
        int num = item->columnCount();

        plist << QString("%1").arg(num);
        for(int i = 0; i < 3; ++i){
            tableWidget->setItem(row, i, new QTableWidgetItem(plist[i]));
        }
        row++;
    });

    // 双击文件打开功能
    connect(treeWidget, &QTreeWidget::itemDoubleClicked, [=](QTreeWidgetItem *item, int column){
        QMessageBox::information(this, "文件内容", "正文内容", QMessageBox::Save|QMessageBox::Cancel
                                 , QMessageBox::Cancel);
    });

    // 右键菜单功能
    connect(treeWidget, &QTreeWidget::itemClicked, [=](QTreeWidgetItem *item, int column){
        QMenu menu(this);
        QAction *actionEdit = menu.addAction("编辑项");
        QAction *actionDelete = menu.addAction("删除项");
        menu.addSeparator();
        QAction *actionInfo = menu.addAction("查看信息");

    });

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(treeWidget);
    hLayout->addWidget(tableWidget);
    setLayout(hLayout);

}

Widget::~Widget()
{
}

