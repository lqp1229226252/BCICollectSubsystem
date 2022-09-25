#ifndef START_GAME_H
#define START_GAME_H
#include "QListWidgetItem"
#include <QWidget>

namespace Ui {
class start_game;
}

class start_game : public QWidget
{
    Q_OBJECT

public:
    explicit start_game(QWidget *parent = nullptr);
    ~start_game();
    void addGame();
private:
    Ui::start_game *ui;
    QList<QListWidgetItem *> game;

};

#endif // START_GAME_H
