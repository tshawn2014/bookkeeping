#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>
#include <string>
#include "IOE.h"
using namespace std;

class Expense:public IOE
{
    private:
        string  Sort;
    public:
        Expense(double amount,int month,int date,string reason,string Sort);//:IOE(amount,month,date,reason);
        virtual ~Expense();
};

#endif // EXPENSE_H
