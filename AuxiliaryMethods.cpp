#include "AuxiliaryMethods.h"

char AuxiliaryMethods::loadSign() {
    string input = "";
    char sign  = {0};
    while (true) {
        cin.sync();
        getline(cin, input);

        if (input.length() == 1) {
            sign = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}
int AuxiliaryMethods::charToInt(){
    stringstream str;

    str << "1";

    double x;
    str >> x;
    return x;
}
string AuxiliaryMethods::doubleToString(double number)
{
    stringstream ss;
    string str;
    ss << number;
    ss >> str;
    return  str;
}
double AuxiliaryMethods::stringToDouble(string number) {
    double doubleNumber;
    istringstream iss(number);
    iss >> doubleNumber;
    return doubleNumber;
}
string AuxiliaryMethods::intToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
int AuxiliaryMethods::tmToInt(tm* &tmDate) {
    int intDate;
    intDate = (tmDate->tm_year + 1900) * pow(10,4) + (tmDate->tm_mon + 1) * pow (10,2) + tmDate->tm_mday;
    return intDate;
}


string AuxiliaryMethods::floatToString(float number)
{
     ostringstream ss;
     ss << number;
     return ss.str();
}

int AuxiliaryMethods::stringToInt(string stringNumber)
{
    int intNumber;
    istringstream ss(stringNumber);
    ss >> intNumber;
    return intNumber;
}

float AuxiliaryMethods::stringToFloat(string stringNumber)
{
    float floatNumber;
    istringstream ss(stringNumber);
    ss >> floatNumber;
    return floatNumber;
}

string AuxiliaryMethods::loadLine()
{
    string text;
    cin.sync();
    getline(cin, text);
    return text;
}

char AuxiliaryMethods::loadCharacter()
{
    string input= "";
    char singleCharacter  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            singleCharacter = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return singleCharacter;
}

int AuxiliaryMethods::loadInteger()
{
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

int AuxiliaryMethods::convertDateToInt(string date)
{
    int intDate;
    date.erase(4,1);
    date.erase(6,1);
    intDate = stringToInt(date);
    return intDate;
}

string AuxiliaryMethods::convertDateToString(int date)
{
    string strDate = intToString(date);
    strDate.insert(4,"-");
    strDate.insert(7,"-");
    return strDate;
}

float AuxiliaryMethods::getMoneyAmountFromUser()
{
    float amount, money;
    string strAmount = loadLine();
    int i=0, length = strAmount.length();

    while (i<length)
    {
        if(strAmount[i] == ',')
        {
            strAmount[i]='.';
        }
        i++;
    }
    amount = setPrecisionToMoney(stringToFloat(strAmount));

    return amount;
}
float AuxiliaryMethods::setPrecisionToMoney(float amount)
{
    stringstream myStream;
    myStream << std::fixed << std::setprecision(2) << amount;
    myStream >> amount;
    return amount;
}
string AuxiliaryMethods::convertIntDateToString(int date) {
    string stringDate = AuxiliaryMethods::intToString(date);
    stringDate.insert(6,"-");
    stringDate.insert(4,"-");
    return stringDate;
}
