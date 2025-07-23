#include "CommunicationHub.h"

CommunicationHub::CommunicationHub(QObject *parent)
    : QObject(parent)
{

}

bool CommunicationHub::registerComponent(QObject *comp){
    if(comp->objectName().isEmpty()){
        qWarning() << "Component must have objectName";
        return false;
    }

    // 防止重复注册
    if(components.contains(comp)){
        return true;
    }

    components.insert(comp);

    // 自动连接接收器
    if (auto* appComp = qobject_cast<AppComponent*>(comp)) {
        connect(this, &CommunicationHub::routedMessage,
                appComp, &AppComponent::receive,
                Qt::UniqueConnection);
    } else {
        qWarning() << "Invalid component type during connection";
    }

    return true;
}

void CommunicationHub::routeMessage(QString msg){
    emit routedMessage(sender(), msg);

    // 可选:消息日志
    logMessage(sender(), msg);
}

void CommunicationHub::logMessage(QObject* source, const QString & msg){
    qInfo() << "[Hub] Routing from"
            << source->objectName()
            << ":" << msg;
}
