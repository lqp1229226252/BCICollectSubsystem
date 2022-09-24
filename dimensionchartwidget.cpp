#include "dimensionchartwidget.h"
#include <QPainter>
#include <QtMath>
#include <QDebug>
#include <QPainterPath>

DimensionChartWidget::DimensionChartWidget(QWidget *parent) : QWidget(parent)
{
    m_radius = 0;
    m_sidesNumber = 1;
}

void DimensionChartWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(QColor(m_backgroundColor));
    painter.setBrush(QBrush(m_backgroundColor));
    painter.drawRoundedRect(rect(), m_filletRadius, m_filletRadius);

    // 绘图设备的坐标原点（0,0)在左上角，水平向右增长，垂直向下增长。
    // 将坐标系原点移动到界面中间
    painter.translate(width() / 2.0, height() / 2.0);

    // 设中心点到边的垂线与半径的夹角为degree=（360/count)/2
    float degree = 360.0 / m_dimensionInfos.size();

    // 开始绘制多边形，并为每个区域上色
    painter.setPen(m_sidesPen);
    QPointF lastPoint(0, -m_radius);
    QVector<QPointF> points;
    for(int i = 0; i < m_dimensionInfos.size(); i++)
    {
        float radian = qDegreesToRadians(degree * (i + 1));
        float x = m_radius * qSin(radian);
        float y = m_radius * qCos(radian);

        // 绘制该三角区块
        QPainterPath path;
        QPointF point(x, -y);
        path.lineTo(point);
        path.lineTo(lastPoint);
        path.lineTo(0, 0);
        painter.drawPath(path);

        //  绘制内线
        for(int j = m_sidesNumber - 1; j > 0; j--)
        {
            float multiple = (float)j / m_sidesNumber;
            painter.drawLine(point * multiple, lastPoint * multiple);
        }

        // 绘制文本
        painter.save();
        painter.setPen(m_textPen);
        painter.setFont(m_textFont);
        drawText(painter, point, m_dimensionInfos.at(i).text());
        painter.restore();

        lastPoint = point;
        points << point * m_dimensionInfos.at(i).percentage();
    }

    // 绘制维度信息
    painter.setPen(m_dimensionPen);
    QColor color = m_dimensionPen.color();
    color.setAlpha(150);
    painter.setBrush(QBrush(color));
    QPolygonF polygon(points);
    QPainterPath painterPath;
    painterPath.addPolygon(polygon);
    painter.drawPolygon(polygon);
}

/**
 * @brief DimensionChartWidget::drawText 绘制文本
 */
void DimensionChartWidget::drawText(QPainter& painter, QPointF point, QString text)
{
    //TODO // 这一部分要是有好的想法可以交流一下
    convertPoint(point);
    QRectF textRect;
    textRect.setSize(QSize(50, 30));
    int flag = Qt::AlignCenter;
    if(point.x() > 0)
    {
        if(point.y() < 0)
        {
            //x > 0 y < 0
//            textRect.moveCenter();
            textRect.setBottomLeft(point);
            textRect.setTopRight(QPoint(point.x() + 50, point.y() - 30));
            flag = Qt::AlignBottom | Qt::AlignLeft;
        }
        else if(point.y() > 0)
        {
            //x>0 y>0
            textRect.setTopLeft(point);
            textRect.setBottomRight(QPoint(point.x() + 50, point.y() + 30));
            flag = Qt::AlignTop | Qt::AlignLeft;
        }
        else
        {
            //x>0 y=0
            point.setY(point.y() - 15);
            textRect.setTopLeft(point);
            textRect.setBottomRight(QPoint(point.x() + 50, point.y() + 30));
            flag = Qt::AlignVCenter | Qt::AlignLeft;
        }
    }
    else if(point.x() < 0)
    {
        if(point.y() < 0)
        {
            //x<0 y<0
            textRect.setBottomRight(point);
            textRect.setTopLeft(QPoint(point.x() - 50, point.y() - 30));
            flag = Qt::AlignBottom | Qt::AlignRight;
        }
        else if(point.y() > 0)
        {
            //x<0 y>0
            textRect.setTopRight(point);
            textRect.setBottomLeft(QPoint(point.x() - 50, point.y() + 30));
            flag = Qt::AlignTop | Qt::AlignRight;
        }
        else
        {
            //x<0 y=0
            point.setY(point.y() - 15);
            textRect.setTopRight(point);
            textRect.setBottomLeft(QPoint(point.x() - 50, point.y() + 30));
            flag = Qt::AlignVCenter | Qt::AlignRight;
        }
    }
    else
    {
        if(point.y() < 0)
        {
            //x=0 y<0
            point.setX(point.x() - 25);
            textRect.setBottomRight(point);
            textRect.setTopLeft(QPoint(point.x() + 50, point.y() - 30));
            flag = Qt::AlignHCenter | Qt::AlignBottom;
        }
        else if(point.y() > 0)
        {
            //x=0 y>0
            point.setX(point.x() - 25);
            textRect.setTopLeft(point);
            textRect.setBottomRight(QPoint(point.x() + 50, point.y() + 30));
            flag = Qt::AlignHCenter | Qt::AlignTop;
        }
    }
    painter.drawText(textRect, flag, text);
}

/**
 * @brief DimensionChartWidget::convertPoint 通过三角函数换算的坐标在这里插入代码片误差大，这里对0进行校正
 * @param point 坐标
 */
void DimensionChartWidget::convertPoint(QPointF& point)
{
    if(qAbs(point.x()) < 0.001)
    {
        point.setX(0);
    }
    else if(qAbs(point.y()) < 0.001)
    {
        point.setY(0);
    }
}
