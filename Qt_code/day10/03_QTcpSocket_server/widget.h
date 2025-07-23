#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void handle();
    QString process(const QString &request);

private:
    Ui::Widget *ui;
    QTcpServer *_tcpSever;
};
#endif // WIDGET_H
