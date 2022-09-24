#ifndef PERSONALDATA_H
#define PERSONALDATA_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class PersonalData; }
QT_END_NAMESPACE

class PersonalData : public QWidget
{
    Q_OBJECT

public:
    PersonalData(QWidget *parent = nullptr);
    ~PersonalData();

public slots:
    void initRadarChart();
    void paintEvent(QPaintEvent *);
    void gameStyle();
    void detailedData();
private:
    Ui::PersonalData *ui;
};
#endif // PERSONALDATA_H
