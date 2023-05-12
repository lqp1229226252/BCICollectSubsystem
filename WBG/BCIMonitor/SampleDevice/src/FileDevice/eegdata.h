#ifndef EEGDATA_H
#define EEGDATA_H

#include "QList"
#include "QByteArray"
class EEGData
{
public:
    EEGData();
    void setData(QByteArray);
    void setData(QString name);
    void setCh_names(const QStringList &value);
    void setCh_names(QByteArray value);
    void clear();
    QList<double> getData();
    QStringList getCh_names() const;

private:
    QVector<QVector<double>> data;
    QStringList ch_names;
    void analysis(QByteArray);
    int data_index;
};

#endif // EEGDATA_H
