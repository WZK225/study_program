#include "widget.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    // 动态设置属性"name"
    w.setProperty("name", "wangdao");
    qDebug() << w.property("name").toString();

    // 动态设置属性"age"
    w.setProperty("age", 100);
    qDebug() << w.property("age").toInt();


    return a.exec();
}
