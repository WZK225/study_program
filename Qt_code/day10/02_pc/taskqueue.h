#ifndef TASKQUEUE_H
#define TASKQUEUE_H

#include <QMutex>
#include <QQueue>
#include <QWaitCondition>

class TaskQueue
{
public:
    TaskQueue(size_t capacity);
    ~TaskQueue();

    void push(const int &value);
    int pop();

    bool empty() const;
    bool full() const;

private:
    size_t _capacity;
    QQueue<int> _que;
//    QMutex *_mutex;
    mutable QMutex _mutex;
    QWaitCondition _notEmpty;
    QWaitCondition _notFull;
};

#endif // TASKQUEUE_H

