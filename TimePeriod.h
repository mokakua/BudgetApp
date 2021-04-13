#ifndef TIMEPERIOD_H
#define TIMEPERIOD_H
#include <iostream>

using namespace std;

class TimePeriod {

    int firstDay, lastDay;

public:

    TimePeriod():
        firstDay(2000-01-01), lastDay(2000-01-31){};

    void setFirstDay (int date);
    void setLastDay (int date);

    int getFirstDay();
    int getLastDay();



};
#endif // TIMEPERIOD_H
