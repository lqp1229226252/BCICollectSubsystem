#include "introducewidget.h"
#include "ui_introducewidget.h"
#include "QDebug"

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QToolButton>
#include <QState>
#include <QIcon>
#include <QPixmap>
#include <QMediaPlaylist>
#include <QTimer>
//改动位置
IntroduceWidget::IntroduceWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IntroduceWidget)
{
    ui->setupUi(this);

    init();

    // 初始化播放器
    initPlayer();

    //添加
    m_pPicturePlayer = new MPicturePlayer(this);
    ui->verticalLayout_2->addWidget(m_pPicturePlayer);
    m_pPicturePlayer->setFirsrt();
    //
    setFuncList();
    setProductList();
    setAutoFillBackground(true);

    QPalette palette;
    QPixmap pix("qrc:/image/image/bg.png");
    palette.setBrush(QPalette::Window,pix);
    this->setPalette(palette);

}

IntroduceWidget::~IntroduceWidget()
{
    delete ui;
}

void IntroduceWidget::init()
{
    // 初始化控件
    this->player = new QMediaPlayer;
    this->vw = new QVideoWidget;
    this->vBox = new QVBoxLayout;

    ui->playstopBtn->setIcon(QIcon(":/image/introduce_pic/24gf-play.png"));
    ui->soundBtn->setIcon(QIcon(":/image/introduce_pic/24gf-volumeDisable.png"));

    ui->videoSlider->setEnabled(false);

    // 设置大小
    vw->setFixedSize(650, 280);

    // 将vw放到布局当中
    vBox->addWidget(vw);
    //设置videwidget的布局
    ui->playArea->setLayout(vBox);


/*    ui->introduceLayout->setStretch(0,2);
    ui->introduceLayout->setStretch(1,1);

    ui->productLayout->setStretch(0,1);
    ui->productLayout->setStretch(1,5);
    ui->functionLayout->setStretch(0,1);
    ui->functionLayout->setStretch(1,5);
    ui->contactLayout->setStretch(0,1);
    ui->contactLayout->setStretch(1,5);

    ui->widgetLayout->setStretch(0,2);
    ui->widgetLayout->setStretch(1,1);

    ui->textLayout->insertStretch(0,1);
    ui->textLayout->addStretch(1);
    ui->textLayout->setStretch(1,4);
    ui->textLayout->setStretch(2,4);
    ui->textLayout->setStretch(3,4);*/
}

// 初始化播放器
void IntroduceWidget::initPlayer(){

    //设置播放内容 D:\CUIT\bci\BCIV1.9\video

    QString path=QCoreApplication::applicationDirPath()+"/video/test_games.mp4";

    player->setMedia(QUrl::fromLocalFile(path));

    player->setVideoOutput(vw);

    //获取视频长宽比
//    qDebug() << vw->aspectRatioMode();

    // 默认设置静音
    player->setMuted(true);
    // 默认设置音量为20%
    player->setVolume(20);
    // 播放
//    player->play();

    // 设置默认不播放
    player->pause();

    connect(ui->playstopBtn, &QToolButton::clicked, this, &IntroduceWidget::onplaystopBtnClicked);
    connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(onStateChanged(QMediaPlayer::State)));

    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(onDurationChanged(qint64)));
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(onPlayerPositionChanged(qint64)));
//    connect(ui->videoSlider, SIGNAL(sliderMoved(int)), this, SLOT(onSliderMoved(qint64)));
    connect(ui->videoSlider, SIGNAL(sliderMoved(int)), this, SLOT(onSliderMoved()));
    connect(ui->videoSlider, SIGNAL(sliderReleased()), this, SLOT(onSliderReleased()));

    connect(ui->soundBtn, SIGNAL(clicked(bool)), this, SLOT(onSoundBtnClicked(bool)));
    connect(player, SIGNAL(mutedChanged(bool)), this, SLOT(onMutedChanged(bool)));


}

void IntroduceWidget::UpdataInfo(QString account,QString name)
{
    ui->label_name->setText(name);
    ui->label_id->setText(account);
}

void IntroduceWidget::onplaystopBtnClicked(){
    QMediaPlayer::State state;
    // get current state of player
    state = player->state();
    if(state == QMediaPlayer::StoppedState || state == QMediaPlayer::PausedState){
        player->play();
    }else{
        player->pause();
    }
}

void IntroduceWidget::onStateChanged(QMediaPlayer::State newstate){
    if(newstate == QMediaPlayer::StoppedState || newstate == QMediaPlayer::PausedState){
        ui->playstopBtn->setText("播放");
        ui->playstopBtn->setIcon(QIcon(":/image/introduce_pic/24gf-play.png"));
        qDebug() <<"播放器状态:" << player->state();
    }else{
        ui->playstopBtn->setText("暂停");
        ui->playstopBtn->setIcon(QIcon(":/image/introduce_pic/24gf-pause.png"));
        qDebug() <<"播放器状态:" << player->state();
    }
}

void IntroduceWidget::onDurationChanged(qint64 duration){
    ui->videoSlider->setEnabled(true);
    ui->videoSlider->setRange(0, maxvalue);

    qDebug() << "videoduration:" << duration;
//    ui->videoSlider->setMaximum(duration);
    this->videoDuration = duration;

    timer = new QTimer();
    timer->setInterval(100);    //100ms
    timer->start();

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));
}

void IntroduceWidget::onSliderMoved() {
//    player->setPosition(currentDuration);

    timer->stop();
    player->setPosition(ui->videoSlider->value()*player->duration()/maxvalue);
}

void IntroduceWidget::onSliderReleased(){
    timer->start();
}

void IntroduceWidget::onPlayerPositionChanged(qint64 currentDuration){
//    ui->videoSlider->setValue(currentDuration);
    // 手动设置循环播放
    if(currentDuration == videoDuration){
        player->setPosition(0);
        player->play();
    }

}

void IntroduceWidget::onSoundBtnClicked(bool) {
    if(player->isMuted())
        player->setMuted(false);
    else
        player->setMuted(true);
}

void IntroduceWidget::onMutedChanged(bool muted) {
    if(muted)
        ui->soundBtn->setIcon(QIcon(":/image/introduce_pic/24gf-volumeDisable.png"));
    else
        ui->soundBtn->setIcon(QIcon(":/image/introduce_pic/24gf-volumeZero.png"));
}

void IntroduceWidget::onTimerOut(){

    ui->videoSlider->setValue(player->position()*maxvalue/player->duration());
}

void IntroduceWidget::setFuncList()
{
    for (int i=0;i<2 ;i++ ) {
        CFuncDetial* pFunDetail = new CFuncDetial(this);
        ui->gridLayout_funlist->addWidget(pFunDetail,i,0);
        CFuncDetial* pFunDetail2 = new CFuncDetial(this);
        ui->gridLayout_funlist->addWidget(pFunDetail2,i,1);
    }
}

void IntroduceWidget::setProductList()
{
    //设置产品
    for (int i=0;i<4 ;i++ ) {
        CProduct * ptempProduct = new CProduct(this);
        ui->verticalLayout_productList->addWidget(ptempProduct);
    }

}
