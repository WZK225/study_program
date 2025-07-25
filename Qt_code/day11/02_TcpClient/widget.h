#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:


private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *m_client;
};
#endif // WIDGET_H
