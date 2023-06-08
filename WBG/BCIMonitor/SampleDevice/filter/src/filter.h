#ifndef FILTER_H
#define FILTER_H
#include "QList"
#include "iirfilter.h"
class  Filter
{
public:
    Filter();
    QList<double> filterData(QList<double> data);
private:
    IIRFILTER *iirfilter;
};

#endif // FILTER_H
