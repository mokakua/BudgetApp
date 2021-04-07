#include <iostream>
#include "XmlFileManager.h"
#include "Transaction.h"
#include "TransactionManager.h"
#include "DateManager.h"
#include "time.h"


using namespace std;


int main() {

    string date = "";
    //date = "1999-10-01";
    //date = "2021-04-01";
    //date = "2021-04-31";
    //date = "2021-05-01";
    //date = "2021-001-01";
    //date = "2021-13-01";
    date = "2021-04-30";


    cout << "Date: " << date << endl;
    int dateAsInt = DateManager::getIntDateFromString(date);
    cout << "Data jako int:" <<  dateAsInt << endl;

    DateManager::isUserInputCorrect(date);

    cout << "Is date in current month period? ";
    if (DateManager::isDateInPeriod(dateAsInt, DateManager::getCurrentMonthPeriod())){
        cout << "Yes" <<endl;

    }else{
        cout << "No" <<endl;
    }

    /*
    cout << "Is date later than today? ";
    time_t today = time(NULL);
    if(dateAsInt > DateManager::getIntDateFromStruct(*localtime(&today))){
        cout << "Yes" <<endl;
    }else{
        cout << "No" <<endl;
    }
*/
    return 0;
}
