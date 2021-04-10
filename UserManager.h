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

    string askForInput(string inputName);
    //void loadUsersFromFile();
    //void addUserToFile();
    //User enterDataOfNewUser();
    //int getIdOfNewUser();
    //bool doesLoginExists(string loginInput);

public:

    UserManager(string usersFileName);
    void registerUser();
    void login();
    void changePassword();
    void logOut();
    int getIdOfLoggedInUser();


    void loadUsersFromFile();
    void addUserToFile();
    User enterDataOfNewUser();
    int getIdOfNewUser();
    bool doesLoginExists(string loginInput);

};
#endif // USERMANAGER_H
