#include <iostream>
#include "fisrt.h"
#include "ui_fisrt.h"

fisrt::fisrt(QWidget *parent):
    QDialog(parent),
    ui(new Ui::fisrt),
    money(0),
    ReservePperClickMoney(1000)

{
    ui->setupUi(this);
}

fisrt::~fisrt()
{
    delete ui;
}

void fisrt::on_pushButton_clicked()
{
    money += ReservePperClickMoney;

    long long eok = money / 100000000;
    long long man = (money % 100000000) / 10000;
    long long won = money % 10000;

    std:: cout << money << std::endl;

    if(money >= 100000000)
    {
        ui->label->setText(QString::number(eok) + "억 " +  QString::number(man) + "만 " + QString::number((won)) + "원");
    }
    else if(money >= 10000)
    {
        ui->label->setText(QString::number(man) + "만 " + QString::number((won)) + "원");
    }
    else
    {
        ui->label->setText(QString::number(won) + "원");
    }
}

void fisrt::on_pushButton_2_clicked()
{
    ReservePperClickMoney *= 2;
}

