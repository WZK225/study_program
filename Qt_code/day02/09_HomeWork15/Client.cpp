#include "Client.h"

Client::Client(QString id, QObject *parent)
    : QObject(parent)
    , _clientId(id)
{

}

void Client::send(const QString message){
//    if(message){
        emit sendMsg(_clientId, message);
//    }
}


void Client::receive(const QString& clientId, const QString& msg)
{
    if(clientId != _clientId){
        qDebug() << _clientId << "接受到了" << clientId << "发送的消息:" << msg;
    }
}
