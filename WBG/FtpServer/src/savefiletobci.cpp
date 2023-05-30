#include "savefiletobci.h"

SaveFileToBCI::SaveFileToBCI(QObject *parent) : QObject(parent)
{
    qDebug()<<"开始监测文件";
    startTimer(5000);
    initFilePath();
}
void SaveFileToBCI::initFilePath(){
    //1.读FTP服务器配置文件若不存在配置文件则使用默认路径
    //判断文件是否存在
    QFileInfo fileInfo("config/FTP/FTPConfig.ini");
    if (!fileInfo.isFile())
    {
        //无配置文件使用默认参数
        qDebug()<<u8"缺少FTPConfig.ini文件！";
        //设置本地ftp服务器路径
        setFTPSavePath("D:/BCIData/FTP-Receive");
        //设置本地保存xxx.bci文件路径
        setLocalSavePath("D:/BCIData/FTP-LocalSave");
        //若无则创建
        isDirExist(FTPFileDir);
        isDirExist(SaveFileDir);

    }//若存在配置文件就用配置文件中的路径并且在同级目录下创建FTP-LocalSave
    else{
        QSettings settings("config/FTP/FTPConfig.ini", QSettings::IniFormat);
        settings.setIniCodec("utf-8");// 解决乱码
        settings.beginGroup("FTP");
        QString filepath=settings.value("filepath").toString();
        settings.endGroup();
        //qDebug()<<filepath;
        setFTPSavePath(filepath);
        //分割出同级目录+FTP-LocalSave
        QStringList list = filepath.split("/");
        list.removeLast();
        QString ftplocalpath="";
        for(QString s:list){
            ftplocalpath+=s+"/";
        }
        ftplocalpath+="FTP-LocalSave";
        setLocalSavePath(ftplocalpath);
    }

    //设置游戏服务器ftp信息
    //初始化xxx.gam文件上传ftp服务器的信息
    //upLoadFileFtp.SetURL("10.23.66.17",21,"yw","yw","/");
}

 int SaveFileToBCI::CalculateControlParameters(const QString filename,QString &tcp_message,QMap<QString,double> &radar_data)
{
    QFile file(filename);
    QString line;
    QStringList arr;
    file.open(QIODevice::ReadOnly);
    int cnt=0;
    bool flag=false;
    while (!file.atEnd()) {
        line=file.readLine();
        if(line.contains("Result"))
            flag=true;
        if(flag==false) continue;
        if(cnt<11){
            arr += line.split(QRegExp("[: \r\n]"),QString::SkipEmptyParts);
            cnt++;
        }
        else break;
    }
    //十个指标
    //若发来的BCI文件有误应该返回错误
    if(arr.size()<11) return -1;
    QVector<double> target(10,0);
    QVector<QString> target_name(10,0);
    for(int i=1;i<11;i++){
        QStringList  strs=  arr[i].split("=");
        target[i-1]=(strs[1].toDouble()/100);
        target_name[i-1]=strs[0];
    }
    //组装为控制消息
    tcp_message="MsgType=Ajust,";
    for(int i=0;i<10;i++){
        int X=0;
        if(target[i]>=80)
            X=3;
        else if(target[i]>=60&&target[i]<80)
            X=2;
        else
            X=1;
        tcp_message += target_name[i]+"="+QString::number(X)+",";
        radar_data.insert(target_name[i],target[i]);
    }
    tcp_message+="MsgEnd";
    return 1;
}


void SaveFileToBCI::setFTPSavePath(const QString path)
{
    FTPFileDir=path;
}

void SaveFileToBCI::setLocalSavePath(const QString path)
{
    SaveFileDir=path;
}

SaveFileToBCI::~SaveFileToBCI()
{

}

void SaveFileToBCI::timerEvent(QTimerEvent *event)
{
    HandelFile();
}


void SaveFileToBCI::HandelFile()
{

    //嗝一段时间就读取一次FTP文件目录
    QStringList fileNameList=GetFileNameList(FTPFileDir);
    if(fileNameList.empty()) return;
    foreach(QString fileName,fileNameList){
        if(fileName.contains(".bci"))
            HandelBCIFile(fileName);
//        else if(fileName.contains(".game"))  暂时没有.game
//            HandelGamFile(fileName);
        else//不是两种文件就跳过
            continue;
    }

}
//直接copy到指定目录就行了
void SaveFileToBCI::HandelBCIFile(const QString filename)
{
    //2.根据.bci文件中的十个参数计算出调控参数，后通过TCP发送到游戏平台
    QString TCPmessage="";
    QMap<QString,double> RadarData;
    int ret=CalculateControlParameters(FTPFileDir+"/"+filename,TCPmessage,RadarData);
    if(ret==1){
        //1.保存在本地
        QFile::copy(FTPFileDir+"/"+filename,SaveFileDir+"/"+filename);
        //3.将要发送的数据通过信号抛出去
        emit TcpControlMessageReady(TCPmessage);
        //4.发送信号，给雷达图画图
        emit RadarDataReady(RadarData);
    }
    else{
        qDebug()<<".bci文件有误！";
    }
    //处理完了就删除
    QFile::remove(FTPFileDir+"/"+filename);
}

//2.xxxtoGam 不做任何处理直接转发给游戏端
//void SaveFileToBCI::HandelGamFile(const QString filename)
//{
//    //先把FTP接收区收到的xxx.gam发送给游戏服务器
//    upLoadFileFtp.uploadFileByName(FTPFileDir+"/"+filename);
//    //再删除这个文件
//    QFile::remove(FTPFileDir+"/"+filename);

//}

//获取目录下的文件名
QStringList SaveFileToBCI::GetFileNameList(const QString &strDirpath)
{
    QDir dir(strDirpath);
    QFileInfoList Info_list = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
    QListIterator<QFileInfo> Iterator(Info_list);
    QStringList strFileNameList;
    QFileInfo Info;
    while (Iterator.hasNext())
    {
        Info = Iterator.next();
        if (Info.isFile())
        {
            strFileNameList << Info.fileName();
        }
    }
    return strFileNameList;
}

bool SaveFileToBCI::isDirExist(QString fullPath)
{
    QDir dir(fullPath);
    if(dir.exists())
    {
      return true;
    }
    else
    {
       bool ok = dir.mkpath(fullPath);//创建多级目录
       return ok;
    }
}
