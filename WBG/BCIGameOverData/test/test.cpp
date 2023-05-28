#include "test.h"
#include "gameoverwidget.h"

test::test(QObject *parent) : QObject(parent)
{

    gameOverWidget = new GameOverWidget;

//    connect(tool, &AnalyzeGameMsgTool::analyzeMsgDoneSignal, gameOverWidget, &GameOverWidget::setMap);

}

void test::analze(QMap<QString, QString> value)
{
    gameOverWidget->setMap(value);
}
