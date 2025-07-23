#include "taskqueue.h"

TaskQueue::TaskQueue(size_t capacity)
    :_capacity(capacity)
//    ,_que()
//    ,_mutex()
//    ,_notEmpty()
//    ,_notFull()

{

}

TaskQueue::~TaskQueue()
{
    _notFull.wakeAll();
    _notEmpty.wakeAll();
}

// 生产数据
void TaskQueue::push(const int &value){
    //1.上锁
    QMutexLocker ul(&_mutex);
    //_mutex->lock();
    while(full()){
        _notFull.wait(&_mutex);
    }
    _que.push_back(value);
    _notEmpty.wakeOne();
}

// 消费数据
int TaskQueue::pop(){
    QMutexLocker ul(&_mutex);
    //_mutex->lock();
    while(empty()){
        _notEmpty.wait(&_mutex);
    }
    int value = _que.front();
    _que.pop_front();
    _notFull.wakeOne();
    return value;
}

// 判空
bool TaskQueue::empty() const{
    return 0 == _que.size();
}

// 判满
bool TaskQueue::full() const{
    return _capacity == _que.size();
}


