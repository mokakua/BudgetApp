#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>

using namespace std;

class Transaction {

    int transactionId, userId;
    int date;
    string item;
    double value;

public:

    bool operator<(Transaction transaction2);
    void setTransactionId (int transId);
    void setUserId (int userId);
    void setDate (int date);
    void setItem (string item);
    void setValue (double value);

    int getTransactionId() const;
    int getUserId() const;
    int getDate() const;
    string getItem() const;
    double getValue() const;

};
#endif // TRANSACTION_H
