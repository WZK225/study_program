#include "widget.h"
#include "ui_widget.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("HTTP Client");
    resize(600, 480);

    m_manager = new QNetworkAccessManager(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QUrl url(ui->lineEdit->text());

    QNetworkRequest request(url);

    QNetworkReply *rep = m_manager->get(request);

    connect(rep, &QNetworkReply::finished, [=]{

        if(rep->error() == QNetworkReply::NoError){
            QString html(rep->readAll());
            ui->plainTextEdit->setPlainText(html);
        }else{
            ui->plainTextEdit->setPlainText(rep->errorString());
        }
        rep->deleteLater();
    });
}
