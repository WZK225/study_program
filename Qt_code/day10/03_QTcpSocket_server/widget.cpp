#include "widget.h"
#include <QMessageBox>
#include <QTcpServer>
#include <QTcpSocket>
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置窗口标题
    setWindowTitle("TCP服务器");
    // 初始化
    _tcpSever = new QTcpServer(this);
    // 通过槽函数进行连接
    connect(_tcpSever, &QTcpServer::newConnection, this, &Widget::handle);
    // 监听端口
    bool ret = _tcpSever->listen(QHostAddress::Any, 8888);
    if(!ret){
        QMessageBox::critical(this, "服务器启动失败", _tcpSever->errorString());
        return;
    }
}

void Widget::handle(){
    // 获取到新的连接对应的socket
    QTcpSocket *clientSocket = _tcpSever->nextPendingConnection();
    QString log = QString('[') + clientSocket->peerAddress().toString() + ":"
            + QString::number(clientSocket->peerPort()) + "] 客户端上线!";

    // 通过信号槽.处理收到的请求的情况
    connect(clientSocket, &QTcpSocket::readyRead, this, [=]{
        // 读取出请求数据
        QString request = clientSocket->readAll();
        // 根据请求处理相应
        const QString &response = process(request);
        //写回客户端
        clientSocket->write(response.toUtf8());

        QString log = QString("[") + clientSocket->peerAddress().toString() + ":"
                + QString::number(clientSocket->peerPort()) + "] req:" +
                request + ", resp: " + response;
        ui->listWidget->addItem(log);
        clientSocket->deleteLater();
    });
}

QString Widget::process(const QString &request){
    return request;
}


Widget::~Widget()
{
}

