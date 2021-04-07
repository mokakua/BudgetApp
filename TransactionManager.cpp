#include "TransactionManager.h"
#include "XmlFileManager.h"
#include "DateManager.h"
#include "Markup.h"
#include <cstdlib>
#include <string>
#include <time.h>

bool TransactionManager::loadTransactionsFromFile(string fileName) {
    XmlFileManager fileOpener;
    CMarkup xmlFile;
    if (fileOpener.openFile(&xmlFile, fileName)) {
        xmlFile.FindElem();
        xmlFile.IntoElem();
        while (xmlFile.FindElem("Transaction")) {
            Transaction transaction;
            xmlFile.FindChildElem("userId");
            transaction.setUserId(atoi(xmlFile.GetChildData().c_str()));
            xmlFile.ResetChildPos();
            xmlFile.FindChildElem("info");
            transaction.setInfo(xmlFile.GetChildData().c_str());
            xmlFile.ResetChildPos();
            xmlFile.FindChildElem("date");
            transaction.setDate(DateManager::getIntDateFromString(xmlFile.GetChildData()));
            xmlFile.ResetChildPos();
            xmlFile.FindChildElem("value");
            transaction.setValue(atof(xmlFile.GetChildData().c_str()));
            xmlFile.ResetChildPos();
            transactions.push_back(transaction);
        }
        return true;
    } else {
        return false;
    }

}

void TransactionManager::listTransactions() {
    if(transactions.empty()) {
        cout << "No transactions added." <<endl;
    } else {
        vector <Transaction>::iterator trans = transactions.begin(), transEnd = transactions.end();
        for (; trans!=transEnd; trans++) {
            trans->present();
        }
    }
}

void TransactionManager::getTransaction() {
    Transaction transaction;
    transaction.setInfo(askForInfo());
    transaction.setValue(askForValue());
    transaction.setDate(DateManager::getIntDateFromString(askForDate()));
    transactions.push_back(transaction);

}

string TransactionManager::askForInfo() {
    cout << "Enter transaction's info: ";
    string info;
    getline(cin,info);
    return info;
}

float TransactionManager::askForValue() {
    string input = "";
    do {
        cout << "Enter transaction's value [$]: ";
        getline(cin,input);
    } while (!isValueFormatCorrect(input));
    float value = atof(input.c_str());
    return value;
}

string TransactionManager::askForDate() {
    string dateInput = "";
    do {
        cout << "Enter transaction's date [yyyy-mm-dd]: ";
        getline(cin,dateInput);
    } while (!DateManager::isUserInputCorrect(dateInput));
    return dateInput;
}

bool TransactionManager::isValueFormatCorrect(string &input) {
    int length = input.length();
    bool separatorExist = false;
    for (int i = 0; i<length; i++) {
        if (isdigit(input[i])) {
            continue;
        } else if((input[i] == ',' || input[i] == '.') && !separatorExist) {
            separatorExist = true;
            if (input[i] == ',') {
                input[i] = '.';
            }
        } else {
            cout << "Invalid input" <<endl;
            return false;
        }
    }
    return true;
}
