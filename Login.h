#pragma once 

#include <iostream>
#include <string>
#include <fstream> // Added include for ifstream
#include "AdminInfo.h"
#include "loadingBar.h"

using namespace std;

class Login {
private:
    string usernameOrEmail;
    string password1;
    string password;
    string username;
    string email;

    // Load information from file
    void loadFromFile() {
        ifstream adminInfo("data/adminInfo.txt");
        if (adminInfo.is_open()) {
            string line;
            while (getline(adminInfo, line)) {
                if (line.find("Username:") != string::npos) {
                    username = line.substr(line.find(":") + 2);
                } else if (line.find("Email:") != string::npos) {
                    email = line.substr(line.find(":") + 2);
                } else if (line.find("Password:") != string::npos) {
                    password = line.substr(line.find(":") + 2);
                }
            }
            adminInfo.close();
        } else {
            cerr << "Error: Unable to open file." << endl;
        }
    }

public:
    bool userLogin() {
        cout << "+==============================================================================+" << endl;
        cout << "|                                   ---------                                  |" << endl;
        cout << "|                                >>>  LOGIN  <<<                               |" << endl;
        cout << "|                                   ---------                                  |" << endl;
        cout << "+==============================================================================+" << endl;
        
        loadFromFile();
        
        cout << "[+] Enter your Username or Email : ";
        //cin.ignore();
        getline(cin, this->usernameOrEmail);
        
        cout << "[+] Enter your Password : ";
        getline(cin, this->password1);

        // Debugging output
        cout << "DEBUG: Username or Email entered: " << this->usernameOrEmail << endl;
        cout << "DEBUG: Password entered: " << this->password1 << endl;
        cout << "DEBUG: Stored Username: " << this->username << endl;
        cout << "DEBUG: Stored Email: " << this->email << endl;
        cout << "DEBUG: Stored Password: " << this->password << endl;

        if ((this->usernameOrEmail == email || this->usernameOrEmail == username) && this->password1 == password) {
            return true; // Success
        }
        
        return false; // Failure
    }
};
