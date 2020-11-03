#ifndef OPERATIONSMANAGER_H
#define OPERATIONSMANAGER_H
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <conio.h>
#include <windows.h>

#include "income.h"
#include "operationsOnDate.h"
#include "AuxiliaryMethods.h"
#include "IncomeFiles.h"




class operationsManager {

    const  int loggedInUserId;;
    vector <income> incomes;
    vector <income> expenses;
    IncomeFiles incomeFiles;
    IncomeFiles expenseFiles;
    int getCurrentDate();
    int getUserDate();


public:
    operationsManager (string IncomeFileName,string ExpenseFileName,int LOGGEDINUSERID):incomeFiles(IncomeFileName),
    expenseFiles(ExpenseFileName),loggedInUserId(LOGGEDINUSERID) {
        incomes = incomeFiles.loadIncomeFromFile(loggedInUserId);
        expenses = expenseFiles.loadIncomeFromFile(loggedInUserId);

    };

    void addIncome();
    void addExpense();



};

#endif //FINANCIALOPERATIONSMANAGE
