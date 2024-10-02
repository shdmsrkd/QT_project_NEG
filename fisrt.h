#ifndef FISRT_H
#define FISRT_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class fisrt;
}

class fisrt : public QDialog
{
    Q_OBJECT

public:
    explicit fisrt(QWidget *parent = nullptr);
    ~fisrt();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::fisrt *ui;
    long long money;
    int ReservePperClickMoney;
};

#endif // FISRT_H
