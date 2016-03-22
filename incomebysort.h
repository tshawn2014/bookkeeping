#ifndef INCOMEBYSORT_H
#define INCOMEBYSORT_H
#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
using namespace std;


class incomeBySort
{
    private:
        string Sort;
        double income;
        QSqlDatabase db;
        //QSqlQuery query;
    public:
        incomeBySort(string Sort);
        bool createConnection();
        void setSortIncome(double income2);
        string getSort();//¼¦Àß
        double getIncome();
        virtual ~incomeBySort();
};

#endif // INCOMEBYSORT_H
