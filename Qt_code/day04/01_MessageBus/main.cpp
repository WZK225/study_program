#include "widget.h"
#include "messagebus.h"

#include <QApplication>
#include <QMetaType>

struct PositionUpdate{
    int objectId;
    double x;
    double y;
};
Q_DECLARE_METATYPE(PositionUpdate)

struct SystemEvent{
    enum Type{ Startup, Shutdown, Error};
    Type eventType;
    QString message;
};
Q_DECLARE_METATYPE(SystemEvent);


class GameObject : public QObject
{
public:
    void updatePosition()
    {
        PositionUpdate update;
        update.objectId = this->id;
        update.x = this->x;
        update.y = this->y;

        // 发布位置更新
        MessageBus::instance().publish("ObjectPosition", update);
    }

private:
    int id;
    double x, y;
};

class SystemMonitor : public QObject
{
public:
    void criticalError(const QString & msg)
    {
        SystemEvent event;
        event.eventType = SystemEvent::Error;
        event.message = msg;

        // 发布系统事件
        MessageBus::instance().publish("SystemEvents", event);
    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();

    // 注册消息通道
    MessageBus::instance().registerChannel<PositionUpdate>("ObjextPosition");
    MessageBus::instance().registerChannel<SystemEvent>("SystemEvent");


    return a.exec();
}
