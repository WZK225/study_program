#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void timerEvent(QTimerEvent *event) override;

private:
    Ui::Widget *ui;
    int m_id1;
    int m_id2;
};
#endif // WIDGET_H
