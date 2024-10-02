#include "casino.h"
#include "ui_casino.h"
#include <fisrt.h>
#include <ctime>
#include <iostream>



Casino::Casino(fisrt* f, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Casino)
    , propertyRatio(0.0)
    , RandomNumber(0)
    , fix(0)
{
    parentFisrt = f;

    ui->setupUi(this);

    ui->horizontalSlider->setRange(1, 30);

    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->label_2->hide();

    srand(static_cast<unsigned int>(time(NULL)));

}

Casino::~Casino()
{
    delete ui;
}

void Casino::on_horizontalSlider_valueChanged(int value)
{
    if(fix == 0)
    {
        ui->label->setText("재산의 " + QString::number(value) + "%를 걸었습니다" );

        std::cout << value << std::endl;

        propertyRatio = value;
    }
}

void Casino::on_pushButton_clicked()
{
    ui->pushButton->hide();
    ui->horizontalSlider->hide();
    fix = 1;

    ui->pushButton_2->show();
    ui->pushButton_3->show();

    parentFisrt->money -= parentFisrt->money * (propertyRatio / 100);

    RandomNumber = rand() % 6 + 1;
}


void Casino::on_pushButton_2_clicked()
{
    judgmentOfCorrectAnswer(1);
}


void Casino::on_pushButton_3_clicked()
{
    judgmentOfCorrectAnswer(0);
}



void Casino::judgmentOfCorrectAnswer(bool OddOrEven)
{

    ui->label_2->show();

    ui->pushButton_2->hide();
    ui->pushButton_3->hide();

    if(OddOrEven == 1)
    {
        if (RandomNumber % 2 == 1)
        {
            ui->label_2->setText("뽑힌수는 " + QString::number(RandomNumber) + "입니다. 축하합니다!!");
            parentFisrt->money += parentFisrt->money * (2 * propertyRatio / 100);
        }
        else
        {
            ui->label_2->setText("뽑힌수는 " + QString::number(RandomNumber) + "입니다. 다음 기회를 노려보세요!");
        }
    }

    else
    {
        if (RandomNumber % 2 == 1)
        {
            ui->label_2->setText("뽑힌수는 " + QString::number(RandomNumber) + "입니다. 다음 기회를 노려보세요!");
        }
        else
        {
            ui->label_2->setText("뽑힌수는 " + QString::number(RandomNumber) + "입니다. 축하합니다!!");
            parentFisrt->money += parentFisrt->money * (2 * propertyRatio / 100);
        }
    }
}
