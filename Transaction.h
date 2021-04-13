#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>

using namespace std;

class Transaction {

    string info;
    int userId;
    int date;
    double value;

public:

    void setInfo (string info);
    void setUserId (int id);
    void setDate (int date);
    void setValue (double value);

    string getInfo();
    int getUserId();
    int getDate();
    double getValue();

};
#endif // TRANSACTION_H
