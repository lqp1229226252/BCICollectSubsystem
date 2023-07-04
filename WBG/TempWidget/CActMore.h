#ifndef CACTMORE_H
#define CACTMORE_H

#include <QWidget>

namespace Ui {
class CActMore;
}

class CActMore : public QWidget
{
    Q_OBJECT

public:
    explicit CActMore(QWidget *parent = nullptr);
    ~CActMore();

private:
    Ui::CActMore *ui;
};

#endif // CACTMORE_H
