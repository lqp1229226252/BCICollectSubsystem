#include "store.h"
#include "ui_store.h"
#include "newgameitem.h"
#include "welfarecenter.h"

#include <QDebug>
#include <QIcon>

// #pragma execution_character_set("utf-8") ；

Store::Store(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);
    ui->play_current_list->setIconSize(QSize(30, 30));
    ui->play_current_list->setHorizontalScrollMode(QListWidget::ScrollPerPixel);
    ui->welfare_center_list->setVerticalScrollMode(QListWidget::ScrollPerPixel);
    playCurrentGameList = new QStringList;

    addGame();
    newGame();
    game_point_list();
    initWelfareCenterMap();
    initWelfareCenterItems();

    initWelfareCenter();
}
void Store::addGame()
{
    initPlayCurrentList();
    qDebug() << playCurrentGameList->size();
    for (int i = 0; i < playCurrentGameList->size(); ++i) {
        QListWidgetItem *item = new QListWidgetItem;
        item->setIcon(playCurrentIconList[i]);
        item->setText(playCurrentGameList->at(i));

        ui->play_current_list->addItem(item);
    }
}
void Store::newGame()
{
//    ui->new_game_list->addItem("日期：2022/9/25             ");
//    ui->new_game_list->addItem("日期：2022/9/25             ");
//    ui->new_game_list->addItem("...");
    initNewGameList();

    QListIterator<newgameitem *> iter(newGameList);
    while(iter.hasNext()){
        QListWidgetItem *qitem = new QListWidgetItem;
        qitem->setSizeHint(QSize(140,210));
        ui->new_game_list->addItem(qitem);
        ui->new_game_list->setItemWidget(qitem, iter.next());
    }

    ui->gamePicA->setPixmap(demoGame[0]);
    ui->gamePicB->setPixmap(demoGame[1]);


}
void Store::game_point_list()
{
    ui->game_point_list->addItem("当前积分：");
    ui->game_point_list->addItem("1000积分：消费券");
    ui->game_point_list->addItem("5000积分：一桶油");
    ui->game_point_list->addItem("荣誉称号：强脑健将（连续30天）= 5000分");

}

void Store::initNewGameList(){

    // 列表
    QList<QString> imgList;
    imgList.append("pic/res/cover/0.png");
    imgList.append("pic/res/cover/1.png");
    imgList.append("pic/res/cover/2.png");
    imgList.append("pic/res/cover/3.png");

    QListIterator<QString> iter(imgList);
    while(iter.hasNext()){
           newgameitem *item = new newgameitem;
           item->setData(iter.next());

           newGameList.append(item);
    }

    // 两个试玩游戏展示
    demoGame.append(QPixmap("pic/res/dynamic/0.png"));
    demoGame.append(QPixmap("pic/res/dynamic/1.png"));

}

void Store::initPlayCurrentList(){
    playCurrentIconList.append(QIcon("pic/res/0.png"));
    playCurrentIconList.append(QIcon("pic/res/1.png"));
    playCurrentIconList.append(QIcon("pic/res/2.png"));
    playCurrentIconList.append(QIcon("pic/res/3.png"));

    playCurrentGameList->append("注意训练");
    playCurrentGameList->append("记忆训练");
    playCurrentGameList->append("视知觉训练");
    playCurrentGameList->append("听知觉训练");
}

void Store::initWelfareCenterMap(){
    // 初始数据,可从数据库抓取到
    welFareCenterMap.insert("注意训练","将军鬼神免费送");
    welFareCenterMap.insert("记忆训练","十周年盛典活动现已开启");
    welFareCenterMap.insert("视知觉训练","探索像素世界 赢取限定奖励");
    welFareCenterMap.insert("听知觉训练","全新幻能朋克系列 限时必得");
    welFareCenterMap.insert("手眼协调训练","春风纸鸢活动现实返场");

}

void Store::initWelfareCenterItems(){
    QMapIterator<QString, QString> map(welFareCenterMap);
    while(map.hasNext()){
        QMapIterator<QString, QString>::Item item = map.next();
        WelfareCenter *welfare = new WelfareCenter;;
        welfare->setData(item.key(), item.value());

        welfareCenterItems.append(welfare);

    }

}

void Store::initWelfareCenter(){

    QListIterator<WelfareCenter *> iter(welfareCenterItems);
    while(iter.hasNext()){
        QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(QSize(290, 100));

        ui->welfare_center_list->addItem(item);
        ui->welfare_center_list->setItemWidget(item, iter.next());
    }

}

Store::~Store()
{
    delete ui;
}
