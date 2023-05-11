#include "drawecharts.h"
#include "ui_drawecharts.h"
#include "analyzeechartsdata.h"
#include <windows.h>
#include <QDir>
#include <QTimer>

DrawEcharts::DrawEcharts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawEcharts)
{
    ui->setupUi(this);
    initialize();
//    initCharts();
//    writeChartsInfo();
//    test();

}

//测试
void DrawEcharts::test()
{
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    m_pTimer->start((5*1000));
    writeChartsInfo();

}

void DrawEcharts::initialize()
{
    // 初始化
    analyzeEchartsData = new AnalyzeEChartsData;
    // 连接信号槽
    setConnect();

    _htmlDir = "";     // 使用了绝对路径,引到html文件夹
    _indexFileNameRadar1 = "radar1.html";
    QDir *dir = new QDir(QDir::currentPath());
    dir->cdUp();
    dir->cdUp();
    QString currentPath = dir->path();
    //    QString currentPath = QDir::currentPath();
    //    _htmlDir+=currentPath+"/EChart/";
    _htmlDir+=currentPath+"/PersonalData/EChart/";
    qDebug() << "Current path:" << currentPath;
    version = "v1.0.0";
    setWindowTitle(QString("test").arg(version));
    ui->WebEngineView_radar1->setContextMenuPolicy(Qt::NoContextMenu);
    qDebug()<<QUrl(_htmlDir + _indexFileNameRadar1);
    ui->WebEngineView_radar1->load(QUrl(_htmlDir + _indexFileNameRadar1));

    _indexFileNameRadar2 = "radar2.html";
    ui->WebEngineView_radar2->setContextMenuPolicy(Qt::NoContextMenu);
    ui->WebEngineView_radar2->load(QUrl(_htmlDir + _indexFileNameRadar2));

    _indexFileNameHistogram1 = "Histogram1.html";
    ui->WebEngineView_Histogram1->setContextMenuPolicy(Qt::NoContextMenu);
    ui->WebEngineView_Histogram1->load(QUrl(_htmlDir + _indexFileNameHistogram1));

    _indexFileNameHistogram2 = "Histogram2.html";
    ui->WebEngineView_Histogram2->setContextMenuPolicy(Qt::NoContextMenu);
    ui->WebEngineView_Histogram2->load(QUrl(_htmlDir + _indexFileNameHistogram2));

    _indexFileNameLineBar1 = "LineBarChart1.html";
    ui->WebEngineView_LinBar1->setContextMenuPolicy(Qt::NoContextMenu);
    ui->WebEngineView_LinBar1->load(QUrl(_htmlDir + _indexFileNameLineBar1));

    _indexFileNameLineBar2 = "LineBarChart2.html";
    ui->WebEngineView_LinBar2->setContextMenuPolicy(Qt::NoContextMenu);
    ui->WebEngineView_LinBar2->load(QUrl(_htmlDir + _indexFileNameLineBar2));

}

// 初始化图表数据（本地文件）
void DrawEcharts::initCharts()
{
    qDebug() << "DrawEcharts::initCharts()";
    analyzeEchartsData->initDatas();
}

void DrawEcharts::giveChartsValue(QVector<QVector<double>> inputDatas)
{
    QJsonArray data;
    for(int i=0;i<5;i++){
        int randNum = qrand() % 51;
        data.append(randNum);
    }
    emit drawing(data);

}

void DrawEcharts::writeChartsInfo()
{
    connect(this,&DrawEcharts::drawing,this,&DrawEcharts::DrawingRadar1);
    connect(this,&DrawEcharts::drawing,this,&DrawEcharts::DrawingRadar2);
    connect(this,&DrawEcharts::drawing,this,&DrawEcharts::DrawingHistogram1);
    connect(this,&DrawEcharts::drawing,this,&DrawEcharts::DrawingHistogram2);
    connect(this,&DrawEcharts::drawing,this,&DrawEcharts::DrawingLineBar1);
    connect(this,&DrawEcharts::drawing,this,&DrawEcharts::DrawingLineBar2);
}

QString DrawEcharts::transformJsontoJs(QJsonArray data)
{
    QJsonObject seriesData;
    seriesData.insert("data", data);
    QString optionStr = QJsonDocument(seriesData).toJson();
    QString js = QString("init2(%1)").arg(optionStr);

    return js;
}

void DrawEcharts::setConnect()
{
    connect(this->analyzeEchartsData, &AnalyzeEChartsData::extractMapDataDone1, this, &DrawEcharts::DrawingRadar1);
    connect(this->analyzeEchartsData, &AnalyzeEChartsData::extractMapDataDone1, this, &DrawEcharts::DrawingHistogram1);
    connect(this->analyzeEchartsData, &AnalyzeEChartsData::extractMapDataDone1, this, &DrawEcharts::DrawingLineBar1);

    connect(this->analyzeEchartsData, &AnalyzeEChartsData::extractMapDataDone2, this, &DrawEcharts::DrawingRadar2);
    connect(this->analyzeEchartsData, &AnalyzeEChartsData::extractMapDataDone2, this, &DrawEcharts::DrawingHistogram2);
    connect(this->analyzeEchartsData, &AnalyzeEChartsData::extractMapDataDone2, this, &DrawEcharts::DrawingLineBar2);

    connect(this, &DrawEcharts::getRecChartDatas, this->analyzeEchartsData, &AnalyzeEChartsData::extractMapData);

    connect(ui->WebEngineView_LinBar2, &QWebEngineView::loadFinished, this, &DrawEcharts::initCharts);
}

void DrawEcharts::initRadarToZero()
{
    QJsonObject seriesData;
    QJsonArray data={0,0,0,0,0};
    seriesData.insert("data", data);
    QString optionStr = QJsonDocument(seriesData).toJson();
    QString js = QString("init2(%1)").arg(optionStr);
    ui->WebEngineView_radar1->page()->runJavaScript(js);
}

void DrawEcharts::DrawingRadar1(QJsonArray data)
{
    QString js = transformJsontoJs(data);

    qDebug() << "DrawEcharts::DrawingRadar1::data--" << data;
    qDebug() << "DrawEcharts::DrawingRadar1::js--" << js;


    ui->WebEngineView_radar1->page()->runJavaScript(js);
}

void DrawEcharts::DrawingRadar2(QJsonArray data)
{
    QString js = transformJsontoJs(data);
    ui->WebEngineView_radar2->page()->runJavaScript(js);
}

void DrawEcharts::DrawingHistogram1(QJsonArray data)
{
    QString js = transformJsontoJs(data);
    ui->WebEngineView_Histogram1->page()->runJavaScript(js);
}

void DrawEcharts::DrawingHistogram2(QJsonArray data)
{
    QString js = transformJsontoJs(data);
    ui->WebEngineView_Histogram2->page()->runJavaScript(js);
}

void DrawEcharts::DrawingLineBar1(QJsonArray data)
{
    QString js = transformJsontoJs(data);
    ui->WebEngineView_LinBar1->page()->runJavaScript(js);

}

void DrawEcharts::DrawingLineBar2(QJsonArray data)
{
    QString js = transformJsontoJs(data);
    ui->WebEngineView_LinBar2->page()->runJavaScript(js);
}


DrawEcharts::~DrawEcharts()
{
    delete ui;
}

void DrawEcharts::resizeEvent(QResizeEvent *event)
{

}

void DrawEcharts::handleTimeout()
{
    QJsonArray data;
    for(int i=0;i<5;i++){
        int randNum = qrand() % 51;
        data.append(randNum);
    }
    emit drawing(data);
}
