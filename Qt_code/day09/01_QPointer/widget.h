#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 将绘画的图片显示在QWidget上时,需要重写paintEvent事件处理函数
    void paintEvent(QPaintEvent *event) override;
};
#endif // WIDGET_H
