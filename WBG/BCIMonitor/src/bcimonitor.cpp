#include "bcimonitor.h"
#include <QDebug>
#include "ui_bcimonitor.h"
#include "QIcon"
#include "QFileDialog"
BCIMonitor::BCIMonitor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BCIMonitor)
{
    ui->setupUi(this);
    init();
    setConnect();
}

BCIMonitor::~BCIMonitor()
{
    delete ui;
    delete filestorage;
    delete sample;
    delete processData;
}

void BCIMonitor::connectAmplifier()
{
    selectdialog=new SelectDialog(this);
    selectdialog->setDeviceType({"BP","文件"});
    selectdialog->setModal(true);
    selectdialog->open();
    connect(selectdialog,&SelectDialog::select,this,&BCIMonitor::setDeviceType);
}

void BCIMonitor::setDeviceType(int index)
{
    delete selectdialog;
    selectdialog=NULL;
    switch (index) {
    case 0:
        //初始化为BP设备
        sample->setSampleDeivce(Sample::BP);
        connectdialog=new ConnectDialog(this);
        connectdialog->setFamily(sample->GetDeviceFamily());
        connectdialog->setType(sample->GetInterfaceType());
        connectdialog->setModal(true);
        connectdialog->open();
        setConnectDialog();
    break;
    case 1:
        //初始化文件设备
        sample->setSampleDeivce(Sample::FILE);
        QString name=QFileDialog::getOpenFileName(this,"打开文件","","file(*.vhdr)");
        if(name.isEmpty())
        {
        }
        else
        {
            sample->open(name);
            connectdialog=NULL;
            connectSuccess();
        }

    }
}

void BCIMonitor::updateAmplifierMsg()
{
//    float voltage=sample->getBatteryVoltage();
//    bool  check=sample->CheckImpedances();
//    QString message="电压:"+QString::number(voltage)+"V";
//    if(check)
//    {
//        message+="阻抗:正常";
//    }
//    else
//    {
//        message+="阻抗:异常";
//    }
//    statusbar->showMessage(message);
}

void BCIMonitor::setFileMsg(QString dir, QString account, int game_id)
{
    filestorage->setFileNameMsg(dir,account,game_id);
}

void BCIMonitor::start()
{
    filestorage->start();
}

void BCIMonitor::appendMarkEnemyBorn(QMap<QString, QString>)
{
    curvegroup->appendMark("敌人刷新");
    filestorage->appendEvent(EventType::EnemyBorn);
}

void BCIMonitor::appendMarkEnemyDie(QMap<QString, QString>)
{
    curvegroup->appendMark("敌人死亡");
     filestorage->appendEvent(EventType::EnemyDie);
}

void BCIMonitor::appendMarkFireHit(QMap<QString, QString> map)
{
    if(map["HitRight"].toInt()==1)
    {
        curvegroup->appendMark("开枪命中");
        filestorage->appendEvent(EventType::FireHit);
    }
    else
    {
       curvegroup->appendMark("命中错误");
       filestorage->appendEvent(EventType::FireHitErr);
    }
}

void BCIMonitor::appendMarkFireMiss(QMap<QString, QString>)
{
    curvegroup->appendMark("开枪未命中");
    filestorage->appendEvent(EventType::FireMiss);
}

void BCIMonitor::appendMarkCutHit(QMap<QString, QString> map)
{
    if(map["HitRight"].toInt()==1)
    {
        curvegroup->appendMark("挥砍命中");
        filestorage->appendEvent(EventType::CutHit);
    }
    else
    {
       curvegroup->appendMark("命中错误");
       filestorage->appendEvent(EventType::CutHitErr);
    }
}
void BCIMonitor::init()
{
    initTool();
    initStatus();
    initCurveGroup();
    initFileStorage();
    initSample();
    initProcessData();
}

void BCIMonitor::setConnect()
{
    setToolConnet();
    setCurveConnect();
    setProcessDataConnect();
    setFileConnect();
    setSampleConnect();
}

void BCIMonitor::initTool()
{
   toolbar=new QToolBar();
   this->addToolBar(toolbar);
   toolbar->addAction(QIcon(":/start.png"),"");
   toolbar->addAction(QIcon(":/pause.png"),"");
   toolbar->addAction(QIcon(":/stop.png"),"");
   toolbar->addAction(QIcon(":/last.png"),"");
   toolbar->addAction(QIcon(":/next.png"),"");
   toolbar->addAction(QIcon(":/IncreaseChannel.png"),"");
   toolbar->addAction(QIcon(":/ReduceChannel.png"),"");
   toolbar->addAction(QIcon(":/Increasescale.png"),"");
   toolbar->addAction(QIcon(":/Reducescale.png"),"");
   toolbar->addAction(QIcon(":/connect.png"),"");
   toolButton=toolbar->actions();
   enableSample(false);
}

void BCIMonitor::setToolConnet()
{
    connect(toolButton[0],&QAction::triggered,filestorage,&FileStorage::start);
    connect(toolButton[1],&QAction::triggered,filestorage,&FileStorage::pause);
    connect(toolButton[2],&QAction::triggered,filestorage,&FileStorage::stop);

    connect(toolButton[0],&QAction::triggered,sample,&Sample::start);
    connect(toolButton[1],&QAction::triggered,sample,&Sample::pause);
    connect(toolButton[2],&QAction::triggered,sample,&Sample::stop);
    connect(toolButton[9],&QAction::triggered,this,&BCIMonitor::connectAmplifier);
}
void BCIMonitor::enableSample(bool enable)
{
    for(int i=0;i<7;i++)
    {
        toolButton[i]->setEnabled(enable);
    }
}

void BCIMonitor::initStatus()
{
    statusbar=new QStatusBar;
    this->setStatusBar(statusbar);
}

void BCIMonitor::initProcessData()
{
    processData=new ProcessData;
}

void BCIMonitor::setProcessDataConnect()
{
    connect(processData,&ProcessData::downData,this,&BCIMonitor::downData);
}
void BCIMonitor::initCurveGroup()
{
    int curve_num_group=6;
    int sample_point=2400;
    curvegroup=new CurveGroup();
    this->setCentralWidget(curvegroup);
    curvegroup->setMaxPoint(sample_point);
    curvegroup->setCurveNumGroup(curve_num_group);

}

void BCIMonitor::setCurve()
{
    QStringList labels=sample->getChannelName();
    curvegroup->setCurveLabels(labels);
    curvegroup->setCurveNum(labels.size());
}

void BCIMonitor::setCurveConnect()
{
    connect(toolButton[3],&QAction::triggered,curvegroup,&CurveGroup::last);
    connect(toolButton[4],&QAction::triggered,curvegroup,&CurveGroup::next);
    connect(toolButton[5],&QAction::triggered,curvegroup,&CurveGroup::increaseGroupChannel);
    connect(toolButton[6],&QAction::triggered,curvegroup,&CurveGroup::reduceGroupChannel);
    connect(toolButton[7],&QAction::triggered,curvegroup,&CurveGroup::increaseScale);
    connect(toolButton[8],&QAction::triggered,curvegroup,&CurveGroup::reduceScale);
}
void BCIMonitor::initFileStorage()
{
    filestorage=new FileStorage();
    filestorage->setSrate(250);
}

void BCIMonitor::setFileConnect()
{
    connect(this,&BCIMonitor::setChannelNum,filestorage,&FileStorage::setChannel_num);
    connect(this,&BCIMonitor::setChanlocs,filestorage,&FileStorage::setChanlocs);
    connect(filestorage,&FileStorage::saveFinish,this,&BCIMonitor::saveFinished);
    connect(filestorage,&FileStorage::mergeMsg,this,[=](QString msg){
        statusbar->showMessage(msg);
    });
}
void BCIMonitor::initSample()
{
    sample=new Sample();
    timer=new QTimer;
}

void BCIMonitor::setSampleConnect()
{
    //存储模块
    connect(sample,SIGNAL(readData(QList<double>)),filestorage,SLOT(append_eeg(QList<double>)));
    //曲线
    connect(sample,SIGNAL(readData(QList<double>)),curvegroup,SLOT(append(QList<double>)));
    connect(sample,SIGNAL(readData(QList<double>)),processData,SLOT(receiveData(QList<double>)));
    //采集器信息
    connect(timer,&QTimer::timeout,this,&BCIMonitor::updateAmplifierMsg);
}

void BCIMonitor::initConnectDialog()
{
    connectdialog=NULL;
}
void BCIMonitor::setConnectDialog()
{
    connect(connectdialog,SIGNAL(search(int,int)),sample,SLOT(searchDeivce(int,int)));
    connect(connectdialog,&ConnectDialog::connect,sample,&Sample::connectDeivce);
    connect(sample,&Sample::searchFinish,connectdialog,&ConnectDialog::setDeviceNum);
    connect(sample,&Sample::connectSuccess,this,&BCIMonitor::connectSuccess);
    connect(sample,&Sample::error,connectdialog,&ConnectDialog::showError);
    connect(connectdialog,&ConnectDialog::destroyed,this,&BCIMonitor::closeConnectDialog);
}

void BCIMonitor::connectSuccess()
{
   //设置通道数
   emit setChannelNum(sample->getChannelName().size());
   //导联信息
   emit setChanlocs(sample->getChanlocs());
   //设置曲线信息
   setCurve();
   //关闭连接窗口
   closeConnectDialog();
   //使能采集按钮
   enableSample(true);

   timer->start(3000);

}

void BCIMonitor::closeConnectDialog()
{
    //窗口未手动销毁
    if(connectdialog!=NULL)
    {
         connectdialog->close();
//         delete  connectdialog;
         connectdialog=NULL;
    }
}

