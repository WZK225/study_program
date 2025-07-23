#include "widget.h"
#include "ui_widget.h"

#include <QUdpSocket>
#include <QMessageBox>
#include <QNetworkDatagram>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("UDP Server");
    resize(600, 480);

    // 1.创建QUdpSocket对象
    m_server = new QUdpSocket(this);

    // 2.bind绑定端口
    bool ret = m_server->bind(QHostAddress::Any, 8888);
    if(!ret){
        QMessageBox::critical(this, "服务器启动失败", m_server->errorString());
        return;
    }

    // 3.当数据准备好时,执行handle函数进行处理
    connect(m_server, &QUdpSocket::readyRead, this, &Widget::handle);
}


Widget::~Widget()
{
    delete ui;
}


void Widget::handle(){
    // 读取请求,读取一个UDP数据报,获取数据
    const QNetworkDatagram &requestDatagram = m_server->receiveDatagram();
    QString request = requestDatagram.data();

    // 根据需求相应
    const QString &response = process(request);
    // 将响应协会客户端
    // 封装成数据报,并发送给客户端
    QNetworkDatagram responseDatagram(response.toUtf8(),
                                      requestDatagram.senderAddress(),
                                      requestDatagram.senderPort());
    m_server->writeDatagram(responseDatagram);

    // 显示打印日志
    QString log = "[" + requestDatagram.senderAddress().toString()
            + ":" + QString::number(requestDatagram.senderPort())
            + "] req: " + request + ", resp: " + response;
    ui->listWidget->addItem(log);
}

QString Widget::process(const QString &req){
    return req;
}

