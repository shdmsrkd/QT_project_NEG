#ifndef PEEREMPLOYMENTSCENE_H
#define PEEREMPLOYMENTSCENE_H

#include <QDialog>
#include <fisrt.h>
#include <ui_peeremploymentscene.h>


class Roster
{
public:
    Roster();
    ~Roster();

    std::string name;
    long long employmentPrice;
    long long personalIncome;
    int level;
private:

};

namespace Ui {
class peerEmploymentScene;
}

class peerEmploymentScene : public QDialog
{
    Q_OBJECT

public:
    explicit peerEmploymentScene(fisrt * f , QWidget *parent = nullptr);
    ~peerEmploymentScene();

    void uiSave();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::peerEmploymentScene *ui;
    fisrt* parentFisrt;
    long long moneyValue;
    int earningsFromPartTimeJobValue;

    // bool employmentStatusR1;
    // bool employmentStatusR2;
    // bool employmentStatusR3;
    // bool employmentStatusR4;
    Roster R1;
    Roster R2;
    Roster R3;
    Roster R4;

};

#endif // PEEREMPLOYMENTSCENE_H
