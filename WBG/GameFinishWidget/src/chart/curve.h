#ifndef CURVE_H
#define CURVE_H

#include <QWidget>

namespace Ui {
class Curve;
}

class Curve : public QWidget
{
    Q_OBJECT

public:
    explicit Curve(QWidget *parent = nullptr);
    ~Curve();
    void setSeriesname(QStringList);
    void append(QList<double> data);

private:
    Ui::Curve *ui;
};

#endif // CURVE_H
