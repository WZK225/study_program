#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    int m_x = 0;
    QListWidget *m_listWidget = nullptr;

};
#endif // WIDGET_H
