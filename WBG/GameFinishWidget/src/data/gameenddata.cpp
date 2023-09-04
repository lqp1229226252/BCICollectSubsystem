#include "gameenddata.h"
#include "ui_gameenddata.h"

GameEndData::GameEndData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameEndData)
{
    ui->setupUi(this);
    initGameEndData();
    this->setFixedWidth(400);
}

GameEndData::~GameEndData()
{
    delete ui;
}
void GameEndData::initGameEndData()
{
    list_widget = ui->listWidget;
    list_widget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    list_widget->setFrameShape(QListWidget::NoFrame);
    //    ui->title_game_type->setText("游戏类型");
//    ui->title_total_score->setText("总分数");
//    ui->title_react_time->setText("平均反应时间");
//    ui->title_right_react_time->setText("平均正确反应时间");
//    ui->title_total_enemy->setText("总出现敌人数量");
//    ui->title_total_kill->setText("总消灭敌人数量");
//    ui->title_total_miss->setText("总遗漏数量");
//    ui->title_total_wrong->setText("总打错数量");
//    ui->title_total_fire->setText("总射击数量");
//    ui->title_total_time->setText("本局游戏时间");
    //    ui->title_hit_rate->setText("命中率");
}


void GameEndData::showGameEndData(QMap<QString, QString> data)
{
//    qDebug() << "键的数量：" << data.keys().size();

    QList<QString> all_keys = convertKeysText(data.keys());
    QList<QString> all_values = data.values();

    list_widget->clear();
    for (int i=0;i<all_keys.size();i++) {
        QListWidgetItem *item = new QListWidgetItem();

        item->setSizeHint(QSize(180,70));

        dataitem = new gameenddataitem();
        dataitem->setTitle(all_keys[i]);
        dataitem->setValue(all_values[i]);
        list_widget->addItem(item);
        list_widget->setItemWidget(item, dataitem);
    }

}

QList<QString> GameEndData::convertKeysText(QList<QString> keys)
{
    QList<QString> newKeys;
    newKeys.clear();
    for (int i=0;i<keys.size();i++) {
        if(keys[i]=="GameType"){
            newKeys.append("游戏类型");
        }else if (keys[i] == "TotalScore") {
            newKeys.append("总分数");
        }else if (keys[i] == "AverageReactTime") {
            newKeys.append("平均反应时间");
        }else if (keys[i] == "AverageRightReactTime") {
            newKeys.append("平均正确反应时间");
        }else if (keys[i] == "TotalEnemyNum") {
            newKeys.append("总出现敌人数量");
        }else if (keys[i] == "TotalKillNum") {
            newKeys.append("总消灭敌人数量");
        }else if (keys[i] == "TotalMissNum") {
            newKeys.append("总遗漏数量");
        }else if (keys[i] == "TotalWrongNum") {
            newKeys.append("总打错数量");
        }else if (keys[i] == "TotalFire") {
            newKeys.append("总射击数量");
        }else if (keys[i] == "TotalGameTime") {
            newKeys.append("本局游戏时间");
        }else if (keys[i] == "HitRate") {
            newKeys.append("命中率");
        }

    }
    return newKeys;
}
