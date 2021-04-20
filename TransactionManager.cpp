#include "TransactionManager.h"
#include "DateManager.h"
#include "Markup.h"
#include <cstdlib>
#include <string>
#include <time.h>
#include <iomanip>
#include <algorithm>

TransactionManager::TransactionManager(int id, const string& NAME_OF_INCOMES_FILE, const string& NAME_OF_EXPENSES_FILE):
    incomesFile(NAME_OF_INCOMES_FILE), expensesFile(NAME_OF_EXPENSES_FILE), userId(id), MESSAGE_LENGTH(40) {}

void TransactionManager::loadUserTransactionsFromFile() {
    expenses = expensesFile.loadUserTransactionsFromFile(userId);
    incomes = incomesFile.loadUserTransactionsFromFile(userId);
}

void TransactionManager::listUsersTransactions() {
    cout << setprecision(2) << std::fixed;
    cout << "All incomes:" <<endl;
    listTransactions(incomes);
    cout << endl;
    cout << "All expenses:" <<endl;
    listTransactions(expenses);
    cout << endl;
}
void TransactionManager::listTransactionsFromPeriod(const vector <Transaction>& incomesFromPeriod, const vector <Transaction>& expensesFromPeriod, const TimePeriod& period){
    cout << "Balance from " << DateManager::getStringDateFromInt(period.getFirstDay());
    cout << " to " << DateManager::getStringDateFromInt(period.getLastDay()) <<endl;
    cout << setprecision(2) << std::fixed;
    cout << "***INCOMES***:" <<endl;
    listTransactions(incomesFromPeriod);
    cout << endl;
    cout << "***EXPENSES***:" <<endl;
    listTransactions(expensesFromPeriod);
    cout << endl;
}

void TransactionManager::listTransactions(vector <Transaction> transactions) {
    if(transactions.empty()) {
        cout << "No transactions." <<endl;
    } else {
        string separator = "";
        separator.append(MESSAGE_LENGTH+17,'-');
        vector <Transaction>::iterator trans = transactions.begin(), transEnd = transactions.end();
        for (; trans!=transEnd; trans++) {
            cout << DateManager::getStringDateFromInt(trans->getDate()) <<'\t';
            cout << showInfo(trans->getItem())                          <<' ';
            cout << '=' <<trans->getValue() << "zl"                     <<endl;
            cout << separator                                           <<endl;
        }
    }
}

string TransactionManager::showInfo(string info) {
    int infoLength = info.length();
    info.append(MESSAGE_LENGTH-infoLength,' ');
    return info;
}

bool TransactionManager::isTransactionLaterThan (const Transaction& trans1, const Transaction& trans2) {
    return trans1.getDate()<trans2.getDate();
}

void TransactionManager::sortTransactionsToLatest(vector <Transaction>& transactions) {
    sort(transactions.begin(), transactions.end());
}

vector <Transaction> TransactionManager::getTransactionsFromPeriod(const TimePeriod& period, const vector <Transaction>& transactions) {
    vector <Transaction> transactionsFromPeriod;
    vector <Transaction>::const_iterator trans = transactions.begin(), transEnd = transactions.end();
    for( ; trans!=transEnd ; trans++) {
        if(trans->getDate() >= period.getFirstDay() && trans->getDate() <= period.getLastDay()) {
            transactionsFromPeriod.push_back(*trans);
        }
    }
    return transactionsFromPeriod;
}

double TransactionManager::getBalanceOfTransactions(const vector <Transaction>& incomes, const vector <Transaction>& expenses) {
    double balance1=0, balance2=0;
    vector <Transaction>::const_iterator trans = incomes.begin(), transEnd = incomes.end();
    for( ; trans!=transEnd ; trans++) {
            balance1 += trans->getValue();
    }
    cout << "Total Incomes: " << balance1 <<endl;
    vector <Transaction>::const_iterator trans2 = expenses.begin(), transEnd2 = expenses.end();
    for( ; trans2!=transEnd2 ; trans2++) {
            balance2 += trans2->getValue();
    }
    cout << "Total Expenses: " << balance2 <<endl;

    return balance1-balance2;
}

void TransactionManager::showCurrentMonthBalance() {
    TimePeriod period= DateManager::getCurrentMonthPeriod();
    vector <Transaction> incomesFromPeriod, expensesFromPeriod;
    incomesFromPeriod = getTransactionsFromPeriod(period, incomes);
    sortTransactionsToLatest(incomesFromPeriod);
    expensesFromPeriod = getTransactionsFromPeriod(period, expenses);
    sortTransactionsToLatest(expensesFromPeriod);
    listTransactionsFromPeriod(incomesFromPeriod, expensesFromPeriod, period);
    //cout << "Total Incomes: " << <<endl;
    //cout << "Total Expenses: " << <<endl;
    double total = getBalanceOfTransactions(incomesFromPeriod, expensesFromPeriod);
    cout << "TOTAL: " << total <<endl;
}

void TransactionManager::showPreviousMonthBalance() {

}

void TransactionManager::showCustomPeriodBalance() {

}

void TransactionManager::addIncome() {
    cout << "***ADD INCOME***" <<endl;
    Transaction transaction = enterTransactionData();
    transaction.setTransactionId(incomesFile.getLastTransactionId()+1);
    incomes.push_back(transaction);
    incomesFile.addTransactionToFile(transaction);
    incomesFile.saveFile();
}

void TransactionManager::addExpense() {
    cout << "***ADD EXPENSE***" <<endl;
    Transaction transaction = enterTransactionData();
    transaction.setTransactionId(expensesFile.getLastTransactionId()+1);
    expenses.push_back(transaction);
    expensesFile.addTransactionToFile(transaction);
    expensesFile.saveFile();
}

Transaction TransactionManager::enterTransactionData() {
    Transaction transaction;
    transaction.setItem(askForItem());
    transaction.setValue(askForValue());
    transaction.setDate(askForDate());
    transaction.setUserId(userId);
    return transaction;
}

string TransactionManager::askForItem() {
    string info = "";
    do {
        cout << "Enter transaction's info (up to " << MESSAGE_LENGTH << " chars): ";
        getline(cin,info);
    } while (info.length() > MESSAGE_LENGTH || info.length() < 1);
    return info;
}

double TransactionManager::askForValue() {
    string input = "";
    do {
        cout << "Enter transaction's value [PLN]: ";
        getline(cin,input);
    } while (!isValueFormatCorrect(input));
    double value = atof(input.c_str());
    return value;
}

int TransactionManager::askForDate() {
    string dateInput = "";
    dateInput = DateManager::enterDate();
    int date = DateManager::getIntDateFromString(dateInput);
    return date;
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
