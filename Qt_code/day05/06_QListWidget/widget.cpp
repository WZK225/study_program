#include "widget.h"
#include <QListWidgetItem>
#include <QListWidget>
#include <QDebug>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("测试窗口");
    resize(600, 480);

    QListWidgetItem *plw = new QListWidgetItem("锄禾日当午");

    QListWidget *listWidget = new QListWidget(this);
    listWidget->addItem(plw);

    plw->setTextAlignment(Qt::AlignHCenter);

    QStringList lst;
    lst << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";
    listWidget->addItems(lst);

    listWidget->addItem("锄禾日当午");
    listWidget->addItem("汗滴禾下土");
    listWidget->addItem("谁知盘中餐");
    listWidget->addItem("粒粒皆辛苦");

    QListWidgetItem *item = new QListWidgetItem("item with icon");
    item->setFont(QFont("黑体"));
    item->setBackground(Qt::red);
    listWidget->addItem(item);

    connect(listWidget, &QListWidget::itemClicked, [](QListWidgetItem *item){
       qDebug() << "Clicked Item:" << item->text();
       qDebug() << item->font().family().toUtf8().data()
                <<item->font().bold();
    });

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(listWidget);
    setLayout(hLayout);
}

Widget::~Widget()
{
}

