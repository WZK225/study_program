#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_8_clicked()
{
    ch = '+';
}

void MainWindow::on_pushButton_12_clicked()
{
    ch = '-';
}

void MainWindow::on_pushButton_15_clicked()
{
    ch = '*';
}

void MainWindow::on_pushButton_16_clicked()
{
    ch = '/';
}

void MainWindow::on_pushButton_14_clicked()
{
   // 存放最总的结果
   int result = 0;
   if(ch == '+'){
       result = leftNum + rightNum;
       qDebug() << result;
   }else if(ch == '-'){
       result = leftNum - rightNum;
       qDebug() << result;
   }else if(ch == '*'){
       result = leftNum * rightNum;
       qDebug() << result;
   }else if(ch == '/'){
//       if(rightNum == 0){
//           qDebug() << "rightNum不合法";
//       }
       result = leftNum / rightNum;
       qDebug() << result;
   }
}
