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

public:
    TransactionsFile(string name);
    vector <Transaction> loadUserTransactionsFromFile(int userId);
    void addTransactionToFile(const Transaction& transaction);
    void saveFile();
    int extractLastTransactionId();
    int getLastTransactionId();
};
#endif // TRANSACTIONSFILE_H