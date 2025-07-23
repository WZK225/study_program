#include "widget.h"
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QPlainTextEdit>
#include <QTextEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("测试QFileDialog的对话框");
    resize(800, 800);

    QPushButton *btn = new QPushButton("按钮1", this);
    btn->move(50, 100);
    btn->resize(100, 30);

//    QPlainTextEdit *pte = new QPlainTextEdit(this);
//    pte->move(200, 100);
//    pte->resize(500, 600);

    QTextEdit *pte = new QTextEdit(this);
    pte->move(200, 100);
    pte->resize(500, 600);

    connect(btn, &QPushButton::clicked, [=]{
        QString path = QFileDialog::getOpenFileName(this, "窗口",
                                                    "C:/Users/18200/Desktop/file",
                                                    "(*.pro);;(*.txt)");
        qDebug() << path;

        QFile fle(path);
        fle.open(QIODevice::ReadOnly);

        QByteArray ba = fle.readAll();

        QString msg(ba);

        pte->setPlainText(msg);

        fle.close();
    });

}

Widget::~Widget()
{
}

