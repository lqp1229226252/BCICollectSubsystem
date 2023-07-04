#include "wbgwidget.h"
#include "ui_wbgwidget.h"
#include "QDebug"
#include "windows.h"


WBGWIdget::WBGWIdget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WBGWIdget)
{
    ui->setupUi(this);
    ftpWidget=new FtpServerWidget();
    initParams();
    setLayout();
    setConnect();
    LoginWidget->show();
    this->setWindowFlags(Qt::FramelessWindowHint); //不显示边框

    QPalette palette;
    QPixmap pix(":/image/image/bg.png");
    palette.setBrush(QPalette::Window,pix);
    this->setPalette(palette);



}

WBGWIdget::~WBGWIdget()
{
//    m_process->kill();
    delete ui;
//    delete indexWidget;
//    delete introduceWidget;
//    delete LoginWidget;
//    delete userGameWidget;
////    delete bciMonitor;
//    delete storeWidget;
//    delete startGameWidget;
//    delete personalDataWidget;

//    delete bciWidget;
//    delete m_widget;
//    delete  m_process;

}

void WBGWIdget::initParams()
{

    move_flage=false;//窗口移动标志初始化为Flase
    indexWidget=new IndexWidget();
    introduceWidget=new IntroduceWidget();
    LoginWidget=new Login();
    userGameWidget = new UserGameWidget();
    personalDataWidget = new PersonalDataWidget();
    storeWidget = new Store();
    startGameWidget = new start_game();
    bcimonitor=new BCIMonitor();
    handler = new UploadFileHandler();

    initBCIMonitor();
    initTCP();

    initFTPRevice();
    initUserGameWidget();
    initIndexWidget();
    initStartGameWidget();
    initGameEndWidget();
}

void WBGWIdget::setConnect()
{
    connect(LoginWidget,&Login::LoginSucceedSignal,[=](QString account){
        this->account=account;  //登录成功后可以传来用户账号
        this->showMaximized();
        LoginWidget->close();
        initFTP();
    });

    //点击indexwidget的关闭按钮后关闭整个程序
    connect(indexWidget,&IndexWidget::closeSingal,this,[=](){
       this->close();
    });

    connect(indexWidget,&IndexWidget::minSingal,this,[=](){
       this->showMinimized();
    });

    connect(indexWidget,&IndexWidget::maxSingal,this,[=](){
           if(isMaximized){
               this->showNormal();
               isMaximized=0;
//               this->resize(1263, 770);
           }
           else{
               this->showMaximized();
               isMaximized=1;
//               this->resize(1920, 977);
            }
        });
    setMoniotrConnect();
    setTCPConnect();
    setFTPReviceConnect();

}

void WBGWIdget::setLayout()
{
    ui->layout->addWidget(indexWidget);
}

void WBGWIdget::initIndexWidget()
{
    indexWidget->addWidget(u8"主页",introduceWidget);
    indexWidget->addWidget(u8"用户信息",userGameWidget);
    indexWidget->addWidget("采集",bcimonitor);
    indexWidget->addWidget(u8"评估",personalDataWidget);
    indexWidget->addWidget("社区", storeWidget);
    indexWidget->addWidget("启动训练",startGameWidget);

}

void WBGWIdget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
         if(event->y()<20)
         {
            move_flage=true;
            last_mouse_x=event->globalX();//获取鼠标开始移动的x坐标
            last_mouse_y=event->globalY();//获取鼠标开始移动的y坐标
         }
    }
}

void WBGWIdget::mouseMoveEvent(QMouseEvent *event)
{
    if(move_flage)
    {
        int widget_x=this->pos().x();//获取当前窗口x坐标
        int widget_y=this->pos().y();//获取当前窗口y坐标
        //获取此时的鼠标x,y坐标
        int mouse_x=event->globalX();
        int mouse_y=event->globalY();
//        qDebug()<<"global_x:"<<global_x;
//        qDebug()<<"global_y:"<<global_y;
//        qDebug()<<"x:"<<x;
//        qDebug()<<"y:"<<y;
//        qDebug()<<"move_x:"<<x-start_move_x;
//        qDebug()<<"move_y:"<<y-start_move_y;
        //计算鼠标移动的距离
        int move_x=mouse_x-last_mouse_x;
        int move_y=mouse_y-last_mouse_y;
        //移动窗口坐标
        this->move(widget_x+move_x,widget_y+move_y);
        //记录这次的鼠标位置，用于计算鼠标坐标的移动
        last_mouse_x=mouse_x;
        last_mouse_y=mouse_y;

    }
}

void WBGWIdget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        move_flage=false;
    }
}

void WBGWIdget::acceptGameAccount(QMap<QString, QString> map)
{
    QString account=map["Account"];
    QDir dir;
    saveMatPath+="temp";
    dir.mkdir(saveMatPath);
    saveMatPath+="/"+account;
    dir.mkdir(saveMatPath);
    saveMatPath+="/"+QDate::currentDate().toString("yyMMdd")+QTime::currentTime().toString("hhmmss");
    dir.mkdir(saveMatPath);
    int id=map["GameType"].toInt();
    bcimonitor->setFileMsg(saveMatPath,account,id);
    bcimonitor->start();
    initUploadFileHandler();
}

void WBGWIdget::initGameEndWidget()
{
    gameoverwidget=new GameOverWidget;
}

void WBGWIdget::setGameEndWidgetConnect()
{
}

void WBGWIdget::setMoniotrConnect()
{
    connect(bcimonitor,&BCIMonitor::downData,tcpserver,&TcpServer::tcpSendContent);
}

void WBGWIdget::initBCIMonitor()
{

    bcimonitor->setFileMsg(saveMatPath,account,game_id);

}


QList<GameData> createData()
{
    QList<GameData> gamedata;
    QStringList names={"注意训练","记忆训练","视知觉训练","听知觉训练","手眼协调训练","综合训练"};
    QString url="pic/res/";
    QString cover_url="pic/res/cover/";
    for(int i=0;i<names.size();i++)
    {
        GameData data;
        data.setName(names[i]);
        QString path=url+QString::number(i)+".png";
        QPixmap pixmap(path);
        data.setIcon(pixmap);
        path=cover_url+QString::number(i)+".png";
        pixmap.load(path);
        data.setCover(pixmap);
        data.setPlaytime(i+1);
        data.setPlayrank(i+1);
        gamedata.append(data);
    }
    return gamedata;
}
QList<DynamicData> createDynamicData()
{
    QList<DynamicData> gamedata;
    QStringList dynamic_names={"注意训练","记忆训练","视知觉训练","听知觉训练","手眼协调训练"};
    QStringList game_names={"介绍","介绍","介绍","介绍","介绍"};
    QString game_cover="pic/res/";
    QString dynamic_cover="pic/res/dynamic/";
    for(int i=0;i<game_names.size();i++)
    {
        DynamicData data;
        data.setGame_name(game_names[i]);

        QString game_path=game_cover+QString::number(i)+".png";
        QPixmap pixmap(game_path);
        data.setGame_icon(pixmap);

        QString dynamic_path=dynamic_cover+QString::number(i)+".png";
        QPixmap pixmap1(dynamic_path);
        data.setCover(pixmap1);

        data.setDate("今天");

        data.setDynamic_name(dynamic_names[i]);

        gamedata.append(data);
    }
    return gamedata;
}

void WBGWIdget::initUserGameWidget()
{
//    QList<GameData> gamedata=createData();
//    QList<DynamicData> dynamicdata=createDynamicData();
//    userGameWidget->addGame(gamedata);
//    userGameWidget->addGamePlay(gamedata);
//    userGameWidget->addGameUpdate(gamedata);
//    userGameWidget->setGameOverview(gamedata);
//    userGameWidget->setGameDynamic(dynamicdata);
}

QList<start_game::GameData> createGameData()
{
    QList<start_game::GameData> gamedata;
    QStringList names={"注意训练","记忆训练","视知觉训练","听知觉训练","手眼协调训练","综合训练"};
    QString url="pic/res/";
    for(int i=0;i<names.size();i++)
    {
        start_game::GameData data;
        data.name=names[i];
        QString path=url+QString::number(i)+".png";
        data.icon=QIcon(path);
        gamedata.append(data);
    }
    return  gamedata;
}

void WBGWIdget::initStartGameWidget()
{
    QList<start_game::GameData> gamedata=createGameData();
    startGameWidget->addGame(gamedata);
}

void WBGWIdget::initUploadFileHandler()
{
    //初始化mat文件的发送FTP
    //连接bciMonitor保存好mat文件的信号和发送mat文件的操作
    connect(bcimonitor,&BCIMonitor::saveFinished,handler,&UploadFileHandler::uploadFile);

}

void WBGWIdget::initFTPRevice()
{
    ftprevice=new SaveFileToBCI();
}

void WBGWIdget::setFTPReviceConnect()
{
    connect(ftpWidget,&FtpServerWidget::_TcpControlMessageReady,tcpserver,&TcpServer::tcpSendContent);
    connect(ftpWidget,&FtpServerWidget::_RadarDataReady,personalDataWidget,&PersonalDataWidget::getRecChartDatas);
//    connect(ftprevice,&SaveFileToBCI::TcpControlMessageReady,tcpserver,&TcpServer::tcpSendContent);
//    connect(ftprevice,&SaveFileToBCI::RadarDataReady,personalDataWidget,&PersonalDataWidget::getRecChartDatas);
}

void WBGWIdget::initTCP()
{
    tcpserver=new TcpServer;
    tcpserver->tcpListen();
}

void WBGWIdget::setTCPConnect()
{
    connect(tcpserver,&TcpServer::gameEnemyBorn,bcimonitor,&BCIMonitor::appendMarkEnemyBorn);
    connect(tcpserver,&TcpServer::gameEnemyDie,bcimonitor,&BCIMonitor::appendMarkEnemyDie);
    connect(tcpserver,&TcpServer::gameFireHit,bcimonitor,&BCIMonitor::appendMarkFireHit);
    connect(tcpserver,&TcpServer::gameFireMiss,bcimonitor,&BCIMonitor::appendMarkFireMiss);
    connect(tcpserver,&TcpServer::gameCutHit,bcimonitor,&BCIMonitor::appendMarkCutHit);
    connect(tcpserver,&TcpServer::gameFinish,gameoverwidget,&GameOverWidget::setMap);
    connect(tcpserver,&TcpServer::gameStart,this,&WBGWIdget::acceptGameAccount);
}

void WBGWIdget::initFTP()
{
    if(ftpWidget->LoadIni()==-1){
        QString path = "D:/BCIData/FTP-Receive";
        ftpWidget->set_ftp_para("127.0.0.1","21","demo","demo",path);
    }
    else{
        ftpWidget->set_ftp_para(ftpWidget->ftpinfo.ip,ftpWidget->ftpinfo.port,ftpWidget->ftpinfo.username,
                               ftpWidget->ftpinfo.password,ftpWidget->ftpinfo.filepath);
    }
    ftpWidget->show();
}



