#include "widget.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("测试窗口");
    resize(800, 600);

    QStandardItemModel *mode = new QStandardItemModel;

    QTableView *tableView = new QTableView(this);
    tableView->setModel(mode);

    // 添加表头
    mode->setHorizontalHeaderItem(0, new QStandardItem("学号"));
    mode->setHorizontalHeaderItem(1, new QStandardItem("姓名"));
    mode->setHorizontalHeaderItem(2, new QStandardItem("性别"));
    mode->setHorizontalHeaderItem(3, new QStandardItem("分数"));

    // 添加数据
    mode->setItem(0, 0, new QStandardItem("191101"));
    mode->setItem(0, 1, new QStandardItem("张三风"));
    mode->setItem(0, 2, new QStandardItem("男"));
    mode->setItem(0, 3, new QStandardItem("700"));

    mode->setItem(1, 0, new QStandardItem("191103"));
    mode->setItem(1, 1, new QStandardItem("赵敏"));
    mode->setItem(1, 2, new QStandardItem("女"));
    mode->setItem(1, 3, new QStandardItem("748"));

    mode->setItem(2, 0, new QStandardItem("191102"));
    mode->setItem(2, 1, new QStandardItem("杨逍"));
    mode->setItem(2, 2, new QStandardItem("男"));
    mode->setItem(2, 3, new QStandardItem("680"));

    // 设置是否可以修改
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 排序
    mode->sort(3, Qt::AscendingOrder);

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(tableView);
    setLayout(vLayout);
}

Widget::~Widget()
{
}

