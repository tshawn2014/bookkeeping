#include "IOE.h"
#include <iostream>
#include <string>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
using namespace std;
//对数据库进行变量的赋值
//SET可以少很多，get还是要有
//IOE中的get方法可以不要了，直接用一个函数代替输入条目的那种情况
//父类中不插入数据库，到子类的函数中再插入吧


IOE::IOE(double amount,int month,int date,string reason)
{
    this->amount = amount;//ctor
    this->month = month;
    this->date = date;
    this->reason = reason;
}//重载构造函数

bool IOE::createConnection()
{
 // QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");//建立与MySQL数据库的连接
  //QSqlDatabase db;
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
    return false;
  }
  return true;
}


IOE::~IOE()
{
    //dtor
}
