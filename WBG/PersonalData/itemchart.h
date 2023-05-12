#ifndef PERSONALDATACHART_H
#define PERSONALDATACHART_H
#include <QtCharts>
#include <qlayout.h>
#include "personaldatawidget.h"

class itemChart
{
public:
    itemChart(QWidget *parent,QWidget *chartObject);

    QStringList getDimensionName() const;
    void setDimensionName(QStringList value);
    // 第一个参数为图表类型   如: 0:雷达图 1:折线图 2:条形图  默认为0
    void showChart(int chartType=0);
    void showPolarChart();
    void showLineChart();
    void showBarChart();

    void initSeries();
//    QVector<double> getChartDatas() const;
//    void setChartDatas(QVector<double> value);

    QVector<QVector<double> > getChartDatas() const;
    void setChartDatas(const QVector<QVector<double> > &value);

    double calculateDataSum(QVector<double> value);
    double calculateDataMax(QVector<double> value);
    double calculateDataMin(QVector<double> value);
    QVector<double> getShowSumDatas(int dimSize);
    QVector<QVector<double>> getShowDatas(int dimSize);


private:
    QWidget *parentObject, *chartObject;
    QChartView *chartView;
    QPolarChart *polarChart;
    QChart *chart;
    QVector<QVector<double>> chartDatas;
    QHBoxLayout *hLayout;
    QStringList dimensionName;
};



#endif // PERSONALDATACHART_H
