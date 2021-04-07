#ifndef DATE_MANAGER_H
#define DATE_MANAGER_H
#include "Transaction.h"
#include <iostream>
#include <vector>

using namespace std;

class DateManager {

    string formattedValue;
    struct tm Components;
    const vector <int> LONGMONTHS, SHORTMONTHS;

    bool isFormatCorrect();
    void extractComponents ();
    //bool areValuesCorrect();
    bool isLeapYear ();

public:
    Date();
    Date(string date);  //temp
    ~Date() {};

    void askUserForInput();
    bool isEarlierThan(time_t anotherDate);

    bool areValuesCorrect();    //temp
};
#endif // DATE_MANAGER_H
