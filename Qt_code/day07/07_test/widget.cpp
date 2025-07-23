#include "widget.h"
#include <QTreeWidget>
#include <QTextEdit>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QCheckBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 创建对象
    QTreeWidget *treeWidget = new QTreeWidget;
    QTextEdit *line = new QTextEdit;
    QTableWidget *tableWidget = new QTableWidget;
    QRadioButton *rbtn1= new QRadioButton(tableWidget);
    QRadioButton *rbtn2= new QRadioButton(tableWidget);
    QCheckBox *cbtn1 = new QCheckBox(tableWidget);
    QCheckBox *cbtn2 = new QCheckBox(tableWidget);

    // 设置布局
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(rbtn1);
    vLayout->addWidget(rbtn2);
    vLayout->addWidget(cbtn1);
    vLayout->addWidget(cbtn2);
    tableWidget->setLayout(vLayout);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(treeWidget);
    hLayout->addWidget(line);
    hLayout->addWidget(tableWidget);
    setLayout(hLayout);
}

Widget::~Widget()
{
}

