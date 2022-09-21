#ifndef INTRODUCEWIDGET_H
#define INTRODUCEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class IntroduceWidget; }
QT_END_NAMESPACE

class IntroduceWidget : public QWidget
{
    Q_OBJECT

public:
    IntroduceWidget(QWidget *parent = nullptr);
    ~IntroduceWidget();
    void  init();

private:
    Ui::IntroduceWidget *ui;
};
#endif // INTRODUCEWIDGET_H
