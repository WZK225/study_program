#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QMap>

#include "client1.h"


class MessageBus : public QObject
{
    Q_OBJECT
public:
    explicit MessageBus(QObject *parent = nullptr);

    // 注册客户端到消息总线
    void registerClient(QObject *client, const QString &clinetId);

signals:
    // 总线的消息接收信号
    void messageReceived(const QString &senderId, const QString &message);

public slots:
    // 处理接收到的消息并转发
    void onMessageReceived(const QString &senderId, const QString &message);

private:

};

#endif // MESSAGEBUS_H
