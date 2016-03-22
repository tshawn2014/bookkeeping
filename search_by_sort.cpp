#include "search_by_sort.h"
#include "ui_search_by_sort.h"
#include <QTextCodec>
#include "expenseBySort.h"
#include "incomebysort.h"
#include <QDebug>

search_by_sort::search_by_sort(int type, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search_by_sort)
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    ui->setupUi(this);
    if(type==1)
    {
        QString str = QString("shopping");
        expenseBySort temp =  expenseBySort(str.toStdString());
        ui->label_num->setText(QString::number(temp.getExpense(),'f',2));
        ui->labelHint->setText(QObject::tr("按月查询个人支出"));
        ui->comboBox_income->hide();

    }
    if(type==2)
    {

        QString str = QString("salary");
        incomeBySort temp =  incomeBySort(str.toStdString());
        ui->label_num->setText(QString::number(temp.getIncome(),'f',2));
        ui->labelHint->setText(QObject::tr("按月查询个人收入"));
        ui->comboBox_expense->hide();

    }
}

search_by_sort::~search_by_sort()
{
    delete ui;
}

void search_by_sort::on_back_clicked()
{
    this->hide();
    parentWidget()->show();
}

void search_by_sort::on_comboBox_expense_currentIndexChanged(const QString &arg1)
{
    expenseBySort temp =  expenseBySort(arg1.toStdString());
    ui->label_num->setText(QString::number(temp.getExpense(),'f',2));
}

void search_by_sort::on_comboBox_income_currentIndexChanged(const QString &arg1)
{
    incomeBySort temp =  incomeBySort(arg1.toStdString());
    ui->label_num->setText(QString::number(temp.getIncome(),'f',2));
}
