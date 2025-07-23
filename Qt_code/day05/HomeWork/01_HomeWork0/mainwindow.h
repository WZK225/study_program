#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int add(int left, int right);
    int dev(int left, int right);
    int mul(int left, int right);
    int sub(int left, int right);

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::MainWindow *ui;
    int leftNum;    // 左操作数
    int rightNum;   // 右操作数
    char ch;        // 操作符
};
#endif // MAINWINDOW_H
