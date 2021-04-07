#include "DateManager.h"
#include "Markup.h"
#include <cstdlib>
#include <string>
#include <sstream>
#include <time.h>
#include <algorithm>

bool DateManager::isUserInputCorrect(string userInput) {
    if(isFormatCorrect(userInput) && areValuesCorrect(userInput)) {
        return true;
    }
    return false;
}

bool DateManager::isFormatCorrect(string dateAsString) {
    int inputLength = dateAsString.length();
    if (inputLength != 10) {
        cout << "Invalid format" <<endl;
        return false;
    }
    for (int i = 0; i<inputLength; i++) {
        if (!isdigit(dateAsString[i]) && i!=4 && i!=7) {
            return false;
        } else if (dateAsString[i] != '-' && (i==4 || i==7)) {
            return false;
        }
    }
    return true;
}

bool DateManager::areValuesCorrect(string dateAsString) {
    struct tm components = getComponentsFromString(dateAsString);
    int year, month, day;
    year    = components.tm_year+1900;
    month   = components.tm_mon+1;
    day     = components.tm_mday;

    if (month<1 || month >12) {
        cout << "Month is out of range" <<endl;
        return false;

    } else if (day < 1 || day > howManyDaysInMonth(components)) {
        cout << "Days are out of range" <<endl;
        return false;

    } else if ((year<2000) || isDateLatterThan(getStructDateFromString(dateAsString),getCurrentMonthPeriod().getLastDay())) {
        cout << "Time is out of range" <<endl;
        return false;
    }

    cout << "Ok" <<endl;
    return true;
}

bool DateManager::isLeapYear (int year) {
    if (year%400 == 0 || (year%4 == 0 && year%100 != 0)) {
        return true;
    } else {
        return false;
    }
}

int DateManager::howManyDaysInMonth(struct tm date) {
    int year, month;
    year    = date.tm_year+1900;
    month   = date.tm_mon+1;

    if (month>=1 && month <=12) {
        if ((month == 4 || month == 6 || month == 9 || month == 11)) {
            return 30;
        } else if   (month == 2) {
            if (isLeapYear(year)) {
                return 29;
            } else {
                return 28;
            }
        } else {
            return 31;
        }
    }
    return 0;
}

struct tm DateManager::getComponentsFromString (string dateAsString) {
    struct tm components = {0};
    stringstream ss;
    string stream;
    ss << dateAsString;
    getline(ss,stream,'-');
    components.tm_year = (atoi(stream.c_str())-1900);
    getline(ss,stream,'-');
    components.tm_mon = (atoi(stream.c_str())-1);
    getline(ss,stream,'-');
    components.tm_mday = (atoi(stream.c_str()));
    return components;
}

struct tm DateManager::getStructDateFromString(string dateAsString) {
    struct tm dateAsStruct = getComponentsFromString(dateAsString);
    mktime(&dateAsStruct);
    dateAsStruct.tm_hour = 0;
    return dateAsStruct;
}

//string DateManager::getStringDateFromStruct(struct tm components) {}

bool DateManager::isDateLatterThan(struct tm dateEnd, struct tm dateBeginning) {

    time_t timeEnd, timeBeginning;
    timeEnd = mktime(&dateEnd);
    timeBeginning = mktime(&dateBeginning);
    if (difftime(timeEnd, timeBeginning) > 0) {
        return true;
    } else {
        return false;
    }
}

TimePeriod DateManager::getCurrentMonthPeriod() {
    TimePeriod currentMonth;
    time_t now = time(NULL);
    struct tm nowStruct = *localtime(&now);

    nowStruct.tm_mday=1;
    resetClockTime(nowStruct);
    mktime(&nowStruct);
    currentMonth.setFirstDay(nowStruct);

    nowStruct.tm_mday=howManyDaysInMonth(nowStruct);
    resetClockTime(nowStruct);
    mktime(&nowStruct);
    currentMonth.setLastDay(nowStruct);

    return currentMonth;
}

//TimePeriod DateManager::getPreviousMonthPeriod() {}

//TimePeriod DateManager::enterTimePeriod() {}

int DateManager::getCurrentMonth() {
    time_t now = time(NULL);
    struct tm *nowStruct = localtime(&now);
    return nowStruct->tm_mon + 1;
}

void DateManager::resetClockTime(struct tm &dateAsStruct){
    dateAsStruct.tm_hour = 0;
    dateAsStruct.tm_min = 0;
    dateAsStruct.tm_sec = 0;
}
bool DateManager::isDateInPeriod(struct tm dateAsStruct, TimePeriod period){
    if (!isDateLatterThan(period.getFirstDay(),dateAsStruct) && !isDateLatterThan(dateAsStruct,period.getLastDay())){
        return true;
    }
    return false;
}
