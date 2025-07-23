#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("测试窗口");
    this->resize(800, 600);

    QMenuBar *mbar = new QMenuBar(this);
    mbar->resize(300, 100);

    QMenu *fileMenu = new QMenu("文件", this);
    QMenu *editMenu = new QMenu("编辑", this);
    QMenu *toolMenu = new QMenu("工具", this);
    mbar->addMenu(fileMenu);
    mbar->addMenu(editMenu);
    mbar->addMenu(toolMenu);

    fileMenu->addMenu("新建");
    fileMenu->addMenu("打开");
    fileMenu->addMenu("保存");


    QPushButton *bt = new QPushButton("关闭", this);
    bt->move(200, 200);
    bt->resize(100,100);

    connect(bt, &QPushButton::clicked, [this](){
       close();
    });

}

MainWindow::~MainWindow()
{

}
