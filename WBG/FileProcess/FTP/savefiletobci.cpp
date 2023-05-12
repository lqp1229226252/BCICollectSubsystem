#include "savefiletobci.h"
#include <QDebug>
#include <QDir>
SaveFileToBCI::SaveFileToBCI(QObject *parent) : QObject(parent)
{
    startTimer(10000);
    test();

}
void SaveFileToBCI::test(){
    //设置本地ftp服务器路径
    setFTPSavePath("D:/BCIData/FTP-Receive");
    //设置本地保存xxx.bci文件路径
    setLocalSavePath("D:/BCIData/FTP-LocalSave");
    //若无则创建
    isDirExist(FTPFileDir);
    isDirExist(SaveFileDir);

    //设置游戏服务器ftp信息
    //初始化xxx.gam文件上传ftp服务器的信息
    upLoadFileFtp.SetURL("10.23.66.17",21,"yw","yw","/");
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
        else if(fileName.contains(".gam"))
            HandelGamFile(fileName);
        else//不是两种文件就跳过
            continue;
    }
}
//直接copy到指定目录就行了
void SaveFileToBCI::HandelBCIFile(const QString filename)
{
    QFile::copy(FTPFileDir+"/"+filename,SaveFileDir+"/"+filename);
    //处理完了就删除
    QFile::remove(FTPFileDir+"/"+filename);
}


//2.xxxtoGam 不做任何处理直接转发给游戏端
void SaveFileToBCI::HandelGamFile(const QString filename)
{
    //先把FTP接收区收到的xxx.gam发送给游戏服务器
    upLoadFileFtp.uploadFileByName(FTPFileDir+"/"+filename);
    //再删除这个文件
    QFile::remove(FTPFileDir+"/"+filename);

}
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
