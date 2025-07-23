#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>

class myobject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName
               RESET resetName NOTIFY namechange)

public:
    explicit myobject(QObject *parent = nullptr);

public:
    // 读属性值
    Q_INVOKABLE QString getName() const;
    // 对属性进行写操作
    Q_INVOKABLE void setName(const QString &nme);
    // 重置属性的值
    Q_INVOKABLE void resetName();

signals:
    // 当属形式name发生变化时,可以触发信号
    void namechange(const QString &nme);
private:
    QString m_name;
};

#endif // MYOBJECT_H
