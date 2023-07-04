#ifndef CPLAYVIDEO_H
#define CPLAYVIDEO_H

#include <QWidget>
#include <QMessageBox>
#include <QMainWindow>
#include <QScreen>
#include <QVariant>
#include <QSettings>
#include <QFileDialog>
#include <QCommandLineParser>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
namespace Ui {
class CPlayVideo;
}

class CPlayVideo : public QWidget
{
    Q_OBJECT

public:
    explicit CPlayVideo(QWidget *parent = nullptr);
    ~CPlayVideo();

    void setVideoPath(const QString&url);
    void openMedia(const QString &mediaUrl);
private:
    Ui::CPlayVideo *ui;
    QMediaPlayer* m_pPlayer;
    QVideoWidget* m_pVideoWidget;
    QMediaPlaylist*m_pMediaPlayList;

};

#endif // CPLAYVIDEO_H
