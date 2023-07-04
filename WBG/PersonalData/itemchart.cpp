#include "itemchart.h"
#include <QChart>
#include <QVector>
#include <numeric>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPolarChart>

const qreal angularMin = 0;

const qreal angularMax = 360;

const qreal radialMin = 0;

const qreal radialMax = 100;

int radialTickCount = 5;

//int angularTickCount = 5;


itemChart::itemChart(QWidget *parent ,QWidget *chart)
{
    parentObject = parent;
    chartObject = chart;
    hLayout = new QHBoxLayout(parentObject);
    hLayout->setContentsMargins(0, 0, 0, 0);
}

void itemChart::showChart(int chartType)
{
    if(chartType==0){
        hLayout->removeWidget(chartView);
        showPolarChart();
    }
    else if(chartType==1){
        hLayout->removeWidget(chartView);
        showLineChart();
    } else if(chartType==2){
        hLayout->removeWidget(chartView);
        showBarChart();
    }

}


void itemChart::showPolarChart()
{
    //准备QChartView对象显示chart
    chartView = new QChartView(chartObject);
    chartView->setContentsMargins(0, 0, 0, 0);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setFocusPolicy(Qt::NoFocus);

    //准备极坐标对象
    polarChart = new QPolarChart();
    polarChart->setBackgroundVisible(false);
    polarChart->setTheme(QChart::ChartThemeBlueCerulean);
    chartView->setChart(polarChart);
    polarChart->setFocusPolicy(Qt::NoFocus);
    polarChart->legend()->hide();


    // 准备维度信息
    dimensionName = getDimensionName();
    int angularTickCount = dimensionName.size();


    //得到显示数据
    QVector<double> datas = getShowSumDatas(angularTickCount);

    // 获取序列最大值和最小值
    double biggest = calculateDataMax(datas);
    double smallest = calculateDataMin(datas);

    //准备series1序列
    QLineSeries *series1 = new QLineSeries();
    int num = 0;
    for (int i=0; i<360 ;i+=(360/angularTickCount)) {

        series1->append(i, datas.at(num));
        num++;
    }
//    initSeries();

    QLineSeries *series2 = new QLineSeries();

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(0.0, 0x3cc63c);
    gradient.setColorAt(1.0, 0x5BC2E7);
    QAreaSeries *areaSeries = new QAreaSeries(series1, series2);
    areaSeries->setOpacity(0.5);
//    areaSeries->setName("能力值");
    areaSeries->setBrush(gradient);


    //将散点序列添加到chart对象
    polarChart->addSeries(areaSeries);

    //准备坐标轴对象
    QCategoryAxis *angularAxis = new QCategoryAxis();
    angularAxis->setTickCount(angularTickCount);

    int num2 = 0;
    for (int i = angularMin; i<angularMax; i+=(angularMax/angularTickCount)){
        angularAxis->append(dimensionName.at(num2) ,i);
        num2 += 1;
    }

    angularAxis->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);

    polarChart->addAxis(angularAxis, QPolarChart::PolarOrientationAngular);

    QValueAxis *radialAxis = new QValueAxis();

    radialAxis->setTickCount(radialTickCount);

    radialAxis->setLabelFormat("%d");

    radialAxis->setLabelsVisible(true);

    polarChart->addAxis(radialAxis, QPolarChart::PolarOrientationRadial);

    if(biggest==0){
        radialAxis->setRange(radialMin, radialMax);
    }else{
        if(smallest>0){
            radialAxis->setRange(radialMin, biggest);
        }else{
            radialAxis->setRange(smallest, biggest);
        }
    }

    angularAxis->setRange(angularMin, angularMax);

    areaSeries->attachAxis(radialAxis);

    areaSeries->attachAxis(angularAxis);

    hLayout->addWidget(chartView);

    chartObject->setLayout(hLayout);
}

void itemChart::showLineChart()
{
    chartView = new QChartView(chartObject);
    chartView->setContentsMargins(0, 0, 0, 0);
    chartView->setFocusPolicy(Qt::NoFocus);

    chart = new QChart();
    chart->setTheme(QChart::ChartThemeBlueCerulean);
    chart->legend()->hide();
    chart->setBackgroundVisible(false);
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // 准备维度信息
    dimensionName = getDimensionName();
    int dimNum = dimensionName.size();

    //得到显示数据
    QVector<double> datas = getShowSumDatas(dimNum);

    // 获取序列最大值和最小值
    double biggest = calculateDataMax(datas);
    double smallest = calculateDataMin(datas);

//    qDebug() << datas.at(2);

    //准备series序列
    QLineSeries *series = new QLineSeries();
    int num = 0;

    int zeroFlag = 1;

    for (int i=0; i<360 ;i+=(360/dimNum)) {
//        qDebug() << datas.at(num);
        if(datas.at(num) != 0){
            zeroFlag = 0;
        }
        series->append(i, datas.at(num));
        num++;
    }
//    series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
//    series->setPointLabelsFormat("@yPoint");
//    series->setPointLabelsVisible();

    chart->addSeries(series);


    //准备坐标轴对象
    QCategoryAxis *axisX = new QCategoryAxis();
    axisX->setRange(0, dimensionName.size()-1);
    axisX->setTitleText("能力");

    //下边这一句代码的作用是让刻度线和刻度的label对齐
    axisX->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);

    axisX->setLabelsAngle(60);

    for (int i = 0; i<dimensionName.size(); i+=1){
//        qDebug()<<dimensionName.at(i);
        axisX->append(dimensionName.at(i) ,i);
    }

    QValueAxis *axisY = new QValueAxis; //Y 轴
    if(biggest==0){
        axisY->setRange(radialMin, radialMax);
    }else{
        if(smallest>0){
            axisY->setRange(0, biggest+10);
        }else{
            axisY->setRange(smallest, biggest+10);
        }
    }

    axisY->setTitleText("总数值");
    axisY->setLabelFormat("%.2f"); //标签格式
    axisY->setTickCount(10);
//    axisY->setMinorTickCount(4);

    //图表添加坐标轴
    if (zeroFlag!=0){
        chart->addAxis(axisX, Qt::AlignBottom);
        chart->addAxis(axisY, Qt::AlignLeft);
    }else{
        chart->createDefaultAxes();
        chart->setAxisX(axisX);
    }


//    series->attachAxis(axisX);
//    series->attachAxis(axisY);

    hLayout->addWidget(chartView);
    chartObject->setLayout(hLayout);

}


void itemChart::showBarChart()
{
    chartView = new QChartView(chartObject);
    chartView->setContentsMargins(0, 0, 0, 0);
    chartView->setFocusPolicy(Qt::NoFocus);

    chart = new QChart();
    chart->setTheme(QChart::ChartThemeBlueCerulean);
    chart->setBackgroundVisible(false);
    chartView->setChart(chart);

    // 准备维度信息
    dimensionName = getDimensionName();
    int dimSize = dimensionName.size();

    //得到显示数据
    QVector<QVector<double>> datas = getShowDatas(dimSize);

    QVector<double> maxDatas, minDatas;
//    qDebug()<<"第一处";
//    qDebug()<<"维度大小："<<dimSize;
//    qDebug()<<"数据二维大小："<<datas.at(1).size();
    for(int i=0;i<dimSize;i++)
    {
        double max = calculateDataMax(datas.at(i));
        double min = calculateDataMin(datas.at(i));
        maxDatas.append(max);
        minDatas.append(min);
    }
//    qDebug()<<"第二处";
    // 获取序列最大值和最小值
    double biggest = calculateDataMax(maxDatas);
    double smallest = calculateDataMin(minDatas);


    //准备series序列
    QBarSeries *series = new QBarSeries();


    for(int i=0;i<dimSize;i+=1){
        QBarSet *set = new QBarSet(dimensionName.at(i));
        QVector<double> dimDatas = datas.at(i);
        for(int j=0;j<dimDatas.size();j+=1){
            set->append(dimDatas.at(j));
        }
        series->append(set);
    }

    series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    series->setLabelsVisible();

    chart->addSeries(series);

    //准备坐标轴对象
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
//    axisX->setRange(0, "1");

    for(int i=0;i<datas.at(0).size();i+=1){
        axisX->append(QString("第"+QString::number(i+1)+"组"));
    }


    QValueAxis *axisY = new QValueAxis();
    if(biggest==0){
        axisY->setRange(radialMin, radialMax);
    }else{
        if(smallest>0){
            axisY->setRange(0, biggest+10);
        }else{
            axisY->setRange(smallest, biggest+10);
        }
    }


    //图表添加坐标轴
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    hLayout->addWidget(chartView);
    chartObject->setLayout(hLayout);
}

QVector<QVector<double>> itemChart::getChartDatas() const
{
    return chartDatas;
}

void itemChart::setChartDatas(const QVector<QVector<double> > &value)
{
    chartDatas = value;
}

QStringList itemChart::getDimensionName() const
{
    return dimensionName;
}

void itemChart::setDimensionName(QStringList value)
{
    dimensionName = value;
}

double itemChart::calculateDataSum(QVector<double> value)
{
    double result = 0;
    for(int i=0;i<value.size();i++){
        result += value.at(i);
    }
    return result;
}

double itemChart::calculateDataMax(QVector<double> value)
{
    auto max = std::max_element(std::begin(value), std::end(value));
    double biggest = *max;
    return biggest;
}

double itemChart::calculateDataMin(QVector<double> value)
{
    auto min = std::min_element(std::begin(value), std::end(value));
    double smallest = *min;
    return smallest;
}

QVector<double> itemChart::getShowSumDatas(int dimSize)
{
    QVector<double> datas;
    if(getChartDatas().size()==0){
        for (int i = 0; i < dimSize; ++i) {
             datas.append(0);
        }
    }else{
        for(int i=0;i<getChartDatas().size();i++){

            QVector<double> data = getChartDatas().at(i);
            double sum = calculateDataSum(data);
            datas.append(sum);
        }
    }


    return datas;
}

QVector<QVector<double> > itemChart::getShowDatas(int dimSize)
{
    QVector<QVector<double>> datas;

    if(getChartDatas().size()==0)
    {
        for(int i=0;i<dimSize;i++){
            QVector<double> data ={0};
            datas.append(data);
        }
    }
    else
    {
        for(int i=0;i<getChartDatas().size();i++){
            QVector<double> data = getChartDatas().at(i);
            datas.append(data);
        }
    }
    return datas;
}





