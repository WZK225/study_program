#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QPushButton>
#include <QSlider>
#include <QLabel>

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
    //打开文件
    void openFile();
    //更新进度条的位置
    void updatePosition(qint64 position);
    //更新进度条范围
    void updateDuration(qint64 duration);
    //设置进度条的位置
    void setPosition(int position);

private:
    Ui::Widget *ui;
    QMediaPlayer *m_player;     //视频播放器
    QVideoWidget *m_videoWidget;    //视频输出组件
    QPushButton *m_openButton;      //打开文件按钮
    QPushButton *m_playButton;      //播放按钮
    QPushButton *m_pauseButton;     //暂停按钮
    QPushButton *m_stopButton;      //停止按钮
    QSlider *m_positionSlider;      //进度条
    QSlider *m_volumeSlider;        //声音条
    QLabel *m_timeLabel;        //进度时间标签
};
#endif // WIDGET_H
