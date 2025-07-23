#include "widget.h"
#include "messagebus.h"
#include "client1.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    // 创建消息总线
    MessageBus bus;

    // 创建两个客户端
    Client client1("Client1");
    Client client2("Client2");

    // 注册客户端到消息总线
    bus.registerClient(&client1, "Client1");
    bus.registerClient(&client2, "client2");

    // 模拟消息总线
    client1.send("Hello");
    client2.send("Greetings");
    client1.send("How are you");
    client2.send("Ok");

    return a.exec();
}
