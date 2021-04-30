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
    bool addUserToFile(const User& user);
    bool changeUserData(const User& user);
};
#endif // USERSFILE_H
