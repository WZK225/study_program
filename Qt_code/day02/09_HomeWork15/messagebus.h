#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H

//#include "send_client.h"
//#include "receive_client.h"
#include <QObject>

class MessageBus : public QObject
{
    Q_OBJECT
public:
    explicit MessageBus(QObject *parent = nullptr);

public:


signals:
    void sendMessage(const QString& ClientId, const QString& msg);


public slots:
    void receiveMessage(const QString& clientId, const QString& msg);

};


#endif // MESSAGEBUS_H
