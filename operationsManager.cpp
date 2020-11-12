#include "operationsManager.h"


using namespace std;

void operationsManager::addIncome()
{
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

int operationsManager::getNewTransactionId(vector <Income> incomes)
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}
void operationsManager::addExpense()
{
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

void operationsManager::sortTransactions(vector<Income> &incomes,vector<Income> &expenses) {
    sort(incomes.begin(), incomes.end());
    sort(expenses.begin(), expenses.end());
}
void operationsManager::showCurrentMonthBalance()
{
    int incomesNumber =0;
    int expenseNumber =0;
    double incomeSum = 0;
    double expenseSum = 0;
    double mouthBalance = 0;
    //sortTransactions(incomes,expenses);

    int beginningDate = operationsOnDate::getBeginningOfMonth();
    cout <<AuxiliaryMethods::convertDateToString(beginningDate)<<endl;
    int endingDate = operationsOnDate::getEndOfMonth();
    cout <<AuxiliaryMethods::convertDateToString(endingDate)<<endl;

    if (!incomes.empty())
    {

        //sort(incomes.begin(), incomes.end());
        //incomes.begin(), incomes.end(),greater<Income>();
        //sort(expenses.begin(), expenses.end());

        cout<<"\nPRZYCHODY W BIEZACYM MIESIACU:\n\n";


        for (vector<Income>::iterator itr=incomes.begin(); itr!=incomes.end(); itr++)
        {

            if (((itr->getDate()) >= beginningDate) && (itr->getDate() <= endingDate))
            {
                cout << endl << "IncomeID: " << itr ->getIncomeId() << endl;
                cout << "Date:             "<< AuxiliaryMethods::convertDateToString(itr ->getDate()) << endl;
                cout << "Item:             " <<itr ->getItem() << endl;
                cout << "Amount:           " << setprecision(15) << itr ->getAmount() << endl;
                cout << "------------------------" << endl;
                AuxiliaryMethods::conversionFromDoubleToString(incomeSum +=  itr->getAmount());

            }

        }

        cout<<endl;
    }

    if (!expenses.empty())
    {

        cout<<"\nWYDATKI W BIEZACYM MIESIACU:\n\n";


        for (vector<Income>::iterator itr=expenses.begin(); itr!=expenses.end(); itr++)
        {
            if (((itr->getDate()) >= beginningDate) && (itr->getDate() <= endingDate))
            {
                 sort(incomes.begin(), incomes.end());
                cout << endl << "IncomeID: " << itr ->getIncomeId() << endl;
                cout << "Date:             "<< AuxiliaryMethods::convertDateToString(itr ->getDate()) << endl;
                cout << "Item:             " <<itr ->getItem() << endl;
                cout << "Amount:           " << setprecision(15) << itr ->getAmount() << endl;
                cout << "------------------------" << endl;
                AuxiliaryMethods::conversionFromDoubleToString(expenseSum +=  itr->getAmount());
                expenseNumber++;
            }

        }
        cout<<">>>>MIESIECZNY BILANS PRZYCHODOW I WYDATKOW<<<< "<<endl;
        mouthBalance = incomeSum - expenseSum;
        cout<<"SUMA PRZYCHODOW   "<<incomeSum<<" zl"<<endl;
        cout<<"SUMA WYDATKOW     "<<expenseSum<<" zl"<<endl;
        cout<<"BILANS            "<<mouthBalance<<" zl"<<endl;


    }
    system("pause");
}
void operationsManager::showLastMonthBalance()
{
    int incomesNumber =0;
    int expenseNumber =0;
    double incomeSum = 0;
    double expenseSum = 0;
    double mouthBalance =0;


    int beginningDate = operationsOnDate::getBeginningOfLastMonth();
    cout <<AuxiliaryMethods::convertDateToString(beginningDate)<<endl;
    int endingDate = operationsOnDate::getEndOfLastMonth();
    cout <<AuxiliaryMethods::convertDateToString(endingDate)<<endl;
    if (!incomes.empty())
    {


        incomes.begin(), incomes.end(),greater<Income>();


        cout<<"\nPRZYCHODY W POPRZEDNIM MIESIACU:\n\n";


        for (vector<Income>::iterator itr=incomes.begin(); itr!=incomes.end(); itr++)
        {
            if (((itr->getDate()) >= beginningDate) && (itr->getDate() <= endingDate))
            {
                cout << endl << "IncomeID: " << itr ->getIncomeId() << endl;
                cout << "Date:             "<< AuxiliaryMethods::convertDateToString(itr ->getDate()) << endl;
                cout << "Item:             " <<itr ->getItem() << endl;
                cout << "Amount:           " << setprecision(15) << itr ->getAmount() << endl;
                cout << "------------------------" << endl;
                AuxiliaryMethods::conversionFromDoubleToString(incomeSum +=  itr->getAmount());

            }

        }

        cout<<endl;
    }

    if (!expenses.empty())
    {

        cout<<"\nWYDATKI W POPRZEDNIM MIESIACU:\n\n";


        for (vector<Income>::iterator itr=expenses.begin(); itr!=expenses.end(); itr++)
        {
            if (((itr->getDate()) >= beginningDate) && (itr->getDate() <= endingDate))
            {
                cout << endl << "IncomeID: " << itr ->getIncomeId() << endl;
                cout << "Date:             "<< AuxiliaryMethods::convertDateToString(itr ->getDate()) << endl;
                cout << "Item:             " <<itr ->getItem() << endl;
                cout << "Amount:           " << setprecision(15) << itr ->getAmount() << endl;
                cout << "------------------------" << endl;
                AuxiliaryMethods::conversionFromDoubleToString(expenseSum +=  itr->getAmount());
                expenseNumber++;
            }

        }
        cout<<">>>> BILANS PRZYCHODOW I WYDATKOW<<<< "<<endl;
        mouthBalance = incomeSum - expenseSum;
        cout<<"SUMA PRZYCHODOW   "<<incomeSum<<" zl"<<endl;
        cout<<"SUMA WYDATKOW     "<<expenseSum<<" zl"<<endl;
        cout<<"BILANS            "<<mouthBalance<<" zl"<<endl;


    }
    system("pause");
}
void operationsManager::showSelectPeriodBalance()
{
    system("cls");
    int incomesNumber =0;
    int expenseNumber =0;
    double incomeSum = 0;
    double expenseSum = 0;
    double mouthBalance =0;

    cout<<"Podaj okres z jakiego chcesz otrzymac dane."<<endl;
    cout<<"Data rozpoczynajaca okres w formacie rrrr-mm-dd: "<<endl;
    int beginningDate = operationsOnDate::getUserDate();

    cout<<"Data konczaca okres w formacie rrrr-mm-dd: ";
    int endingDate = operationsOnDate::getUserDate();

    if (!incomes.empty())
    {


        cout<<"\nPRZYCHODY W WYBRANYM OKRESIE :\n\n"<<endl;
        cout<<"OD  "<<AuxiliaryMethods::convertDateToString(beginningDate)<<endl;
        cout<<"DO  "<<AuxiliaryMethods::convertDateToString(endingDate)<<endl;


        for (vector<Income>::iterator itr=incomes.begin(); itr!=incomes.end(); itr++)
        {
            if (((itr->getDate()) >= beginningDate) && (itr->getDate() <= endingDate))
            {
                cout << endl << "IncomeID: " << itr ->getIncomeId() << endl;
                cout << "Date:             "<< AuxiliaryMethods::convertDateToString(itr ->getDate()) << endl;
                cout << "Item:             " <<itr ->getItem() << endl;
                cout << "Amount:           " << setprecision(15) << itr ->getAmount() << endl;
                cout << "------------------------" << endl;
                AuxiliaryMethods::conversionFromDoubleToString(incomeSum +=  itr->getAmount());

            }

        }

        cout<<endl;
    }

    if (!expenses.empty())
    {

        cout<<"\nWYDATKI W WYBRANYM OKRESIE:\n\n";
        cout<<"OD  "<<AuxiliaryMethods::convertDateToString(beginningDate)<<endl;
        cout<<"DO  "<<AuxiliaryMethods::convertDateToString(endingDate)<<endl;

        for (vector<Income>::iterator itr=expenses.begin(); itr!=expenses.end(); itr++)
        {
            if (((itr->getDate()) >= beginningDate) && (itr->getDate() <= endingDate))
            {
                cout << endl << "IncomeID: " << itr ->getIncomeId() << endl;
                cout << "Date:             "<< AuxiliaryMethods::convertDateToString(itr ->getDate()) << endl;
                cout << "Item:             " <<itr ->getItem() << endl;
                cout << "Amount:           " << setprecision(15) << itr ->getAmount() << endl;
                cout << "------------------------" << endl;
                AuxiliaryMethods::conversionFromDoubleToString(expenseSum +=  itr->getAmount());
                expenseNumber++;
            }

        }
        cout<<">>>> BILANS PRZYCHODOW I WYDATKOW<<<< "<<endl;
        mouthBalance = incomeSum - expenseSum;
        cout<<"SUMA PRZYCHODOW   "<<incomeSum<<" zl"<<endl;
        cout<<"SUMA WYDATKOW     "<<expenseSum<<" zl"<<endl;
        cout<<"BILANS            "<<mouthBalance<<" zl"<<endl;


    }
    system("pause");
}
