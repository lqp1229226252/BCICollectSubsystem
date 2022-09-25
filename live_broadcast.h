#ifndef LIVE_BROADCAST_H
#define LIVE_BROADCAST_H
#include "QListWidgetItem"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class live_broadcast; }
QT_END_NAMESPACE

class live_broadcast : public QWidget
{
    Q_OBJECT

public:
    live_broadcast(QWidget *parent = nullptr);
    ~live_broadcast();
    void addGame();
    void addGamer();

private:
    Ui::live_broadcast *ui;
    QList<QListWidgetItem *> game;//游戏
    QList<QListWidgetItem *> gamer;//主播
};
#endif // LIVE_BROADCAST_H
