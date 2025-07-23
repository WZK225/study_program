#include "messagebus.h"

MessageBus::MessageBus(QObject *parent)
    : QObject(parent)
{

}

void MessageBus::registerClient(QObject *client, const QString &clientId){
    // 将客户端的sendMessage信号连接到总线的onMEssageReceived槽
    QObject::connect(client, &Client::sendMessage, this, &MessageBus::onMessageReceived);

    // 将总线的messageReceive信号连接到客户端的receiveMessage槽
    QObject::connect(this, &MessageBus::messageReceived, client, &Client::receiveMessage);

    qDebug() << "Client1 registered" << clientId;
}

void MessageBus::onMessageReceived(const QString &senderId, const QString &message){
    qDebug() << "MessageBus forwording message from"
             << senderId << ":" << message;
    emit messageReceived(senderId, message);
}
