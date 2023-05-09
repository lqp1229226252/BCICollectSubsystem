#ifndef WELFARECENTER_H
#define WELFARECENTER_H

#include <QWidget>

namespace Ui {
class WelfareCenter;
}

class WelfareCenter : public QWidget
{
    Q_OBJECT

public:
    explicit WelfareCenter(QWidget *parent = nullptr);
    ~WelfareCenter();

    void setData(const QString title, const QString content);

private:
    Ui::WelfareCenter *ui;
};

#endif // WELFARECENTER_H
