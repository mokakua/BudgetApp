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

void TransactionManager::listTransactionsFromPeriod(const vector <Transaction>& periodicIncomes, const vector <Transaction>& periodicExpenses, const TimePeriod& period){
    cout << "Statement from " << DateManager::getStringDateFromInt(period.getFirstDay());
    cout << " to " << DateManager::getStringDateFromInt(period.getLastDay()) <<endl;
    cout << setprecision(2) << std::fixed;
    cout << "***INCOMES***:" <<endl;
    listTransactions(periodicIncomes);
    cout << endl;
    cout << "***EXPENSES***:" <<endl;
    listTransactions(periodicExpenses);
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
            cout << '=' << trans->getValue() << "zl"                    <<endl;
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

vector <Transaction> TransactionManager::selectTransactionsFromPeriod(const TimePeriod& period, const vector <Transaction>& transactions) {
    vector <Transaction> transactionsFromPeriod;
    vector <Transaction>::const_iterator trans = transactions.begin(), transEnd = transactions.end();
    for( ; trans!=transEnd ; trans++) {
        if(trans->getDate() >= period.getFirstDay() && trans->getDate() <= period.getLastDay()) {
            transactionsFromPeriod.push_back(*trans);
        }
    }
    return transactionsFromPeriod;
}
double TransactionManager::sumOfTransactions(const vector <Transaction>& transactions){
    double sumOfTransactions=0;
    vector <Transaction>::const_iterator trans = transactions.begin(), transEnd = transactions.end();
    for( ; trans!=transEnd ; trans++) {
            sumOfTransactions += trans->getValue();
    }
    return sumOfTransactions;
}

void TransactionManager::showBalanceOfTransactions(const vector <Transaction>& incomes, const vector <Transaction>& expenses) {
    double incomesTotal=0, expensesTotal=0;
    incomesTotal = sumOfTransactions(incomes);
    expensesTotal = sumOfTransactions(expenses);
    cout << "***TOTAL***"<< endl;
    cout << "INCOME\t"   << incomesTotal                 << endl;
    cout << "OUTCOME\t"  << expensesTotal                << endl;
    cout << "BALANCE\t"  << incomesTotal - expensesTotal << endl;
}


void TransactionManager::showPeriodStatement(const TimePeriod& period) {
    vector <Transaction> incomesFromPeriod, expensesFromPeriod;
    incomesFromPeriod = selectTransactionsFromPeriod(period, incomes);
    sortTransactionsToLatest(incomesFromPeriod);
    expensesFromPeriod = selectTransactionsFromPeriod(period, expenses);
    sortTransactionsToLatest(expensesFromPeriod);
    listTransactionsFromPeriod(incomesFromPeriod, expensesFromPeriod, period);
    showBalanceOfTransactions(incomesFromPeriod, expensesFromPeriod);
}

void TransactionManager::showCurrentMonthStatement(){
    TimePeriod period= DateManager::getCurrentMonthPeriod();
    showPeriodStatement(period);
}

void TransactionManager::showPreviousMonthStatement() {
    TimePeriod period= DateManager::getPreviousMonthPeriod();
    showPeriodStatement(period);
}

void TransactionManager::showCustomPeriodStatement() {
    TimePeriod period= DateManager::enterTimePeriod();
    showPeriodStatement(period);
}

void TransactionManager::listAllUsersTransactions() {
    cout << setprecision(2) << std::fixed;
    cout << "All incomes:" <<endl;
    listTransactions(incomes);
    cout << endl;
    cout << "All expenses:" <<endl;
    listTransactions(expenses);
    cout << endl;
}
