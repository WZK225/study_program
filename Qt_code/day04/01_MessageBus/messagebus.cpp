#include "messagebus.h"
#include <QDebug>
#include <QMetaObject>
#include <QMetaMethod>

MessageBus::MessageBus(QObject *parent) : QObject(parent)
{
    // 连接外部分发信号
    connect(this, &MessageBus::_signalDispatch, this,
            [this](const QString & channel,
                   const QVariant & message,
                   const QString & messageTypeName){
        QMutexLocker locker(&m_mutex);

        // 1.查找通道注册信息
        if(!m_registeredChannels.contains(channel)){
            qWarning() << "MessageBus: Attempted to publsh on unregistered channle:"
                      << channel;
            return;
        }

        // 2.验证消息类型匹配
        if(m_registeredChannels[channel] != messageTypeName){
            qWarning() << "MessageBus: Message type mismatch on channel"
                       << channel
                       << "Expected: " << m_registeredChannels[channel]
                       << "Got" << messageTypeName;
            return;
        }

        // 3.分发给通用订阅者
        auto subscribers = m_genericSubscriptions.values(channel);
        for(const auto & pair : subscribers){
            QObject * receiver = pair.first;
            const char * methodName = pair.second;

            if(!receiver){
                // 清理无效接收者
                m_genericSubscriptions.remove(channel, pair);
                continue;
            }

            // 使用元系统动态调用
            const QMetaObject * methObject = receiver->metaObject();
            int methodIndex = methObject->indexOfMethod(methodName);
            if(methodIndex == -1){
                qWarning() << "MessageBus: Slot not found in receiver:"
                           <<methodName;
                continue;
            }

            QMetaMethod method = metaObject()->method(methodIndex);
            method.invoke(receiver, Qt::AutoConnection,
                          QGenericArgument(messageTypeName.toUtf8().constData(), message.constData()));
        }

        // 4.分发给 Lambda订阅者
        auto lambdaSubscribers = m_lambdaSubscriptions.values(channel);
        for(LambdaWrapper * wrapper : lambdaSubscribers){
            if(!wrapper) continue;

            // Lambda 版本处理 Qvariant 包裹的消息
            QMetaObject::invokeMethod(wrapper, "onSignal", Qt::AutoConnection,
                                      Q_ARG(QVariant, message));
        }

    });
}

MessageBus & MessageBus::instance()
{
    static MessageBus bus;
    return bus;
}

template<typename MessageType>
void MessageBus::registerChannel(const QString & channel)
{
    QMutexLocker locker(&m_mutex);

    if(m_registeredChannels.contains(channel)){
        qWarning() << "MessageBus: Channel already registered:" << channel;
        return;
    }

    const QString typeName = QMetaType::typeName(qMetaTypeId<MessageType>());
    if(typeName.isEmpty()){
        qCritical() << "MessageBus: Failed to register unregisttered type for channel:" << channel;
        return;
    }

    qDebug() << "MessageBus: Registering channel:" << channel << "with type:" << typeName;
    m_registeredChannels[channel] = typeName;
}

template<typename MessageType>
void MessageBus::subscribe(const QString & channel, QObject* receiver,
                           void (QObject::*method)(const MessageType&),
                           Qt::ConnectionType connectionType)
{
    QMutexLocker locker(&m_mutex);

    // 确保通道已注册且消息类型匹配
    if(!m_registeredChannels.contains((channel))){
            qWarning() << "MessageBus: Subcsription attempt to unregistered channel:" << channel;
            return;
    }

    const QString expectedType = m_registeredChannels[channel];
    const QString actualType = QMetaType::typeName(qMetaTypeId<MessageType>());

    if(expectedType != actualType){
        qWarning() << "MessageBus: Subscriptioon type mismatch on channel"
                   << channel << "Expected:" << expectedType
                   << "Got:" << actualType;
        return;
    }

    // 获取槽函数的标准化签名
    auto methodNormalized = QMetaMethod::fromSignal(method);
    const QByteArray normalizedSignature = methodNormalized.methodSignature();

    // 存储订阅关系
    m_genericSubscriptions.insert(channel, qMakePair(receiver, normalizedSignature.constData()));
}

template<typename MessageType>
void MessageBus::subscribe(const QString & channel,
                           std::function<void(const MessageType &)> callback,
                           QObject *context)
{
       QMutexLocker locker(&m_mutex);

       // 确保通道已注册且消息类型匹配
       if(!m_registeredChannels.contains(channel)){
           qWarning() << "MessageBus: Lambda subscription to unregistered channel:" << channel;
           return;
       }

       const QString expectedType = m_registeredChannels[channel];
       const QString actualType = QMetaType::typeName(qMetaTypeId<MessageType>());

       if(expectedType != actualType){
           qWarning() << "MessageBus: Lambda subscription type mismatch on channel" << channel
                      << "Expected:" << expectedType << "Got:" << actualType;
            return;
       }

       // 创建包装器处理QVariant解包
       auto wrapper = new LambdaWrapper([callback](const QVariant & variant){
           callback(variant.value<MessageType>());
       }, context);

       if(context){
           // 上下文管理声明周期
           wrapper->setParent(context);
       }

       m_lambdaSubscriptions.insert(channel, wrapper);
}

void MessageBus::unsubscribe(QObject *receiver){
    QMutexLocker locker(&m_mutex);

    // 移除所有通用订阅
    auto it = m_genericSubscriptions.begin();
    while(it != m_genericSubscriptions.end()){
        if(it.value().first == receiver){
            it = m_genericSubscriptions.erase(it);
        }else{
            ++it;
        }
    }

    // 移除所有 Lambda 订阅(如果接收者时上下文)
    auto lambdaIt = m_lambdaSubscriptions.begin();
    while(lambdaIt != m_lambdaSubscriptions.end()){
        // 检查接收者是否是上下文
        if(lambdaIt.value()->parent() == receiver){
            delete lambdaIt.value();    // 删除包装器
            lambdaIt = m_lambdaSubscriptions.erase(lambdaIt);
        }else{
            ++lambdaIt;
        }
    }
}


void MessageBus::unsubscribe(const QString &channel, QObject *receiver){
    QMutexLocker locker(&m_mutex);

    // 移除指定通道的通用订阅
    auto pairs = m_genericSubscriptions.values(channel);
    for(const auto & pair : pairs){
        if(pair.first == receiver){
            m_genericSubscriptions.remove(channel, pair);
        }
    }

    // 移除指定通道的 Lambda 订阅
    auto wrappers = m_lambdaSubscriptions.values(channel);
    for(LambdaWrapper* wrapper : wrappers){
        if(wrapper->parent() == receiver){
            m_lambdaSubscriptions.remove(channel, wrapper);
            delete wrapper;
        }
    }
}

template<typename MessageType>
void MessageBus::publish(const QString & channel, const MessageType& message)
{
    // 验证通道注册
    if(!m_registeredChannels.contains(channel)){
        qWarning() << "MessageBus: Attempt to publish on unregistered channel:" << channel;
        return;
    }

    // 验证消息类型
    const QString expectedType = m_registeredChannels[channel];
    const QString actualType = QMetaType::typeName((qMetaTypeId<MessageType>));

    if(expectedType != actualType){
        qWarning() << "MessageBus: Published type mismatch on channel" << channel
                           << "Expected:" << expectedType << "Got:" << actualType;
        return;
    }

    // 异步分发消息(保证线程安全)
    QVariant var = QVariant::fromValue(message);
    emit _signalDispatch(channel, var, actualType);
}

template<typename MessageType>
bool MessageBus::isChannelRegistered(const QString & channel)
{
    QMutexLocker locker(&m_mutex);
    return m_registeredChannels.contains(channel) &&
           m_registeredChannels[channel] ==
           QMetaType::typeName(qMetaTypeId<MessageType>());
}




