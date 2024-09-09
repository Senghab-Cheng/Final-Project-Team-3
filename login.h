#pragma once 

#include <iostream>
#include <string>
#include "AdminInfo.h"

using namespace std;

class Login{
    private :
        string usernameOrEmail;
        string password;

    public :
        bool userLogin() {
            cout << "[+] Enter your username or email : ";
            getline(cin, this->usernameOrEmail);

            cout << "[+] Enter your password : ";
            getline(cin, this->password);

            Admin admin1;
            if ((this->usernameOrEmail == admin1.getUsername() || this->usernameOrEmail == admin1.getEmail()) && this->password == admin1.getPassword()) {
            return 1;
            }
        return 0;
        }
};