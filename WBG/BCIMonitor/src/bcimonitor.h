#ifndef BCIMONITOR_H
#define BCIMONITOR_H

#include <QMainWindow>
#include "QToolBar"
#include "QtCharts/QChart"
#include "curvegroup.h"
#include "sample.h"
#include "filestorage.h"
#include "selectdialog.h"
#include "connectdialog.h"
#include "processdata.h"
using namespace QtCharts;
QT_BEGIN_NAMESPACE
namespace Ui { class BCIMonitor; }
QT_END_NAMESPACE
class BCIMonitor : public QMainWindow
{
    Q_OBJECT
public:
    BCIMonitor(QWidget *parent = nullptr);
    ~BCIMonitor();
public slots:
    //存储
    void setFileMsg(QString,QString,int);
    void start();
    //曲线
    void appendMarkEnemyBorn(QMap<QString,QString>);
    void appendMarkEnemyDie(QMap<QString,QString>);
    void appendMarkFireHit(QMap<QString,QString>);
    void appendMarkFireMiss(QMap<QString,QString>);
    void appendMarkCutHit(QMap<QString,QString>);
signals:
    void downData(QString);
    void saveFinished(QString);
    //与存储模块的交互
    void setChannelNum(quint8);
    void setChanlocs(QVariantList);
private slots:
    void connectAmplifier();
    void setDeviceType(int index);
    void updateAmplifierMsg();
private:

    //事件类型
    typedef  enum
    {
       EnemyBorn=0, //敌人刷新
       EnemyDie, //敌人死亡
       FireHit,  //开枪命中
       FireHitErr, //开枪命中错误
       FireMiss,  //开枪未命中
       CutHit,   //挥砍命中
       CutHitErr, //挥砍命中错误
    }EventType;
    Ui::BCIMonitor *ui;
    void init();
    void setConnect();
    //工具栏
    QToolBar *toolbar;
    QList<QAction *> toolButton;
    void initTool();
    void setToolConnet();
    void enableSample(bool);

    //状态栏
    QStatusBar *statusbar;
    void initStatus();

    //数据降采样
    ProcessData *processData;
    void initProcessData();
    void setProcessDataConnect();
    //曲线
    CurveGroup *curvegroup;
    void initCurveGroup();
    void setCurve();
    void setCurveConnect();
    //存储模块
    FileStorage *filestorage;
    void initFileStorage();
    void setFileConnect();
    //采集模块
    Sample *sample;
    //定时更新采集器信息
    QTimer *timer;
    void initSample();
    void setSampleConnect();

    //连接
    SelectDialog *selectdialog;
    ConnectDialog *connectdialog;
    void initConnectDialog();
    void setConnectDialog();

    //断开连接
    void connectSuccess();
    void closeConnectDialog();



};
#endif // BCIMONITOR_H
