#include "filter.h"

Filter::Filter()
{
    iirfilter=new IIRFILTER();
}

QList<double> Filter::filterData(QList<double> data)
{
    int num=data.size();
    for(int i=0;i<32;i++)
    {
        //高通滤波
        data[i]=iirfilter->iir(&iirfilter->ah[0][0],&iirfilter->bh[0][0],&iirfilter->matrixh[i][0][0],data[i],2);
        //低通滤波
        data[i]=iirfilter->iir(&iirfilter->al[0][0],&iirfilter->bl[0][0],&iirfilter->matrixl[i][0][0],data[i],2);
    }
    return data;
}
