#include "widget.h"
#include "CommunicationHub.h"
#include "appcomponent.h"

#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    CommunicationHub hub;

    AppComponent compA("ComponentA"), compB("ComponentB"), compC("ComponentC");

    // 全部组件向中介注册
    hub.registerComponent(&compA);
    hub.registerComponent(&compB);
    hub.registerComponent(&compC);

    // 连接广播信号
    QObject::connect(&compA, &AppComponent::broadcast, &hub, &CommunicationHub::routeMessage);
    QObject::connect(&compB, &AppComponent::broadcast, &hub, &CommunicationHub::routeMessage);
    QObject::connect(&compC, &AppComponent::broadcast, &hub, &CommunicationHub::routeMessage);

//    QObject::connect(&hub, &CommunicationHub::routedMessage, &compA, &AppComponent::receive);
//    QObject::connect(&hub, &CommunicationHub::routedMessage, &compB, &AppComponent::receive);
//    QObject::connect(&hub, &CommunicationHub::routedMessage, &compC, &AppComponent::receive);

    // 测试用例
    compA.send("hello");

    return a.exec();
}
