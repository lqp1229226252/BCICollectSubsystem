#ifndef INTRODUCEWIDGET_H
#define INTRODUCEWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QPixmap>
#include <QMediaPlaylist>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class IntroduceWidget; }
QT_END_NAMESPACE

class IntroduceWidget : public QWidget
{
    Q_OBJECT

public:
    IntroduceWidget(QWidget *parent = nullptr);
    ~IntroduceWidget();

    void  init();
    void initPlayer();


private:
    Ui::IntroduceWidget *ui;

    QMediaPlayer *player;
    QVideoWidget *vw;
    QVBoxLayout *vBox;

    // 视频总长度
    qint64 videoDuration;

    QPixmap pixmap;

    // 播放列表
    QMediaPlaylist *playList;

    QTimer *timer;
    // 进度条总长度
    int maxvalue = 1000;

private slots:
    void onStateChanged(QMediaPlayer::State);
    void onplaystopBtnClicked();
    void onDurationChanged(qint64);
    void onSliderMoved();
    void onSliderReleased();
    void onPlayerPositionChanged(qint64);
    void onSoundBtnClicked(bool);
    void onMutedChanged(bool);
    void onTimerOut();
};
#endif // INTRODUCEWIDGET_H
