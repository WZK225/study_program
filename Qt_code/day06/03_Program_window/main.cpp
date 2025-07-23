#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w, w2;
    w.test();
    w.resize(600, 480);
    w.show();
    w.setWindowTitle("win1");

    w2.setWindowTitle("win2");
    w2.resize(600, 480);
    w2.show();

    return a.exec();
}
