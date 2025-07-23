#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)

{
    m_tc = new teacher;
    m_st = new student;

    // 将信号与槽进行连接
    //1.qt4的写法
//    connect(m_tc, SIGNAL(treat()), m_st, SLOT(eat()));

    // connect没有接收者的版本,槽函数使用lambda进行替代
//    connect(m_tc, &teacher::treat, [](){
//       qDebug() << "hahaha";
//    });

    connect(m_tc, &teacher::treat, m_st, &student::eat);

    // 当有函数重载的时候,可以显式的使用成员函数指针进行体现
//    void (teacher::*ptcVoid)() = &teacher::treat;
//    void (student::*pstVoid)() = &student::eat;
//    connect(m_tc, ptcVoid, m_st, pstVoid);

//    void (teacher::*ptcArg)(QString) = &teacher::treat;
//    void (student::*pstArg)(QString) = &student::eat;
//    connect(m_tc, ptcArg, m_st, pstArg);

    // 针对于重载版本的时候,C++的写法
//    connect(m_tc, QOverload<>::of(&teacher::treat),
//            m_st, QOverload<>::of(&student::eat));

//    connect(m_tc, QOverload<QString>::of(&teacher::treat),
//            m_st, QOverload<QString>::of(&student::eat));


    // 针对于重载版本的时候,c++14的写法
//    connect(m_tc, qOverload<>(&teacher::treat),
//            m_st, qOverload<>(&student::eat));

//    connect(m_tc, qOverload<QString>(&teacher::treat),
//            m_st, qOverload<QString>(&student::eat));
//    connect(m_tc, qOverload<QString>(&teacher::treat), [](){
//        qDebug() << "哈哈哈";
//    });

    classIsOver();
}

Widget::~Widget()
{
    delete m_tc;
    delete m_st;
}

void Widget::classIsOver(){
    // 触发信号
    emit m_tc->treat();
//    emit m_tc->treat("满汉全席");
}

