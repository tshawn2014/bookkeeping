#include "expenseBySort.h"
#include <iostream>
#include <string>
#include <QString>
#include <cstdlib>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

using namespace std;



expenseBySort::expenseBySort(string Sort)
{
    this ->Sort = Sort;
}

bool expenseBySort::createConnection()
{
    //QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");//建立与MySQL数据库的连接

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

void expenseBySort::setSortExpense(double expense2)
{
    expense = getExpense() + expense2;
    //更新数据库，写回
     if(!createConnection())
     {
        exit(0);
     }
     QString buffer = QString("UPDATE expensebysort SET expense = %1 where sort = '%2'")
               .arg(expense2)
               .arg(QString::fromStdString(this->Sort));

      QSqlQuery query(buffer,db);
    db.close();
}
string expenseBySort::getSort()
{
    //数据库中查询
     if(!createConnection())
     {
        exit(0);
     }

     QString buffer = QString("select sort from expensebysort where sort = '%1'")
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
double expenseBySort::getExpense()
{
   //数据库中查询
     if(!createConnection())
     {
        exit(0);
     }

     QString buffer = QString("select expense from expensebysort where sort = '%1'").arg(QString::fromStdString(this->Sort));
     QSqlQuery query = QSqlQuery(buffer,db);
     query.exec();
    while(query.next())
       {
         this ->expense = query.value(0).toDouble();
       }
    db.close();
    return this->expense;
}

expenseBySort::~expenseBySort()
{
    //dtor
}
