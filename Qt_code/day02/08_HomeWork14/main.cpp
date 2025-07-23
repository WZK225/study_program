#include "widget.h"
#include "student.h"

#include <QApplication>
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    Student st;

    QObject::connect(&st, &Student::ageChanged, [](const qint32 age){
        qDebug() << "age = " << age;
    });

    st.setName("jack");
    st.setAge(16);

    st.setProperty("name", "Tom");
    qDebug() << st.property("name").toString();

    const QMetaObject *meta = st.metaObject();

    for(int idx = 0; idx < meta->propertyCount(); ++idx){
        QMetaProperty pro = meta->property(idx);
        qDebug() << "属性的名字" << pro.name()
                 << "属性的属性" << pro.typeName();
    }

    for(int idx = 0; idx < meta->methodCount(); ++idx){
        QMetaMethod method = meta->method(idx);
        qDebug() << "Method" << method.methodSignature();
    }

    return a.exec();
}
