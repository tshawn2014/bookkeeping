#include "month.h"
#include "ui_month.h"
#include <iostream>
#include <string>
#include <QString>
#include <cstdlib>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

month::month(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::month)
{
    ui->setupUi(this);
    QSqlDatabase db;
    if(QSqlDatabase::contains("mydata"))
         db = QSqlDatabase::database("mydata");
     else
         db = QSqlDatabase::addDatabase("QMYSQL","mydata");
    db.setDatabaseName("mydata");//设置数据库名称
    //告知数据库的用户名和密码
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
   if(!db.open())
   {
     //QMessageBox::critical(0,QObject::tr("Database Error"),db.lastError().text());
     exit(0); //改成结束整个函数
   }
     //查询明细
    int index = 1;
    ui->tableWidget_expense->clearContents();
    ui->tableWidget_expense->setRowCount(0);
    ui->tableWidget_income->clearContents();
    ui->tableWidget_income->setRowCount(0);
   QString buffer = QString("select * from expense where month = %1").arg(index);
   QSqlQuery query = QSqlQuery(buffer,db);
   int row_count;
     while(query.next())
       {
         row_count = ui->tableWidget_expense->rowCount(); //获取表单行数
         ui->tableWidget_expense->insertRow(row_count); //插入新行
         QString month1= query.value(2).toString();
         QString date1= query.value(3).toString();
         QString amount1= query.value(1).toString();
         QString reason1 = query.value(5).toString();
         QString sort1 = query.value(4).toString();
         QString time1 = month1+"."+date1;
         qDebug()<<month1<<"  "<<date1<<"  "<<sort1<<" "<<time1<<endl;

         QTableWidgetItem *item = new QTableWidgetItem();
         QTableWidgetItem *item1 = new QTableWidgetItem();
         QTableWidgetItem *item2 = new QTableWidgetItem();
         QTableWidgetItem *item3 = new QTableWidgetItem();
         item->setText(sort1);
         item1->setText(amount1);
         item2->setText(reason1);
         item3->setText(time1);
         ui->tableWidget_expense->setItem(row_count, 0, item);
         ui->tableWidget_expense->setItem(row_count, 1, item1);
         ui->tableWidget_expense->setItem(row_count, 2, item2);
         ui->tableWidget_expense->setItem(row_count, 3, item3);
       }

     QString buffer2 = QString("select * from income where month = %1").arg(index);
     QSqlQuery query2 = QSqlQuery(buffer2,db);

     while(query2.next())
       {
         row_count = ui->tableWidget_income->rowCount(); //获取表单行数
         ui->tableWidget_income->insertRow(row_count); //插入新行
         QString month1= query2.value(2).toString();
         QString date1= query2.value(3).toString();
         QString amount1= query2.value(1).toString();
         QString reason1 = query2.value(5).toString();
         QString sort1 = query2.value(4).toString();
         QString time1 = month1+"."+date1;
         QTableWidgetItem *item = new QTableWidgetItem();
         QTableWidgetItem *item1 = new QTableWidgetItem();
         QTableWidgetItem *item2 = new QTableWidgetItem();
         QTableWidgetItem *item3 = new QTableWidgetItem();
          qDebug()<<month1<<"  "<<date1<<"  "<<sort1<<" "<<time1<<endl;
         item->setText(sort1);
         item1->setText(amount1);
         item2->setText(reason1);
         item3->setText(time1);
         ui->tableWidget_income->setItem(row_count, 0, item);
         ui->tableWidget_income->setItem(row_count, 1, item1);
         ui->tableWidget_income->setItem(row_count, 2, item2);
         ui->tableWidget_income->setItem(row_count, 3, item3);
       }
}

month::~month()
{
    delete ui;
}

void month::on_back_clicked()
{
    this->hide();
    parentWidget()->show();
}



void month::on_comboBox_month_currentIndexChanged(int index)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("mydata"))
         db = QSqlDatabase::database("mydata");
     else
         db = QSqlDatabase::addDatabase("QMYSQL","mydata");
    db.setDatabaseName("mydata");//设置数据库名称
    //告知数据库的用户名和密码
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
   if(!db.open())
   {
     //QMessageBox::critical(0,QObject::tr("Database Error"),db.lastError().text());
     exit(0); //改成结束整个函数
   }
     //查询明细
    index++;
    ui->tableWidget_expense->clearContents();
    ui->tableWidget_expense->setRowCount(0);
    ui->tableWidget_income->clearContents();
    ui->tableWidget_income->setRowCount(0);
    if(index!=13){
   QString buffer = QString("select * from expense where month = %1").arg(index);
   QSqlQuery query = QSqlQuery(buffer,db);
   int row_count = 0;
     while(query.next())
       {
         row_count = ui->tableWidget_expense->rowCount(); //获取表单行数
         ui->tableWidget_expense->insertRow(row_count); //插入新行
         QString month1= query.value(2).toString();
         QString date1= query.value(3).toString();
         QString amount1= query.value(1).toString();
         QString reason1 = query.value(5).toString();
         QString sort1 = query.value(4).toString();
         QString time1 = month1+"."+date1;
         qDebug()<<month1<<"  "<<date1<<"  "<<sort1<<" "<<time1<<endl;

         QTableWidgetItem *item = new QTableWidgetItem();
         QTableWidgetItem *item1 = new QTableWidgetItem();
         QTableWidgetItem *item2 = new QTableWidgetItem();
         QTableWidgetItem *item3 = new QTableWidgetItem();
         item->setText(sort1);
         item1->setText(amount1);
         item2->setText(reason1);
         item3->setText(time1);
         ui->tableWidget_expense->setItem(row_count, 0, item);
         ui->tableWidget_expense->setItem(row_count, 1, item1);
         ui->tableWidget_expense->setItem(row_count, 2, item2);
         ui->tableWidget_expense->setItem(row_count, 3, item3);
       }

     QString buffer2 = QString("select * from income where month = %1").arg(index);
     QSqlQuery query2 = QSqlQuery(buffer2,db);
     row_count = 0 ;

     while(query2.next())
       {
         row_count = ui->tableWidget_income->rowCount(); //获取表单行数
         ui->tableWidget_income->insertRow(row_count); //插入新行
         QString month1= query2.value(2).toString();
         QString date1= query2.value(3).toString();
         QString amount1= query2.value(1).toString();
         QString reason1 = query2.value(5).toString();
         QString sort1 = query2.value(4).toString();
         QString time1 = month1+"."+date1;
         QTableWidgetItem *item = new QTableWidgetItem();
         QTableWidgetItem *item1 = new QTableWidgetItem();
         QTableWidgetItem *item2 = new QTableWidgetItem();
         QTableWidgetItem *item3 = new QTableWidgetItem();
          qDebug()<<month1<<"  "<<date1<<"  "<<sort1<<" "<<time1<<endl;
         item->setText(sort1);
         item1->setText(amount1);
         item2->setText(reason1);
         item3->setText(time1);
         ui->tableWidget_income->setItem(row_count, 0, item);
         ui->tableWidget_income->setItem(row_count, 1, item1);
         ui->tableWidget_income->setItem(row_count, 2, item2);
         ui->tableWidget_income->setItem(row_count, 3, item3);
         row_count++;
       }
    }
    else{
        QString buffer = QString("select * from expense");
        QSqlQuery query = QSqlQuery(buffer,db);
        int row_count = 0;
          while(query.next())
            {
              row_count = ui->tableWidget_expense->rowCount(); //获取表单行数
              ui->tableWidget_expense->insertRow(row_count); //插入新行
              QString month1= query.value(2).toString();
              QString date1= query.value(3).toString();
              QString amount1= query.value(1).toString();
              QString reason1 = query.value(5).toString();
              QString sort1 = query.value(4).toString();
              QString time1 = month1+"."+date1;
              qDebug()<<month1<<"  "<<date1<<"  "<<sort1<<" "<<time1<<endl;

              QTableWidgetItem *item = new QTableWidgetItem();
              QTableWidgetItem *item1 = new QTableWidgetItem();
              QTableWidgetItem *item2 = new QTableWidgetItem();
              QTableWidgetItem *item3 = new QTableWidgetItem();
              item->setText(sort1);
              item1->setText(amount1);
              item2->setText(reason1);
              item3->setText(time1);
              ui->tableWidget_expense->setItem(row_count, 0, item);
              ui->tableWidget_expense->setItem(row_count, 1, item1);
              ui->tableWidget_expense->setItem(row_count, 2, item2);
              ui->tableWidget_expense->setItem(row_count, 3, item3);
            }

          QString buffer2 = QString("select * from income");
          QSqlQuery query2 = QSqlQuery(buffer2,db);
          row_count = 0 ;

          while(query2.next())
            {
              row_count = ui->tableWidget_income->rowCount(); //获取表单行数
              ui->tableWidget_income->insertRow(row_count); //插入新行
              QString month1= query2.value(2).toString();
              QString date1= query2.value(3).toString();
              QString amount1= query2.value(1).toString();
              QString reason1 = query2.value(5).toString();
              QString sort1 = query2.value(4).toString();
              QString time1 = month1+"."+date1;
              QTableWidgetItem *item = new QTableWidgetItem();
              QTableWidgetItem *item1 = new QTableWidgetItem();
              QTableWidgetItem *item2 = new QTableWidgetItem();
              QTableWidgetItem *item3 = new QTableWidgetItem();
               qDebug()<<month1<<"  "<<date1<<"  "<<sort1<<" "<<time1<<endl;
              item->setText(sort1);
              item1->setText(amount1);
              item2->setText(reason1);
              item3->setText(time1);
              ui->tableWidget_income->setItem(row_count, 0, item);
              ui->tableWidget_income->setItem(row_count, 1, item1);
              ui->tableWidget_income->setItem(row_count, 2, item2);
              ui->tableWidget_income->setItem(row_count, 3, item3);
              row_count++;
            }

    }
}
