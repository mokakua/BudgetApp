#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include "User.h"
#include "UsersFile.h"
#include <vector>

using namespace std;

class UserManager {

    vector <User> users;
    int idOfLoggedInUser;
    UsersFile usersFile;

    string enterUserData(string inputName);
    void addUserToFile(const User& user);
    int getIdOfNewUser();
    bool doesLoginExists(string loginInput);
    vector <User>::iterator getUserByLogin(string login);
    vector <User>::iterator getLoggedInUser();
    string convertFirstToUpperOtherToLower(string input);

public:

    UserManager(string usersFileName);
    void registerUser();
    void logIn();
    void changePassword();
    void logOut();
    int getIdOfLoggedInUser();
    void loadUsersFromFile();

    void listUsers();

    string enterPassword();//

};
#endif // USERMANAGER_H
