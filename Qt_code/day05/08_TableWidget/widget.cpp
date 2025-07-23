#include "widget.h"
#include <QTableWidget>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("测试窗口");
    resize(600, 480);

    // 设置列数
    QTableWidget *tableWidget = new QTableWidget;
    tableWidget->setColumnCount(3);

    // 设置水平表头
    tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");
    // 设置行数
    tableWidget->setRowCount(5);

    // 设置正文
    QStringList nameList;
    nameList << "刘备" << "关羽" << "张飞" << "小乔" << "赵云";

    QStringList sexList;
    sexList << "男" << "男" << "男" << "女" << "男";

    for(int i = 0; i < 5; ++i){
        int col = 0;
        tableWidget->setItem(i, col++, new QTableWidgetItem(nameList[i]));
        tableWidget->setItem(i, col++, new QTableWidgetItem(sexList.at(i)));
        tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(i + 18)));
    }

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(tableWidget);
    setLayout(hLayout);
}

Widget::~Widget()
{
}

