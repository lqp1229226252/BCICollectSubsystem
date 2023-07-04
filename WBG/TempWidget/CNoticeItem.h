#ifndef CNOTICEITEM_H
#define CNOTICEITEM_H

#include <QWidget>

namespace Ui {
class CNoticeItem;
}

class CNoticeItem : public QWidget
{
    Q_OBJECT

public:
    explicit CNoticeItem(QWidget *parent = nullptr);
    ~CNoticeItem();

private:
    Ui::CNoticeItem *ui;
};

#endif // CNOTICEITEM_H
