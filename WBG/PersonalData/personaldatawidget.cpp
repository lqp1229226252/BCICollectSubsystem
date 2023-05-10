#include "personaldatawidget.h"
#include "itemchart.h"
#include "ui_personaldatawidget.h"
#include "savefiletobci.h"
#include <QDateTime>

itemChart *leftChart, *rightChart;
itemChart *leftLineChart, *rightLineChart;
itemChart *leftBarChart, *rightBarChart;

PersonalDataWidget::PersonalDataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalDataWidget)
{
    ui->setupUi(this);
//    startTimer(3000);
    initPager();
    initChartLayout();
    initConnetion();
    initFolderPath();
    initDimName();
    initDatas();
    initChart();


}

PersonalDataWidget::~PersonalDataWidget()
{
    delete ui;
}

void PersonalDataWidget::initPager()
{
//    bgLabel = new QLabel(this);
//    bgLabel->setScaledContents(true);				// 设置标签为可扩展内容
//    bgLabel->lower();
//    QMovie *movie = new QMovie(":/res/personaldata/image/bg2.gif");
//    bgLabel->setMovie(movie);
//    movie->start();
//    bgLabel->show();
//    QWidget *left = ui->widget_left;
    //    left->resize(100,100);
}

void PersonalDataWidget::initChartLayout()
{
    ui->widget_left->setFocusPolicy(Qt::StrongFocus);
    ui->widget_right->setFocusPolicy(Qt::StrongFocus);
    ui->widget_bar_left->setFocusPolicy(Qt::StrongFocus);
    ui->widget_bar_right->setFocusPolicy(Qt::StrongFocus);
    ui->widget_line_left->setFocusPolicy(Qt::StrongFocus);
    ui->widget_line_right->setFocusPolicy(Qt::StrongFocus);
}

void PersonalDataWidget::initConnetion()
{
}

void PersonalDataWidget::initFolderPath()
{
    mFolderPath = "D:/BCIData/FTP-LocalSave";
}

void PersonalDataWidget::initDimName()
{
    leftDimName.append("视觉能力");
    leftDimName.append("听觉能力");
    leftDimName.append("注意能力");
    leftDimName.append("肢体协调能力");
    leftDimName.append("综合认知能力");

    rightDimName.append("应激强度");
    rightDimName.append("压力强度");
    rightDimName.append("士气水平");
    rightDimName.append("唤醒度");
    rightDimName.append("情绪属性");

}

void PersonalDataWidget::initDatas()
{
    QString newFilePath = getNewBCIFile();
    QMap<QString, double> initChartDatas = readNewBCIFileContent(newFilePath);

    if(initChartDatas.size()!=0){
        parseChartDatas(initChartDatas);
    }
}

QString PersonalDataWidget::getNewBCIFile()
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

QMap<QString, double> PersonalDataWidget::readNewBCIFileContent(QString path)
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
    return radarDatas;
}


void PersonalDataWidget::initChart()
{

    leftChart = new itemChart(this, ui->widget_left);
    leftChart->setChartDatas(leftValue);
    leftChart->setDimensionName(leftDimName);
    leftChart->showChart(0);


    rightChart = new itemChart(this, ui->widget_right);
    rightChart->setChartDatas(rightValue);
    rightChart->setDimensionName(rightDimName);
    rightChart->showChart(0);

    leftLineChart = new itemChart(this, ui->widget_line_left);
    leftLineChart->setChartDatas(leftValue);
    leftLineChart->setDimensionName(leftDimName);
    leftLineChart->showChart(1);


    rightLineChart = new itemChart(this, ui->widget_line_right);
    rightLineChart->setChartDatas(rightValue);
    rightLineChart->setDimensionName(rightDimName);
    rightLineChart->showChart(1);


    leftBarChart = new itemChart(this, ui->widget_bar_left);
    leftBarChart->setChartDatas(leftValue);
    leftBarChart->setDimensionName(leftDimName);
    leftBarChart->showChart(2);


    rightBarChart = new itemChart(this, ui->widget_bar_right);
    rightBarChart->setChartDatas(rightValue);
    rightBarChart->setDimensionName(rightDimName);
    rightBarChart->showChart(2);

}

void PersonalDataWidget::repaintChart()
{
    leftChart->setChartDatas(leftValue);
    leftChart->showChart(0);

    rightChart->setChartDatas(rightValue);
    rightChart->showChart(0);

    leftLineChart->setChartDatas(leftValue);
    leftLineChart->showChart(1);

    rightLineChart->setChartDatas(rightValue);
    rightLineChart->showChart(1);

    leftBarChart->setChartDatas(leftValue);
    leftBarChart->showChart(2);

    rightBarChart->setChartDatas(rightValue);
    rightBarChart->showChart(2);
}

void PersonalDataWidget::parseChartDatas(QMap<QString, double> radarData)
{
    leftValue.clear();
    rightValue.clear();
    if(radarData.contains("Visual")){
        addChartValue(0, radarData, "Visual");
    }
    if(radarData.contains("Auditory")){
        addChartValue(0, radarData, "Auditory");
    }
    if(radarData.contains("Attention")){
        addChartValue(0, radarData, "Attention");
    }if(radarData.contains("MotorCoordination")){
        addChartValue(0, radarData, "MotorCoordination");
    }
    if(radarData.contains("ComprehensiveCognitive")){
        addChartValue(0, radarData, "ComprehensiveCognitive");
    }
    if(radarData.contains("Stress")){
        addChartValue(1, radarData, "Stress");
    }
    if(radarData.contains("Pressure")){
        addChartValue(1, radarData, "Pressure");
    }
    if(radarData.contains("Morale")){
        addChartValue(1, radarData, "Morale");
    }
    if(radarData.contains("Arousal")){
        addChartValue(1, radarData, "Arousal");
    }
    if(radarData.contains("EmotionalValence")){
        addChartValue(1, radarData, "EmotionalValence");
    }
}



void PersonalDataWidget::getRecChartDatas(QMap<QString, double> radarData)
{
    if(radarData.size()!=0){
        parseChartDatas(radarData);
        repaintChart();
    }

}

//void PersonalDataWidget::timerEvent(QTimerEvent *event)
//{
//    qDebug()<<"run";

//    qDebug()<<leftValue;
//    repaintChart();
//}


void PersonalDataWidget::addChartValue(int chartType, QMap<QString, double> radarData, QString key)
{
    QVector<double> value;
    value.append(radarData.value(key));
    if(chartType==0){
        leftValue.append(value);
    }else{
        rightValue.append(value);
    }
}

// 数据转置
QVector<QVector<double>> PersonalDataWidget::dataTranspose(QVector<QVector<double> > dimValues)
{

    QVector<QVector<double>> array;
    QVector<double> temparay;
    for (int i = 0; i < dimValues[0].size(); ++i)
    {
        for (int j = 0; j < dimValues.size(); ++j) {
            temparay.push_back(dimValues[j][i]);
        }
        array.push_back(temparay);
        temparay.erase(temparay.begin(), temparay.end());
    }
    return array;
}



//void PersonalDataWidget::on_chart_change_left_currentIndexChanged(int index)
//{
//    index = ui->chart_change_left->currentIndex();
//    setCurrentLeftChartType(index);
//    leftChart->showChart(index);
//}



//void PersonalDataWidget::on_chart_change_right_currentIndexChanged(int index)
//{
//    index = ui->chart_change_right->currentIndex();
//    qDebug()<<"Index"<< index <<": "<< ui->chart_change_right->currentText();
//    setCurrentRightChartType(index);
//    rightChart->showChart(index);
//}

int PersonalDataWidget::getCurrentRightChartType() const
{
    return currentRightChartType;
}

void PersonalDataWidget::setCurrentRightChartType(int value)
{
    currentRightChartType = value;
}

int PersonalDataWidget::getCurrentLeftChartType() const
{
    return currentLeftChartType;
}

void PersonalDataWidget::setCurrentLeftChartType(int value)
{
    currentLeftChartType = value;
}


QStringList PersonalDataWidget::getRightDimName() const
{
    return rightDimName;
}

void PersonalDataWidget::setRightDimName(const QStringList &value)
{
    rightDimName = value;
}

QStringList PersonalDataWidget::getLeftDimName() const
{
    return leftDimName;
}

void PersonalDataWidget::setLeftDimName(const QStringList &value)
{
    leftDimName = value;
}

QVector<QVector<double> > PersonalDataWidget::getRightValue() const
{
    return rightValue;
}

void PersonalDataWidget::setRightValue(const QVector<QVector<double> > &value)
{
    rightValue = value;
}

QVector<QVector<double> > PersonalDataWidget::getLeftValue() const
{
    return leftValue;
}

void PersonalDataWidget::setLeftValue(const QVector<QVector<double> > &value)
{
    leftValue = value;
}

QStringList PersonalDataWidget::getRightDateNameItem() const
{
    return rightDateNameItem;
}

void PersonalDataWidget::setRightDateNameItem(const QStringList &value)
{
    rightDateNameItem = value;
}

QStringList PersonalDataWidget::getLeftDateNameItem() const
{
    return leftDateNameItem;
}

void PersonalDataWidget::setLeftDateNameItem(const QStringList &value)
{
    leftDateNameItem = value;
}
