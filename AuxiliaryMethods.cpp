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
string AuxiliaryMethods::firstCapitalRestLowercase(string word) {
    if (!word.empty()) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word[0] = toupper(word[0]);
    }
    return word;
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
