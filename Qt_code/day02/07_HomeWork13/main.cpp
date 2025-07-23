#include "widget.h"
#include "counter.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    Counter co;

    QObject::connect(&co, &Counter::valueChanged, [](int value){
        qDebug() << "value = " << value;
    });

    co.setValue(10);
    co.setValue(100);

    return a.exec();
}
