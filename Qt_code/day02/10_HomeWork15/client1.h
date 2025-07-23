#ifndef CLIENT1_H
#define CLIENT1_H

#include <QObject>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(const QString & id, QObject *parent = nullptr);

    void send(QString emssage);

signals:
    void sendMessage(const QString &senderId, const QString &message);

public slots:
    void receiveMessage(const QString &senderId, const QString &message);

private:
    QString m_id;
};

#endif // CLIENT1_H
