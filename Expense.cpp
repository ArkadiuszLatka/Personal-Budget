#include "Expense.h"


int Expense::getExpenseId() {
    return expenseId;
}

int Expense::getUserId() {
    return userId;
}
int Expense::getDate() {
    return date;
}
string Expense::getItem() {
    return item;
}
double Expense::getAmount() {
    return amount;
}
string Expense::getStringValue() {
    return stringValue;
}
string Expense::getStringDate() {
    return stringDate;
}
void Expense::setExpenseId(int newExpenseId) {
    if (newExpenseId >= 0)
        expenseId = newExpenseId;
}

void Expense::setUserId(int newUserId) {
    userId = newUserId;
}
void Expense::setDate(int newDate) {
    date = newDate;
    stringDate = AuxiliaryMethods::intToString(date);
    stringDate.insert(6,"-");
    stringDate.insert(4,"-");
}
void Expense::setItem(string newItem) {
    item = newItem;
}
void Expense::setAmount(double newAmount) {
    amount = newAmount;
    stringValue = AuxiliaryMethods::doubleToString(amount);
}
//void income::setLastTransactionID(int ID)
//{
    //lastTransactionID = ID;
//}
