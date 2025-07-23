#include "widget.h"
#include "ui_widget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QTime>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QUrl>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("MP4视频播放器");
    resize(800, 600);

    //初始化播放器组件
    m_player = new QMediaPlayer(this);
    m_videoWidget = new QVideoWidget(this);

    //设置视频输出
    m_player->setVideoOutput(m_videoWidget);

    //创建控制按钮
    m_openButton = new QPushButton("打开文件");
    m_playButton = new QPushButton("播放");
    m_pauseButton = new QPushButton("暂停");
    m_stopButton = new QPushButton("停止");

    //进度条和音量控制
    m_positionSlider = new QSlider(Qt::Horizontal);
    m_volumeSlider = new QSlider(Qt::Horizontal);
    m_volumeSlider->setRange(0, 100);
    m_volumeSlider->setValue(50);
    m_timeLabel = new QLabel("00:00/00:00");

    //主布局
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_videoWidget);

    //控制按钮布局
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(m_openButton, 0, 0, 1, 3);
    gridLayout->addWidget(m_playButton, 0, 3, 1, 3);
    gridLayout->addWidget(m_pauseButton, 0, 6, 1, 3);
    gridLayout->addWidget(m_stopButton, 0, 9, 1, 3);
    gridLayout->addWidget(new QLabel("音量:"), 0 ,12);
    gridLayout->addWidget(m_volumeSlider, 0, 13, 1, 6);
    gridLayout->addWidget(new QLabel("进度:"), 1 ,0);
    gridLayout->addWidget(m_positionSlider, 1, 11, 1, 18);
    gridLayout->addWidget(m_timeLabel, 2, 0, 1, 19);
    mainLayout->addLayout(gridLayout);

    m_timeLabel->setFixedHeight(50);
    m_timeLabel->setAlignment(Qt::AlignCenter);     //保持文字居中

    setLayout(mainLayout);

    //信号与槽链接
    // 打开文件按钮
    connect(m_openButton, &QPushButton::clicked, this, &Widget::openFile);
    // 播放视频按钮
    connect(m_playButton, &QPushButton::clicked, m_player, &QMediaPlayer::play);
    // 暂停视频按钮
    connect(m_pauseButton, &QPushButton::clicked, m_player, &QMediaPlayer::pause);
    // 停止播放按钮
    connect(m_stopButton, &QPushButton::clicked, m_player, &QMediaPlayer::stop);
    // 设置音量
    connect(m_volumeSlider, &QSlider::valueChanged, m_player, &QMediaPlayer::setVolume);
    // 滑动进度条
    connect(m_positionSlider, &QSlider::sliderMoved, this, &Widget::setPosition);
    // 更新进度条
    connect(m_player, &QMediaPlayer::positionChanged, this, &Widget::updatePosition);
    // 更新时间
    connect(m_player, &QMediaPlayer::durationChanged, this, &Widget::updateDuration);

}

// 打开视频文件
void Widget::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "选择视频文件",
                                                     QDir::homePath(),
                                                    "视频文件 (*.mp4 *.avi *.mkv *.mov)");
    if(!fileName.isEmpty())
    {
        m_player->setMedia(QUrl::fromLocalFile(fileName));
        m_player->play();
    }
}

// 更新播放进度显示
void Widget::updatePosition(qint64 position)
{
    m_positionSlider->setValue(position);

    // 更新时间标签
    QTime currentTime(0, 0, 0);
    currentTime = currentTime.addMSecs(position);
    QTime totalTime(0, 0, 0);
    totalTime = totalTime.addMSecs(m_player->duration());
    m_timeLabel->setText(currentTime.toString("hh:mm:ss")
                         + "/" + totalTime.toString("hh:mm:ss"));
}

// 更新总时长
void Widget::updateDuration(qint64 duration){
    m_positionSlider->setRange(0, duration);
}

// 手动设置播放位置
void Widget::setPosition(int position){
    m_player->setPosition(position);
}

Widget::~Widget()
{
    delete ui;
}

