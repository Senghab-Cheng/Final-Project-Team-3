#pragma once 

#include <iostream>
#include <string>
#include "AdminInfo.h"
#include "loadingBar.h"

using namespace std;

class Login{
    private :
        string usernameOrEmail;
        string password;

    public :
        bool userLogin() {
            cout << "+==============================================================================+" << endl;
            cout << "|                                   ---------                                  |" << endl;
            cout << "|                                >>>  LOGIN  <<<                               |" << endl;
            cout << "|                                   ---------                                  |" << endl;
            cout << "+==============================================================================+" << endl;
            cout << "[+] Enter your username or email : ";
            cin.ignore();
            getline(cin, this->usernameOrEmail);
            cout << "[+] Enter your password : ";
            getline(cin, this->password);
            
            getLoadingBar();
            Admin admin1;
            if ((this->usernameOrEmail == admin1.getUsername() || this->usernameOrEmail == admin1.getEmail()) && this->password == admin1.getPassword()) {
                return 1;
            }
        return 0;
        }
};