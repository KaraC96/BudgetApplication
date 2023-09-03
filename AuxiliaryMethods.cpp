#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntegerToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
string AuxiliaryMethods::loadLine()
{
    string entry = "";
    getline(cin, entry);
    return entry;
}

int AuxiliaryMethods::convertStringToInteger(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

char AuxiliaryMethods::loadChar()
{
    string entry = "";
    char choice  = {0};

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1)
        {
            choice = entry[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return choice;
}

bool AuxiliaryMethods::isDateInRange(const struct tm& dateStruct)
{
    struct tm minDate = {0};
    minDate.tm_year = 100;
    minDate.tm_mon = 0;
    minDate.tm_mday = 1;

    struct tm maxDate;
    time_t currentTime = time(nullptr);
    localtime_s(&maxDate, &currentTime);
    maxDate.tm_hour = 0;
    maxDate.tm_min = 0;
    maxDate.tm_sec = 0;
    maxDate.tm_mday = 1;

    if (maxDate.tm_mon == 11)
    {
        maxDate.tm_year += 1;
        maxDate.tm_mon = 0;
    }
    else
    {
        maxDate.tm_mon += 1;
    }

    return (difftime(mktime(const_cast<struct tm*>(&dateStruct)), mktime(&minDate)) >= 0) &&
           (difftime(mktime(const_cast<struct tm*>(&dateStruct)), mktime(&maxDate)) <= 0);
}

bool AuxiliaryMethods::isValidDate(int year, int month, int day)
{
    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);


    if (month < 1 || month > 12 || day < 1 || day > daysInMonth[month] || (month == 2 && isLeapYear && day > 29))
    {
        return false;
    }

    return true;
}


bool AuxiliaryMethods::parseDate(const string &date, string &formattedDate)
{
    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
    {
        cout << "Niepoprawny format daty." << endl;
        return false;
    }

    if (!isValidDate(year, month, day))
    {
        cout << "Niepoprawny format daty." << endl;
        return false;
    }

    struct tm timeStruct = {};
    timeStruct.tm_year = year - 1900;
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_mday = day;

    if (!isDateInRange(timeStruct))
    {
        cout << "Data poza zakresem (od 2000-01-01 do ostatniego dnia biezcego miesiaca)." << endl;
        return false;
    }

    stringstream formattedDateStream;
    formattedDateStream << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day;
    formattedDate = formattedDateStream.str();

    return true;
}

string AuxiliaryMethods::getTodayDate()
{
    string formattedDate;

    chrono::system_clock::time_point now = chrono::system_clock::now();
    time_t now_time_t = chrono::system_clock::to_time_t(now);
    tm* now_tm = localtime(&now_time_t);
    int year = now_tm->tm_year + 1900;
    int month = now_tm->tm_mon + 1;
    int day = now_tm->tm_mday;

    stringstream formattedDateStream;
    formattedDateStream << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day;
    formattedDate = formattedDateStream.str();

    return formattedDate;
}

int AuxiliaryMethods::convertDateToInt(const string& date)
{
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    return year * 10000 + month * 100 + day;
}
