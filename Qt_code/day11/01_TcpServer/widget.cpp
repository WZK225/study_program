#include "widget.h"
#include "ui_widget.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QMessageBox>
#include <QByteArray>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("TCP Server");
    resize(600, 480);

    // 1.创建一个QTcpServer对象
    m_server = new QTcpServer;

    // 2.进行监听端口
    bool ret = m_server->listen(QHostAddress::Any, 888);
    if(!ret){
        QMessageBox::critical(this, "严重错误", "连接失败");
        return;
    }

    // 有新连接时,触发数据处理
    connect(m_server, &QTcpServer::newConnection, this, &Widget::handle);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::handle(){
    // 使用nextPendingConnection()函数得到一个QTcpWidget对象
    QTcpSocket *socket = m_server->nextPendingConnection();

    // 读取数据,处理数据
    connect(socket, &QTcpSocket::readyRead, [=]{
        // 显示通知
        ui->listWidget->addItem(QString("客户端上线了"));

        // 读取数据
        QByteArray ba = socket->readAll();

        // 将数据显示到listWidget上
        QString str = QString::fromUtf8(ba);
        ui->listWidget->addItem(QString("服务器接收到客户端发送的数据为:") + str);

        // 将数据回显到Client上面
        socket->write(ba);
        ui->listWidget->addItem("服务器发送给客户端的数据: " + QString::fromUtf8(ba));
    });

    // 关闭窗口,回收内存
    connect(socket, &QTcpSocket::disconnected, [=]{
        m_server->close();
        socket->deleteLater();
        close();
    });
}
