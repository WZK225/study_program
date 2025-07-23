#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QDebug>
#include <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel(QLabel *parent = nullptr);
    ~MyLabel();

    // 鼠标进入事件
    void enterEvent(QEvent *event) override;

    // 鼠标离开事件
    void leaveEvent(QEvent *event) override;

    // 重写鼠标按压事件
    void mousePressEvent(QMouseEvent *event) override;

    // 重写鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *ev) override;

    // 重写鼠标移动事件
    void mouseMoveEvent(QMouseEvent *ev) override;


    // 重写event函数
    bool event(QEvent *e) override;

    // 重写事件过滤函数()事件过滤器
    bool eventFilter(QObject *obj, QEvent *event) override;

};

#endif // MYLABEL_H
