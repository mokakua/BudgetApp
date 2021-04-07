#include "TimePeriod.h"

    void TimePeriod::setFirstDay (struct tm date){
    this->firstDay = date;
    }

    void TimePeriod::setLastDay (struct tm date){
    this->lastDay = date;
    }

    struct tm TimePeriod::getFirstDay(){
    return this->firstDay;
    }

    struct tm TimePeriod::getLastDay(){

    return this->lastDay;
    }
