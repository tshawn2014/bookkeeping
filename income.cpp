#include "income.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
using namespace std;

Income::Income(double amount,int month,int date,string reason,string Sort):IOE(amount,month,date,reason)
{
    QString buffer;
    this ->Sort = Sort;
    //连接数据库，插入数据库的操作

    if(QSqlDatabase::contains("mydata"))
        db = QSqlDatabase::database("mydata");
    else
        db = QSqlDatabase::addDatabase("QMYSQL","mydata");
    qDebug()<<db.isValid();
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
     buffer = QString("insert into income(amount,month,date,sort,reason)values(%1,%2,%3,'%4','%5')")
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

Income::~Income()
{
    //dtor
}
