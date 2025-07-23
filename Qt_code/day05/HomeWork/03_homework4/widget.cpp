#include "widget.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QHBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
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

//   connect(treeWidget, &QTreeWidget::itemClicked, [](QTreeWidgetItem *item, int column){
////       qDebug() << item->text(column);
//       while(1){
//           QTreeWidgetItem *tmp = ui->treeWidget->topLevelWidget(0);
//       }
//   });


   QHBoxLayout *bLayout = new QHBoxLayout;
   bLayout->addWidget(treeWidget);
   setLayout(bLayout);
}

Widget::~Widget()
{
}

