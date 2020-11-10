#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

class AuxiliaryMethods {
public:
    static char loadSign();

    static string doubleToString(double number);
    static double stringToDouble(string number);
    static string intToString(int number);
    static int tmToInt(tm* &tmDate);
    int charToInt();
    static string floatToString(float number);
    static int stringToInt(string stringNumber);
    static float stringToFloat(string stringNumber);
    static string loadLine();
    static char loadCharacter();
    static int loadInteger();
    static string capitaliseFirstLetter(string line);
    static string convertDateToString(int date);
    static int convertDateToInt(string date);
    static float getMoneyAmountFromUser();
    static double setPrecisionToMoney(double amount);
    static string convertIntDateToString(int date);
    static double conversionFromStringToDouble(string strAmount);
    static string conversionFromDoubleToString(double number);
};


#endif
