#include "income.h"

void Income::setIncomeId(int newIncomeId) {
    if (newIncomeId >= 0)
        incomeId = newIncomeId;
}

void Income::setUserId(int newUserId) {
    userId = newUserId;
}

void Income::setItem(string newItem) {
    item = newItem;
}
void Income::setAmount(double newAmount)
{
    if(newAmount<0)
        newAmount*=(-1);
    amount = newAmount;
}

int Income::getIncomeId() {
    return incomeId;
}

int Income::getUserId() {
    return userId;
}
int Income::getDate() {
    return date;
}
string Income::getItem() {
    return item;
}
double Income::getAmount() {
    return amount;
}
void Income::setDate(int newDate) {
    date = newDate;
    stringDate = AuxiliaryMethods::intToString(date);
    stringDate.insert(6,"-");
    stringDate.insert(4,"-");
}

