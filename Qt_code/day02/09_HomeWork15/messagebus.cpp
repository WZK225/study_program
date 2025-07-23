#include "messagebus.h"

MessageBus::MessageBus(QObject *parent)
    : QObject(parent)
{

}

void MessageBus::receiveMessage(const QString& clientId, const QString& msg){
    emit sendMessage(clientId, msg);
}
