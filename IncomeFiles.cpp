#include "IncomeFiles.h"



vector<Income> IncomeFiles::loadIncomeFromFile( int loggedInUserId){

    vector<Income>incomes;
    CMarkup xml;
    xml.Load(incomeFileName);

    while (xml.FindElem("INCOME")) {
        Income income;
        xml.IntoElem();
        xml.FindElem("USERID");
        int userId = atoi(MCD_2PCSZ(xml.GetData()));
        if (userId == loggedInUserId) {
            xml.ResetMainPos();
            xml.IntoElem();
            xml.FindElem("INCOMEID");
            income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("DATE");
            income.setDate(operationsOnDate::convertStringDateToInt(xml.GetData()));
            xml.FindElem("ITEM");
            income.setItem(xml.GetData());
            xml.FindElem("AMOUNT");
            income.setAmount(AuxiliaryMethods::stringToDouble(xml.GetData()));

            incomes.push_back(income);

        }
        xml.OutOfElem();
    }
    return incomes;
}
vector<Income> IncomeFiles::loadExpenseFromFile( int loggedInUserId){

    vector<Income>incomes;
    CMarkup xml;
    xml.Load(incomeFileName);

    while (xml.FindElem("Expense")) {
        Income income;
        xml.IntoElem();
        xml.FindElem("USERID");
        int userId = atoi(MCD_2PCSZ(xml.GetData()));
        if (userId == loggedInUserId) {
            xml.ResetMainPos();
            xml.IntoElem();
            xml.FindElem("EXPENSEID");
            income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("DATE");
            income.setDate(operationsOnDate::convertStringDateToInt(xml.GetData()));
            xml.FindElem("ITEM");
            income.setItem(xml.GetData());
            xml.FindElem("AMOUNT");
            income.setAmount(AuxiliaryMethods::stringToDouble(xml.GetData()));

            incomes.push_back(income);

        }
        xml.OutOfElem();
    }
    return incomes;
}
void IncomeFiles::addIncomeToFile (Income income) {
    CMarkup xml;

    xml.Load(incomeFileName);
    xml.AddElem( "INCOME" );
    xml.IntoElem();
    {
        xml.AddElem( "INCOMEID", income.getIncomeId() );
        xml.AddElem( "USERID", income.getUserId() );
        xml.AddElem( "DATE", AuxiliaryMethods::convertDateToString(income.getDate()));
        xml.AddElem( "ITEM", income.getItem() );
        xml.AddElem( "AMOUNT", income.getAmount() );
    }

    xml.OutOfElem();
    xml.Save(incomeFileName);


}
void IncomeFiles::addExpenseToFile (Income income) {
    CMarkup xml;

    xml.Load(incomeFileName);
    xml.AddElem( "Expense" );
    xml.IntoElem();
    {
        xml.AddElem( "EXPENSEID", income.getIncomeId() );
        xml.AddElem( "USERID", income.getUserId() );
        xml.AddElem( "DATE", AuxiliaryMethods::convertDateToString(income.getDate()));
        xml.AddElem( "ITEM", income.getItem() );
        xml.AddElem( "AMOUNT", income.getAmount() );
    }

    xml.OutOfElem();
    xml.Save(incomeFileName);
}



