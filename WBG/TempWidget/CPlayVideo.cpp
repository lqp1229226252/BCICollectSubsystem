#include "CPlayVideo.h"
#include "ui_CPlayVideo.h"

CPlayVideo::CPlayVideo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CPlayVideo)
  ,m_pVideoWidget(nullptr)
{
    ui->setupUi(this);
    m_pPlayer = new QMediaPlayer(this);
    m_pVideoWidget = new QVideoWidget(this);
    ui->verticalLayout->addWidget(m_pVideoWidget);
    m_pPlayer->setVideoOutput(m_pVideoWidget);
    m_pPlayer->setMedia(QUrl::fromLocalFile(":image/image/head_video.mp4"));


}

CPlayVideo::~CPlayVideo()
{
    delete ui;
}
void CPlayVideo::setVideoPath(const QString&url)
{

}
void CPlayVideo::openMedia(const QString &mediaUrl)
{
    m_pPlayer->setMedia(QUrl::fromLocalFile(mediaUrl));
    m_pPlayer->play();
}

