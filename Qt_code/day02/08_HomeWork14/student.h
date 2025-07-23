#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(int age READ getAge WRIET setAge NOTIFY ageChanged)

public:
    Student(QObject *parent = nullptr);

public:
    Q_INVOKABLE QString getName() const;
    Q_INVOKABLE void setName(const QString &name);

    Q_INVOKABLE int getAge() const;
    Q_INVOKABLE void setAge(const int &age);

signals:
    void ageChanged(const int &);

private:
    QString _name;
    int _age;
};

#endif // STUDENT_H
