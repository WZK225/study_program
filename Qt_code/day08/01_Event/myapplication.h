#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>
#include <QDebug>

class MyApplication : public QApplication
{
    Q_OBJECT
public:
    explicit MyApplication(int argc, char *argv[]);

    // 重写notify函数
    bool notify(QObject *receiver, QEvent *event) override;
};

#endif // MYAPPLICATION_H
