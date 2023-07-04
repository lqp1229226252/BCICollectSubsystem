#ifndef CSHOWBORDER_H
#define CSHOWBORDER_H

#include <QWidget>

namespace Ui {
class CShowBorder;
}

class CShowBorder : public QWidget
{
    Q_OBJECT

public:
    explicit CShowBorder(QWidget *parent = nullptr);
    ~CShowBorder();

private:
    Ui::CShowBorder *ui;
};

#endif // CSHOWBORDER_H
