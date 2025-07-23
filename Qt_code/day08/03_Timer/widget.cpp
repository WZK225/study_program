#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 启动定时器
    m_id1 = startTimer(500);
    m_id2 = startTimer(1000);

    // 第二种定时器用法:使用QTimer类型
    QTimer *tm = new QTimer(this);

    connect(tm, &QTimer::timeout, [=]{
        static int num3 = 1;
        ui->label_4->setText(QString::number(num3++));
    });

    tm->start(2000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event){
    if(m_id1 == event->timerId()){
        static int num1 = 1;
        ui->label->setText(QString::number(num1++));
    }

    if(m_id2 == event->timerId()){
        static int num2 = 1;
        ui->label_2->setText(QString::number(num2++));
    }
}


