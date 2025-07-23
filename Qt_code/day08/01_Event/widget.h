#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 重写鼠标按压操作
    void mousePressEvent(QMouseEvent *event) override;
//    void mouseDoubleClickEvent(QMouseEvent *event) override;

    // 重写event函数
    bool event(QEvent *event) override;

    // 键盘按压事件
    void keyPressEvent(QKeyEvent *event) override;

};
#endif // WIDGET_H
