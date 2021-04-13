#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include <vector>
#include "XMLFile.h"
#include "User.h"
#include "Markup.h"
using namespace std;

class UsersFile :public XMLFile {


public:
    UsersFile(string name);
    vector <User> loadUserFromFile();
    void addUserToFile(const User& user);
    void changeUserData(const User& user);
    void saveFile();
};
#endif // USERSFILE_H
