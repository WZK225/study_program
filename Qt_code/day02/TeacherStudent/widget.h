#ifndef WIDGET_H
#define WIDGET_H

#include "student.h"
#include "teacher.h"

#include <QWidget>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void classIsOver();

private:
    teacher *m_tc;
    student *m_st;
};
#endif // WIDGET_H
