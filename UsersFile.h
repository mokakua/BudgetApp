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
    void addUserToFile(User user);
    void saveAllUsersToFile();


};
#endif // USERSFILE_H
