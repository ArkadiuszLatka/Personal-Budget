#include "PersonalBudget.h"

bool PersonalBudget::isUserLogged()
{
    userManager.isUserLogged();
}

int PersonalBudget::getLoggedUserId(){
     userManager.getLoggedUserId();
}

 void PersonalBudget::userRegistration()
 {
     userManager.userRegistration();
 }

void PersonalBudget::userLogin() {
    userManager.userLogin();
    if(userManager.isUserLogged()){
    OperationsManager = new operationsManager (IncomeFileName,ExpenseFileName,userManager.getLoggedUserId());
    }
}

void PersonalBudget::changeLoggedUserPassword()
{
    userManager.changeLoggedUserPassword();
}

void PersonalBudget::logoutUser()
{
    userManager.logoutUser();
    delete OperationsManager;
    OperationsManager = NULL;

}
void PersonalBudget::addIncome()
{
    if (userManager.isUserLogged()) {
        OperationsManager->addIncome();
    } else {
        cout << "Log in to add income." << endl;
        system("pause");
    }
}
void PersonalBudget::addExpense()
{
    if (userManager.isUserLogged()) {
        OperationsManager->addExpense();
    } else {
        cout << "Log in to add expense." << endl;
        system("pause");
    }
}



