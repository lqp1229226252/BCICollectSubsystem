#ifndef CFUNCDETIAL_H
#define CFUNCDETIAL_H

#include <QWidget>

namespace Ui {
class CFuncDetial;
}

class CFuncDetial : public QWidget
{
    Q_OBJECT

public:
    explicit CFuncDetial(QWidget *parent = nullptr);
    ~CFuncDetial();

private:
    Ui::CFuncDetial *ui;
};

#endif // CFUNCDETIAL_H
