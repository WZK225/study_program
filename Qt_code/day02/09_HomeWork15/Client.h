#ifndef SEND_CLIENT_H
#define SEND_CLIENT_H
#include "messagebus.h"
#include <QObject>
#include <QDebug>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QString id, QObject *parent = nullptr);

private:
    QString ID;

public:
    void send(const QString message);

signals:
    void sendMsg(const QString& clientId, const QString& msg);

public slots:
     void receive(const QString& clientId, const QString& msg);

private:
     QString _clientId;

};

#endif // SEND_CLIENT_H
