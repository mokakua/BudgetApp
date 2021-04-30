#ifndef TRANSACTIONSFILE_H
#define TRANSACTIONSFILE_H
#include <iostream>
#include <vector>
#include "XMLFile.h"
#include "Transaction.h"
#include "Markup.h"
using namespace std;

class TransactionsFile :public XMLFile {
    int lastTransactionId;

    int extractLastTransactionId();

public:
    TransactionsFile(string name);
    vector <Transaction> loadUserTransactionsFromFile(int userId);
    bool addTransactionToFile(const Transaction& transaction);
    int getLastTransactionId();
};
#endif // TRANSACTIONSFILE_H
