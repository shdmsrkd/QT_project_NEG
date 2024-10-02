#include "peeremploymentscene.h"
#include "ui_peeremploymentscene.h"
#include <fisrt.h>
#include <iostream>

bool employmentStatusR1 = 0;
bool employmentStatusR2 = 0;
bool employmentStatusR3 = 0;
bool employmentStatusR4 = 0;

int levelR1 = 1;
int levelR2 = 1;
int levelR3 = 1;
int levelR4 = 1;

peerEmploymentScene::peerEmploymentScene(fisrt* f, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::peerEmploymentScene)
    , moneyValue(0)
    , earningsFromPartTimeJobValue(0)
    // , employmentStatusR1(0)

{
    parentFisrt = f;
    ui->setupUi(this);

    ui->pushButton->setStyleSheet("background-color: red; color: white;");
    ui->pushButton_2->setStyleSheet("background-color: red; color: white;");
    ui->pushButton_3->setStyleSheet("background-color: red; color: white;");
    ui->pushButton_4->setStyleSheet("background-color: red; color: white;");
    ui->pushButton_5->setStyleSheet("background-color: red; color: white;");
    ui->pushButton_6->setStyleSheet("background-color: red; color: white;");
    ui->pushButton_7->setStyleSheet("background-color: red; color: white;");
    ui->pushButton_8->setStyleSheet("background-color: red; color: white;");

    ui->pushButton->setText("맥도날드직원\n고용하기\n : 300만원");
    ui->pushButton_2->setText("Locked");
    ui->pushButton_3->setText("곰돌이\n고용하기\n: 1억원");
    ui->pushButton_4->setText("Locked");
    ui->pushButton_5->setText("알바천국\n고용하기\n: 100억원");
    ui->pushButton_6->setText("Locked");
    ui->pushButton_7->setText("CEO\n고용하기\n: 1000억원");
    ui->pushButton_8->setText("Locked");

    R1.name = "맥도날드직원";
    R1.employmentPrice = 3000000;
    R1.personalIncome = 9860;


    R2.name = "곰돌이";
    R2.employmentPrice = 100000000;
    R2.personalIncome = 9860;

    R3.name = "알바천국";
    R3.employmentPrice = 10000000000;
    R3.personalIncome = 9860;

    R4.name = "CEO";
    R4.employmentPrice = 100000000000;
    R4.personalIncome = 9860;



    uiSave();

}
    peerEmploymentScene::~peerEmploymentScene()
{
    delete ui;
}

Roster::Roster()
{
    name = "";
    employmentPrice = 0;
    personalIncome = 0;

}


Roster::~Roster() {}


// void Roster::nameAdd(std::string n)
// {
//     name = n;
// }


// void Roster::employmentPriceAdd(int eP)
// {
//     employmentPrice = eP;
// }


// void Roster::personalIncomeAdd(int pI)
// {
//     personalIncome = pI;
// }


void peerEmploymentScene::uiSave()
{
    if(employmentStatusR1 == 1)
    {
        ui->pushButton->setStyleSheet("background-color: white; color: black;");
        ui->pushButton_2->setStyleSheet("background-color: white; color: black;");
        ui->pushButton->setText("맥도날드직원\n고용중");
        ui->pushButton_2->setText(QString::fromStdString(R1.name) + " 업그레이드(Lv " + QString::number(levelR1) + ")");

        std::cout << "work" << std::endl;
    }

    if(employmentStatusR2 == 1)
    {
        ui->pushButton_3->setStyleSheet("background-color: white; color: black;");
        ui->pushButton_4->setStyleSheet("background-color: white; color: black;");
        ui->pushButton_3->setText(QString::fromStdString(R2.name) + "\n고용중");
        ui->pushButton_4->setText(QString::fromStdString(R2.name) + " 업그레이드(Lv " + QString::number(levelR2) + ")");
    }

    if(employmentStatusR3 == 1)
    {
        ui->pushButton_5->setStyleSheet("background-color: white; color: black;");
        ui->pushButton_6->setStyleSheet("background-color: white; color: black;");
        ui->pushButton_5->setText(QString::fromStdString(R3.name) + "\n고용중");
        ui->pushButton_6->setText(QString::fromStdString(R3.name) + " 업그레이드(Lv " + QString::number(levelR3) + ")");
    }

    if(employmentStatusR4 == 1)
    {
        ui->pushButton_7->setStyleSheet("background-color: white; color: black;");
        ui->pushButton_8->setStyleSheet("background-color: white; color: black;");
        ui->pushButton_7->setText(QString::fromStdString(R4.name) + "\n고용중");
        ui->pushButton_8->setText(QString::fromStdString(R4.name) + " 업그레이드(Lv " + QString::number(levelR4) + ")");
    }
}

void peerEmploymentScene::on_pushButton_clicked()
{
    if(employmentStatusR1 == 0)
    {
        parentFisrt->money -= R1.employmentPrice;

        if(parentFisrt->money <= 0)
        {
            parentFisrt->money += R1.employmentPrice;
            parentFisrt->OutputOfLackOfMoney();
        }
        else
        {
            parentFisrt->earningsFromPartTimeJob += R1.personalIncome;
            employmentStatusR1 = 1;

            std::cout << "employmentStatusR1 : " << employmentStatusR1 << std::endl;


            ui->pushButton->setStyleSheet("background-color: white; color: black;");
            ui->pushButton_2->setStyleSheet("background-color: white; color: black;");
            ui->pushButton->setText(QString::fromStdString(R1.name) + "\n고용중");
            ui->pushButton_2->setText(QString::fromStdString(R1.name) + " 업그레이드(Lv " + QString::number(levelR1) + ")");


            parentFisrt->R1 = 1;
        }
    }
}


void peerEmploymentScene::on_pushButton_2_clicked()
{
    if(employmentStatusR1 == 1)
    {

        parentFisrt->money -= R1.personalIncome * 7;

        if(parentFisrt->money <= 0)
        {
            parentFisrt->money += R1.personalIncome * 7;
            parentFisrt->OutputOfLackOfMoney();
        }
        else
        {
            levelR1++;
            R1.personalIncome *= 1.5;

            std::cout << "R1.personalIncome : " << R1.personalIncome << std::endl;
            ui->pushButton_2->setText(QString::fromStdString(R1.name) + " 업그레이드(Lv " + QString::number(levelR1) + ")");

            parentFisrt->earningsFromPartTimeJob += R1.personalIncome;
        }
    }
}


void peerEmploymentScene::on_pushButton_3_clicked()
{
    if(employmentStatusR2 == 0)
    {
        parentFisrt->money -= R2.employmentPrice;

        if(parentFisrt->money <= 0)
        {
            parentFisrt->money += R2.employmentPrice;
            parentFisrt->OutputOfLackOfMoney();
        }
        else
        {
            parentFisrt->earningsFromPartTimeJob += R2.personalIncome;
            employmentStatusR2 = 1;

            std::cout << "employmentStatusR2 : " << employmentStatusR2 << std::endl;


            ui->pushButton_3->setStyleSheet("background-color: white; color: black;");
            ui->pushButton_4->setStyleSheet("background-color: white; color: black;");
            ui->pushButton_3->setText(QString::fromStdString(R2.name) + "\n고용중");
            ui->pushButton_4->setText(QString::fromStdString(R2.name) + " 업그레이드(Lv " + QString::number(levelR2) + ")");

            parentFisrt->R2 = 1;
        }
    }
}





void peerEmploymentScene::on_pushButton_4_clicked()
{
    if(employmentStatusR2 == 1)
    {

        parentFisrt->money -= R2.personalIncome * 7;

        if(parentFisrt->money <= 0)
        {
            parentFisrt->money += R2.personalIncome * 7;
            parentFisrt->OutputOfLackOfMoney();
        }
        else
        {
            levelR2++;
            R2.personalIncome *= 1.5;

            std::cout << "R2.personalIncome : " << R2.personalIncome << std::endl;
            ui->pushButton_4->setText(QString::fromStdString(R2.name) + " 업그레이드(Lv " + QString::number(levelR2) + ")");

            parentFisrt->earningsFromPartTimeJob += R2.personalIncome;
        }
    }
}


void peerEmploymentScene::on_pushButton_5_clicked()
{
    if(employmentStatusR3 == 0)
    {
        parentFisrt->money -= R3.employmentPrice;

        if(parentFisrt->money <= 0)
        {
            parentFisrt->money += R3.employmentPrice;
            parentFisrt->OutputOfLackOfMoney();
        }
        else
        {
            parentFisrt->earningsFromPartTimeJob += R3.personalIncome;
            employmentStatusR3 = 1;

            std::cout << "employmentStatusR3 : " << employmentStatusR3 << std::endl;


            ui->pushButton_5->setStyleSheet("background-color: white; color: black;");
            ui->pushButton_6->setStyleSheet("background-color: white; color: black;");
            ui->pushButton_5->setText(QString::fromStdString(R3.name) + "\n고용중");
            ui->pushButton_6->setText(QString::fromStdString(R3.name) + " 업그레이드(Lv " + QString::number(levelR3) + ")");

            parentFisrt->R3 = 1;
        }
    }
}


void peerEmploymentScene::on_pushButton_6_clicked()
{
    if(employmentStatusR3 == 1)
    {

        parentFisrt->money -= R3.personalIncome * 7;

        if(parentFisrt->money <= 0)
        {
            parentFisrt->money += R3.personalIncome * 7;
            parentFisrt->OutputOfLackOfMoney();
        }
        else
        {
            levelR3++;
            R3.personalIncome *= 1.5;

            std::cout << "R3.personalIncome : " << R3.personalIncome << std::endl;
            ui->pushButton_6->setText(QString::fromStdString(R3.name) + " 업그레이드(Lv " + QString::number(levelR3) + ")");

            parentFisrt->earningsFromPartTimeJob += R3.personalIncome;
        }
    }
}


void peerEmploymentScene::on_pushButton_7_clicked()
{
    if(employmentStatusR4 == 0)
    {
        parentFisrt->money -= R4.employmentPrice;

        if(parentFisrt->money <= 0)
        {
            parentFisrt->money += R4.employmentPrice;
            parentFisrt->OutputOfLackOfMoney();
        }
        else
        {
            parentFisrt->earningsFromPartTimeJob += R4.personalIncome;
            employmentStatusR4 = 1;

            std::cout << "employmentStatusR4 : " << employmentStatusR4 << std::endl;


            ui->pushButton_7->setStyleSheet("background-color: white; color: black;");
            ui->pushButton_8->setStyleSheet("background-color: white; color: black;");
            ui->pushButton_7->setText(QString::fromStdString(R4.name) + "\n고용중");
            ui->pushButton_8->setText(QString::fromStdString(R4.name) + " 업그레이드(Lv " + QString::number(levelR4) + ")");

            parentFisrt->R4 = 1;
        }
    }
}


void peerEmploymentScene::on_pushButton_8_clicked()
{
    if(employmentStatusR4 == 1)
    {

        parentFisrt->money -= R4.personalIncome * 7;

        if(parentFisrt->money <= 0)
        {
            parentFisrt->money += R4.personalIncome * 7;
            parentFisrt->OutputOfLackOfMoney();
        }
        else
        {
            levelR4++;
            R4.personalIncome *= 1.5;

            std::cout << "R4.personalIncome : " << R4.personalIncome << std::endl;
            ui->pushButton_8->setText(QString::fromStdString(R4.name) + " 업그레이드(Lv " + QString::number(levelR4) + ")");

            parentFisrt->earningsFromPartTimeJob += R4.personalIncome;
        }
    }
}

