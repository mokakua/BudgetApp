#include "Transaction.h"

bool Transaction::operator<(Transaction transaction2){return date< transaction2.getDate();}

void Transaction::setTransactionId (int transId) {
    this->transactionId = transId;
}

void Transaction::setItem(string item) {
    this->item = item;
}

void Transaction::setUserId(int userId) {
    this->userId = userId;
}

void Transaction::setDate (int date) {
    this->date = date;
}

void Transaction::setValue (float value) {
    this->value = value;
}

int Transaction::getTransactionId() const {
    return this->transactionId;
}

string Transaction::getItem() const {
    return this->item;
}

int Transaction::getUserId() const {
    return this->userId;
}

int Transaction::getDate() const {
    return this->date;
}

float Transaction::getValue() const {
    return this-> value;
}
