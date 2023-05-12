#ifndef GAMEOVERWIDGET_H
#define GAMEOVERWIDGET_H


#include <QWidget>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class GameOverWidget; }
QT_END_NAMESPACE

class GameOverWidget : public QWidget
{
    Q_OBJECT

public:
    GameOverWidget(QWidget *parent = nullptr);
    ~GameOverWidget();


public slots:
    void onAnalyzeMsgDone();


    void setMap(QMap<QString, QString>);

private:
    Ui::GameOverWidget *ui;


    QMap<QString, QString> map;


    void setStyle();

    void init();

signals:
    void setGameOverMsgSignal();
    void analyzeMsgDoneSignal();

};
#endif // GAMEOVERWIDGET_H
