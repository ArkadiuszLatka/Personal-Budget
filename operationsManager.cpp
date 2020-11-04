#include "operationsManager.h"


using namespace std;

void operationsManager::addIncome() {
    char choice;
    income Income;
    string incomeName;


    cout<<"DODAJ PRZYCHOD\n\n";
    cout<<"Aby dodac przychod z dnia dzisiejszego wybierz 1. \n"
    "Aby wpisac date recznie wybierz 2.\n";

    choice = AuxiliaryMethods::loadCharacter();
    if (choice == '1')
    {
        Income.setDate(operationsOnDate::getCurrentDate());

    }
    else if (choice == '2')
    {
        cout<<"Wprowadz date uzyskania przychodu w formacie rrrr-mm-dd: ";

        Income.setDate(operationsOnDate::getUserDate());
    }
    else
    {
        cout<< "Nie ma takiej opcji. Wybierz jeszcze raz.";
    }
    Income.setIncomeId(getNewTransactionId(incomes) );

    Income.setUserId(loggedInUserId);

    cout << "Wprowadz rodzaj uzyskanego przychodu: "<<endl;
    incomeName =AuxiliaryMethods::loadLine();
    Income.setItem(incomeName);



    cout<<"Wprowadz wysokosc przychodu: ";
    Income.setAmount(AuxiliaryMethods::getMoneyAmountFromUser());

    incomes.push_back(Income);
    incomeFiles.addIncomeToFile(Income);


}
int operationsManager::getNewTransactionId(vector <income> incomes) {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}
void operationsManager::addExpense() {
    char choice;
    income expense;
    string exspenseName;


    cout<<"DODAJ WYDATEK\n\n";
    cout<<"Aby dodac wydatek z dnia dzisiejszego wybierz 1. \n"
    "Aby wpisac date recznie wybierz 2.\n";

    choice = AuxiliaryMethods::loadCharacter();
    if (choice == '1')
    {
        expense.setDate(operationsOnDate::getCurrentDate());

    }
    else if (choice == '2')
    {
        cout<<"Wprowadz date  wydatku w formacie rrrr-mm-dd: ";

        expense.setDate(operationsOnDate::getUserDate());
    }
    else
    {
        cout<< "Nie ma takiej opcji. Wybierz jeszcze raz.";
    }
    expense.setIncomeId(getNewTransactionId(expenses) );

    expense.setUserId(loggedInUserId);

    cout << "Wprowadz rodzaj wydatku: "<<endl;
    exspenseName =AuxiliaryMethods::loadLine();
    expense.setItem(exspenseName);



    cout<<"Wprowadz wysokosc wydatku: ";
    expense.setAmount(AuxiliaryMethods::getMoneyAmountFromUser());

    expenses.push_back(expense);
    expenseFiles.addExpenseToFile(expense);


}
