#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H
#include <iostream>
#include "UserManager.h"
#include "TransactionManager.h"

using namespace std;

class BudgetManager {
    UserManager userManager;
    TransactionManager *transactionManager;
    const string NAME_OF_USERS_FILE;
    const string NAME_OF_INCOMES_FILE;
    const string NAME_OF_EXPENSES_FILE;

    char enterCharacter();
    void chooseStartOption(char choice);
    void chooseMainOption(char choice);

public:
    BudgetManager(string usersFileName, string incomesFileName, string expensesFileName);
    ~BudgetManager();
    void showMenu();
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
};

#endif // BUDGETMANAGER_H
