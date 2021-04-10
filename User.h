#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User {

    string name, surname, login, password;
    int id;

public:

    void setName (string name);
    void setSurname (string surname);
    void setLogin (string login);
    void setPassword (string passsword);
    void setId (int id);


    string getName();
    string getSurname();
    string getLogin();
    string getPassword();
    int getId();

};
#endif // USER_H
