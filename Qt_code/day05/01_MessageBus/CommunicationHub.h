#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H

#include <QObject>
#include <QSet>
#include <QString>
#include <QDebug>

#include "appcomponent.h"

class CommunicationHub : public QObject
{
    Q_OBJECT
public:
    explicit CommunicationHub(QObject *parent = nullptr);

    bool registerComponent(QObject* comp);

signals:
    void routedMessage(QObject* source, QString msg);

public slots:
    void routeMessage(QString msg);

private:
    QSet<QObject*> components;

    void logMessage(QObject* source, const QString & msg);
};

#endif // MESSAGEBUS_H
