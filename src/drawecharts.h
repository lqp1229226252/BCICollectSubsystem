#ifndef DRAWECHARTS_H
#define DRAWECHARTS_H

#include "analyzeechartsdata.h"
#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEngineProfile>
#include <QFile>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QWebChannel>
#pragma execution_character_set("utf-8")

namespace Ui {
class DrawEcharts;
}

class DrawEcharts : public QWidget
{
    Q_OBJECT

public:
    explicit DrawEcharts(QWidget *parent = nullptr);
    ~DrawEcharts();
    void initJs();
    void resizeEvent(QResizeEvent *event);
    void test();
    QTimer *m_pTimer;


signals:
    void drawing(QJsonArray data);
    void getRecChartDatas(QMap<QString, double>);

public slots:
    void giveChartsValue(QVector<QVector<double>> inputDatas);
    void initRadarToZero();

    void DrawingRadar1(QJsonArray data);
    void DrawingRadar2(QJsonArray data);

    void DrawingHistogram1(QJsonArray data);
    void DrawingHistogram2(QJsonArray data);

    void DrawingLineBar1(QJsonArray data);
    void DrawingLineBar2(QJsonArray data);

    //测试用
    void handleTimeout();


private:
    Ui::DrawEcharts *ui;
    void initialize();
    void initCharts();
    void writeChartsInfo();
    QString transformJsontoJs(QJsonArray);
    void setConnect();
    QWebEngineView *_pWebEngineView;            // 浏览器窗口
    QString filePath;
    QString version;                            //版本
    QString _htmlDir;
    //雷达图 html文件夹路径
    QString _indexFileNameRadar1;               // html文件
    QString _indexFileNameRadar2;
    // 柱状图html文件
    QString _indexFileNameHistogram1;           // html文件
    QString _indexFileNameHistogram2;
    // 线状图html文件
    QString _indexFileNameLineBar1;           // html文件
    QString _indexFileNameLineBar2;
    QString _initJsStr;                         // 第一次初始化的表格

    // 解析数据
    AnalyzeEChartsData *analyzeEchartsData;

};

#endif // DRAWECHARTS_H
