#ifndef INCOMEFILES_H
#define INCOMEFILES_H

#include <iostream>
#include <vector>
#include <sstream>
#include "income.h"
#include "Markup.h"

using namespace std;

class IncomeFiles {

    Income income;
    vector<Income>incomes;
    const string incomeFileName;


public:

    IncomeFiles (string INCOMEFILENAME):incomeFileName(INCOMEFILENAME)
    { };

    vector<Income> loadIncomeFromFile( int loggedInUserId);
    vector<Income> loadExpenseFromFile( int loggedInUserId);
    void addIncomeToFile(Income income);
    void addExpenseToFile (Income income);



};

#endif
