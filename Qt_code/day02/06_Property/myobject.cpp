#include "myobject.h"

myobject::myobject(QObject *parent) : QObject(parent)
{

}

// 读属性值
QString myobject::getName() const{
    return m_name;
}

// 对属性值进行写操作
void myobject::setName(const QString &nme){
    if(nme != m_name){
        m_name = nme;
        emit namechange(nme);
    }
}

// 重置属性的值
void myobject::resetName(){
    m_name = "wangdao";
}
