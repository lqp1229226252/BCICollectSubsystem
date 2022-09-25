#include "start_game.h"
#include "ui_start_game.h"

start_game::start_game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start_game)
{
    ui->setupUi(this);
    addGame();
}
void start_game::addGame()
{
    ui->game_list->addItem("游戏A");
    ui->game_list->addItem("游戏B");
    ui->game_list->addItem("...");
}
start_game::~start_game()
{
    delete ui;
}
