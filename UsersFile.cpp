#include "UsersFile.h"

UsersFile::UsersFile(string name)
    :XMLFile(name) {
    if(!file.Load(name)) {
        file.AddElem("Users");
        file.Save(name);
    }
}

vector <User> UsersFile::loadUserFromFile() {
    vector <User> users;
    file.FindElem("Users");
    file.IntoElem();
    while(file.FindElem("User")) {
        User user;
        file.FindChildElem("name");
        user.setName(file.GetChildData());
        file.ResetChildPos();
        file.FindChildElem("surname");
        user.setSurname(file.GetChildData());
        file.ResetChildPos();
        file.FindChildElem("login");
        user.setLogin(file.GetChildData());
        file.ResetChildPos();
        file.FindChildElem("password");
        user.setPassword(file.GetChildData());
        file.ResetChildPos();
        file.FindChildElem("id");
        user.setId(atoi(file.GetChildData().c_str()));
        users.push_back(user);
    }
    file.OutOfElem();
    file.ResetPos();
    return users;
}

void UsersFile::addUserToFile(User user) {
    file.FindElem("Users");
    file.IntoElem();
    file.AddElem("User");
    file.AddChildElem("name", user.getName());
    file.AddChildElem("surname", user.getSurname());
    file.AddChildElem("login", user.getLogin());
    file.AddChildElem("password", user.getPassword());
    file.AddChildElem("id", user.getId());
    file.OutOfElem();
    file.ResetPos();
    file.Save(name);
}

void UsersFile::saveAllUsersToFile() {
}


