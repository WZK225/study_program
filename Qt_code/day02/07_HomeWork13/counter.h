#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = nullptr);


signals:
    void valueChanged(int);

public slots:
    void setValue(int);

private:
    int m_value;
};

#endif // COUNTER_H
