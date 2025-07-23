#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>
#include <QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    ,_networkManager(new QNetworkAccessManager(this))
    ,_currentReply(nullptr)
    ,_outputFile(nullptr)
    ,_isDownloading(false)
{
    ui->setupUi(this);
    setWindowTitle("下载器");
    resize(600, 480);

    connect(ui->downloadButton, &QPushButton::clicked,
            this, &Widget::on_pushButton_clicked);

    // 设置进度条初始状态
    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);
}

Widget::~Widget()
{
    delete ui;
    if(_currentReply){
        _currentReply->deleteLater();
    }

    if(_outputFile){
        _outputFile->deleteLater();
    }
}


void Widget::on_pushButton_clicked()
{
    if(_isDownloading){
        QMessageBox::warning(this, "警告", "当前已下载!");
        return;
    }

    QString downloadUrl = ui->lineEdit->text().trimmed();
    if(downloadUrl.isEmpty()){
        QMessageBox::warning(this, "错误", "请输入下载连接!");
        return;
    }

    // 设置保存位置
    QString savePath = QDir::homePath() + "/Downloads/";
    QString fileName = downloadUrl.split("/").last();
    if(fileName.isEmpty()){
        fileName = "music.mp3";
    }

    QString fileFullPath = savePath + fileName;

    // 检查文件是否存在
    if(QFile::exists(fileFullPath)){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "文件已存在", "该文件是否覆盖?",
                                      QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::No){
            return;
        }
    }

    //打开文件用于写入
    _outputFile = new QFile(fileFullPath);
    if(!_outputFile->open(QIODevice::WriteOnly)){
        QMessageBox::critical(this, "错误", "无法创建文件!");
        delete _outputFile;
        _outputFile = nullptr;
        return;
    }

    // 开始下载
    QNetworkRequest request(downloadUrl);
    _currentReply = _networkManager->get(request);

    // 连接信号
    connect(_currentReply, &QNetworkReply::downloadProgress,
            this, &Widget::on_pushButton_clicked);
    connect(_currentReply, &QNetworkReply::finished,
            this, &Widget::onDownloadFinished);
    connect(_currentReply, &QNetworkReply::readyRead, [this]{
        _outputFile->write(_currentReply->readAll());
    });

    _isDownloading = true;
    ui->downloadButton->setText("正在下载...");
}

void Widget::onDownloadProgerss(qint64 bytesReceived, qint64 bytesTotal){
    if(bytesTotal > 0){
        int progress = static_cast<int>((bytesReceived * 100) / bytesTotal);
        ui->progressBar->setValue(progress);
        ui->statusLabel->setText(QString("已下载: %1 / %2 KB")
                                 .arg(bytesReceived / 1024).arg(bytesTotal / 1024));
    }
}

void Widget::onDownloadFinished(){
    if(_outputFile){
        _outputFile->flush();
        _outputFile->close();
        delete _outputFile;
        _outputFile = nullptr;
    }

    if(_currentReply->error() == QNetworkReply::NoError){
        QMessageBox::information(this, "完成", "歌曲下载成功!");
    }else{
        QMessageBox::critical(this, "错误", "下载失败:" + _currentReply->errorString());
    }

    _currentReply->deleteLater();
    _currentReply = nullptr;
    _isDownloading = false;
    ui->downloadButton->setText("下载");
}
