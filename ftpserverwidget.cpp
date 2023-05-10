#include "ftpserverwidget.h"


FtpServerWidget::FtpServerWidget(QWidget *parent)
    : QWidget{parent}
{
    this->value_init();
    this->control_init();

}

FtpServerWidget::~FtpServerWidget()
{
    this->ftp_stop_server();
}


void FtpServerWidget::value_init()
{
    this->ftpIp = "127.0.0.1";
}
int FtpServerWidget::LoadIni()  //loadName字符串是 配置文件里的“节”名称
{
    //判断文件是否存在
    QFileInfo fileInfo("FTPConfig.ini");
    if (!fileInfo.isFile())
    {
        QMessageBox::critical(NULL, QString::fromLocal8Bit("错误"),
        QString::fromLocal8Bit("缺少FTPConfig.ini文件！"));
        return -1;//无配置文件使用默认参数
    }
    //读取配置文件
    QSettings settings("FTPConfig.ini", QSettings::IniFormat);
    settings.setIniCodec("utf-8");// 解决乱码
    settings.beginGroup("FTP");
    QString ip=settings.value("ip").toString();
    QString port=settings.value("port").toString();
    QString username=settings.value("username").toString();
    QString password=settings.value("password").toString();
    QString filepath=settings.value("filepath").toString();
    settings.endGroup();
    qDebug()<<ip<<port<<username<<password<<filepath;
    if(ip!=""&&port!=""&&username!=""&&password!=""&&filepath!=""){
        ftpinfo.ip=ip;
        ftpinfo.port=port;
        ftpinfo.username=username;
        ftpinfo.password=password;
        ftpinfo.filepath=filepath;
        return 1;
    }
    return -1;//某项为空
}


//手搓UI界面
void FtpServerWidget::control_init()
{
    this->resize(450, 330);
    this->setMinimumSize(QSize(450, 330));
    this->setMaximumSize(QSize(500, 380));
    this->setWindowTitle(tr("FTP服务器参数设置"));

    gridLayout = new QGridLayout();
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

    label = new QLabel();
    label->setText(tr("服务器IP:"));
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::white);
    label->setPalette(pe);

    label->setObjectName(QString::fromUtf8("label"));
    label->setAlignment(Qt::AlignCenter);

    horizontalLayout->addWidget(label);

    lineEditIp = new QLineEdit();
    lineEditIp->setObjectName(QString::fromUtf8("lineEditIp"));

    horizontalLayout->addWidget(lineEditIp);

    horizontalLayout->setStretch(0, 1);
    horizontalLayout->setStretch(1, 4);

    gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

    label_2 = new QLabel();
    label_2->setText(tr("服务器端口:"));
    label_2->setPalette(pe);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setAlignment(Qt::AlignCenter);

    horizontalLayout_2->addWidget(label_2);

    lineEditPort = new QLineEdit();
    lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

    horizontalLayout_2->addWidget(lineEditPort);

    horizontalLayout_2->setStretch(0, 1);
    horizontalLayout_2->setStretch(1, 4);

    gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

    label_3 = new QLabel();
    label_3->setText(tr("用户名:"));
    label_3->setPalette(pe);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setAlignment(Qt::AlignCenter);

    horizontalLayout_3->addWidget(label_3);

    lineEditUser = new QLineEdit();
    lineEditUser->setObjectName(QString::fromUtf8("lineEditUser"));

    horizontalLayout_3->addWidget(lineEditUser);

    horizontalLayout_3->setStretch(0, 1);
    horizontalLayout_3->setStretch(1, 4);

    gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

    label_4 = new QLabel();
    label_4->setText(tr("登录密码:"));
    label_4->setPalette(pe);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setAlignment(Qt::AlignCenter);

    horizontalLayout_4->addWidget(label_4);

    lineEditPassward = new QLineEdit();
    lineEditPassward->setObjectName(QString::fromUtf8("lineEditPassward"));

    horizontalLayout_4->addWidget(lineEditPassward);

    horizontalLayout_4->setStretch(0, 1);
    horizontalLayout_4->setStretch(1, 4);

    gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

    horizontalLayout_6 = new QHBoxLayout();
    horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));

    label_6 = new QLabel();
    label_6->setText(tr("文件路径:"));
    label_6->setPalette(pe);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setAlignment(Qt::AlignCenter);

    horizontalLayout_6->addWidget(label_6);

    lineEditPath = new QLineEdit();
    lineEditPath->setObjectName(QString::fromUtf8("lineEditPath"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(lineEditPath->sizePolicy().hasHeightForWidth());
    lineEditPath->setSizePolicy(sizePolicy);

    horizontalLayout_6->addWidget(lineEditPath);

    btnSelectPath = new QPushButton();
    btnSelectPath->setText(tr("..."));
    btnSelectPath->setObjectName(QString::fromUtf8("toolBtnSelectPath"));
    btnSelectPath->setMinimumSize(QSize(82, 0));

    horizontalLayout_6->addWidget(btnSelectPath);

    horizontalLayout_6->setStretch(0, 1);
    horizontalLayout_6->setStretch(1, 3);
    horizontalLayout_6->setStretch(2, 1);

    gridLayout->addLayout(horizontalLayout_6, 4, 0, 1, 1);

    horizontalLayout_7 = new QHBoxLayout();
    horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));

    btnCancel = new QPushButton();
    btnCancel->setText(tr("取消"));
    btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
    QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(btnCancel->sizePolicy().hasHeightForWidth());
    btnCancel->setSizePolicy(sizePolicy1);
    btnCancel->setMinimumSize(QSize(0, 50));

    horizontalLayout_7->addWidget(btnCancel);

    btnConfirm = new QPushButton();
    btnConfirm->setText(tr("确定"));
    btnConfirm->setObjectName(QString::fromUtf8("btnConfirm"));
    sizePolicy1.setHeightForWidth(btnConfirm->sizePolicy().hasHeightForWidth());
    btnConfirm->setSizePolicy(sizePolicy1);
    btnConfirm->setMinimumSize(QSize(0, 50));

    horizontalLayout_7->addWidget(btnConfirm);


    gridLayout->addLayout(horizontalLayout_7, 5, 0, 1, 1);

    this->setLayout(gridLayout);

    //限制lineedit格式输入
    QRegularExpression regIpStr("(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])\\.(\\d{1,2}|1\\d\\d|2[0-4]\\d|25[0-5])");
    QValidator * validator = new QRegularExpressionValidator(regIpStr, this->lineEditIp);
    this->lineEditIp->setValidator(validator);

    this->lineEditPort->setValidator(new QIntValidator(0,65535,this->lineEditPort));


    QRegularExpression regUserStr("[a-zA-Z0-9]+$");
    validator = new QRegularExpressionValidator(regUserStr, this->lineEditUser);
    this->lineEditUser->setValidator(validator);
    this->lineEditPassward->setValidator(validator);
    this->lineEditUser->setMaxLength(8);
    this->lineEditPassward->setMaxLength(8);

    this->lineEditIp->setPlaceholderText(tr("请输入服务器IP地址！"));
    this->lineEditPort->setPlaceholderText(tr("请输入服务器端口！"));
    this->lineEditUser->setPlaceholderText(tr("请输入登录用户名！"));
    this->lineEditPassward->setPlaceholderText(tr("请输入登录密码！"));
    this->lineEditPath->setPlaceholderText(tr("请输入文件路径！"));

    this->lineEditIp->setStyleSheet("border:2px groove gray;border-radius:8px;padding:2px 4px;border-style: outset;");
    this->lineEditPort->setStyleSheet("border:2px groove gray;border-radius:8px;padding:2px 4px;border-style: outset;");
    this->lineEditUser->setStyleSheet("border:2px groove gray;border-radius:8px;padding:2px 4px;border-style: outset;");
    this->lineEditPassward->setStyleSheet("border:2px groove gray;border-radius:8px;padding:2px 4px;border-style: outset;");
    this->lineEditPath->setStyleSheet("border:2px groove gray;border-radius:8px;padding:2px 4px;border-style: outset;");

    this->lineEditIp->setReadOnly(true);


    //路径选择dialog初始化
    this->dirSelectDlg = new QFileDialog(this);
    this->dirSelectDlg->setFileMode(QFileDialog::Directory);
    this->dirSelectDlg->setWindowTitle(tr("请选择一个文件夹！"));
    this->dirSelectDlg->setModal(false);
    this->dirSelectDlg->close();
    connect(this->dirSelectDlg,&QFileDialog::fileSelected,this,&FtpServerWidget::dir_select_slot);

    //错误提示messagebox初始化
    this->paraMessageBox = new QMessageBox(this);
    this->paraMessageBox->setModal(false);
    this->paraMessageBox->setWindowTitle(tr("参数错误！"));
    this->paraMessageBox->setIcon(QMessageBox::Warning);
    this->paraMessageBox->setMinimumSize(500,100);
    this->paraMessageBox->close();

    //设置背景颜色
    QPalette pal(this->palette());        //设置的就是当前窗口,当前窗口是QWidget,如果是其他控件换成其他控件
    pal.setColor(QPalette::Background, QColor("#000000"));
    this->setAutoFillBackground(true);
    this->setPalette(pal);


    connect(this->btnConfirm,&QPushButton::clicked,this,&FtpServerWidget::btn_click_slot);
    connect(this->btnCancel,&QPushButton::clicked,this,&FtpServerWidget::btn_click_slot);
    connect(this->btnSelectPath,&QPushButton::clicked,this,&FtpServerWidget::btn_click_slot);

}
bool FtpServerWidget::set_ftp_para(QString ip, QString port, QString userName, QString password, QString path)
{

    qDebug()<<"ip:"<<ip<<"  port:"<<port<<"  userName:"<<userName<<"  password:"<<password<<"  path:"<<path;
    if(ip == nullptr)
    {
        this->paraMessageBox->setText(tr("IP不能为空！"));
        this->paraMessageBox->show();
        return false;
    }
    if(port == nullptr)
    {
        this->paraMessageBox->setText(tr("端口设置不能为空！"));
        this->paraMessageBox->show();
        return false;
    }
    if(port.toUInt() >65535)
    {
        this->paraMessageBox->setText(tr("端口值设置错误！"));
        this->paraMessageBox->show();
        return false;
    }
    if(userName == nullptr)
    {
        this->paraMessageBox->setText(tr("用户名不能为空！"));
        this->paraMessageBox->show();
        return false;
    }
    if(password == nullptr)
    {
        this->paraMessageBox->setText(tr("用户密码不能为空！"));
        this->paraMessageBox->show();
        return false;
    }
    if(path == nullptr)
    {
        this->paraMessageBox->setText(tr("路径不能为空！"));
        this->paraMessageBox->show();
        return false;
    }
    QFileInfo info(path);
    if(!info.exists())
    {
        this->paraMessageBox->setText(tr("路径不存在！"));
        this->paraMessageBox->show();
        return false;
    }


    this->ftpIp = ip;
    this->ftpPort = port;
    this->ftpUserName = userName;
    this->ftpPassword = password;
    this->ftpPath = path;
    return true;
}

bool FtpServerWidget::ftp_start_server()
{
    if(this->ftpIp == nullptr)
    {
        return false;
    }
    if(this->ftpPort == nullptr)
    {
        return false;
    }
    if(this->ftpPort.toUInt() >65535)
    {
        return false;
    }
    if(this->ftpUserName == nullptr)
    {
        return false;
    }
    if(this->ftpPassword == nullptr)
    {
        return false;
    }
    if(this->ftpPath == nullptr)
    {
        return false;
    }
    QFileInfo info(this->ftpPath);
    if(!info.exists())
    {
        return false;
    }

    if (this->ftpServer !=nullptr)
    {
        qDebug() << "服务器已经启动";
        return true;
    }
    this->ftpServer = new FtpServer(this, this->ftpPath, this->ftpPort.toInt(), this->ftpUserName, this->ftpPassword);
    //connect(m_server, SIGNAL(newPeerIp(QString)), this, SLOT(onNewPeerIp(QString)));

    qDebug() << "服务器已启动";
    this->hide();
    return true;
}
bool FtpServerWidget::ftp_stop_server()
{
    if(this->ftpServer != nullptr)
    {
        delete this->ftpServer;
        this->ftpServer = NULL;
    }
    qDebug() << "服务器已关闭";
    return true;
}

QString FtpServerWidget::get_ip()
{
    return this->ftpIp;
}

void FtpServerWidget::set_ip(QString val)
{
    this->ftpIp = val;
    emit para_changed();
}

QString FtpServerWidget::get_port()
{
     return this->ftpPort;
}

void FtpServerWidget::set_port(QString val)
{
    this->ftpPort = val;
    emit para_changed();

}

QString FtpServerWidget::get_user_name()
{
    return this->ftpUserName;
}

void FtpServerWidget::set_user_name(QString val)
{
    this->ftpUserName = val;
    emit para_changed();
}

QString FtpServerWidget::get_password()
{
    return this->ftpPassword;
}

void FtpServerWidget::set_password(QString val)
{
    this->ftpPassword = val;
    emit para_changed();
}

QString FtpServerWidget::get_path()
{
    return this->ftpPath;
}

void FtpServerWidget::set_path(QString val)
{
    this->ftpPath = val;
    emit para_changed();
}



void FtpServerWidget::btn_click_slot()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    if(btn == this->btnConfirm) //确定
    {
        QString ipStr = this->lineEditIp->text();
        QString portStr = this->lineEditPort->text();
        QString userStr = this->lineEditUser->text();
        QString passwordStr = this->lineEditPassward->text();
        QString pathStr = this->lineEditPath->text();

        this->set_ftp_para(ipStr,portStr,userStr,passwordStr,pathStr);
        this->ftp_start_server();
        //隐藏窗口
        //this->hide();
        //写入配置文件
        QSettings settings("FTPConfig.ini", QSettings::IniFormat);
        settings.setIniCodec("utf-8");// 解决乱码
        settings.beginGroup("FTP");
        settings.setValue("ip",ipStr);
        settings.setValue("port",portStr);
        settings.setValue("username",userStr);
        settings.setValue("password",passwordStr);
        settings.setValue("filepath",pathStr);
        settings.endGroup();
        qDebug()<<"保存配置文件成功！";

    }
    else if(btn == this->btnCancel) //取消
    {
        this->close();
    }
    else if(btn == this->btnSelectPath) //选择路径
    {
        this->dirSelectDlg->show();
    }
}

void FtpServerWidget::dir_select_slot(const QString &directory)
{
    this->lineEditPath->setText(directory);
}
void FtpServerWidget::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
    if(this->ftpIp != nullptr)
    {
        this->lineEditIp->setText(this->ftpIp);
    }
    if(this->ftpPort != nullptr)
    {
        this->lineEditPort->setText(this->ftpPort);
    }
    if(this->ftpUserName !=nullptr)
    {
        this->lineEditUser->setText(this->ftpUserName);
    }
    if(this->ftpPassword != nullptr)
    {
        this->lineEditPassward->setText(this->ftpPassword);
    }
    if(this->ftpPath != nullptr)
    {
        this->lineEditPath->setText(this->ftpPath);
    }

}
void FtpServerWidget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    this->dirSelectDlg->close();
    this->paraMessageBox->close();
}
