#include "student.h"

#include <QDebug>

student::student(QObject *parent) : QObject(parent)
{

}

void student::eat(){
    qDebug() << "此大米饭";
}

//void student::eat(QString food){
//    qDebug() << "老师请学生吃大米饭" << food;
//}
