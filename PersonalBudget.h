#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <windows.h>


#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include "User.h"
#include "operationsManager.h"

using namespace std;

class PersonalBudget {

    UserManager userManager;
    operationsManager *OperationsManager;
    const string IncomeFileName;
    const string ExpenseFileName;

    public:
    PersonalBudget (string usersFilename, string INCOMEFILENAME,string EXPENSEFILENAME )
        : userManager(usersFilename),IncomeFileName(INCOMEFILENAME),ExpenseFileName(EXPENSEFILENAME) {};
    ~PersonalBudget() {

    delete OperationsManager;
    }

    int getLoggedUserId();
    void loginMenu();
    void userRegistration();
    void userLogin();
    void logoutUser();

    void wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuEdycja();
    void changeLoggedUserPassword();
    void addIncome();
    void addExpense();
    bool isUserLogged();
    void showCurrentMonthBalance();
    void showLastMonthBalance();
    void showSelectPeriodBalance();
};
#endif
