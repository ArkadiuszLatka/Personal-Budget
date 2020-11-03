#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "AuxiliaryMethods.h"
#include "operationsOnDate.h"


class income {
    int incomeId;
    int userId;
    int date;;
    string item;
    double amount;
    string stringDate;


public:

    int getIncomeId();
    int getUserId();
    int getDate();

    string getItem();
    double getAmount();



    void setIncomeId (int newIncomeId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);
};

#endif
