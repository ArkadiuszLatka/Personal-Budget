#include "operationsManager.h"


using namespace std;

void operationsManager::addIncome() {
    char choice;
    Income income;
    string incomeName, amount;



    cout<<"DODAJ PRZYCHOD\n\n";
    cout<<"Aby dodac przychod z dnia dzisiejszego wybierz 1. \n"
    "Aby wpisac date recznie wybierz 2.\n";

    choice = AuxiliaryMethods::loadCharacter();
    if (choice == '1')
    {
        income.setDate(operationsOnDate::getCurrentDate());

    }
    else if (choice == '2')
    {
        cout<<"Wprowadz date uzyskania przychodu w formacie rrrr-mm-dd: ";

        income.setDate(operationsOnDate::getUserDate());
    }
    else
    {
        cout<< "Nie ma takiej opcji. Wybierz jeszcze raz.";
    }
    income.setIncomeId(getNewTransactionId(incomes) );

    income.setUserId(loggedInUserId);

    cout << "Wprowadz rodzaj uzyskanego przychodu: "<<endl;
    incomeName =AuxiliaryMethods::loadLine();
    income.setItem(incomeName);



    cout<<"Wprowadz wysokosc przychodu: ";
    amount =AuxiliaryMethods::loadLine();
    income.setAmount(AuxiliaryMethods::conversionFromStringToDouble(amount));

    incomes.push_back(income);
    incomeFiles.addIncomeToFile(income);


}

int operationsManager::getNewTransactionId(vector <Income> incomes) {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}
void operationsManager::addExpense() {
    char choice;
    Income expense;
    string exspenseName,amount;


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
    amount =AuxiliaryMethods::loadLine();
    expense.setAmount(AuxiliaryMethods::conversionFromStringToDouble(amount));

    expenses.push_back(expense);
    expenseFiles.addExpenseToFile(expense);


}
