#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H
#include "Transaction.h"
#include <iostream>
#include <vector>


using namespace std;

class TransactionManager {

    vector <Transaction> transactions;
    string askForInfo();
    float askForValue();
    string askForDate();
    bool isValueFormatCorrect(string &input);

public:
    TransactionManager() {};
    ~TransactionManager() {};

    bool loadTransactionsFromFile(string fileName);
    void listTransactions();
    void getTransaction();

};
#endif // TRANSACTIONMANAGER_H
