#include "Transaction.h"

void Transaction::setInfo(string info) {
    this->info = info;
}
void Transaction::setUserId(int userId) {
    this->userId = userId;
}
void Transaction::setDate (int date) {
    this->date = date;
}
void Transaction::setValue (double value) {
    this->value = value;
}

string Transaction::getInfo() {
    return this->info;
}

int Transaction::getUserId() {
    return this->userId;
}
int Transaction::getDate() {
    return this->date;
}
double Transaction::getValue() {
    return this-> value;
}
