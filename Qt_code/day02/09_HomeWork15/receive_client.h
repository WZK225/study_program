#ifndef RECEIVE_CLIENT_H
#define RECEIVE_CLIENT_H

#include <QObject>
#include <QDebug>
#include "messagebus.h"

class Receive_Client : public QObject
{
    Q_OBJECT
public:
    explicit Receive_Client(QObject *parent = nullptr);
    Receive_Client(const QString & id);

public:
    void send(MessageBus & bus, const QString &message);
//    QString receive(MessageBus & bus);
    void receive(MessageBus & bus);

private:
    QString ID;

signals:

};

#endif // RECEIVE_CLIENT_H
