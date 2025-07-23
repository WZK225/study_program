#include "appcomponent.h"

AppComponent::AppComponent(QString name,QObject *parent)
    : QObject(parent)
    ,m_name(name)
{
    setObjectName(name);
}

void AppComponent::send(QString msg)
{
    // 防止重入
    if(m_blockSelf){
        return;
    }
    m_blockSelf = true;
    emit broadcast(msg);
    m_blockSelf = false;
}

void AppComponent::receive(QObject* source, QString msg)
{
    // 过滤自己发出的消息
    if(source == this){
        return;
    }

    // 过滤无效消息
    if(msg.trimmed().isEmpty()){
        return;
    }

    qDebug().nospace()
            << m_name << " << ["
            << source->objectName() << "] "
            << msg;

    // 触发业务处理
    //handleMessage(source, msg);
}
