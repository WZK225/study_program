#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include "taskqueue.h"


class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(TaskQueue &taskQueue, QObject *parent = nullptr);
    ~Producer();

public slots:
    void produce();

private:
    TaskQueue &taskQue;

signals:
    void signalQuit1();
};

#endif // PRODUCER_H


