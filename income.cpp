#include "income.h"

void income::setIncomeId(int newIncomeId) {
    if (newIncomeId >= 0)
        incomeId = newIncomeId;
}

void income::setUserId(int newUserId) {
    userId = newUserId;
}

void income::setItem(string newItem) {
    item = newItem;
}
void income::setAmount(double newAmount)
{
    if(newAmount<0)
        newAmount*=(-1);
    amount = newAmount;
}

int income::getIncomeId() {
    return incomeId;
}

int income::getUserId() {
    return userId;
}
int income::getDate() {
    return date;
}
string income::getItem() {
    return item;
}
double income::getAmount() {
    return amount;
}
void income::setDate(int newDate) {
    date = newDate;
    stringDate = AuxiliaryMethods::intToString(date);
    stringDate.insert(6,"-");
    stringDate.insert(4,"-");
}

