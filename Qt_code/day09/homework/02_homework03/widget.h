#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *event) override;

    void second_move(QPainter & pat);
    void minute_move(QPainter & pat);
    void hour_move(QPainter & pat);

    void setLine(QPainter & pat);
    void set_currentTime();

private:
//    int m_angle = 0;
    int second = 0;
    int minute = 0;
    int hour = 0;
};
#endif // WIDGET_H
