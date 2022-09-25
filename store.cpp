#include "store.h"
#include "ui_store.h"

Store::Store(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);
    addGame();
    newGame();
    game_point_list();
}
void Store::addGame()
{
     ui->play_current_list->addItem("游戏A");
     ui->play_current_list->addItem("游戏B");
     ui->play_current_list->addItem("...");
}
void Store::newGame()
{
    ui->new_game_list->addItem("日期：2022/9/25             ");
    ui->new_game_list->addItem("日期：2022/9/25             ");
    ui->new_game_list->addItem("...");
}
void Store::game_point_list()
{
    ui->game_point_list->addItem("当前积分：");
    ui->game_point_list->addItem("1000积分：消费券");
    ui->game_point_list->addItem("5000积分：一桶油");
    ui->game_point_list->addItem("荣誉称号：强脑健将（连续30天）= 5000分");


}
Store::~Store()
{
    delete ui;
}
