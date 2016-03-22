#ifndef EXPENSEBYSORT_H
#define EXPENSEBYSORT_H
#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
using namespace std;


class expenseBySort
{
    private:
        string Sort;
        double expense;
        QSqlDatabase db;
        //QSqlQuery query;
    public:
        expenseBySort(string Sort);
        bool createConnection();
        void setSortExpense(double expense2);
        string getSort();//¼¦Àß
        double getExpense();
        virtual ~expenseBySort();
};

#endif // EXPENSEBYSORT_H
