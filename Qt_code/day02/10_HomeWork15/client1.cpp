#include "client1.h"

#include <QDebug>

Client1::Client(const QString &id, QObject *parent)
    : QObject(parent)
    , m_id(id)
{

}

void Client::send(QString message){
    emit sendMessage(m_id, message);
    qDebug() << m_id << "sent message:" << message;
}

void Client::receiveMessage(const QString &senderId, const QString & message){
   if(senderId != m_id){
       qDebug() << m_id << "received from" << senderId << ":" << message;
   }
}
