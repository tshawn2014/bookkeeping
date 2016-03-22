#ifndef IOE_H
#define IOE_H
#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
using namespace std;


class IOE
{
     protected:
        double amount;
        int month;
        int date;
        string reason;
        QSqlDatabase db;
        //QSqlQuery query;
     public:
        IOE(double amount,int month,int date,string reason);
        bool createConnection();
        virtual ~IOE();
};

#endif // IOE_H
