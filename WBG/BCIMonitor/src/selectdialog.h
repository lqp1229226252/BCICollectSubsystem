#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H

#include <QDialog>

namespace Ui {
class SelectDialog;
}

class SelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectDialog(QWidget *parent = nullptr);
    ~SelectDialog();
    void setDeviceType(QStringList);
signals:
    void select(int index);
private slots:

    void on_select_clicked();

private:
    Ui::SelectDialog *ui;
};

#endif // SELECTDIALOG_H
