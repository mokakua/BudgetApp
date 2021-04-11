#include "User.h"


void User::setName (string name) {
    this->name = name;
}
void User::setSurname (string surname) {
    this->surname = surname;
}
void User::setLogin (string login) {
    this->login = login;
}
void User::setPassword (string passsword) {
    this->password = passsword;
}
void User::setId (int id) {
    this->id = id;
}

string User::getName() const {
    return this->name;
}
string User::getSurname() const {
    return this->surname;
}
string User::getLogin() const {
    return this->login;
}
string User::getPassword() const {
    return this->password;
}
int User::getId() const {
    return this->id;
}
