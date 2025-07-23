#include "widget.h"
#include <QPushButton>
#include <QDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("测试对话框程序");
        resize(600, 480);

        QPushButton *btn1 = new QPushButton("模态对话框按钮", this);
        QPushButton *btn2 = new QPushButton("栈对象非模态对话框按钮", this);
        QPushButton *btn3 = new QPushButton("堆对象非模态对话框按钮", this);
        btn1->move(100, 100);
        btn2->move(100, 200);
        btn3->move(100, 300);
        btn1->resize(300, 50);
        btn2->resize(300, 50);
        btn3->resize(300, 50);

        connect(btn1, &QPushButton::clicked, [=]{
            QDialog dlg(this);
            dlg.setWindowTitle("模态对话框");
            dlg.resize(300, 200);

            dlg.exec();//对话框阻塞在此处，并且不能与父窗口交互
            qDebug() << "模态对话框";
        });

        connect(btn2, &QPushButton::clicked, [=]{
            QDialog dlg(this);
            dlg.setWindowTitle("栈非模态对话框");
            dlg.resize(300, 200);

            dlg.show();//对话框闪一下就没有了，dlg用完就销毁了
            qDebug() << "非模态模态对话框";
        });

        connect(btn3, &QPushButton::clicked, [=]{
            QDialog *pdlg = new QDialog(this);
            pdlg->setWindowTitle("堆非模态对话框");
            pdlg->resize(300, 200);
            //设置对话框属性
            pdlg->setAttribute(Qt::WA_DeleteOnClose);//关闭的时候释放内存
            pdlg->show();//对话框闪一下就没有了，dlg2用完就销毁了
            qDebug() << "非模态模态对话框";
        });
}

Widget::~Widget()
{
}

