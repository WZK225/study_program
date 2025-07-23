#include "widget.h"
#include <QListView>
#include <QStringListModel>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("测试窗口");
    resize(600, 480);

    // 1.创建对象
    QListView *lt = new QListView(this);
    lt->move(100, 100);
    lt->resize(300, 200);

    // 需要填充的内容
    // QStringList重载了输出流运算符,因此该对象可以直接使用<<
    QStringList list;
    list << "运动类：篮球、足球"
         << "娱乐类：看电影、写小说、听音乐"
         << "游戏类：五子棋、扑克牌、中国象棋"
         << "旅游类：国外旅游、国内旅游";

    // 需要与视图链接的模型
    QStringListModel *listMode = new QStringListModel(list);
    // 将视图与模型建立练习
    lt->setModel(listMode);

    // 使用信号与槽
    // QMessageBox--用于显示消息对话框的类
    // information()--显示信息对话框，默认有一个OK按钮
    // data()
    // toString()
    connect(lt, &QListView::clicked, [&](const QModelIndex &index){
        QMessageBox::information(this, "提示", "展示内容" + index.data().toString());
    });

}

Widget::~Widget()
{
}

