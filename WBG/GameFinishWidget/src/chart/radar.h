#ifndef RADAR_H
#define RADAR_H

#include <QWidget>

namespace Ui {
class Radar;
}

class Radar : public QWidget
{
    Q_OBJECT

public:
    explicit Radar(QWidget *parent = nullptr);
    ~Radar();
    void setRadarLabel(QStringList);
    void setData(QList<double> data);
private:
    Ui::Radar *ui;
};

#endif // RADAR_H
