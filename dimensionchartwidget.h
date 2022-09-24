#ifndef DIMENSIONCHARTWIDGET_H
#define DIMENSIONCHARTWIDGET_H

#include <QMap>
#include <QPen>
#include <QObject>
#include <QWidget>

class DimensionInfo;
class DimensionChartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DimensionChartWidget(QWidget *parent = nullptr);

    inline QColor backgroundColor() const { return m_backgroundColor; }
    inline void setBackgroundColor(const QColor &backgroundColor) { m_backgroundColor = backgroundColor; }

    inline float radius() const { return m_radius; }
    inline void setRadius(float radius) { m_radius = radius; }

    inline int sidesNumber() const { return m_sidesNumber; }
    inline void setSidesNumber(int sidesNumber) {m_sidesNumber = sidesNumber; }

    inline QPen sidesPen() const { return m_sidesPen; }
    inline void setSidesPen(const QPen &sidesPen) { m_sidesPen = sidesPen; }

    inline QVector<DimensionInfo> dimensionInfos() const { return m_dimensionInfos; }
    inline void setDimensionInfos(const QVector<DimensionInfo> &dimensionInfos) { m_dimensionInfos = dimensionInfos; }

    inline QPen textPen() const { return m_textPen; }
    inline void setTextPen(const QPen &textPen) { m_textPen = textPen; }

    inline QPen dimensionPen() const { return m_dimensionPen; }
    inline void setDimensionPen(const QPen &dimensionPen) { m_dimensionPen = dimensionPen; }

    inline QFont textFont() const { return m_textFont; }
    inline void setTextFont(const QFont &textFont) { m_textFont = textFont; }

    inline int filletRadius() const { return m_filletRadius; }
    inline void setFilletRadius(int filletRadius) { m_filletRadius = filletRadius; }

protected:
    void paintEvent(QPaintEvent*);
    void drawText(QPainter&, QPointF, QString text);
    void convertPoint(QPointF&);

private:
    QPen m_textPen;
    QPen m_sidesPen;
    QPen m_dimensionPen;
    QFont m_textFont;
    QColor m_backgroundColor;

    int m_filletRadius;
    float m_radius;
    int m_sidesNumber;
    QVector<DimensionInfo> m_dimensionInfos;
};


class DimensionInfo {
public:
    DimensionInfo() = default;
    DimensionInfo(QString text, float percentage) { m_text = text; m_percentage = percentage; }

    inline QString text() const { return m_text; }
    inline void setText(const QString &text) { m_text = text; }

    inline float percentage() const { return m_percentage; }
    inline void setPercentage(float percentage) { m_percentage = percentage; }

private:
    QString m_text;
    float m_percentage;
};
#endif // DIMENSIONCHARTWIDGET_H

