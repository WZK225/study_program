#include "widget.h"
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("测试窗口");
    resize(600, 480);

    QPushButton *pbt1 = new QPushButton("Add Item");
    QPushButton *pbt2 = new QPushButton("Remove Selected");

    m_listWidget = new QListWidget(this);
    m_listWidget->addItem("锄禾日当午");
    m_listWidget->addItem("汗滴禾下土");
    m_listWidget->addItem("谁知盘中餐");
    m_listWidget->addItem("粒粒皆辛苦");

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(m_listWidget);
    vLayout->addWidget(pbt1);
    vLayout->addWidget(pbt2);
    setLayout(vLayout);


    connect(pbt1, &QPushButton::clicked, [&]{
        static int count = 0;
        m_listWidget->addItem(QString("Item %1").arg(++count));
        //listWidget->addItem("Item X");
    });

    // 是否选中列表项
    // bool flag = false;
    // 被选中列表项的行号
    // int row = -1;

//    // 判断是否选中
//    connect(listWidget, &QListWidget::itemClicked, [&]{
//        flag = true;
//        row = listWidget->currentRow();
//    });

//    // 将被选中的列表项删除
//    connect(pbt2, &QPushButton::clicked ,[=](){
//        if(flag){
//           listWidget->takeItem(row);
//        }
//    });

    connect(pbt2, &QPushButton::clicked, this, [this](){
        if(auto currentItem = m_listWidget->currentItem()){
            delete m_listWidget->takeItem(m_listWidget->row(currentItem));
        }else{
            QMessageBox::information(this, "提示", "请先选择一个列表项");
        }
    });

}

Widget::~Widget()
{
}

