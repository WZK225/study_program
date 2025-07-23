#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class teacher : public QObject
{
    Q_OBJECT
public:
    explicit teacher(QObject *parent = nullptr);

signals:
    void treat();
//    void treat(QString food);

};

#endif // TEACHER_H
