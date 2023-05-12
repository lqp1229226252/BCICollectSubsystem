#ifndef PROCESSDATA_H
#define PROCESSDATA_H

#include <QObject>

class ProcessData : public QObject
{
    Q_OBJECT
public:
    explicit ProcessData(QObject *parent = nullptr);
    void setSrate(const quint16 &value);
public slots:
    void receiveData(QList<double>);
signals:
    void downData(QString);
private:
    QVector<QList<double>> data;
    quint16 down_sample;
};

#endif // PROCESSDATA_H
