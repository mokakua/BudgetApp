#include "TimePeriod.h"

void TimePeriod::setFirstDay (int date) {
    this->firstDay = date;
}

void TimePeriod::setLastDay (int date) {
    this->lastDay = date;
}

int TimePeriod::getFirstDay() const{
    return this->firstDay;
}

int TimePeriod::getLastDay() const{

    return this->lastDay;
}
