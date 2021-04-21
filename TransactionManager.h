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
    const size_t MESSAGE_LENGTH;

    Transaction enterTransactionData();
    string askForItem();
    double askForValue();
    int askForDate();
    bool isValueFormatCorrect(string &input);
    void listTransactions(vector <Transaction> transactions);
    string showInfo(string info);
    bool isTransactionLaterThan (const Transaction& trans1, const Transaction& trans2);


    vector <Transaction> selectTransactionsFromPeriod(const TimePeriod& period, const vector <Transaction>& transactions);
    void listTransactionsFromPeriod(const vector <Transaction>& periodicIncomes, const vector <Transaction>& periodicExpenses, const TimePeriod& period);
    void sortTransactionsToLatest(vector <Transaction>& transactions);
    double sumOfTransactions(const vector <Transaction>& transactions);
    void showBalanceOfTransactions(const vector <Transaction>& incomes, const vector <Transaction>& expenses);
    void showPeriodStatement(const TimePeriod& period);

public:
    TransactionManager(int id, const string& NAME_OF_INCOMES_FILE, const string& NAME_OF_EXPENSES_FILE);

    void addIncome();
    void addExpense();
    void showCurrentMonthStatement();
    void showPreviousMonthStatement();
    void showCustomPeriodStatement();
    void loadUserTransactionsFromFile();

    void listAllUsersTransactions();

};
#endif // TRANSACTIONMANAGER_H
