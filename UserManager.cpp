#include "UserManager.h"
#include <cstdlib>
#include <windows.h>

UserManager::UserManager(string usersFileName):
    idOfLoggedInUser(0), usersFile(usersFileName) {

}
string UserManager::askForInput(string inputName) {
    string input = "";
    while (input == "") {
        system("cls");
        cout << "Enter user " << inputName << ": ";
        cin >> input;
        if(inputName == "login") {
            if(doesLoginExists(input)) {
                cout << "Login exists already. Try again" <<endl;
                Sleep(700);
                input = "";
                continue;
            }
        }
    }
    return input;
}

void UserManager::registerUser() {
    User user;
    user.setName(askForInput("name"));
    user.setSurname(askForInput("surname"));
    user.setLogin(askForInput("login"));
    user.setLogin(askForInput("password"));
    user.setId(getIdOfNewUser());
}
void UserManager::login() {

}
void UserManager::changePassword() {

}
void UserManager::logOut() {

}
int UserManager::getIdOfLoggedInUser() {

}


void UserManager::loadUsersFromFile() {

}
void UserManager::addUserToFile() {

}
User UserManager::enterDataOfNewUser() {

}
int UserManager::getIdOfNewUser() {
    int id = 0;
    return id;
}

bool UserManager::doesLoginExists(string loginInput) {
    vector <User> ::iterator user = users.begin(), endOfUsers = users.end();
    for (; user!=endOfUsers; user++) {
        if (user->getLogin() == loginInput) {
            return true;
        }
    }
    return false;
}

