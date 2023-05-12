#ifndef GAMEOVERWIDGET_H
#define GAMEOVERWIDGET_H

#include "tcpserver.h"
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

    QString getGameOverMsg() const;
    void setGameOverMsg(const QString &value);


private slots:
    void onSetGameOverMsg();
    void onAnalyzeMsgDone();

    void onGetData(QString str);

private:
    Ui::GameOverWidget *ui;

    QString gameOverMsg;

    QMap<QString, QString> map;

    TcpServer *tcp = TcpServer::getInstance();

    void analyzeMsg();

signals:
    void setGameOverMsgSignal();
    void analyzeMsgDoneSignal();

};
#endif // GAMEOVERWIDGET_H
