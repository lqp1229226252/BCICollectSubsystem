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

    this->setFixedSize(1110, 500);
    this->setWindowFlags(Qt::FramelessWindowHint);

    connect(ui->confirmBtn, &QPushButton::clicked, this, &GameOverWidget::close);
    connect(this, &GameOverWidget::analyzeMsgDoneSignal, this, &GameOverWidget::onAnalyzeMsgDone);
}


void GameOverWidget::setStyle()
{
    //    this->setStyleSheet("background-image:url(./gameover_bgpic.png)");   //周换到ui内完成操作了。
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
    ui->TotalMissNum->setText(map.value("TotalMissNum"));
    ui->TotalWrongNum->setText(map.value("TotalWrongNum"));
    ui->AverageRightReactTime->setText(map.value("AverageRightReactTime"));

    this->show();

}


void GameOverWidget::setMap(QMap<QString, QString> qmap)
{
    this->map = qmap;
    qDebug() << "setMap::" << this->map;

    emit analyzeMsgDoneSignal();

}



