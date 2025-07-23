#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
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
    void openFile();
    void setVolume(int value);
    void updatePosition();
    void updateDuration(qint64 duration);
    void seekPosition();

private:
    Ui::Widget *ui;
    QMediaPlayer *m_player;
    QSlider *m_volumeSlider;
    QSlider *m_positionSlider;
    QLabel *m_timeLabel;
};
#endif // WIDGET_H
