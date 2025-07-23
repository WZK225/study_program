#include "widget.h"
#include "myobject.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    myobject obj;
    myobject * pobj = new myobject;
//    myobject * pobj = new myobject(&obj);

//    delete pobj;
    pobj->deleteLater();

    return a.exec();
}
