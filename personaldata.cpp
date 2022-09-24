#include "personaldata.h"
#include "ui_personaldata.h"
#include "dimensionchartwidget.h"
#include <QPen>
#include <QPainter>
#include <QPixmap>
#include <QLabel>

PersonalData::PersonalData(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PersonalData)
{
    ui->setupUi(this);


    initRadarChart();
}

PersonalData::~PersonalData()
{
    delete ui;

}

void PersonalData::gameStyle(){
    QImage *img=new QImage; //新建一个image对象
    img->load("qrc:/Image/a.png");
    ui->label_gameStyle->setPixmap(QPixmap::fromImage(*img));
//    ui->label_gameStyle->setScaledContents(true);

}

void PersonalData::detailedData(){
    QPainter p;//创建画家对象
    p.begin(ui->widget_detailedData);
    QPixmap tempPixmap = QPixmap("qrc:/Image/a.png");
    p.drawPixmap(0, 0,401,241, tempPixmap);

}

void PersonalData::paintEvent(QPaintEvent *)
{
    QPainter painter(ui->widget_radar);
    painter.setPen(QPen(QColor("#1A1A1A")));
    painter.setBrush(QBrush(QColor("#1A1A1A")));
//    painter.drawRect(rect());
}

void PersonalData::initRadarChart(){
        DimensionChartWidget* pDimensionChartWidget = new DimensionChartWidget(ui->widget_radar);
        pDimensionChartWidget->resize(ui->widget_radar->width(),ui->widget_radar->height());
//        pDimensionChartWidget->move(30, 30);

        // 设置维度网格数量
        pDimensionChartWidget->setSidesNumber(5);

        // 设置维度边长
        pDimensionChartWidget->setRadius(120);

        // 设置维度网格画笔
        QPen sidesPen;
        sidesPen.setColor(QColor("#003545"));
        sidesPen.setWidth(2);
        pDimensionChartWidget->setSidesPen(sidesPen);

        // 设置维度画笔
        QPen dimensionPen;
        dimensionPen.setColor(QColor("#0095C5"));
        dimensionPen.setWidth(3);
        pDimensionChartWidget->setDimensionPen(dimensionPen);

        // 设置字体信息
        QPen textPen;
        textPen.setColor(Qt::GlobalColor::white);
        pDimensionChartWidget->setTextPen(textPen);
        QFont textFont;
        textFont.setFamily("微软雅黑");
        textFont.setPointSize(10);
        pDimensionChartWidget->setTextFont(textFont);

        // 设置维度信息
        QVector<DimensionInfo> dimensionInfos;
        DimensionInfo dimensionInfo("维度1", 0.85);
        dimensionInfos.append(dimensionInfo);

        dimensionInfo.setText("维度2");
        dimensionInfo.setPercentage(0.85);
        dimensionInfos.append(dimensionInfo);

        dimensionInfo.setText("维度3");
        dimensionInfo.setPercentage(0.95);
        dimensionInfos.append(dimensionInfo);

        dimensionInfo.setText("维度4");
        dimensionInfo.setPercentage(0.75);
        dimensionInfos.append(dimensionInfo);

        dimensionInfo.setText("维度5");
        dimensionInfo.setPercentage(0.65);
        dimensionInfos.append(dimensionInfo);
        pDimensionChartWidget->setDimensionInfos(dimensionInfos);

}
