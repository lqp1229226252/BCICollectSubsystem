#include "start_game.h"
#include "ui_start_game.h"

start_game::start_game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start_game)
{
    ui->setupUi(this);
}
void start_game::addGame(QList<GameData> data)
{
    for(QList<GameData>::iterator begin=data.begin();begin!=data.end();begin++)
    {
        QListWidgetItem *item=new QListWidgetItem((*begin).icon,(*begin).name);
        ui->game_list->addItem(item);
    }
    ui->game_icon->setPixmap(data[0].icon.pixmap(ui->game_icon->size()));
}
start_game::~start_game()
{
    delete ui;
}

void start_game::on_game_list_itemPressed(QListWidgetItem *item)
{
    QIcon icon=item->icon();
    ui->game_icon->setPixmap(icon.pixmap(ui->game_icon->size()));
}
