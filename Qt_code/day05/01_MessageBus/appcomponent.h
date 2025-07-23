#ifndef APPCOMPONENT_H
#define APPCOMPONENT_H

#include <QObject>
#include <QDebug>
#include <QString>

class AppComponent : public QObject
{
    Q_OBJECT
public:
    explicit AppComponent(QString name, QObject *parent = nullptr);

    void send(QString msg);

signals:
    void broadcast(QString msg);    // 对外广播信号

public slots:
    void receive(QObject* source, QString msg);

//protected:
//    // 拓展点:子类实现业务逻辑
//    virtual void handleMessage(QObject* source, const QString& msg);

private:
    QString m_name;
    bool m_blockSelf = false;
};




#endif // APPCOMPONENT_H
