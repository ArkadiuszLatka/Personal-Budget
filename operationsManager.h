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
    vector <Income> incomes;
    vector <Income> expenses;
    IncomeFiles incomeFiles;
    IncomeFiles expenseFiles;
    int getCurrentDate();
    int getUserDate();
    int getNewTransactionId(vector <Income> incomes);


public:
   operationsManager (string incomeFileName,string expenseFileName,int LOGGEDINUSERID):incomeFiles(incomeFileName),
    expenseFiles(expenseFileName),loggedInUserId(LOGGEDINUSERID) {
        incomes = incomeFiles.loadIncomeFromFile(loggedInUserId);
        expenses = expenseFiles.loadExpenseFromFile(loggedInUserId);

    };
    void loadIncomeFromFile();
    void addIncome();
    void addExpense();



};

#endif //FINANCIALOPERATIONSMANAGE
