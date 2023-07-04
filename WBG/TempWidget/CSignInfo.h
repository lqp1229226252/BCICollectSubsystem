#ifndef CSIGNINFO_H
#define CSIGNINFO_H

#include <QWidget>

namespace Ui {
class CSignInfo;
}

class CSignInfo : public QWidget
{
    Q_OBJECT

public:
    explicit CSignInfo(QWidget *parent = nullptr);
    ~CSignInfo();

    void setTextInfo(const QString &key,const QString &value);
private slots:


private:
    Ui::CSignInfo *ui;
};

#endif // CSIGNINFO_H
