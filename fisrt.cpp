#include <iostream>
#include "fisrt.h"
#include "ui_fisrt.h"
#include "peeremploymentscene.h"
#include "casino.h"



fisrt::fisrt(QWidget *parent):
    QDialog(parent),
    ui(new Ui::fisrt),
    money(0),
    reservePerClickMoney(1000),
    earningsFromPartTimeJob(1000),
    reservePerClickMoneyLevel(1),
    earningsFromPartTimeJobLevel(1),
    feverTimeValue(0),
    fevertimeState(0),
    saveReservePerClickMoney(0),
    count(0),
    numberOfItems(0),
    dopingStatus(0),
    itemTimeValue(100),
    itemcount(0),
    useItemcount(0)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &fisrt::earningsFromPartTimeJobs);

    fevertimer = new QTimer(this);
    connect(fevertimer, &QTimer::timeout, this, &fisrt::FeverTimeStartBar);

    imgUpdate = new QTimer(this);
    connect(imgUpdate, &QTimer::timeout, this, &fisrt::imgUpdateF);

    challengeTimer = new QTimer(this);
    connect(challengeTimer, &QTimer::timeout, this, &fisrt::itemAcquisition);

    itemTimer = new QTimer(this);;
    connect(itemTimer, &QTimer::timeout, this, &fisrt::useItem);

    fevertimer->start(1000);
    timer->start(1000);
    imgUpdate->start(100);
    challengeTimer->start(100);
    itemTimer->start(1000);

    QPixmap MC("/home/eungang/Desktop/QT_project/QT_Project_NEG/mainCharacter.jpg");
    ui->label_5->setPixmap(MC);

    ui->pushButton_2->setText("Lv " + QString::number(reservePerClickMoneyLevel) + "\n\n" + QString::number(reservePerClickMoney * 7) + " 원");

    ui->pushButton_6->setText("도핑하기 \n\n남은 개수 : " + QString::number(numberOfItems) + " 개");

}

fisrt::~fisrt()
{
    delete ui;
}

long long fisrt::display_money()
{
    long long gyeong = money / 10000000000000000;
    long long jo = (money % 10000000000000000) / 1000000000000;
    long long eok = (money % 1000000000000) / 100000000;
    long long man = (money % 100000000) / 10000;
    long long won = money % 10000;

    long long gyeong_earningsFromPartTimeJob = earningsFromPartTimeJob / 10000000000000000;
    long long jo_earningsFromPartTimeJob = (earningsFromPartTimeJob % 10000000000000000) / 1000000000000;
    long long eok_earningsFromPartTimeJob = (earningsFromPartTimeJob % 1000000000000) / 100000000;
    long long man_earningsFromPartTimeJob = (earningsFromPartTimeJob % 100000000) / 10000;
    long long won_earningsFromPartTimeJob = earningsFromPartTimeJob % 10000;

    long long gyeong_reservePerClickMoney = reservePerClickMoney / 10000000000000000;
    long long jo_reservePerClickMoney = (reservePerClickMoney % 10000000000000000) / 1000000000000;
    long long eok_reservePerClickMoney = (reservePerClickMoney % 1000000000000) / 100000000;
    long long man_reservePerClickMoney = (reservePerClickMoney % 100000000) / 10000;
    long long won_reservePerClickMoney = reservePerClickMoney % 10000;

    std::cout << money << std::endl;

    if (money >= 10000000000000000)
    {
        ui->label->setText(QString::number(gyeong) + "경 " + QString::number(jo) + "조 " + QString::number(eok) + "억 " + QString::number(man) + "만 " + QString::number(won) + "원");
    }
    else if (money >= 1000000000000)
    {
        ui->label->setText(QString::number(jo) + "조 " + QString::number(eok) + "억 " + QString::number(man) + "만 " + QString::number(won) + "원");
    }
    else if (money >= 100000000)
    {
        ui->label->setText(QString::number(eok) + "억 " + QString::number(man) + "만 " + QString::number(won) + "원");
    }
    else if (money >= 10000)
    {
        ui->label->setText(QString::number(man) + "만 " + QString::number(won) + "원");
    }
    else
    {
        ui->label->setText(QString::number(won) + "원");
    }

    if (earningsFromPartTimeJob >= 10000000000000000)
    {
        ui->label_2->setText(QString::number(gyeong_earningsFromPartTimeJob) + "경 " + QString::number(jo_earningsFromPartTimeJob) + "조 " + QString::number(eok_earningsFromPartTimeJob) + "억 " + QString::number(man_earningsFromPartTimeJob) + "만 " + QString::number(won_earningsFromPartTimeJob) + "원 / 초");
    }
    else if (earningsFromPartTimeJob >= 1000000000000)
    {
        ui->label_2->setText(QString::number(jo_earningsFromPartTimeJob) + "조 " + QString::number(eok_earningsFromPartTimeJob) + "억 " + QString::number(man_earningsFromPartTimeJob) + "만 " + QString::number(won_earningsFromPartTimeJob) + "원 / 초");
    }
    else if (earningsFromPartTimeJob >= 100000000)
    {
        ui->label_2->setText(QString::number(eok_earningsFromPartTimeJob) + "억 " + QString::number(man_earningsFromPartTimeJob) + "만 " + QString::number(won_earningsFromPartTimeJob) + "원 / 초");
    }
    else if (earningsFromPartTimeJob >= 10000)
    {
        ui->label_2->setText(QString::number(man_earningsFromPartTimeJob) + "만 " + QString::number(won_earningsFromPartTimeJob) + "원 / 초");
    }
    else
    {
        ui->label_2->setText(QString::number(won_earningsFromPartTimeJob) + "원 / 초");
    }

    if (reservePerClickMoney >= 10000000000000000)
    {
        ui->label_4->setText(QString::number(gyeong_reservePerClickMoney) + "경 " + QString::number(jo_reservePerClickMoney) + "조 " + QString::number(eok_reservePerClickMoney) + "억 " + QString::number(man_reservePerClickMoney) + "만 " + QString::number(won_reservePerClickMoney) + "원 / 클릭");
    }
    else if (reservePerClickMoney >= 1000000000000)
    {
        ui->label_4->setText(QString::number(jo_reservePerClickMoney) + "조 " + QString::number(eok_reservePerClickMoney) + "억 " + QString::number(man_reservePerClickMoney) + "만 " + QString::number(won_reservePerClickMoney) + "원 / 클릭");
    }
    else if (reservePerClickMoney >= 100000000)
    {
        ui->label_4->setText(QString::number(eok_reservePerClickMoney) + "억 " + QString::number(man_reservePerClickMoney) + "만 " + QString::number(won_reservePerClickMoney) + "원 / 클릭");
    }
    else if (reservePerClickMoney >= 10000)
    {
        ui->label_4->setText(QString::number(man_reservePerClickMoney) + "만 " + QString::number(won_reservePerClickMoney) + "원 / 클릭");
    }
    else
    {
        ui->label_4->setText(QString::number(won_reservePerClickMoney) + "원 / 클릭");
    }

    return money;


}

void fisrt::on_pushButton_clicked()
{
    money += reservePerClickMoney;

    feverTimeValue += 1;
    ui->progressBar->setValue(feverTimeValue);

    display_money();
}

void fisrt::on_pushButton_2_clicked()
{
    money -= reservePerClickMoney * 7;

    if(money <= 0)
    {
        money += reservePerClickMoney * 7;
        OutputOfLackOfMoney();
    }
    else
    {
        reservePerClickMoneyLevel++;
        reservePerClickMoney *= 35;
        display_money();

        ui->pushButton_2->setText("Lv " + QString::number(reservePerClickMoneyLevel) + "\n\n" + QString::number(reservePerClickMoney* 7) + " 원");
    }
}

void fisrt::earningsFromPartTimeJobs()
{
    money += earningsFromPartTimeJob;

    display_money();
}

void fisrt::OutputOfLackOfMoney()
{
    ui->label_3->setText("돈이 부족합니다");

    QTimer::singleShot(1000, this, [this]()
    {
        ui->label_3->clear();
    });
}

void fisrt::imgUpdateF()
{
    if(R1 == 1)
    {
        QPixmap SC1("/home/eungang/Desktop/QT_project/QT_Project_NEG/S1.png");
        ui->label_6->setPixmap(SC1);
    }
    if(R2 == 1)
    {
        QPixmap SC2("/home/eungang/Desktop/QT_project/QT_Project_NEG/S2.png");
        ui->label_7->setPixmap(SC2);
    }
    if(R3 == 1)
    {
        QPixmap SC3("/home/eungang/Desktop/QT_project/QT_Project_NEG/S3.png");
        ui->label_8->setPixmap(SC3);
    }
    if(R4 == 1)
    {
        QPixmap SC4("/home/eungang/Desktop/QT_project/QT_Project_NEG/S4.png");
        ui->label_9->setPixmap(SC4);
    }
    QPixmap potion("/home/eungang/Desktop/QT_project/QT_Project_NEG/Potion.png");
    ui->label_10->setPixmap(potion);
}

void fisrt::FeverTimeStartBar()
{
    if (fevertimeState == 1)
    {
        count++;
        feverTimeValue -= 20;

        if (count == 1)
        {
            reservePerClickMoney *= 5;
        }
        reservePerClickMoney *= 5;
        reservePerClickMoney /= 5;

        if(feverTimeValue <= 0)
        {
            fevertimeState = 0;
            feverTimeValue = 0;
            reservePerClickMoney /= 5;
        }
        ui->progressBar->setValue(feverTimeValue);

    }

    else if (fevertimeState == 0)
    {
        feverTimeValue ++;

        if(feverTimeValue >= 100)
        {
            feverTimeValue = 100;
            fevertimeState = 1;
        }

        ui->progressBar->setValue(feverTimeValue);

        count = 0;
        saveReservePerClickMoney = reservePerClickMoney;
    }
}

long long fisrt::returnMoney()
{
    return money;
}

long long fisrt::returnEarningsFromPartTimeJob()
{
    return earningsFromPartTimeJob;
}


void fisrt::on_pushButton_4_clicked()
{
    peerEmploymentScene employmentScreen(this);
    employmentScreen.setModal(true);
    employmentScreen.exec();
}


void fisrt::on_pushButton_5_clicked()
{
    Casino casinoScreen(this);
    casinoScreen.setModal(true);
    casinoScreen.exec();
}


void fisrt::on_pushButton_6_clicked()
{
    if(numberOfItems >= 1)
    {
        dopingStatus = 1;
        numberOfItems--;
    }

    ui->pushButton_6->setText("도핑하기 \n\n남은 개수 : " + QString::number(numberOfItems) + " 개");
}

void fisrt::itemAcquisition()
{
    if(money >= 100000000 && itemcount == 0)
    {
        itemcount++;
        numberOfItems++;
        ui->pushButton_6->setText("도핑하기 \n\n남은 개수 : " + QString::number(numberOfItems) + " 개");
        std::cout << "work1" << std::endl;
    }

    if(money >= 10000000000 && itemcount == 1)
    {
        itemcount++;
        numberOfItems++;
        ui->pushButton_6->setText("도핑하기 \n\n남은 개수 : " + QString::number(numberOfItems) + " 개");
        std::cout << "work2" << std::endl;
    }

    if (R1 == 1 && R2 == 1 && R3 == 1 && R4 == 1 && itemcount == 2)
    {
        itemcount++;
        numberOfItems++;
        ui->pushButton_6->setText("도핑하기 \n\n남은 개수 : " + QString::number(numberOfItems) + " 개");
        std::cout << "work3" << std::endl;
    }
}

void fisrt::useItem()
{

    if (dopingStatus == 1)
    {
        useItemcount++;
        itemTimeValue -= 10;

        if (useItemcount == 1)
        {
            reservePerClickMoney *= 10;
            std::cout << "work4" << std::endl;
        }
        reservePerClickMoney *= 10;
        reservePerClickMoney /= 10;

        if(itemTimeValue <= 0)
        {
            dopingStatus = 0;
            itemTimeValue = 100;
            useItemcount = 0;
            reservePerClickMoney /= 10;
        }
        ui->pushButton->setStyleSheet("background-color: red; color: white;");
    }
    else if (dopingStatus == 0)
    {
        ui->pushButton->setStyleSheet("background-color: white; color: black;");
    }
}
