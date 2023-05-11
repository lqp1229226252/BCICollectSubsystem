#ifndef ANALYZEECHARTSDATA_H
#define ANALYZEECHARTSDATA_H

#include <QObject>
#include <QJsonArray>
#include <QMap>

class AnalyzeEChartsData : public QObject
{
    Q_OBJECT
public:
    explicit AnalyzeEChartsData(QObject *parent = nullptr);
    virtual~AnalyzeEChartsData();

    QString getNewBCIFile();

    QMap<QString, double> readNewBCIFileContent(QString path);

    void initDatas();


public slots:
    void extractMapData(QMap<QString, double>);


signals:
    void extractMapDataDone1(QJsonArray);
    void extractMapDataDone2(QJsonArray);

private:
    void init();

    // 初始化文件路径
    void initFolderPath();

   // 文件路径
    QString mFolderPath;
};

#endif // ANALYZEECHARTSDATA_H
