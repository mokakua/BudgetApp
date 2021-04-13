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


    string getName() const;
    string getSurname() const;
    string getLogin() const;
    string getPassword() const;
    int getId() const;

};
#endif // USER_H
