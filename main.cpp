#include <iostream>
#include "Transaction.h"
#include "TransactionManager.h"
#include "DateManager.h"
#include "User.h"
#include "UserManager.h"
#include "XMLFile.h"
#include "UsersFile.h"
#include "time.h"



using namespace std;

int main() {

    const string USERSFILENAME = "users.xml";
    UsersFile file(USERSFILENAME);
    /*User user;
    user.setName("Aga");
    user.setSurname("Turek");
    user.setLogin("Tamta");
    user.setPassword("porks098");
    user.setId(4);
    file.addUserToFile(user);*/

    vector <User> users;
    users = file.loadUserFromFile();
    vector <User>::iterator iter = users.begin(), end = users.end();
    for(;iter!=end;iter++){
        cout << iter->getName() <<endl;
        cout << iter->getSurname() <<endl;
        cout << iter->getLogin() <<endl;
        cout << iter->getPassword() <<endl;
        cout << iter->getId() <<endl <<endl;
    }


    return 0;
}

int maindate () {

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
