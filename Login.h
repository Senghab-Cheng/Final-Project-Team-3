#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "AdminInfo.h"
#include "loadingBar.h"
#include <conio.h>  // For masking password on Windows

using namespace std;

#define LIGHT_BLUE "\033[38;5;123m"
#define BRIGHT_GREEN "\033[38;5;122m"
#define LIGHT_GREEN "\033[92m"
#define LIGHT_PINK "\033[38;5;217m"
#define LIGHT_PEACH "\033[38;5;223m"
#define CYAN "\033[36m"
#define GREEN "\033[38;5;46m"
#define BRIGHT_RED "\033[91m"
#define RESET "\033[0m"        // Reset definition

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
            cerr << BRIGHT_RED << "Error: Unable to open file." << RESET << endl;
        }
    }

    // Function to mask password input with '*'
    string inputPassword() {
        string password;
        char ch;
        while ((ch = _getch()) != '\r') {  // Enter key stops input
            if (ch == '\b') {  // Handle backspace
                if (!password.empty()) {
                    cout << "\b \b";  // Erase character from console
                    password.pop_back();
                }
            } else {
                password += ch;
                cout << '*';  // Show '*' for each character
            }
        }
        cout << endl;
        return password;
    }

public:
    bool userLogin() {
        cout << "+=================================================================================================+" << endl;
        cout << "|                                               ---------                                         |" << endl;
        cout << "|";cout << LIGHT_PEACH;cout << "                                            >>>  LOGIN  <<<                                      ";cout << RESET;cout <<"|" << endl;
        cout << "|                                               ---------                                         |" << endl;
        cout << "+=================================================================================================+" << endl;

        loadFromFile();

        cout << CYAN << "[+] Enter your Username or Email : " << RESET;
        cout << LIGHT_GREEN;
        getline(cin, this->usernameOrEmail);
        cout << RESET;

        cout << CYAN << "[+] Enter your Password : " << RESET;
        cout << LIGHT_GREEN;
        this->password1 = inputPassword();  // Using inputPassword() for masked input
        cout << RESET;

        // Check if the entered username/email and password match
        if ((this->usernameOrEmail == email || this->usernameOrEmail == username) && this->password1 == password) {
            return true;  // Login successful
        }

        return false;  // Login failed
    }
};
