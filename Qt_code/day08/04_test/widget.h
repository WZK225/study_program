#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void mousePressEvent(QMouseEvent *event) override;

    bool event(QEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

};
#endif // WIDGET_H
