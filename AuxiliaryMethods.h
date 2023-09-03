#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <string>
#include <iomanip>
#include <chrono>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convertIntegerToString(int number);
    static string loadLine();
    static int convertStringToInteger(string number);
    static string changeFirstLetterForUpperCaseAndOthersForLowerCase(string text);
    static char loadChar();
    static bool isDateInRange(const struct tm& dateStruct);
    static bool parseDate(const string &date, string &formattedDate);
    static bool isValidDate(int year, int month, int day);
    static string getTodayDate();
    static int convertDateToInt(const string& date);
};

#endif
