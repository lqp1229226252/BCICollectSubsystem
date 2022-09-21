#ifndef REGISTER_INFO_H
#define REGISTER_INFO_H

#include <QWidget>

namespace Ui {
class Register_info;
}

class Register_info : public QWidget
{
    Q_OBJECT

public:
    explicit Register_info(QWidget *parent = nullptr);
    ~Register_info();

private:
    Ui::Register_info *ui;
};

#endif // REGISTER_INFO_H
