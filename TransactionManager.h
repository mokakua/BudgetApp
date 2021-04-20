#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H
#include "Transaction.h"
#include "TransactionsFile.h"
#include "TimePeriod.h"
#include <iostream>
#include <vector>


using namespace std;

class TransactionManager {

    vector <Transaction> incomes;
    vector <Transaction> expenses;
    TransactionsFile incomesFile;
    TransactionsFile expensesFile;
    int userId;
    const int MESSAGE_LENGTH;

    void enterData();
    string askForItem();
    double askForValue();
    int askForDate();
    bool isValueFormatCorrect(string &input);
    void listTransactionsFromPeriod(const vector <Transaction>& incomesFromPeriod, const vector <Transaction>& expensesFromPeriod, const TimePeriod& period);
    void listTransactions(vector <Transaction> transactions);
    bool isTransactionLaterThan (const Transaction& trans1, const Transaction& trans2);

    void sortTransactionsToLatest(vector <Transaction>& transactions);
    vector <Transaction> getTransactionsFromPeriod(const TimePeriod& period, const vector <Transaction>& transactions);
    double getBalanceOfTransactions(const vector <Transaction>& incomes, const vector <Transaction>& expenses);
    Transaction enterTransactionData();
    string showInfo(string info);

public:
    TransactionManager(int id, const string& NAME_OF_INCOMES_FILE, const string& NAME_OF_EXPENSES_FILE);

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();
    void loadUserTransactionsFromFile();
    void listUsersTransactions();

};
#endif // TRANSACTIONMANAGER_H
