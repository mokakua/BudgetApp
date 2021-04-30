#include <iostream>
#include "BudgetManager.h"

using namespace std;

int main(){
    const string USERSFILENAME = "users.xml";
    const string EXPENSESFILENAME = "expenses.xml";
    const string INCOMESFILENAME = "incomes.xml";
    BudgetManager bManager(USERSFILENAME, INCOMESFILENAME, EXPENSESFILENAME);
    while (true){
        bManager.showMenu();
    }
}
