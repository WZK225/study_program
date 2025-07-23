#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QString>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void setWidgetLayout();
    void connectSignals();
    void addTestData();

public slots:
    void addEmployee();
    void delEmployee();
    void search(const QString &text);


private:
    QListWidget *listWidget;
    QPushButton *btn1;
    QPushButton *btn2;
    QLineEdit *searchEdit;
};
#endif // WIDGET_H
