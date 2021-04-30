#include "TransactionsFile.h"
#include "DateManager.h"
#include "TransactionManager.h"

TransactionsFile::TransactionsFile(string name)
    :XMLFile(name) {
    if(!file.Load(name)) {
        file.AddElem("Transactions");
        file.Save(name);
    }
    lastTransactionId = extractLastTransactionId();
}

vector <Transaction> TransactionsFile::loadUserTransactionsFromFile(int userId) {
    vector <Transaction> transactions;
    file.FindElem("Transactions");
    file.IntoElem();
    while(file.FindElem("Transaction")) {
        Transaction transaction;
        file.FindChildElem("userId");
        transaction.setUserId(atoi(file.GetChildData().c_str()));
        if(transaction.getUserId()!=userId){
            continue;
        }
        file.ResetChildPos();
        file.FindChildElem("transactionId");
        transaction.setTransactionId(atoi(file.GetChildData().c_str()));
        file.ResetChildPos();
        file.FindChildElem("item");
        transaction.setItem(file.GetChildData());
        file.ResetChildPos();
        file.FindChildElem("date");
        transaction.setDate(DateManager::getIntDateFromString(file.GetChildData()));
        file.ResetChildPos();
        file.FindChildElem("value");
        transaction.setValue(atof(file.GetChildData().c_str()));
        transactions.push_back(transaction);
    }
    file.OutOfElem();
    file.ResetPos();
    return transactions;
}

bool TransactionsFile::addTransactionToFile(const Transaction& transaction) {
    file.FindElem("Transactions");
    file.IntoElem();
    file.AddElem("Transaction");
    file.AddChildElem("userId", transaction.getUserId());
    file.AddChildElem("transactionId", transaction.getTransactionId());
    file.AddChildElem("item", transaction.getItem());
    file.AddChildElem("date", DateManager::getStringDateFromInt(transaction.getDate()));
    file.AddChildElem("value", to_string(transaction.getValue()));
    file.ResetPos();
    return (file.Save(name));
}

int TransactionsFile::extractLastTransactionId(){
    int lastId = 0;
    file.FindElem("Transactions");
    file.IntoElem();
    if(file.FindElem("Transaction")){
        while(file.FindElem("Transaction")){};
        file.FindChildElem("transactionId");
        lastId = atoi(file.GetChildData().c_str());
        file.ResetPos();
    }
    return lastId;
}

int TransactionsFile::getLastTransactionId(){
    return this->lastTransactionId;
};
