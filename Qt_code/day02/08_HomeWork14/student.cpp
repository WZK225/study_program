#include "student.h"

Student::Student(QObject *parent)
    :QObject(parent)
{

}

QString Student::getName() const{
    return _name;
}
void Student::setName(const QString &name){
    if(_name != name){
        _name = name;
    }
}

int Student::getAge() const{
    return _age;
}
void Student::setAge(const int &age){
    if(_age != age){
        _age = age;
        emit ageChanged(_age);
    }
}

