#ifndef TRANSACTIONSFILE_H
#define TRANSACTIONSFILE_H
#include <iostream>
#include <vector>
#include "XMLFile.h"
#include "Transaction.h"
#include "Markup.h"
using namespace std;

class TransactionsFile :public XMLFile {


public:
    TransactionsFile(string name);
    vector <Transaction> loadTransactionsFromFile();
    void addTransactionToFile(const Transaction& transaction);
    //void changeUserData(const Transaction& transaction);
    void saveFile();
};
#endif // TRANSACTIONSFILE_H
