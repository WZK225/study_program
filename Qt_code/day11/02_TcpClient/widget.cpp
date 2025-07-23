#include "widget.h"
#include "ui_widget.h"
#include <QTcpSocket>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("TCP Client");
    resize(600, 480);

    // 创建QTcpSocket对象
    m_client = new QTcpSocket(this);

    // 建立连接
    m_client->connectToHost("127.0.0.1", 888);

    connect(m_client, &QTcpSocket::readyRead, [=]{

        // 读取数据
        QByteArray ba = m_client->readAll();

        // 将数据显示到listWidget上
        QString str = QString::fromUtf8(ba);
        ui->listWidget->addItem(QString("客户端接收到服务端的数据:") + str);

    });
    close();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    // 获取lineEit中的数据
    QString data = ui->lineEdit->text();
    // 将listWidget中的数据发送给server
    m_client->write(QByteArray(data.toUtf8()));

    ui->listWidget->addItem("客户端发送给服务端的数据:" + data);
    // 清空lineEdit中的数据
    ui->lineEdit->clear();

}
