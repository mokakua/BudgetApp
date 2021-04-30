#include <iostream>
#include "Transaction.h"
#include "TransactionManager.h"
#include "DateManager.h"
#include "User.h"
#include "UserManager.h"
#include "UsersFile.h"
#include "time.h"
#include "windows.h"
#include "TransactionsFile.h"
#include "BudgetManager.h"



using namespace std;

int main(){
    const string USERSFILENAME = "users.xml";
    const string EXPENSESFILENAME = "expenses.xml";
    const string INCOMESFILENAME = "incomes.xml";
    BudgetManager bManager(USERSFILENAME, INCOMESFILENAME, EXPENSESFILENAME);
    while (true){
        bManager.showMenu();
    }
}

int mainDate () {   //dateManager


    TimePeriod period = DateManager::getCurrentMonthPeriod();
    cout << DateManager::getStringDateFromInt(period.getFirstDay()) <<endl;
    cout << DateManager::getStringDateFromInt(period.getLastDay()) <<endl;
    period = DateManager::getPreviousMonthPeriod();
    cout << DateManager::getStringDateFromInt(period.getFirstDay()) <<endl;
    cout << DateManager::getStringDateFromInt(period.getLastDay()) <<endl;
/*
time_t today = time(NULL);
cout << "Today: " << ctime(&today) <<endl;
struct tm todayTM = *localtime(&today);
todayTM.tm_mon-=4;
mktime(&todayTM);
cout << "Before 4 months" << asctime(&todayTM) <<endl;
*/
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
