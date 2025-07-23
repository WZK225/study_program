#include "receive_client.h"

Receive_Client::Receive_Client(QObject *parent)
    : QObject(parent)
{

}

Receive_Client::Receive_Client(const QString & id)
    :ID(id)
{

}
void Receive_Client::send(MessageBus & bus, const QString &message){
    QString msg = message + "," + ID;
    bus.set_message(msg);
}

void Receive_Client::sendMessage(MessageBus & bus, const QString &message){
    QString msg = message + "," + ID;
    bus.set_message(msg);
}

void Receive_Client::receive(MessageBus & bus){
    QString msg = bus.get_message();
    qDebug() << "send发送的消息是: " << msg;
//    return bus.get_message();
}
