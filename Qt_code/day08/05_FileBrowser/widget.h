#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTreeWidget>
#include <QTableWidget>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void set_Layout();
    void set_connect();
    void add_data();

private:
    QTreeWidget *treeWidget;
    QTableWidget *tableWidget;

};
#endif // WIDGET_H
