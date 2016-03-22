#include "input.h"
#include "ui_input.h"
#include <QTextCodec>
#include <QComboBox>
#include <QDebug>
#include <expense.h>
#include <income.h>
#include "backhint.h"
#include "iobymonth.h"
#include "expensebysort.h"
#include "incomebysort.h"
#include <QValidator>
input::input(int type,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::input)
{
    this->type = type;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    ui->setupUi(this);
    if(type==1)
    {
        ui->labelHint->setText(QObject::tr("录入个人支出"));
        ui->comboBox_sort_income->hide();
    }
    if(type==2)
    {
        ui->labelHint->setText(QObject::tr("录入个人收入"));
        ui->comboBox_sort_expense->hide();
    }
    ui->lineEdit_money->setValidator(new QDoubleValidator(0,1000000,2,this));
    QRegExp regx("[a-zA-Z0-9]+$");
    QValidator *validator = new QRegExpValidator(regx );
    ui->lineEdit_reason->setValidator(validator);
    //ui->lineEdit_reason->setValidator();

    connect(ui->comboBox_month,SIGNAL(currentIndexChanged(int)),this,SLOT(change_(int)));
}

input::~input()
{
    delete ui;
}

void input::on_Cancel_clicked()
{
    this->hide();
    parentWidget()->show();
}

void input::on_Confirm_clicked()
{

    QString money = ui->lineEdit_money->text();
    double MONEY = money.toDouble();
    int mnth = ui->comboBox_month->currentIndex();
    int dy = ui->comboBox_day->currentIndex();
    QString reason = ui->lineEdit_reason->text();
    std::string REASON = reason.toStdString();
    if(ui->lineEdit_money->text()!="")
    {
        if(type == 1){
            QString expense = ui->comboBox_sort_expense->currentText();
            std::string EXPENSE = expense.toStdString();
            //导入数据库
            Expense temp = Expense(MONEY,mnth+1,dy+1,REASON,EXPENSE);
            IOByMonth temp2 = IOByMonth(mnth+1);
            IOByMonth temp3 = IOByMonth(13);
            expenseBySort temp4 = expenseBySort(EXPENSE);
            temp4.setSortExpense(MONEY);
            temp2.setMonthIO(MONEY,0);
            temp3.setMonthIO(MONEY,0);
        }
        else if(type == 2){
            QString income = ui->comboBox_sort_income->currentText();
            std::string INCOME = income.toStdString();
            //导入数据库
            qDebug()<<MONEY<<" "<<money<<" "<<endl;
            Income temp = Income(MONEY,mnth+1,dy+1,REASON,INCOME);
            IOByMonth temp2 = IOByMonth(mnth+1);
            IOByMonth temp3 = IOByMonth(13);
            incomeBySort temp4 = incomeBySort(INCOME);
            temp4.setSortIncome(MONEY);
            temp2.setMonthIO(0,MONEY);
            temp3.setMonthIO(0,MONEY);
        }
        this->hide();

        backhint* bckhnt = new backhint();
        bckhnt->setModal(true);
        parentWidget()->show();
        bckhnt->show();
    }
    else
    {
        backhint* bckhnt = new backhint(1);
        bckhnt->setModal(true);
        //bckhnt->label->setText(QObject::tr("请输入金额！"));
        parentWidget()->show();
        bckhnt->show();
    }

    //提示窗口

}

void input::change_(int mnth){

    mnth++;
    QStringList big,small,_2;
    big<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"
      <<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"<<"16"
        <<"17"<<"18"<<"19"<<"20"<<"21"<<"22"<<"23"<<"24"
          <<"25"<<"26"<<"27"<<"28"<<"29"<<"30"<<"31";
    small<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"
      <<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"<<"16"
        <<"17"<<"18"<<"19"<<"20"<<"21"<<"22"<<"23"<<"24"
          <<"25"<<"26"<<"27"<<"28"<<"29"<<"30";
    _2<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"
     <<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"<<"16"
       <<"17"<<"18"<<"19"<<"20"<<"21"<<"22"<<"23"<<"24"
         <<"25"<<"26"<<"27"<<"28";
       // int mnth = ui->comboBox_month->currentIndex();
    switch (mnth){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            ui->comboBox_day->clear();
            ui->comboBox_day->addItems(big);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            ui->comboBox_day->clear();
            ui->comboBox_day->addItems(small);
            break;
        case 2:
            ui->comboBox_day->clear();
            ui->comboBox_day->addItems(_2);
            break;
        default:
            ui->comboBox_day->hide();
            break;
     }
}
