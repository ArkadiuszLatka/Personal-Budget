#include "operationsOnDate.h"



int operationsOnDate::getCurrentDate() {
    int currentDate;
    time_t t = time(0);
    tm* now = localtime(&t);
    currentDate = AuxiliaryMethods::tmToInt(now);
    return currentDate;
}
int operationsOnDate::getTodaysDate()
{
    int date;
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    date = (now->tm_year + 1900)*10000+
            (now->tm_mon + 1)*100+
            (now->tm_mday);
    return date;
}
int operationsOnDate::getUserDate() {
    int integerUserDate = NULL;
    string stringUserDate = "";
    do {
        getline(cin, stringUserDate);
        if (correctSignsInDate(stringUserDate)) {
            integerUserDate = convertStringDateToInt(stringUserDate);
            if (integerUserDate != 0)
                break;
        }
        cout << "Wpisz poprawna date: " << endl;
    } while (true);
    return integerUserDate;
}
bool operationsOnDate::correctSignsInDate(string date) {
    int dashCounter = 0;
    if (date[0] == '-') {
        cout << "Zly format daty. #1" << endl;
        return false;
    }
    for (int i = 0; i < date.size(); i++) {
        int sign = date[i];
        if (((sign < 48) || (sign > 57)) && (sign != 45)) {
            cout << "Niedozwolony znak w dacie." << endl;
            return false;
        }
        else if (sign == 45 && int(date[i+1]) == 45) {
            cout << "Zly format daty. #2" << endl;
            return false;
        }
        if (sign == 45) {
            dashCounter++;
        }
    }
    if ((dashCounter != 2) || (date[date.size() - 1] == 45)) {
        cout << "Zly format daty. #3" << endl;
        return false;
    }
    return true;
}
int operationsOnDate::convertStringDateToInt(string date) {
    int i = 0, year = 0, month = 0, day = 0, intDate = 0;
    time_t t = time(0);
    tm* now = localtime(&t);
    for(; (int(date[i]) >= 48) && (int(date[i]) <= 57); i++) {
        year=year*10+int(date[i])-48;
    }
    i++;
    for(; (int(date[i]) >= 48) && (int(date[i]) <= 57); i++) {
        month=month*10+int(date[i])-48;
    }
    i++;
    for(; i < date.size(); i++) {
        day=day*10+int(date[i])-48;
    }
    if ((year < 2000) || (year > (now->tm_year + 1900))) {
        cout << "Niepoprawny rok." << endl;
        return 0;
    }
    if ( ((month < 1) || (month > 12)) || (year == (now->tm_year + 1900) && month > (now->tm_mon + 1)) ) {
        cout << "Niepoprawny miesiac." << endl;
        return 0;
    }
    if ((day == 0) || (day > daysInMonth(year,month))) {
        cout << "Niepoprawny dzien." << endl;
        return 0;
    }
    intDate = (year * pow (10,4)) + (month * pow (10,2)) + day;
    return intDate;
}
int operationsOnDate::daysInMonth(int year, int month) {
    int days;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else if (month == 02) {
        bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (!leapYear)
            days = 28;
        else
            days = 29;
    } else
        days = 31;
    return days;
}
double operationsOnDate::getTransactionValue() {
    double transactionValue = 0;
    string stringValue = "";
    do {
        getline(cin, stringValue);
        if (correctSignsInValue(stringValue)) {
            transactionValue = convertStringValueToDouble(stringValue);
            break;
        }
        cout << "Wpisz poprawna wartosc: " << endl;
    } while (true);
    return transactionValue;
}
bool operationsOnDate::correctSignsInValue(string stringValue) {
    int dotCounter = 0;
    for (int i = 0; i < stringValue.size(); i++) {
        int sign = stringValue[i];
        if (sign == 44 || sign == 46) {
            dotCounter++;
            if (stringValue.size() > i+3) {
                cout << "Zly format wartosci: waluta z dokladnoscia do 0.01 ." << endl;
                return false;
            }
        }
        if (((sign < 48) || (sign > 57)) && (sign != 46)&& (sign != 44)) {
            cout << "Niepoprawny znak w wartosci." << endl;
            return false;
        }
    }
    if (dotCounter > 1) {
        cout << "Zly format wartosci: zbyt wiele przecinkow." << endl;
        return false;
    }
    if (stringValue.empty()) {
        cout << "Nie wprowadzono wartosci." << endl;
        return false;
    }
    return true;
}
double operationsOnDate::convertStringValueToDouble(string stringValue) {
    double doubleValue = 0;
    for (int i = 0, j = stringValue.size()-1; i < stringValue.size(); i++, j--) {
            int sign = stringValue[i];
            if (sign == 44 || sign == 46) {
                    doubleValue = doubleValue / pow(10,j+1);
                    j = 0;
            }
            else {
                    doubleValue = doubleValue + ((sign - 48) * pow(10,j));
            }
    }
    return doubleValue;
}
int operationsOnDate::getEndOfMonth()
{
    int todaysDate = getTodaysDate();
    int month =(todaysDate/100)%100;
    int year = (todaysDate/10000);
    int days = getNumberOfDaysInMonth(todaysDate);
    int endOfMonth = year*10000+month*100+days;

    return endOfMonth;
}

int operationsOnDate::getBeginningOfMonth()
{
    int todaysDate = getTodaysDate();
    int beginningOfMonth = (todaysDate/100)*100+1;
    return beginningOfMonth;
}

int operationsOnDate::getEndOfLastMonth()
{
    int todaysDate = getTodaysDate();
    int year = (todaysDate/10000);
    int month =(todaysDate/100)%100;
    if(month == 1)
    {
        month = 12;
        year-=1;
    }
    else
        month -= 1;

    int date = year*10000+month*100+1;
    int days = getNumberOfDaysInMonth(date);

    int endOfMonth = year*10000+month*100+days;
    return endOfMonth;
}

int operationsOnDate::getBeginningOfLastMonth()
{
    int todaysDate = getTodaysDate();
    int year = (todaysDate/10000);
    int month =(todaysDate/100)%100;

    if(month == 1)
    {
        month = 12;
        year-=1;
    }
    else
        month -= 1;
    cout<<month<<endl;
    int beginningOfMonth = year*10000+month*100+1;

    return beginningOfMonth;
}

string operationsOnDate::getMonthName(int date)
{
    int month =(date/100)%100;
    string monthName="";
    switch (month)
    {
        case 1:
        monthName="styczniu"; break;
        case 2:
        monthName="lutym"; break;
        case 3:
        monthName="marcu"; break;
        case 4:
        monthName="kwietniu"; break;
        case 5:
        monthName="maju"; break;
        case 6:
        monthName="czerwcu"; break;
        case 7:
        monthName="lipcu"; break;
        case 8:
        monthName="sierpniu"; break;
        case 9:
        monthName="wrzesniu"; break;
        case 10:
        monthName="pazdzierniku"; break;
        case 11:
        monthName="listopadzie"; break;
        case 12:
        monthName="grudniu"; break;
    }
    return monthName;
}

int operationsOnDate::getNumberOfDaysInMonth(int date)
{
    int month =(date/100)%100;
    int year = (date/10000);
    int days;
    if(month == 2)
    {
        if(((year%4==0)&&(year%100!=0))||(year%400==0))
            days = 29;
        else
            days = 28;
    }
    else if((month <=7 && month%2==0) || ((month > 7 && month%2==1)))
        days = 30;
    else if((month <=7 && month%2==1) || (month > 7 && month%2==0))
        days = 31;
    return days;
}



