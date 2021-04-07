#ifndef TIMEPERIOD_H
#define TIMEPERIOD_H
#include <time.h>
#include <iostream>

using namespace std;

class TimePeriod {

    struct tm firstDay, lastDay;

public:

    void setFirstDay (struct tm date);
    void setLastDay (struct tm date);

    struct tm getFirstDay();
    struct tm getLastDay();



};
#endif // TIMEPERIOD_H
