#include "Transaction.h"

    void Transaction::present(){
    cout << "Info: " << this->info << endl;
    cout << "Value: " << this->value << "$ from: " << "DateManager"/*DateManager::*/ << endl;
    }
    void Transaction::setInfo(string info){
    this->info = info;
    }
    void Transaction::setUserId(int userId){
    this->userId = userId;
    }
    void Transaction::setDate (struct tm date){
    this->date = date;
    }
    void Transaction::setValue (double value){
    this->value = value;
    }

    string Transaction::getInfo(){
    return this->info;
    }

    int Transaction::getUserId(){
    return this->userId;
    }
    struct tm Transaction::getDate(){
    return this->date;
    }
    double Transaction::getValue(){
    return this-> value;
    }