#include "gameoverwidget.h"
#include "ui_gameoverwidget.h"
#include "tcpserver.h"

#include <QMap>
#include <qdebug.h>

GameOverWidget::GameOverWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameOverWidget)
{
    ui->setupUi(this);
    this->setFixedSize(300, 400);
    connect(this, SIGNAL(setGameOverMsgSignal()), this, SLOT(onSetGameOverMsg()));
    connect(this, SIGNAL(analyzeMsgDoneSignal()), this, SLOT(onAnalyzeMsgDone()));

    connect(tcp, SIGNAL(recvDataSignal(QString)), this, SLOT(onGetData(QString)));

}

GameOverWidget::~GameOverWidget()
{
    map.clear();
    delete ui;
}

QString GameOverWidget::getGameOverMsg() const
{
    return gameOverMsg;
}

void GameOverWidget::setGameOverMsg(const QString &value)
{
    gameOverMsg = value;
    emit setGameOverMsgSignal();
}

void GameOverWidget::analyzeMsg()
{
    QStringList list = gameOverMsg.split(",");
    qDebug() << list;
    QString headMsg = list.at(0);

    // 判断信息类型是否为GameEnd
    if((headMsg.split("="))[1] != "GameEnd"){
        qDebug() << "消息类型不正确";
        return;
    }


    foreach (QString str, list) {
        if(str == "MsgEnd")
            break;
        QStringList entry = str.split("=");
        map.insert(entry[0], entry[1]);
    }
    emit analyzeMsgDoneSignal();
    qDebug() << map;
}

void GameOverWidget::onSetGameOverMsg()
{
    analyzeMsg();
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

void GameOverWidget::onGetData(QString str)
{
    emit setGameOverMsg(str);
}



