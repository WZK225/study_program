#include "widget.h"
#include "myobject.h"

#include <QApplication>
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    myobject obj;

    obj.setName("wuhan");

    qDebug() << obj.getName();

    QObject::connect(&obj, &myobject::namechange, [](const QString &na){
        qDebug() << "变化后的属性值" << na;
    });

    obj.setName("hubei");

    qDebug() << "name222 = " << obj.property("name").toString();

    obj.setProperty("name", "hahaha");

    qDebug() << endl << endl;

    // 使用元对象的指针获取基对象的指针meta
    const QMetaObject *meta = obj.metaObject();

    qDebug() << "基类的名字" << meta->className();

    // 使用元对象的指针获取基对象的属性
    for(int idx = 0; idx < meta->propertyCount(); ++idx){
        QMetaProperty pro = meta->property(idx);
        qDebug() << "属性的名字" << pro.name()
                 << "属性的属性" << pro.typeName();
    }

    // 使用元对象的指针获取基对象的方法
    for(int idx = 0; idx < meta->methodCount(); ++idx){
        QMetaMethod method = meta->method(idx);
        qDebug() << "Method" << method.methodSignature();
    }


    return a.exec();
}
