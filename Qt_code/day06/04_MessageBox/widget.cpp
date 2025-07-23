#include "widget.h"
#include <QMessageBox>
#include <QPushButton>
#include <QColor>
#include <QColorDialog>
#include <QDebug>
#include <QFontDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("测试MessageBox的窗口");
    resize(600, 480);

    QPushButton *btn = new QPushButton("QMessageBox按钮", this);
    btn->move(100, 100);
    btn->resize(200, 100);

//    connect(btn, &QPushButton::clicked, [=]{
//        QMessageBox::question(this, "question"
//                              , "问题"
//                              , QMessageBox::Save | QMessageBox::Cancel
//                              , QMessageBox::Cancel);
//    });

//    connect(btn, &QPushButton::clicked,[=]{
//       QColor col = QColorDialog::getColor(QColor(255, 0, 0));
//       qDebug() << "r = " << col.red()
//                << "g = " << col.green()
//                << "b = " << col.blue();
//    });

    connect(btn, &QPushButton::clicked,[=]{
        bool flag = false;
        QFont qf = QFontDialog::getFont(&flag, QFont("仿宋"));
        qDebug() << "字体:" << qf.family().toUtf8().data() << endl
                 << "字号" << qf.pointSize() << Qt::endl
                 << "是否加粗" << qf.italic() << Qt::endl
                 << "是否下划线:" << qf.underline() << Qt::endl
                 << "是否删除线: " << qf.strikeOut() << Qt::endl
                 << "字体风格:" << qf.style() << Qt::endl
                 << "字重:" << qf.weight() << Qt::endl
                 << "字母间距:" << qf.letterSpacing() << Qt::endl
                 << "单词间距:" << qf.wordSpacing() << Qt::endl
                 << "样式策略:" << qf.styleStrategy() << Qt::endl;
    });

}

Widget::~Widget()
{
}

