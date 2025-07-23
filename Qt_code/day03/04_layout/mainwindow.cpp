#include "mainwindow.h"

#include <QPushButton>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600, 480);

    QPushButton *btn1 = new QPushButton("按钮1");
    QPushButton *btn2 = new QPushButton("按钮2");
    QPushButton *btn3 = new QPushButton("按钮3");
    QPushButton *btn4 = new QPushButton("按钮4");

    QHBoxLayout *hLayout = new QHBoxLayout;
    setLayout(hLayout);

    hLayout->addWidget(btn1);
    hLayout->addWidget(btn2);
    hLayout->addWidget(btn3);
    hLayout->addWidget(btn4);



}

MainWindow::~MainWindow()
{
}

