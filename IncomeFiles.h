#ifndef INCOMEFILES_H
#define INCOMEFILES_H

#include <iostream>
#include <vector>
#include <sstream>
#include "income.h"
#include "Markup.h"

using namespace std;

class IncomeFiles {

    income Income;
    vector<income>incomes;
    const string IncomeFileName;


public:

    IncomeFiles (string INCOMEFILENAME):IncomeFileName(INCOMEFILENAME)
    {};

    vector<income> loadIncomeFromFile( int loggedInUserId);
    void addIncomeToFile(income Income);
    int getNewTransactionId(vector<income> incomes);


};

#endif
