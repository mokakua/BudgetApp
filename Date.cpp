#include "DateManager.h"
#include "Markup.h"
#include <cstdlib>
#include <string>
#include <sstream>
#include <time.h>
#include <algorithm>

Date::Date():
    /*day(1), month(1), year(2000), */Components{}, LONGMONTHS{1,3,5,7,8,10,12}, SHORTMONTHS{4,6,9,11} {

}

Date::Date(string date):
    formattedValue(date), Components{}, LONGMONTHS{1,3,5,7,8,10,12}, SHORTMONTHS{4,6,9,11}
{}

void Date::askUserForInput() {
    do {
        cout << "Enter transaction's date [yyyy-mm-dd]: ";
        getline(cin,formattedValue);
    } while (!isFormatCorrect() || !areValuesCorrect());
}

bool Date::isFormatCorrect() {
    int inputLength = formattedValue.length();
    if (inputLength != 10) {
        cout << "Invalid format" <<endl;
        return false;
    }
    for (int i = 0; i<inputLength; i++) {
        if (!isdigit(formattedValue[i]) && i!=4 && i!=7) {
            return false;
        } else if (formattedValue[i] != '-' && (i==4 || i==7)) {
            return false;
        }
    }
    return true;
}

void Date::extractComponents () {
    stringstream ss;
    string stream;
    ss << formattedValue;
    getline(ss,stream,'-');
    Components.tm_year = atoi(stream.c_str())-1900;
    getline(ss,stream,'-');
    Components.tm_mon = atoi(stream.c_str())-1;
    getline(ss,stream,'-');
    Components.tm_mday = atoi(stream.c_str());
}

bool Date::isLeapYear () {
    int year = Components.tm_year+1900;
    if (year%400 == 0 || year%4 == 0 && year%100 != 0) {
        return true;
    } else {
        return false;
    }
}

bool isMonthInRange (const int& monthNumber, const vector <int> &monthRange) {
    if (find(begin(monthRange), end(monthRange), monthNumber) != end(monthRange)) {
        return true;
    } else {
        return false;
    }
}

bool Date::areValuesCorrect() {
    extractComponents();
    int year, month, day;
    year    = Components.tm_year+1900;
    month   = Components.tm_mon+1;
    day     = Components.tm_mday;
    cout << "rok = " <<year << "  month = " <<month << "  day = " << day <<endl;

    if (month>=1 && month <=12 && day >= 1 && day <=31) {
        if (isMonthInRange(month, SHORTMONTHS) && day>30) {
            cout << "Error - too many days" <<endl;
            return false;
        } else if   ((month == 2) &&
                    ((isLeapYear() && day>29) || (!isLeapYear() && day>28))) {
            cout << "Rok przestepny: "<< isLeapYear() << "Reszta z dzeilenia: " << (Components.tm_year+1900)%400 <<endl;
            cout << "Feb wrong" <<endl;
            return false;
        }
    } else {
        cout << "Long months" <<endl;
        return false;
    }

    if(!(year>=2000) || !isEarlierThan(time(NULL))) {
        cout << "Input out of range." <<endl;
        return false;
    }
    cout << "Ok" <<endl;
    return true;

}

bool Date::isEarlierThan(time_t latterDate) {
    time_t checkDate;
    cout << asctime(&Components) <<endl;
    checkDate = mktime(&Components);
    cout << asctime(&Components) <<endl;
    if (difftime(latterDate, checkDate) >= 0) {
        return true;
    } else {
        return false;
    }
}
