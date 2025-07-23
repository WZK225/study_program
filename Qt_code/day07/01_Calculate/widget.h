#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    // 由于信号的来源都是来自按钮的点击,因此本程序中不需要额外的信号

public slots:
    void on_click_num();        // 点击数字触发的槽函数
    void on_click_operator();   // 点击操作符触发的槽函数
    void on_click_equal();      // 点击等号触发的槽函数
    void on_click_clear();      // 点击清空触发的槽函数

private:
    Ui::Widget *ui;
    QString m_current_num;    // 当前的操作数
    double  m_result;         // 当前运算的结果
    QString m_operator;       // 当前的运算符
    bool flag;                // 是否继续进行计算的标志
};
#endif // WIDGET_H
