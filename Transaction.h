#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <time.h>
#include <iostream>

using namespace std;

class Transaction {

    string info;
    int userId;
    struct tm date;
    double value;

public:
    Transaction() {};
    ~Transaction() {};

    void present();

    void setInfo (string info);
    void setUserId (int id);
    void setDate (struct tm date);
    void setValue (double value);

    string getInfo();
    int getUserId();
    struct tm getDate();
    double getValue();

};
#endif // TRANSACTION_H
