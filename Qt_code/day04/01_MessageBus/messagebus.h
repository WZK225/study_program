#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H

#include <QObject>
#include <QMap>
#include <QMultiMap>
#include <QVariant>
#include <QSet>
#include <QMutex>
#include <functional>

class MessageBus : public QObject
{
    Q_OBJECT
public:
//    explicit MessageBus(QObject *parent = nullptr);

    // 获取单例实例
    static MessageBus& instance();

    // 注册消息通道
    template<typename MessageType>
    void registerChannel(const QString &channel);

    // 订阅通道
    template<typename MessageType>
    void subscribe(const QString &channel, QObject *receiver,
                   void (QObject::*method)(const MessageType&),
                   Qt::ConnectionType ConnectionType = Qt::AutoConnection);

    // lambda方式订阅
    template<typename MessageType>
    void subscribe(const QString &channel,
                   std::function<void(const MessageType&)> callback,
                   QObject *context = nullptr);

    // 取消订阅
    void unsubscribe(QObject *receiver);
    void unsubscribe(const QString &channel, QObject *receiver);

    // 发布消息
    template<typename MessageType>
    void publish(const QString &channel, const MessageType &message);

    // 检查通道是否存在
    template<typename MessageType>
    bool isChannelRegistered(const QString &channel);

signals:
    // 内部信号(禁止外部直接连接)
    void _signalDispatch(const QString & channel,
                         const QVariant & message,
                         const QString & messageTypeName);

private:
    MessageBus(QObject* parent = nullptr);
    ~MessageBus() = default;
    MessageBus(const MessageBus&) = delete;
    MessageBus & operator=(const MessageBus&) = delete;

    struct LambdaWrapper : public QObject
    {
        LambdaWrapper(std::function<void(const QVariant&)> callback,
                      QObject * parent = nullptr)
            :QObject(parent), m_callback(callback) {}

    public slots:
        void onSignal(const QVariant & message)
        {
            m_callback(message);
        }

    private:
        std::function<void(const QVariant &)> m_callback;
    };

    // 通道注册表: 通道名 -> 消息类型
    QMap<QString, QString> m_registeredChannels;

    // 通用订阅: 通道名 -> (接收者, 槽函数)
    QMultiMap<QString, QPair<QObject*, const char*>> m_genericSubscriptions;

    // Lambda 订阅: 通道名 -> LambdaWrapper
    QMultiMap<QString, LambdaWrapper *> m_lambdaSubscriptions;

    QMutex m_mutex;
};

#endif // MESSAGEBUS_H
