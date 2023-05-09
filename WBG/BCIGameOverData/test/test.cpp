#include "test.h"
#include "gameoverwidget.h"

test::test(QObject *parent) : QObject(parent)
{
    gameOverWidget = new GameOverWidget;

}

void test::analze(QString msg)
{
}
