#ifndef FISRT_H
#define FISRT_H

#include <QDialog>
#include <QLabel>
#include <QTimer>


namespace Ui {
class fisrt;
}

class fisrt : public QDialog
{
    Q_OBJECT

public:
    explicit fisrt(QWidget *parent = nullptr);
    ~fisrt();

    long long display_money();
    void earningsFromPartTimeJobs();
    void OutputOfLackOfMoney();
    void FeverTimeStartBar();
    long long returnMoney();
    long long returnEarningsFromPartTimeJob();

    long long earningsFromPartTimeJob;
    long long money;

    void itemAcquisition();
    void useItem();

    void imgUpdateF();

    bool R1 = 0;
    bool R2 = 0;
    bool R3 = 0;
    bool R4 = 0;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

private:
    Ui::fisrt *ui;
    QTimer * timer;
    QTimer * fevertimer;
    QTimer * imgUpdate;
    QTimer * challengeTimer;
    QTimer * itemTimer;


    long long reservePerClickMoney;

    int reservePerClickMoneyLevel;
    int earningsFromPartTimeJobLevel;

    int fevertimeState;
    int feverTimeValue;
    int itemTimeValue;
    int itemcount;
    int saveReservePerClickMoney;
    int count;
    int useItemcount;

    int numberOfItems;
    int dopingStatus;
};

#endif // FISRT_H
