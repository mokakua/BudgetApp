#include "UserManager.h"
#include <cstdlib>
#include <windows.h>
#include <algorithm>
#include <conio.h>

UserManager::UserManager(const string& usersFileName):
    idOfLoggedInUser(0), usersFile(usersFileName) {
    loadUsersFromFile();
}

string UserManager::convertFirstToUpperOtherToLower(string input) {
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    input [0] = toupper(input[0]);
    return input;
}

string UserManager::enterUserData(string inputName) {
    string input = "";
    while (input.empty()) {
        cout << "Enter user " << inputName << ": ";
        if (inputName == "password") {
            input = enterMaskedPassword();
            continue;
        }
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

string UserManager::enterMaskedPassword() {
    string password = "";
    char character = 0;
    enum specialCharacters {backspace = 8, enter = 13, esc = 27};
    while(character != esc) {
        character = getch();
        switch(character) {
        case backspace: {
            if(!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        }
        break;
        case enter: {
            cout << endl;
            return password;
        }
        break;
        case esc:
            break;
        default: {
            if (isalnum(character)) {
                password.push_back(character);
                cout << '*';
            }
        }
        }
    }
    password = "";
    return password;
}

void UserManager::registerUser() {
    User user;
    string data = "";
    system("cls");
    cout << "*** REGISTER NEW USER ***" <<endl <<endl;
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
    addUserToFile(user);
}

vector <User>::iterator UserManager::getUserByLogin(string login) {
    vector <User> ::iterator user = users.begin(), endOfUsers = users.end();
    for (; user!=endOfUsers; user++) {
        if (user->getLogin() == login) {
            break;
        }
    }
    return user;
}

vector <User>::iterator UserManager::getLoggedInUser() {
    vector <User> ::iterator user = users.begin(), endOfUsers = users.end();
    for (; user!=endOfUsers; user++) {
        if (user->getId() == getIdOfLoggedInUser()) {
            break;
        }
    }
    return user;
}

void UserManager::logIn() {
    string login = "";
    string password = "";
    cout << "*** LOG IN ***" <<endl <<endl;
    for (int attempts = 3; attempts>0; attempts--) {

        cout << "Login: ";
        getline(cin,login);
        cout << "Password: ";
        password = enterMaskedPassword();

        if (areCredentialsCorrect(login, password)) {
            idOfLoggedInUser = getUserByLogin(login)->getId();
            return;
        }
        system("cls");
        cout << "Login or password is invalid."                     <<endl;
        cout << "Please try again. Attempts left: " << attempts-1   <<endl <<endl;
    }
    waitPenaltyTime(3);
}

bool UserManager::areCredentialsCorrect(string login, string password) {
    transform(login.begin(), login.end(), login.begin(), ::tolower);
    if (getUserByLogin(login)==users.end()) {
        return false;
    }
    string validPassword = getUserByLogin(login)->getPassword();
    if (password != validPassword) {
        return false;
    }
    return true;
}

void UserManager::waitPenaltyTime(int seconds) {
    for (; seconds > 0; seconds--) {
        system("cls");
        cout << "Operation failed. Penalty time: " << seconds << "s" <<endl;
        Sleep(1000);
    }
}

void UserManager::changePassword() {
    string newPassword = "";
    string repeatedPassword = "";
    auto user = getLoggedInUser();
    while (true) {
        while(newPassword.empty()) {
            cout << "Enter new password: ";
            newPassword = enterMaskedPassword();
        }
        cout << "Repeat password: ";
        repeatedPassword = enterMaskedPassword();
        if(newPassword == repeatedPassword) {
            break;
        }
        cout << "Passwords do not match. Try again" <<endl <<endl;
        newPassword.clear();
    }
    user->setPassword(newPassword);
    changeUserData(*user);
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
    system("cls");
    if (usersFile.addUserToFile(user)) {
        cout << "User successfully registered." <<endl;
    } else {
        cout << "Operation failed." <<endl;
    }
    Sleep(1500);
}

void UserManager::changeUserData(const User& user) {
    system("cls");
    if (usersFile.changeUserData(user)) {
        cout << "Password successfully changed." <<endl;
    } else {
        cout << "Operation failed." <<endl;
    }
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

void UserManager::welcomeLoggedInUser() {
    int id = getIdOfLoggedInUser();
    vector <User>::iterator iter = users.begin(), end = users.end();
    for(; iter!=end; iter++) {
        if(iter->getId() == id) {
            cout << "Welcome " << iter->getName() << ' ' << iter->getSurname() <<endl;
            break;
        }
    }
}
