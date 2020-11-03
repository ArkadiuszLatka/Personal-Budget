#ifndef OPERATIONSONDATE_H
#define OPERATIONSONDATE_H
#include "AuxiliaryMethods.h"
#include <ctime>
#include <string>
#include <windows.h>
#include <sstream>
#include <iostream>
#include <time.h>

class operationsOnDate
{
    public:

    static int getCurrentDate();
    static int getUserDate();
    static bool correctSignsInDate(string date);
    static int convertStringDateToInt(string date);
    static string convertIntDateToString(int date);
    static int daysInMonth(int year, int month);
    static double getTransactionValue();
    static bool correctSignsInValue(string stringValue);
    static double convertStringValueToDouble(string stringValue);

};

#endif // DATE_H
