#include "IncomeFiles.h"



vector<income> IncomeFiles::loadIncomeFromFile( int loggedInUserId){
    CMarkup xml;

    income Income;
    vector<income>incomes;

    xml.Load(IncomeFileName);
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("INCOME")) {
        xml.IntoElem();
        xml.FindElem("USERID");
        int userId = atoi(MCD_2PCSZ(xml.GetData()));
        if (userId == loggedInUserId) {
            Income.setUserId(userId);
            xml.FindElem("INCOMEID");
            Income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("DATE");
            Income.setDate(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("ITEM");
            Income.setItem(xml.GetData());
            xml.FindElem("AMOUNT");
            Income.setAmount(AuxiliaryMethods::stringToDouble(xml.GetData()));

        if (loggedInUserId == Income.getUserId()){
            incomes.push_back(Income);
        }
        }
        xml.OutOfElem();
    }
    return incomes;
}

int IncomeFiles::getNewTransactionId(vector <income> incomes) {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

void IncomeFiles::addIncomeToFile (income Income) {
    CMarkup xml;

    xml.Load(IncomeFileName);
    xml.AddElem( "INCOME" );
    xml.IntoElem();
    {
        xml.AddElem( "INCOMEID", Income.getIncomeId() );
        xml.AddElem( "USERID", Income.getUserId() );
        xml.AddElem( "DATE", AuxiliaryMethods::convertDateToString(Income.getDate()));
        xml.AddElem( "ITEM", Income.getItem() );
        xml.AddElem( "AMOUNT", Income.getAmount() );
    }

    xml.OutOfElem();
    xml.Save(IncomeFileName);

}



