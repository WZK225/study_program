#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QRunnable>
#include <QMutexLocker>
#include <QThread>
#include <QRandomGenerator>
#include <QDebug>

class CustomTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit CustomTask(int id, QObject *parent = nullptr)
        : QObject(parent), taskId(id)
    {
        setAutoDelete(true);  // 自动删除完成任务
    }

    // 核心执行函数
    void run() override
    {
        QMutexLocker locker(&mutex);  // 保证输出完整性

        qDebug() << "[Thread" << QThread::currentThreadId() << "] Task"
                 << taskId << "STARTED";

        // 生成随机延时 (1000-3000ms)
        int delay = QRandomGenerator::global()->bounded(1000, 3000);

        // 模拟实际工作负载
        simulateWorkload(delay);

        qDebug() << "[Thread" << QThread::currentThreadId() << "] Task"
                 << taskId << "FINISHED after" << delay << "ms";

        emit taskCompleted(taskId, delay);  // 发送完成信号
    }

signals:
    void taskCompleted(int id, int duration);  // 任务完成信号

private:
    void simulateWorkload(int ms)
    {
        QThread::msleep(ms);  // 模拟耗时操作
    }

    const int taskId;
    static QMutex mutex;  // 共享的互斥锁
};

QMutex CustomTask::mutex;  // 静态成员初始化
