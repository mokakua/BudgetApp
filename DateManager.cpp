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
    int dateAsInt = getIntDateFromString(dateAsString);
    int year, month, day;
    year    = getYearFromIntDate(dateAsInt);
    month   = getMonthFromIntDate(dateAsInt);
    day     = getDayFromIntDate(dateAsInt);

    if (month<1 || month >12) {
        cout << "Month is out of range" <<endl;
        return false;

    } else if (day < 1 || day > howManyDaysInMonth(dateAsInt)) {
        cout << "Days are out of range" <<endl;
        return false;

    } else if ((year<2000) || dateAsInt > getCurrentMonthPeriod().getLastDay()) {
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

int DateManager::howManyDaysInMonth(int date) {
    int year, month;
    year    = getYearFromIntDate(date);
    month   = getMonthFromIntDate(date);

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

int DateManager::getYearFromIntDate(int dateAsInt) {
    int year = dateAsInt/10000;
    return year;
}

int DateManager::getMonthFromIntDate(int dateAsInt) {
    int month = (dateAsInt/100)%100;
    return month;
}

int DateManager::getDayFromIntDate(int dateAsInt) {
    int day = dateAsInt%100;
    return day;
}

int DateManager::getIntDateFromString(string dateAsString) {
    int dateAsInt = 0;
    stringstream ss;
    string stream;
    ss << dateAsString;
    getline(ss,stream,'-');
    dateAsInt += atoi(stream.c_str());
    dateAsInt *= 100;
    getline(ss,stream,'-');
    dateAsInt += atoi(stream.c_str());
    dateAsInt *= 100;
    getline(ss,stream,'-');
    dateAsInt += atoi(stream.c_str());
    return dateAsInt;
}

int DateManager::getIntDateFromStruct(struct tm dateAsStruct) {
    int dateAsInt = 0;
    dateAsInt += dateAsStruct.tm_year+1900;
    dateAsInt *= 100;
    dateAsInt += dateAsStruct.tm_mon+1;
    dateAsInt *= 100;
    dateAsInt += dateAsStruct.tm_mday;
    return dateAsInt;
}

string getStringDateFromInt(string dateAsInt){

}

TimePeriod DateManager::getCurrentMonthPeriod() {
    TimePeriod currentMonth;
    time_t now = time(NULL);
    struct tm nowStruct = *localtime(&now);

    nowStruct.tm_mday=1;
    mktime(&nowStruct);
    currentMonth.setFirstDay(getIntDateFromStruct(nowStruct));

    nowStruct.tm_mday=howManyDaysInMonth(getIntDateFromStruct(nowStruct));
    mktime(&nowStruct);
    currentMonth.setLastDay(getIntDateFromStruct(nowStruct));

    return currentMonth;
}

//TimePeriod DateManager::getPreviousMonthPeriod() {}

//TimePeriod DateManager::enterTimePeriod() {}

bool DateManager::isDateInPeriod(int dateAsInt, TimePeriod period) {
    if (period.getFirstDay()<=dateAsInt && dateAsInt <= period.getLastDay()){
        return true;
    }
    return false;
}
