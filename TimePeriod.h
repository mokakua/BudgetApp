#ifndef TIMEPERIOD_H
#define TIMEPERIOD_H
#include <iostream>

using namespace std;

class TimePeriod {

    int firstDay, lastDay;

public:

    void setFirstDay (int date);
    void setLastDay (int date);

    int getFirstDay();
    int getLastDay();



};
#endif // TIMEPERIOD_H
