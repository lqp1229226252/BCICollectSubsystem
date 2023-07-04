#ifndef CSHOPPAGE_H
#define CSHOPPAGE_H

#include <QWidget>
#include "MPicturePlayer.h"

namespace Ui {
class CShopPage;
}

class CShopPage : public QWidget
{
    Q_OBJECT

public:
    explicit CShopPage(QWidget *parent = nullptr);
    ~CShopPage();
    void setText();

private:
    Ui::CShopPage *ui;
    MPicturePlayer*m_pPicurePlay;
};

#endif // CSHOPPAGE_H
