#include "widget.h"
#include "Client.h"
#include "receive_client.h"
#include "messagebus.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    MessageBus bus;

    Client c1("C1");
    Client c2("C2");

    QObject::connect(&c1, &Client::sendMsg, &bus, &MessageBus::receiveMessage);
    QObject::connect(&bus, &MessageBus::sendMessage, &c1, &Client::receive);

    QObject::connect(&c2, &Client::sendMsg, &bus, &MessageBus::receiveMessage);
    QObject::connect(&bus, &MessageBus::sendMessage, &c2, &Client::receive);

    c1.send("hello");

    return a.exec();
}
