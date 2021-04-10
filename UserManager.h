#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include "User.h"
#include <vector>

using namespace std;

class UserManager {

    vector <User> users;
    int idOfLoggedInUser;
    //UsersFile usersFile;

    //void loadUsersFromFile();
    //void addUserToFile();
    //User enterDataOfNewUser();
    //int getIdOfNewUser();
    //bool doesUserExists();

public:

    UserManager();
    void registerUser();
    void login();
    void changePassword();
    void logOut();
    int getIdOfLoggedInUser();


    void loadUsersFromFile();
    void addUserToFile();
    User enterDataOfNewUser();
    int getIdOfNewUser();
    bool doesUserExists();

};
#endif // USERMANAGER_H
