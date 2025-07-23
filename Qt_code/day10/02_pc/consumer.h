#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include "taskqueue.h"

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(TaskQueue & taskqueue, QObject *parent = nullptr);
    ~Consumer();

public slots:
    void consume();

private:
    TaskQueue &taskQue;

signals:
    void signalQuit2();
};

#endif // CONSUMER_H
