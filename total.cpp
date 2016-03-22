#include "total.h"
#include "ui_total.h"
#include "iobymonth.h"

total::total(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::total)
{
    ui->setupUi(this);
    IOByMonth temp = IOByMonth(13);
    ui->label_income_num->setText(QString::number(temp.getIncome(),'f',2));
    ui->label_expense_num->setText(QString::number(temp.getExpense(),'f',2));
    ui->label_balanced_num->setText(QString::number(temp.getBalance(),'f',2));
}

total::~total()
{
    delete ui;
}

void total::on_back_clicked()
{
    this->hide();
    parentWidget()->show();
}
