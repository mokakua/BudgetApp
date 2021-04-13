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



using namespace std;

int main() {    //transactionManager

    const string USERSFILENAME = "users.xml";
    const string EXPENSESFILENAME = "expenses.xml";

    TransactionsFile transFile (EXPENSESFILENAME);
    Transaction transaction;
    transaction.setInfo("Za rower");
    transaction.setUserId(1);
    transaction.setDate(20210413);
    transaction.setValue(4999.99);
    transFile.addTransactionToFile(transaction);

    transFile.saveFile();

    return 0;
}

int mainUser() {    //UserManager

    const string USERSFILENAME = "users.xml";

    UserManager userManager(USERSFILENAME);
    userManager.loadUsersFromFile();
    //userManager.listUsers();
    //userManager.registerUser();
    cout << userManager.getIdOfLoggedInUser() << endl;
    userManager.logIn();
    cout << userManager.getIdOfLoggedInUser() <<endl;
    userManager.changePassword();



    return 0;
}

int mainDate () {   //dateManager

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
    if (DateManager::isDateInPeriod(dateAsInt, DateManager::getCurrentMonthPeriod())) {
        cout << "Yes" <<endl;

    } else {
        cout << "No" <<endl;
    }
/*
    while (true){

        period = DateManager::enterTimePeriod();
        cout << period.getFirstDay() <<endl;
        cout << period.getLastDay() <<endl;
    }
*/
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
