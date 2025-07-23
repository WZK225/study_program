#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void onDownloadProgerss(qint64 bytesReceived, qint64 bytesTotal);
    void onDownloadFinished();

private:
    Ui::Widget *ui;

    QNetworkAccessManager *_networkManager;
    QNetworkReply *_currentReply;
    QFile *_outputFile;
    bool _isDownloading;
};
#endif // WIDGET_H
