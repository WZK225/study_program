#include "widget.h"
#include <QCommandLinkButton>
#include <QDesktopServices>
#include <Qurl>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(600, 480);

    QCommandLinkButton * clb = new QCommandLinkButton(this);
    clb->resize(300, 100);
    clb->move(100, 100);
    clb->setDescription("点击按钮进行跳转");

    connect(clb, &QCommandLinkButton::clicked, []{
        QDesktopServices::openUrl(QUrl("www.baidu.com"));
    });
}

Widget::~Widget()
{
}

