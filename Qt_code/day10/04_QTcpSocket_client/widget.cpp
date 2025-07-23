#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置窗口标题
    setWindowTitle("TCP客户端");
    // 实例化socket对象
    tcpClient = new QTcpSocket(this);
    // 与服务器建立连接
    tcpClient->connectToHost("127.0.0.1", 888);

    // 处理服务器返回的相应
    connect(tcpClient, &QTcpSocket::readyRead, this, [=]{
        // 读取当前缓冲区中的所有数据
        QString response = tcpClient->readAll();
        qDebug() << response;
        ui->listWidget->addItem(QString("服务器说: ") + response);

        // 等待并确认连接是否出错
        if(!tcpClient->waitForConnected()){
            QMessageBox::critical(this, "连接服务器出错!", tcpClient->errorString());
            return;
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked(){
    // 获取输入框的内容
    const QString &text = ui->lineEdit->text();
    // 清空输入框的内容
    ui->lineEdit->setText("");
    // 把消息显示到界面上
    ui->listWidget->addItem(QString("客户端说: ") + text);
    // 发送消息给服务器
    tcpClient->write(text.toUtf8());
}

