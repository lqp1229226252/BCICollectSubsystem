#include "newgameitem.h"
#include "ui_newgameitem.h"

#include <QIcon>
#include <QPixmap>

newgameitem::newgameitem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newgameitem)
{
    ui->setupUi(this);


}

newgameitem::~newgameitem()
{
    delete ui;
}

void newgameitem::setData(QString picPth){
    QPixmap pixmap;

    pixmap.load(picPth);
    int pixMapWidth = 140;
    int pixMapHeight = 210;

    QPixmap pixmapPicFit = pixmap.scaled(pixMapWidth, pixMapHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    ui->label->setPixmap(pixmapPicFit);
}
