#include "analyzeechartsdata.h"
#include <QMap>
#include <QJsonArray>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <qdebug.h>

AnalyzeEChartsData::AnalyzeEChartsData(QObject *parent) : QObject(parent)
{
    init();
}

AnalyzeEChartsData::~AnalyzeEChartsData()
{

}

void AnalyzeEChartsData::init()
{
    // 初始化文件目录
    initFolderPath();
}

// 获取到最新文件的路径
QString AnalyzeEChartsData::getNewBCIFile()
{
    //    qDebug() << mFolderPath;
    QStringList fileList;
    QString newBCIFilePath;
    if(mFolderPath.isEmpty() == false){
        QDir dir(mFolderPath);
        mFolderPath = dir.fromNativeSeparators(mFolderPath); //  "\\"转为"/"
        //        qDebug() << mFolderPath;
        if (!dir.exists()) fileList = QStringList("");
        dir.setFilter(QDir::Files);
        dir.setSorting(QDir::Name);
        dir.setNameFilters(QString("*.bci").split(";"));
        fileList = dir.entryList();

        // 初始化临时时间存储变量
        QDateTime tempTime = QDateTime::fromString("2020-01-01 00:00:00", "yyyy-MM-dd hh:mm:ss");
        for (int i = 0; i < fileList.size(); ++i)
        {
            QString path = mFolderPath + "/" +fileList[i];
            QFile file(path);
            bool isok = file.open(QIODevice::ReadOnly);
            if(isok == true)
            {
                while(file.atEnd() == false)
                {
                    QString line = file.readLine();
                    QStringList lineValue = line.split(QRegExp("[=\r\n]"),QString::SkipEmptyParts);

                    if (lineValue.size()>1)
                    {
                        QString key = lineValue[0];

                        QString value = lineValue[1];
                        if(key=="Time")
                        {
                            QDateTime currentFileTime = QDateTime::fromString(value, "yyyy-MM-dd hh:mm:ss");
                            //                            qDebug() << path;
                            if(currentFileTime > tempTime)
                            {

                                newBCIFilePath = path;
                                tempTime = currentFileTime;
                            }
                            break;
                        }
                    }
                }
            }
        }
        qDebug() << "最新文件名：" << newBCIFilePath;
    }
    return newBCIFilePath;
}

// 获取文件内容
QMap<QString, double> AnalyzeEChartsData::readNewBCIFileContent(QString path)
{
    QMap<QString, double> radarDatas;
    QFile file(path);
    bool isok = file.open(QIODevice::ReadOnly);
    if(isok == true)
    {
        QString line;
        QStringList arr;
        int cnt=0;
        bool flag=false;
        while(file.atEnd() == false)
        {
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
        QVector<double> target(10,0);
        QVector<QString> target_name(10,0);
        for(int i=1;i<11;i++){
            QStringList  strs =  arr[i].split("=");
            target[i-1]=(strs[1].toDouble()/100);
            target_name[i-1]=strs[0];
        }

        for (int i=0;i<target.size();i++) {
            radarDatas.insert(target_name[i], target[i]);
        }
        qDebug() << radarDatas;
    }
    file.close();
    return radarDatas;
}

// 返回初始状态的图标数据
void AnalyzeEChartsData::initDatas()
{
    QString newFilePath = getNewBCIFile();
    QMap<QString, double> initChartDatas = readNewBCIFileContent(newFilePath);
    if(initChartDatas.size()!=0){
        qDebug() << "AnalyzeEChartsData::initDatas::initChartDatas--" << initChartDatas;
        extractMapData(initChartDatas);
    }

}

void AnalyzeEChartsData::extractMapData(QMap<QString, double> map)
{
    if(map.size() == 0)
        return;

    QJsonArray jsonArr1;
    QJsonArray jsonArr2;

    jsonArr1.insert(0, map.value("Visual"));
    jsonArr1.insert(1, map.value("Auditory"));
    jsonArr1.insert(2, map.value("Attention"));
    jsonArr1.insert(3, map.value("MotorCoordination"));
    jsonArr1.insert(4, map.value("ComprehensiveCognitive"));

    jsonArr2.insert(0, map.value("Stress"));
    jsonArr2.insert(1, map.value("Pressure"));
    jsonArr2.insert(2, map.value("Morale"));
    jsonArr2.insert(3, map.value("Arousal"));
    jsonArr2.insert(4, map.value("EmotionalValence"));

    QVector<QJsonArray> vector;
    vector.insert(0, jsonArr1);
    vector.insert(1, jsonArr2);

    emit extractMapDataDone1(jsonArr1);
    emit extractMapDataDone2(jsonArr2);

    //    return vector;
}

void AnalyzeEChartsData::initFolderPath()
{
    mFolderPath = "D:/BCIData/FTP-LocalSave";
}

