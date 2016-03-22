#include "iobymonth.h"
#include <iostream>
#include <string>
#include <QString>
#include <QVariant>
#include <cstdlib>
using namespace std;

IOByMonth::IOByMonth(int month)
{
    this-> month = month;//ctor
}

bool IOByMonth::createConnection()
{
  //QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");//建立与MySQL数据库的连接
    //QSqlDatabase db;
      if(QSqlDatabase::contains("mydata"))
          db = QSqlDatabase::database("mydata");
      else
          db = QSqlDatabase::addDatabase("QMYSQL","mydata");
  db.setHostName("localhost");
  db.setDatabaseName("mydata");//设置数据库名称
  //告知数据库的用户名和密码
  db.setUserName("root");
  db.setPassword("");
  if(!db.open())
  {
    //QMessageBox::critical(0,QObject::tr("Database Error"),db.lastError().text());
    return false;
  }

  return true;
}

void IOByMonth::setMonthIO(double expense2,double income2)
{
     this->expense = getExpense() + expense2;
     this->income  = getIncome()+ income2;
     this->balance = this->income - this->expense;
     //更新数据库，将这些数据全部写入


     if(!createConnection())
     {
        exit(0);
     }
     QString buffer = QString("UPDATE iobymonth SET expense = %1,income = %2,balance = %3  where month = %4")
             .arg(this->expense)
             .arg(this->income)
             .arg(this->balance)
             .arg(this->month);
     QSqlQuery query = QSqlQuery(buffer,db);
    db.close();

}
int IOByMonth::getMonth()//感觉无用诶
{
    //从数据库中查询条件，用月份作为条件
     if(!createConnection())
     {
        exit(0);
     }
     QString buffer = QString("select month from iobymonth where month = %1").arg(this->month);
     QSqlQuery query = QSqlQuery(buffer,db);
    while(query.next())

       {

          this ->month=query.value(0).toInt();
       }
    db.close();
    return this ->month;
}
double IOByMonth::getIncome()//知道月份的情况下从数据库中查询，总收支的话月份就为13
{
    //从数据库中查询条件，用月份作为条件
     if(!createConnection())
     {
        exit(0);
     }
     QString buffer = QString("select income from iobymonth where month = %1").arg(this->month);
     QSqlQuery query = QSqlQuery(buffer,db);
    while(query.next())

       {

          this ->income=query.value(0).toDouble();
       }
    db.close();
    return this ->income;
}
double IOByMonth::getExpense()
{
   //从数据库中查询条件，用月份作为条件
     if(!createConnection())
     {
       exit(0);
     }
     QString buffer = QString("select expense from iobymonth where month = %1").arg(this->month);
     QSqlQuery query = QSqlQuery(buffer,db);
     while(query.next())
     {
          this ->expense = query.value(0).toDouble();
     }
     db.close();
    return this ->expense;
}
double IOByMonth::getBalance()
{
    //从数据库中查询条件，用月份作为条件
     if(!createConnection())
     {
        exit(0);
     }
     QSqlQuery query = QSqlQuery(db);
     query.prepare("select balance from iobymonth where month = :month");
     query.bindValue(":month", this->month);
     query.exec();
    while(query.next())
       {

          this ->balance = query.value(0).toDouble();
       }
    db.close();
    return this ->balance;
}

IOByMonth::~IOByMonth()
{
    //dtor
}
