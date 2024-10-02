#ifndef CASINO_H
#define CASINO_H

#include <QDialog>
#include <fisrt.h>

namespace Ui {
class Casino;
}

class Casino : public QDialog
{
    Q_OBJECT

public:
    explicit Casino(fisrt * f , QWidget *parent = nullptr);
    ~Casino();
    void judgmentOfCorrectAnswer(bool OddOrEven);

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Casino *ui;
    fisrt* parentFisrt;

    bool fix;
    float propertyRatio;
    int RandomNumber;
};

#endif // CASINO_H
