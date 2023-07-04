#ifndef CPRODUCT_H
#define CPRODUCT_H

#include <QWidget>

namespace Ui {
class CProduct;
}

class CProduct : public QWidget
{
    Q_OBJECT

public:
    explicit CProduct(QWidget *parent = nullptr);
    ~CProduct();

private:
    Ui::CProduct *ui;
};

#endif // CPRODUCT_H
