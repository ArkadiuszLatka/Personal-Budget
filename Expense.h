#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "AuxiliaryMethods.h"
#include "operationsOnDate.h"
using namespace std;

class Expense {
    int expenseId;
    int id;
    int userId;
    int date;
    string item;
    double amount;
    string stringValue;
    string stringDate;
    int lastTransactionID;

public:
    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();
    string getStringValue();
    string getStringDate();

    void setExpenseId (int newExpenseId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);
};

#endif
