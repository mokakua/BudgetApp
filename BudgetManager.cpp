#include "BudgetManager.h"
#include <cstdlib>
#include <windows.h>
#include <algorithm>
#include <conio.h>

BudgetManager::BudgetManager(string usersFileName, string incomesFileName, string expensesFileName):
    userManager(usersFileName), NAME_OF_INCOMES_FILE(incomesFileName), NAME_OF_EXPENSES_FILE(expensesFileName) {
    transactionManager = NULL;
}

BudgetManager::~BudgetManager() {
    delete transactionManager;
}

void BudgetManager::showMenu() {
    if(userManager.getIdOfLoggedInUser()==0) {
        showStartMenu();
        char choice = enterCharacter();
        chooseStartOption(choice);
    } else {
        showMainMenu();
        char choice = enterCharacter();
        chooseMainOption(choice);
    }
}

void BudgetManager::showStartMenu() {
    system("cls");
    cout << "It's your Budget Manager"  <<endl <<endl;
    cout << "1. Log in"                 <<endl;
    cout << "2. Register"               <<endl;
    cout << "9. Exit"                   <<endl <<endl;
}

void BudgetManager::showMainMenu() {
    system("cls");
    userManager.welcomeLoggedInUser();
    cout << "It's your Budget Manager"          <<endl <<endl;
    cout << "1. Add income."                    <<endl;
    cout << "2. Add expense."                   <<endl;
    cout << "3. Show current month balance."    <<endl;
    cout << "4. Show last month balance."       <<endl;
    cout << "5. Show custom period balance."    <<endl;
    cout << "6. Change password."               <<endl;
    cout << "9. Log out"                        <<endl <<endl;
}

char BudgetManager::enterCharacter() {
    char character = 0;
    cout << "Enter the number." <<endl;
    character = getch();
    return character;
}
void BudgetManager::chooseStartOption(char choice) {
    system("cls");
    switch (choice) {
    case '1': {
        logIn();
    }
    break;
    case '2': {
        registerUser();
    }
    break;
    case '9': {
        exit(0);
    }
    default: {
        cout << "Invalid input " <<endl;
        Sleep(500);
    }
    break;
    }
}

void BudgetManager::chooseMainOption(char choice) {
    system("cls");
    switch (choice) {
    case '1': {
        addIncome();
    }
    break;
    case '2': {
        addExpense();
    }
    break;
    case '3': {
        showCurrentMonthStatement();
    }
    break;
    case '4': {
        showPreviousMonthStatement();
    }
    break;
    case '5': {
        showCustomMonthStatement();
    }
    break;
    case '6': {
        changePassword();
    }
    break;
    case '9': {
        logOut();
        animateMessage("Logging out...");
        return;
    }
    break;
    default: {
        cout << "Invalid input " <<endl;
        Sleep(500);
        return;
    }
    break;
    }
    waitForResponse();
}
void BudgetManager::animateMessage(string message) {
    size_t letters = message.length();
    for(size_t i = 0; i<=letters; i++) {
        cout << message[i];
        Sleep(50);
    }
    Sleep(500);
}
void BudgetManager::logIn() {
    userManager.logIn();
    if (userManager.getIdOfLoggedInUser()!=0) {
        transactionManager = new TransactionManager(userManager.getIdOfLoggedInUser(), NAME_OF_INCOMES_FILE, NAME_OF_EXPENSES_FILE);
    }
}

void BudgetManager::registerUser() {
    userManager.registerUser();
}

void BudgetManager::addIncome() {
    transactionManager->addIncome();
}

void BudgetManager::addExpense() {
    transactionManager->addExpense();
}

void BudgetManager::showCurrentMonthStatement() {
    transactionManager->showCurrentMonthStatement();
}

void BudgetManager::showPreviousMonthStatement() {
    transactionManager->showPreviousMonthStatement();
}

void BudgetManager::showCustomMonthStatement() {
    transactionManager->showCustomPeriodStatement();
}

void BudgetManager::changePassword() {
    userManager.changePassword();
}

void BudgetManager::logOut() {
    userManager.logOut();
    delete transactionManager;
}

void BudgetManager::waitForResponse() {
    cout << "Press any key to continue...";
    getch();
    return;
}
