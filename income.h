#ifndef INCOME_H
#define INCOME_H
#include <iostream>
#include <string>
#include "IOE.h"
using namespace std;

class Income:public IOE
{
    private:
        string  Sort;
    public:
        Income(double amount,int month,int date,string reason,string Sort);//:IOE(amount,month,date,reason);
        virtual ~Income();
};

#endif // INCOME_H
