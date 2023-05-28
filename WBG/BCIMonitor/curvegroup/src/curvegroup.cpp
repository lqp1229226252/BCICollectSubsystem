#include "curvegroup.h"
#define defalut_curve_num 5
#define defalut_max_point 200
CurveGroup::CurveGroup(QWidget *parent):QWidget(parent)
{
    init();
    setConnect();
    initLayout();
    // 设置图表主题
    setCurveStyle();
}

CurveGroup::~CurveGroup()
{
    delete  curvewnd;
    qDeleteAll(seriespoint);
    seriespoint.clear();
}

void CurveGroup::init()
{
    curvewnd=new CurveWnd(this);
    widget_layout=new QHBoxLayout;
    this->curvewnd->lower();
    this->curve_num_group=defalut_curve_num;
    this->curve_num=defalut_curve_num;
    this->group_num=1;
    this->max_point=defalut_max_point;
    this->current_group=0;
    this->scale=1;
}

void CurveGroup::setConnect()
{
    connect(curvewnd,&CurveWnd::CurrentData,this,&CurveGroup::CurrentData);
}
void CurveGroup::initLayout()
{
    this->widget_layout->addWidget(curvewnd);
    this->setLayout(widget_layout);
}
void CurveGroup::setCurveNumGroup(int num)
{
    this->curve_num_group=num;
    this->curvewnd->setCurveNum(num);
}

void CurveGroup::setCurveNum(int num)
{
    this->curve_num=num;
    this->group_num=(curve_num-1)/curve_num_group;
    //初始化曲线数据
    for(int i=0;i<num;i++)
    {
        SeriesPoint *seriepoint=new SeriesPoint();
        seriepoint->setMaxPointNum(this->max_point);
        seriespoint.append(seriepoint);
    }
}
void CurveGroup::setMaxPoint(int num)
{
    this->max_point=num;
    this->curvewnd->setMaxPoint(num);
}

void CurveGroup::setCurveLabels(QStringList labels)
{
    this->labels=labels;
    QStringList show_labels;
    for(int i=0;i<curve_num_group;i++)
    {
        show_labels.append(labels[i+current_group*curve_num_group]);
    }
    this->curvewnd->setCurveLabels(show_labels);
}

void CurveGroup::appendMark(QString mark)
{
    curvewnd->appendMark(mark);
}
void CurveGroup::append(QList<double> data)
{
    QList<double> show_data;
    QList<double>::const_iterator begin=data.begin();
    QList<double>::const_iterator::difference_type n=current_group*curve_num_group;
    int num=curve_num-current_group*curve_num_group;
    for(int i=0;(i<curve_num_group)&&(i<num);i++)
    {
        show_data.append(*(begin+n));
        begin++;
    }
    curvewnd->append(show_data);
}

void CurveGroup::next()
{
    if(current_group==group_num)
    {
        return;
    }
    else
    {
        this->curvewnd->clear();
        this->current_group++;
        QStringList show_labels;
        for(int i=0;i<curve_num_group&&i<(curve_num-current_group*curve_num_group);i++)
        {
            show_labels.append(labels[i+current_group*curve_num_group]);
        }
        if(show_labels.size()<curve_num_group)
        {
            //更新通道数
            curvewnd->updateCurveNum(show_labels.size());
            //更新通道名字
            curvewnd->setCurveLabels(show_labels);
        }
        else
        {
            this->curvewnd->updateCurveLabels(show_labels);
        }
        if(current_group==group_num)
        {
            emit end_group();
        }
    }


}

void CurveGroup::last()
{
    if(current_group==0)
    {
        return;
    }
    else
    {
        this->curvewnd->clear();
        this->current_group--;
        QStringList show_labels;
        for(int i=0;i<curve_num_group;i++)
        {
            show_labels.append(labels[i+current_group*curve_num_group]);
        }
        if(curvewnd->getCurveNum()<curve_num_group)
        {
            //更新通道数
            curvewnd->updateCurveNum(show_labels.size());
            //更新通道名字
            curvewnd->setCurveLabels(show_labels);
        }
        else
        {
            this->curvewnd->updateCurveLabels(show_labels);
        }
        if(current_group==0)
        {
            emit first_group();
        }
    }
}

void CurveGroup::timerEvent(QTimerEvent *event)
{
    //模拟数据
    QList<double> data;
    int y=rand();
    for (int i = 0; i < this->curve_num; i++)
    {
        double chart_data = 5*cos(3.14 * y)+2*cos(3.14*y*2);
        data.append(chart_data);
    }
    this->append(data);
}
void CurveGroup::setScale(int value)
{
    curvewnd->setScale(value);
}

void CurveGroup::increaseScale()
{
    curvewnd->increaseScaleFactor();
}

void CurveGroup::reduceScale()
{
    curvewnd->reduceScaleFactor();
}

void CurveGroup::reduceGroupChannel()
{
    if(curve_num_group>1)
    {
        curve_num_group--;
        //组页重置0
        current_group=0;
        //更新通道数
        curvewnd->updateCurveNum(curve_num_group);
        //更新通道名字
        setCurveLabels(this->labels);
        //更新组数
        group_num=(curve_num-1)/curve_num_group;

    }
}
void CurveGroup::increaseGroupChannel()
{
    if(curve_num_group<8)
    {
        curve_num_group++;
        //组页重置0
        current_group=0;
        //更新通道数
        curvewnd->updateCurveNum(curve_num_group);
        //更新通道名字
        setCurveLabels(this->labels);
        //更新组数
        group_num=(curve_num-1)/curve_num_group;
    }

}
void CurveGroup::test_chart()
{
    startTimer(1);
}
CurveWnd *CurveGroup::getCurveWnd(){
    return this->curvewnd;
}

void CurveGroup::setCurveStyle()
{
    // 设置图表主题
    this->getCurveWnd()->getChart()->setTheme(QChart::ChartThemeDark);
}

