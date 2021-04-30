#ifndef DATE_MANAGER_H
#define DATE_MANAGER_H
#include "Transaction.h"
#include "TimePeriod.h"
#include <iostream>
#include <vector>

using namespace std;

class DateManager {

    static bool isFormatCorrect(string dateAsString);
    static bool areValuesCorrect(string dateAsString);
    static bool isLeapYear (int year);
    static int howManyDaysInMonth(int date);
    static int getIntDateFromStruct(struct tm dateAsStruct);
    static int getYearFromIntDate(int dateAsInt);
    static int getMonthFromIntDate(int dateAsInt);
    static int getDayFromIntDate(int dateAsInt);
    static string convertIntToString (int number);
    static string dateFormatSetter();
    static string getTodayStringDate();

public:

    static bool isUserInputCorrect(string userInput);
    static int getIntDateFromString(string dateAsString);
    static string getStringDateFromInt(int dateAsInt);
    static bool isDateInPeriod(int dateAsInt, TimePeriod period);
    static TimePeriod getCurrentMonthPeriod();
    static TimePeriod getPreviousMonthPeriod();
    static TimePeriod enterTimePeriod();
    static string enterDate();
};
#endif // DATE_MANAGER_H
