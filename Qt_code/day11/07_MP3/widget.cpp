#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QFileDialog>
#include <QUrl>
#include <QTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("MP3音频播放器");
    resize(600, 480);

    // 初始化播放器
    m_player = new QMediaPlayer(this);

    QPushButton *openButton = new QPushButton("打开文件");
    QPushButton *playButton = new QPushButton("播放");
    QPushButton *pauseButton = new QPushButton("暂停");
    QPushButton *stopButton = new QPushButton("停止");

    // 声音滑动条
    m_volumeSlider = new QSlider(Qt::Horizontal);
    // 进度滑动条
    m_positionSlider = new QSlider(Qt::Horizontal);
    // 时间标签
    m_timeLabel = new QLabel("00:00/00:00");

    // 设置音量滑动条范围和初始值
    m_volumeSlider->setRange(0, 100);
    m_volumeSlider->setValue(0);

    // 设置播放音量
    m_player->setVolume(30);

    // 启动播放进度条
    m_positionSlider->setEnabled(true);
    // 设置播放进度的范围
    m_positionSlider->setRange(0, 100);

    // 布局
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(openButton);
    layout->addWidget(playButton);
    layout->addWidget(pauseButton);
    layout->addWidget(stopButton);

    layout->addWidget(new QLabel("音量:"));
    layout->addWidget(m_volumeSlider);
    layout->addWidget(new QLabel("进度:"));
    layout->addWidget(m_positionSlider);
    layout->addWidget(m_timeLabel);
    setLayout(layout);

    // 连接信号与槽
    connect(openButton, &QPushButton::clicked, this, &Widget::openFile);
    connect(playButton, &QPushButton::clicked, m_player, &QMediaPlayer::play);
    connect(pauseButton, &QPushButton::clicked, m_player, &QMediaPlayer::pause);
    connect(stopButton, &QPushButton::clicked, m_player, &QMediaPlayer::stop);
    connect(m_volumeSlider, &QSlider::valueChanged, this, &Widget::setVolume);
    connect(m_player, &QMediaPlayer::positionChanged, this, &Widget::updatePosition);
    connect(m_player, &QMediaPlayer::durationChanged, this, &Widget::updateDuration);
    // 连接进度条拖动信号
    connect(m_positionSlider, &QSlider::sliderReleased, this, &Widget::seekPosition);

    // 定时器用于更新进度条
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::updatePosition);
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::openFile(){
    QString filePath = QFileDialog::getOpenFileName(this, "打开MP3文件",
                                                    "", "MP3文件(*.mp3)");
    if(!filePath.isEmpty()){
        m_player->setMedia(QUrl::fromLocalFile(filePath));
        // 打开即播放
        m_player->play();
    }
}

void Widget::setVolume(int value){
    m_player->setVolume(value);
}

void Widget::updatePosition(){
    // 如果用户正在拖动进度条,则跳过自动更新
    if(m_positionSlider->isSliderDown()){
        return;
    }
    if(m_player->duration() > 0){
        //将播放进度转化为百分比形式,这是乘以100的作用, 不然就是小数
        int position = (m_player->position() * 100 / m_player->duration());
        m_positionSlider->setValue(position);

        // 更新时间显示
        // 当前时间,使用position获取
        QTime currentTime(0, 0);
        currentTime = currentTime.addMSecs(m_player->position());
        // 总时间,使用duration获取
        QTime totalTime(0, 0);
        m_timeLabel->setText(currentTime.toString("mm::ss") + "/"
                             + totalTime.toString("mm::ss"));
    }
}

void Widget::seekPosition(){
    if(m_player->duration() > 0){
        // 计算目标位置(毫秒) = 进度条百分比 * 总时间 / 100
        qint64 targetPos = (m_positionSlider->value() * m_player->duration()/100);

        // 设置播放位置
        m_player->setPosition(targetPos);
    }
}

void Widget::updateDuration(qint64 duration){
    Q_UNUSED(duration);
    m_positionSlider->setRange(0, 100);
}

