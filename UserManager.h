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
    string enterMaskedPassword();
    void addUserToFile(const User& user);
    void changeUserData(const User& user);
    int getIdOfNewUser();
    bool doesLoginExists(string loginInput);
    vector <User>::iterator getUserByLogin(string login);
    vector <User>::iterator getLoggedInUser();
    string convertFirstToUpperOtherToLower(string input);
    void loadUsersFromFile();
    bool areCredentialsCorrect(string login, string password);
    void waitPenaltyTime(int seconds);

public:

    UserManager(const string& usersFileName);
    void registerUser();
    void logIn();
    void changePassword();
    void logOut();
    int getIdOfLoggedInUser();
    void welcomeLoggedInUser();
};
#endif // USERMANAGER_H
