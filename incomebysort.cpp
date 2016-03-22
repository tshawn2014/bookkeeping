#include "incomeBySort.h"
#include <iostream>
#include <string>
#include <QString>
#include <cstdlib>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QVariant>
using namespace std;

incomeBySort::incomeBySort(string Sort)
{
    this->Sort = Sort;//ctor
}
bool incomeBySort::createConnection()
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
void incomeBySort::setSortIncome(double income2)
{

     income = getIncome()+income2;
     //更新数据库，写回
     if(!createConnection())
     {
        exit(0);
     }

       QString buffer = QString("UPDATE incomebysort SET income = %1 where sort = '%2'")
               .arg(income2)
               .arg(QString::fromStdString(this->Sort));
       QSqlQuery query(buffer,db);
    db.close();

}
string incomeBySort::getSort()
{

     if(!createConnection())
     {
        exit(0);
     }

     QString buffer = QString("select sort from incomebysort where sort = '%1'")
             .arg(QString::fromStdString(this->Sort));
    QSqlQuery query(buffer,db);

    while(query.next())
       {
         QString strtemp = query.value(0).toString();
         this->Sort = strtemp.toStdString();
       }
    db.close();
    return this ->Sort;
}
double incomeBySort::getIncome()
{
     if(!createConnection())
     {
        exit(0);
     }
    // query.prepare("select income from incomebysort where sort = :sort");
     //query.bindValue(":sort", QString::fromStdString(this->Sort));
     QString buffer = QString("select income from incomebysort where sort = '%1'")
             .arg(QString::fromStdString(this->Sort));
    QSqlQuery query(buffer,db);
    while(query.next())
       {
         this ->income = query.value(0).toDouble();
       }
    db.close();
    return this ->income;
}
incomeBySort::~incomeBySort()
{
    //dtor
}
