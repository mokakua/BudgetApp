#include "TransactionsFile.h"
#include "DateManager.h"
#include "TransactionManager.h"

TransactionsFile::TransactionsFile(string name)
    :XMLFile(name) {
    if(!file.Load(name)) {
        file.AddElem("Transactions");
        file.Save(name);
    }
}

vector <Transaction> TransactionsFile::loadTransactionsFromFile() {
    vector <Transaction> transactions;
    file.FindElem("Transactions");
    file.IntoElem();
    while(file.FindElem("Transaction")) {
        Transaction transaction;
        file.FindChildElem("info");
        transaction.setInfo(file.GetChildData());
        file.ResetChildPos();
        file.FindChildElem("userId");
        transaction.setUserId(atoi(file.GetChildData().c_str()));
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

void TransactionsFile::addTransactionToFile(const Transaction& transaction) {
    file.FindElem("Transactions");
    file.IntoElem();
    file.AddElem("Transaction");
    file.AddChildElem("info", transaction.getInfo());
    file.AddChildElem("userId", transaction.getUserId());
    file.AddChildElem("date", transaction.getDate());
    file.AddChildElem("value", to_string(transaction.getValue()));
    file.ResetPos();
}
/*
void TransactionsFile::changeTransactionData(const User& user) {
    file.FindElem("Users");
    file.IntoElem();
    while(true) {
        file.FindElem("User");
        file.FindChildElem("id");
        if (atoi(file.GetChildData().c_str())==user.getId()) {
            file.ResetChildPos();
            file.FindChildElem("password");
            file.SetChildData(user.getPassword());
            break;
        }
    }
    file.ResetPos();
}*/

void TransactionsFile::saveFile() {
    if(file.Save(name)) {
        cout << "Data saved to file." <<endl;
    } else {
        cout << "Saving to file failed." <<endl;
    }
}


