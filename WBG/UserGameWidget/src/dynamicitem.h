#ifndef DYNAMICITEM_H
#define DYNAMICITEM_H

#include <QWidget>
#include "dynamicdata.h"
namespace Ui {
class DynamicItem;
}

class DynamicItem : public QWidget
{
    Q_OBJECT

public:
    explicit DynamicItem(QWidget *parent = nullptr);
    ~DynamicItem();
    void setDynamicData(DynamicData data);
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::DynamicItem *ui;
};

#endif // DYNAMICITEM_H
