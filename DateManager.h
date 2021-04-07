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
    //static int howManyDaysInMonth(struct tm date);
    static struct tm getComponentsFromString(string dateAsString);
    static void resetClockTime(struct tm &dateAsStruct);
    //static int getCurrentMonth();

public:

    static bool isUserInputCorrect(string userInput);
    static struct tm getStructDateFromString(string dateAsString);
    static string getStringDateFromStruct(struct tm components);
    static bool isDateLatterThan(struct tm dateEnd, struct tm dateBeginning);
    static bool isDateInPeriod(struct tm dateAsStruct, TimePeriod period);
    static TimePeriod getCurrentMonthPeriod();
    static TimePeriod getPreviousMonthPeriod();
    static TimePeriod enterTimePeriod();

    static int howManyDaysInMonth(struct tm date);  //
    static int getCurrentMonth();   //
};
#endif // DATE_MANAGER_H
