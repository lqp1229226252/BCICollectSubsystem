#ifndef PERSONALDATA_H
#define PERSONALDATA_H

#include <QWidget>

#include <QtCharts>
#include <qlayout.h>
#include <QMap>

namespace Ui {
class PersonalDataWidget;
}

class PersonalDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalDataWidget(QWidget *parent = nullptr);
    ~PersonalDataWidget();

    QStringList getLeftDateNameItem() const;
    void setLeftDateNameItem(const QStringList &value);

    QStringList getRightDateNameItem() const;
    void setRightDateNameItem(const QStringList &value);

    QVector<QVector<double> > getLeftValue() const;
    void setLeftValue(const QVector<QVector<double> > &value);

    QVector<QVector<double> > getRightValue() const;
    void setRightValue(const QVector<QVector<double> > &value);

    QStringList getLeftDimName() const;
    void setLeftDimName(const QStringList &value);

    QStringList getRightDimName() const;
    void setRightDimName(const QStringList &value);


    int getCurrentLeftChartType() const;
    void setCurrentLeftChartType(int value);

    int getCurrentRightChartType() const;
    void setCurrentRightChartType(int value);

private slots:

//    void on_chart_change_left_currentIndexChanged(int index);

//    void on_chart_change_right_currentIndexChanged(int index);

signals:
    void repeatChartsSignal(QVector<QVector<double>>,QVector<QVector<double>>);

private:
    Ui::PersonalDataWidget *ui;

    QChartView *chartView;
    QPolarChart *chart;
    QVector<QVector<double>> leftValue,rightValue;
    QStringList leftDimName,rightDimName;
    QStringList leftDateNameItem, rightDateNameItem;
    QString mFolderPath;
    int currentLeftChartType,currentRightChartType;

    QLabel *bgLabel;

    void initPager();

    void initChartLayout();
    void initConnetion();
    void initFolderPath();
    void initDimName();
    void initDatas();
    QString getNewBCIFile();
    QMap<QString, double> readNewBCIFileContent(QString path);
    void initChart();
    void initCart();
    void repaintChart();
    void getRecChartDatas(QMap<QString,double> radarData);
    void parseChartDatas(QMap<QString,double> radarData);

//    void timerEvent(QTimerEvent *event) override;
    void addChartValue(int chartType, QMap<QString, double> radarData, QString key);
    QVector<QVector<double>> dataTranspose(QVector<QVector<double>> dimValues);


};

#endif // PERSONALDATA_H
