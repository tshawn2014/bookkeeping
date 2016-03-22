#include "expense.h"
#include <iostream>
#include <string>
#include <QString>
#include <cstdlib>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

using namespace std;


Expense::Expense(double amount,int month,int date,string reason,string Sort):IOE(amount,month,date,reason)
{
    this ->Sort = Sort;
    //连接数据库，插入数据库的操作
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
    qDebug()<<"db.lastError().text();";
    //QMessageBox::critical(0,QObject::tr("Database Error"),db.lastError().text());
  }
  else{

      QString buffer = QString("insert into expense(amount,month,date,sort,reason)values(%1,%2,%3,'%4','%5')")
              .arg(this->amount)
              .arg(this->month)
              .arg(this->date)
              .arg(QString::fromStdString(this->Sort))
              .arg(QString::fromStdString(this->reason));

      QSqlQuery query(buffer,db);
      db.close();
      QSqlDatabase::removeDatabase("QMYSQL");
  }
}

Expense::~Expense()
{
    //dtor
}
