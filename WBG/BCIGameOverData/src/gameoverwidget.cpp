#include "gameoverwidget.h"
#include "ui_gameoverwidget.h"

#include <QMap>
#include <qdebug.h>

GameOverWidget::GameOverWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameOverWidget)
{
    ui->setupUi(this);

    init();

}

GameOverWidget::~GameOverWidget()
{
    map.clear();
    delete ui;
}

void GameOverWidget::init()
{

    this->setFixedSize(800, 400);
    this->setWindowFlags(Qt::FramelessWindowHint);

    connect(ui->confirmBtn, &QPushButton::clicked, this, &GameOverWidget::close);
//    connect(tool, &AnalyzeGameMsgTool::analyzeMsgDoneSignal, this, &GameOverWidget::setMap);
    connect(this, &GameOverWidget::analyzeMsgDoneSignal, this, &GameOverWidget::onAnalyzeMsgDone);
}


void GameOverWidget::setStyle()
{
    this->setStyleSheet("background-image:url(:/imgs/gameover_bgpic.png)");
}


void GameOverWidget::onAnalyzeMsgDone()
{
    ui->GameType->setText(map.value("GameType"));
    ui->TotalScore->setText(map.value("TotalScore"));
    ui->AverageReactTime->setText(map.value("AverageReactTime"));
    ui->TotalEnemyNum->setText(map.value("TotalEnemyNum"));
    ui->TotalKillNum->setText(map.value("TotalKillNum"));
    ui->TotalFire->setText(map.value("TotalFire"));
    ui->TotalGameTime->setText(map.value("TotalGameTime"));
    ui->HitRate->setText(map.value("HitRate"));

    this->show();

}


void GameOverWidget::setMap(QMap<QString, QString> qmap)
{
    this->map = qmap;
    qDebug() << "getMap::" << this->map;

    emit analyzeMsgDoneSignal();
}



