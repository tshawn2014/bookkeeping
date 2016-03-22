#ifndef IOBYMONTH_H
#define IOBYMONTH_H
#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
using namespace std;
//需要先行在数据库里面插入13行为除了月份各项为0的情况
//需要使用更新数据库的操作，当写回的时候
//查询数据库获得数据
//总收支调用的话13
//每次创建对象都要传月份（直接构造吧）
class IOByMonth
{
    private:
        int month;
        double income;
        double expense;
        double balance;
        QSqlDatabase db;
        //QSqlQuery query;
    public:
        IOByMonth(int month);
        bool createConnection();
        void setMonthIO(double expense2,double income2);
        int getMonth();//鸡肋
        double getIncome();//知道月份的情况下从数据库中查询，总收支的话月份就为13
        double getExpense();
        double getBalance();
        virtual ~IOByMonth();
};

#endif // IOBYMONTH_H

