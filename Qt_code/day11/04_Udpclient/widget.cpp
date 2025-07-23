#include "widget.h"
#include "ui_widget.h"

#include <QNetworkDatagram>

const QString &SERVER_IP = "127.0.0.1";
const quint16 SERVER_PORT = 8888;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("UDP Client");
    resize(600, 480);

    // 创建一个QUpdSocket对象
    m_client = new QUdpSocket(this);

    connect(m_client, &QUdpSocket::readyRead, this, &Widget::handle);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle(){
    // 读取响应数据
    const QNetworkDatagram &responseDatagram = m_client->receiveDatagram();
    QString response = responseDatagram.data();
    // 将响应的数据显示到界面上
    ui->listWidget->addItem(QString("服务器说: ") + response);
}

void Widget::on_pushButton_clicked()
{
    // 获取lineEdit中的数据
    const QString &str = ui->lineEdit->text();
    // 构造数据
    QNetworkDatagram requestDate(str.toUtf8(),
                                 QHostAddress(SERVER_IP),
                                 SERVER_PORT);
    // 发送数据
    m_client->writeDatagram(requestDate);
    // 消息添加到列表框中
    ui->listWidget->addItem("客户端" + str);
    // 清空输入框
    ui->lineEdit->setText("");
}
