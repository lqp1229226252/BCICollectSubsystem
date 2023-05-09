#ifndef TEST_H
#define TEST_H

#include <QObject>
#include "gameoverwidget.h"

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

    void analze(QString msg);

signals:

private:
    GameOverWidget *gameOverWidget;

};

#endif // TEST_H
