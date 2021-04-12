#include "UserManager.h"
#include <cstdlib>
#include <windows.h>
#include <algorithm>

UserManager::UserManager(string usersFileName):
    idOfLoggedInUser(0), usersFile(usersFileName) {

}

string UserManager::convertFirstToUpperOtherToLower(string input){
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    toupper(input[0]);
    return input;
}

string UserManager::enterUserData(string inputName) {
    string input = "";
    while (input == "") {
        cout << "Enter user " << inputName << ": ";
        getline(cin,input);
        if(inputName == "login") {
            if(doesLoginExists(input)) {
                cout << "Login already exists. Try again" <<endl;
                input = "";
                continue;
            }

        }
    }
    return input;
}

void UserManager::registerUser() {
    User user;
    string data = "";
    system("cls");
    cout << "*** REGISTER NEW USER ***" <<endl;
    data = enterUserData("name");
    user.setName(convertFirstToUpperOtherToLower(data));
    data = enterUserData("surname");
    user.setSurname(convertFirstToUpperOtherToLower(data));
    data = enterUserData("login");
    transform(data.begin(), data.end(), data.begin(), ::tolower);
    user.setLogin(data);
    user.setPassword(enterUserData("password"));
    user.setId(getIdOfNewUser());
    users.push_back(user);
    cout << "User registred" <<endl;
    usersFile.addUserToFile(user);
    Sleep (1000);
    system("cls");
}

vector <User>::iterator UserManager::getUserByLogin(string login){
    vector <User> ::iterator user = users.begin(), endOfUsers = users.end();
    for (; user!=endOfUsers; user++) {
        if (user->getLogin() == login) {
            break;
        }
    }
    return user;
}

vector <User>::iterator UserManager::getLoggedInUser(){
    vector <User> ::iterator user = users.begin(), endOfUsers = users.end();
    for (; user!=endOfUsers; user++) {
        if (user->getId() == getIdOfLoggedInUser()) {
            break;
        }
    }
    return user;
}

void UserManager::logIn() {
    system("cls");
    string login = "";
    string password = "";
    cout << "*** LOG IN ***" <<endl;
    while (true){
        cout << "Login: ";
        getline(cin,login);
        transform(login.begin(), login.end(), login.begin(), ::tolower);
        if (getUserByLogin(login)!=users.end()){
            break;
        }
        cout << "Login does not exist." <<endl;
    }
    string validPassword = getUserByLogin(login)->getPassword();
    for (int attempts = 3; attempts>0; attempts--){
        cout << "Password: ";
        getline(cin,password);
        if (password == validPassword){
            idOfLoggedInUser = getUserByLogin(login)->getId();
            return;
        }
        cout << "Password is not correct. Please try again." <<endl;
        cout << "Attempts left: " << attempts-1 <<endl;
    }
    cout << "Operation failed" <<endl;
    Sleep(3000);
}

void UserManager::changePassword() {
    string newPassword = "";
    string repeatedPassword = "";
    auto user = getLoggedInUser();
    while (true){
        cout << "Enter new password: ";
        getline(cin,newPassword);
        cout << "Repeat password: ";
        getline(cin,repeatedPassword);
        if(newPassword == repeatedPassword){
            break;
        }
        cout << "Passwords do not match. Try again" <<endl <<endl;
    }
    user->setPassword(newPassword);
    cout << "Password changed successfully" <<endl;
    usersFile.changeUserData(*user);
    usersFile.saveFile();
}

void UserManager::logOut() {
    idOfLoggedInUser = 0;
}

int UserManager::getIdOfLoggedInUser() {
    return idOfLoggedInUser;
}

void UserManager::loadUsersFromFile() {
    users = usersFile.loadUserFromFile();
}

void UserManager::addUserToFile(const User& user) {
    usersFile.addUserToFile(user);
    usersFile.saveFile();
}

int UserManager::getIdOfNewUser() {
    if(users.size()>0) {
        int lastId = users[users.size()-1].getId();
        return lastId+1;
    } else {
        return 1;
    }
}

bool UserManager::doesLoginExists(string loginInput) {
    if (getUserByLogin(loginInput) != users.end()) {
            return true;
        }
    return false;
}

void UserManager::listUsers() {
    vector <User>::iterator iter = users.begin(), end = users.end();
    for(; iter!=end; iter++) {
        cout << iter->getName() <<endl;
        cout << iter->getSurname() <<endl;
        cout << iter->getLogin() <<endl;
        cout << iter->getPassword() <<endl;
        cout << iter->getId() <<endl <<endl;
    }
}
