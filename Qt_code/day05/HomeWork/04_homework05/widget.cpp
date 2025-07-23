#include "widget.h"
#include "ui_widget.h"

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDebug>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

   setWindowTitle("测试窗口");
   resize(600, 480);

   QTreeWidget *treeWidget = new QTreeWidget;
   // 无水平头

   // 设置属性部件项目
   QTreeWidgetItem *itemRoot = new QTreeWidgetItem(QStringList() << "Root");

   // 加载顶层结点
   treeWidget->addTopLevelItem(itemRoot);
   // 追加子节点
   QTreeWidgetItem *f1 = new QTreeWidgetItem(QStringList() << "Folder 1");
   itemRoot->addChild(f1);
   QTreeWidgetItem *f2 = new QTreeWidgetItem(QStringList() << "Folder 2");
   itemRoot->addChild(f2);

   QTreeWidgetItem *file1 = new QTreeWidgetItem(QStringList() << "File 1.1");
   f1->addChild(file1);
   QTreeWidgetItem *file2 = new QTreeWidgetItem(QStringList() << "File 1.2");
   f1->addChild(file2);
   QTreeWidgetItem *file3 = new QTreeWidgetItem(QStringList() << "File 2.1");
   f2->addChild(file3);

   treeWidget->expandAll();

   connect(treeWidget, &QTreeWidget::itemClicked, [=](QTreeWidgetItem *item, int column){
       // 获取第一个顶层节点
//       QTreeWidgetItem *top = treeWidget->topLevelItem(0);
//       QTreeWidgetItem *tmp = item->parent();

//       while(1){
//           if((top->text(column)) == tmp->text(column)){
//               qDebug() << "已到达顶层";
//               break;
//           }
//           qDebug() << tmp->text(column);
//           tmp = item->parent();
//       }

       // 从当前项向上遍历到根节点
       QTreeWidgetItem *current = item;

       QStringList list;
       while(current){
           list << "/" << current->text(0);
           //qDebug() << "当前结点:" << current->text(0) << "| 列:" << column;

           // 检查是否到达顶层(没有父节点)
           if(!current->parent()){
               qDebug() << "----已到达顶层结点----";
               break;
           }

           // 移动到父节点
           current = current->parent();
       }
        qDebug() << list;
   });

   QHBoxLayout *bLayout = new QHBoxLayout;
   bLayout->addWidget(treeWidget);
   setLayout(bLayout);
}

Widget::~Widget()
{
}



