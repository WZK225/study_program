#include "myobject.h"

#include <QDebug>

myobject::myobject(QObject *parent) : QObject(parent)
{

}

myobject::~myobject()
{
    qDebug() << "~myobject()";
}
