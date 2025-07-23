#include "widget.h"

#include <QApplication>
#include <mylabel.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
    MyLabel label;
    label.show();
//    w.show();
    return a.exec();
}
