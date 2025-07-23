#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>

class myobject : public QObject
{
    Q_OBJECT
public:
    explicit myobject(QObject *parent = nullptr);
    ~myobject();

signals:

};

#endif // MYOBJECT_H
