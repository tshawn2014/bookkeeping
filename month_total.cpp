#include "month_total.h"
#include "ui_month_total.h"
#include "iobymonth.h"

#include <QDebug>
month_total::month_total(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::month_total)
{
    ui->setupUi(this);
    IOByMonth temp = IOByMonth(1);
    ui->label_income->setText(QString::number(temp.getIncome(),'f',2));
    ui->label_expense->setText(QString::number(temp.getExpense(),'f',2));
    ui->label_balanced->setText(QString::number(temp.getBalance(),'f',2));

}

month_total::~month_total()
{
    delete ui;
}

void month_total::on_back_clicked()
{
    this->hide();
    parentWidget()->show();
}


void month_total::on_comboBox_month_currentIndexChanged(int index)
{
    index++;
    IOByMonth temp = IOByMonth(index);
    ui->label_income->setText(QString::number(temp.getIncome(),'f',2));
    ui->label_expense->setText(QString::number(temp.getExpense(),'f',2));
    ui->label_balanced->setText(QString::number(temp.getBalance(),'f',2));
}
