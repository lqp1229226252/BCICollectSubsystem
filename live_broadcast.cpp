#include "live_broadcast.h"
#include "ui_live_broadcast.h"

live_broadcast::live_broadcast(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::live_broadcast)
{
    ui->setupUi(this);
    addGame();
    addGamer();
}
void live_broadcast::addGame()
{
    ui->game_list->addItem("游戏A");
    ui->game_list->addItem("游戏B");
    ui->game_list->addItem("...");
    ui->game_list->addItem("游戏n");
}
void live_broadcast::addGamer()
{
    ui->gamer_list->addItem("主播A");
    ui->gamer_list->addItem("主播B");
    ui->gamer_list->addItem("...");
    ui->gamer_list->addItem("主播n");
}
live_broadcast::~live_broadcast()
{
    delete ui;
}

