#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_current_num(" ")
    , m_result(0.0)
    , m_operator(" ")
    ,flag(false)
{
    ui->setupUi(this);

    // 1.将数据按钮与槽链接;
    for(int i = 0; i < 9; ++i){
        // UI按钮命名:Button1, BUtton2
        QString buttonaNeme = "Button" + QString::number(i);
        QPushButton *digitButton = findChild<QPushButton*>(buttonaNeme);
        connect(digitButton, &QPushButton::clicked, this, &Widget::on_click_num);
    }

    // 2.将点击操作符与槽函数链接
    connect(ui->ButtonPlus, &QPushButton::clicked, this, &Widget::on_click_operator);
    connect(ui->ButtonMinus, &QPushButton::clicked, this, &Widget::on_click_operator);
    connect(ui->ButtonMultiply, &QPushButton::clicked, this, &Widget::on_click_operator);
    connect(ui->ButtonDivide, &QPushButton::clicked, this, &Widget::on_click_operator);

    // 3.将点击等号与槽函数链接
    connect(ui->ButtonEqual, &QPushButton::clicked, this, &Widget::on_click_equal);

    // 4.将点击clear与槽函数链接
    connect(ui->ButtonClear, &QPushButton::clicked, this, &Widget::on_click_clear);
}

// 点击数字触发的槽函数
void Widget::on_click_num(){
    // sender用于在槽函数内部获取触发当前槽执行的信号的发送者对象
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    QString digit = clickedButton->text();

    // flag:当需要接收操作数时,flag为true,
    //      当需要接收运算符时,flag为false,
    //      默认为false,因为需要首先接收一个操作数

    // 需要更新当前操作数:
    if(flag){
        // 此处已经接收一个运算符,需要接收操作数,
        // 当接收完操作数的第一个数后,将flag设为false,之后操作数的位直接使用QString拼接
        m_current_num = digit;
        flag = false;

    }else{
        // 由于一个操作数可能需要点击多次,因此可以使用QString进行拼接
        // 成为一个完整的操作数,
        m_current_num += digit;
    }

    // 更新完操作数,需要将起显示到LineEdit上
    ui->display->setText(m_current_num);
}
// 点击操作符触发的槽函数
void Widget::on_click_operator(){
    // sender用于在槽函数内部获取触发当前槽执行的信号的发送者对象
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    QString op = clickedButton->text();

    double value = m_current_num.toDouble();

    if(!m_operator.isEmpty()){
        if(op == "+"){
           m_result += value;
        }else if(op == "-"){
           m_result -= value;
        }else if(op == "*"){
           m_result *= value;
        }else if(op == "/"){
           if(value != 0){
               m_result /= value;
           }else{
               ui->display->setText("Error");
               return;
           }
        }
    }else{
        m_result = value;
    }

    // 将结果显示到LineEdit上
    m_operator = op;
    flag = true;
    ui->display->setText(QString::number(m_result));
}
// 点击等号触发的槽函数
void Widget::on_click_equal(){

    if(!m_operator.isEmpty()){
        double value = m_current_num.toDouble();
        if(m_operator == "+"){
           m_result += value;
        }else if(m_operator == "-"){
           m_result -= value;
        }else if(m_operator == "*"){
           m_result *= value;
        }else if(m_operator == "/"){
           if(value != 0){
               m_result /= value;
           }else{
               ui->display->setText("Error");
               return;
           }
        }
    }

    // 更改变量
    m_current_num = QString::number(m_result);
    m_operator.clear();
    flag = true;
    // 将结果显示到LineEdit上
    ui->display->setText(QString::number(m_result));
}

// 点击清空触发的槽函数
void Widget::on_click_clear(){
    m_current_num = " ";
    m_operator.clear();
    m_result = 0.0;
    flag = false;
    ui->display->setText(m_current_num);
}

Widget::~Widget()
{
    delete ui;
}

