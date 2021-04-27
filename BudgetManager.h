#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H
#include <iostream>
#include "UserManager.h"
#include "TransactionManager.h"

using namespace std;

class BudgetManager {
    UserManager userManager;
    const string NAME_OF_INCOMES_FILE;
    const string NAME_OF_EXPENSES_FILE;
    TransactionManager *transactionManager;

    char enterCharacter();
    void chooseStartOption(char choice);
    void chooseMainOption(char choice);
    void showStartMenu();
    void logIn();
    void registerUser();
    void showMainMenu();
    void addIncome();
    void addExpense();
    void showCurrentMonthStatement();
    void showPreviousMonthStatement();
    void showCustomMonthStatement();
    void changePassword();
    void logOut();
    void waitForResponse();

public:
    BudgetManager(string usersFileName, string incomesFileName, string expensesFileName);
    ~BudgetManager();
    void showMenu();

};

#endif // BUDGETMANAGER_H
