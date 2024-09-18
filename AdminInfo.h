#pragma once 

#include <iostream>
#include <iomanip>  // For setw
#include <string>
#include <fstream>  // For file operations
#include <thread>
#include <chrono>
#include <conio.h>
#include <Windows.h>

#include "loadingBar.h"

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

bool isUpdate = 0;

class Admin {
    public : 
        enum KEY { UP = 72, DOWN = 80, ENTER = 13 }; // Arrow keys and Enter key

        void setConsoleTextColor(int color) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        }
    private:
        string username;
        string email;
        string password;
        string bio;
        string tel;
        string telegram;
        string gitHub;

        // Save updated information to file
        void saveToFile() {
            ofstream adminInfo("data/adminInfo.txt");
            if (adminInfo.is_open()) {
                adminInfo << "Username: " << username << endl;
                adminInfo << "Email: " << email << endl;
                adminInfo << "Password: " << password << endl;
                adminInfo << "Bio: " << bio << endl;
                adminInfo << "Tel: " << tel << endl;
                adminInfo << "Telegram: " << telegram << endl;
                adminInfo << "GitHub: " << gitHub << endl;
                adminInfo.close();
                isUpdate = 1;
            } else {
                cerr << BRIGHT_RED << "Unable to open file for writing!" << RESET << endl;
            }
        }

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
                    } else if (line.find("Bio:") != string::npos) {
                        bio = line.substr(line.find(":") + 2);
                    } else if (line.find("Tel:") != string::npos) {
                        tel = line.substr(line.find(":") + 2);
                    } else if (line.find("Telegram:") != string::npos) {
                        telegram = line.substr(line.find(":") + 2);
                    } else if (line.find("GitHub:") != string::npos) {
                        gitHub = line.substr(line.find(":") + 2);
                    }
                }
                adminInfo.close();
            } else {
                cerr << BRIGHT_RED << "Unable to open file for reading!" << RESET << endl;
            }
        }

    public:
        Admin() {
            loadFromFile(); // Load data when object is created
        }

        // Getters
        string getUsername() const {
            return username;
        }
        string getEmail() const {
            return email;
        }
        string getPassword() const {
            return password;
        }
        string getBio() const {
            return bio;
        }
        string getTel() const {
            return tel;
        }
        string getTelegram() const {
            return telegram;
        }
        string getGitHub() const {
            return gitHub;
        }

        // Setters
        void setUsername(const string& newUsername) {
            username = newUsername;
            saveToFile();  // Save to file after updating
        }
        void setEmail(const string& newEmail) {
            email = newEmail;
            saveToFile();  // Save to file after updating
        }
        void setPassword(const string& newPassword) {
            password = newPassword;
            saveToFile();  // Save to file after updating
        }
        void setBio(const string& newBio) {
            bio = newBio;
            saveToFile();  // Save to file after updating
        }
        void setTel(const string& newTel) {
            tel = newTel;
            saveToFile();  // Save to file after updating
        }
        void setTelegram(const string& newTelegram) {
            telegram = newTelegram;
            saveToFile();  // Save to file after updating
        }
        void setGitHub(const string& newGitHub) {
            gitHub = newGitHub;
            saveToFile();  // Save to file after updating
        }
};

class ProfileSetting : public Admin {
    private:
 
        void listUpdateOrShowDetails(int currentSelection, int totalOptions) {
            cout << "+=================================================================================================+" << endl;
            cout << "|                                                                                                 |" << endl;
            cout << "|";cout << LIGHT_PEACH;
            cout << "                                    >>> Admin Profile Settings <<<                               ";cout << RESET;cout << "|" << endl;
            cout << "|                                                                                                 |" << endl;
            cout << "+=================================================================================================+" << endl;
            cout << "|                                                                                                 |" << endl;
            
            string options[3] = {
                "Show Admin Information",
                "Account Settings",
                "Exit"
            };

            for (int i = 0; i < totalOptions; i++) {
                if (i == currentSelection) {
                    setConsoleTextColor(15); // Bold (White text on black background)
                    cout << "|  =>    " << options[i] << string(62 - options[i].length(), ' ') << "                           |" << endl;
                } else {
                    setConsoleTextColor(8); // Normal (Gray text on black background)
                    cout << "|        " << options[i] << string(62 - options[i].length(), ' ') << "                           |" << endl;
                }
            }

            setConsoleTextColor(7); // Reset to normal color
            cout << "|                                                                                                 |" << endl;
            cout << "+=================================================================================================+" << endl;
            cout << "|";cout << LIGHT_GREEN;
            cout << "                          >>>  Select an option by pressing Enter  <<<                           ";cout << RESET;
            cout << "|" << endl;
            cout << "+=================================================================================================+" << endl;


        }

        void showDetails() {
            getLoadingBar();
            cout << "+------------+----------------------------------------+" << endl;
            cout << "| USERNAME   | " << setw(38) << left << getUsername() << " |" << endl;
            cout << "+------------+----------------------------------------+" << endl;
            cout << "| EMAIL      | " << setw(38) << left << getEmail() << " |" << endl;
            cout << "+------------+----------------------------------------+" << endl;
            cout << "| BIO        | " << setw(38) << left << getBio() << " |" << endl;
            cout << "+------------+----------------------------------------+" << endl;
            cout << "| TEL        | " << setw(38) << left << getTel() << " |" << endl;
            cout << "+------------+----------------------------------------+" << endl;
            cout << "| TELEGRAM   | " << setw(38) << left << getTelegram() << " |" << endl;
            cout << "+------------+----------------------------------------+" << endl;
            cout << "| GITHUB     | " << setw(38) << left << getGitHub() << " |" << endl;
            cout << "+------------+----------------------------------------+" << endl;
        }

        void listForUpdate(int currentSelection, int totalOptions) {
            cout << "+=================================================================================================+" << endl;
            cout << "|                                                                                                 |" << endl;
            cout << "|";cout << LIGHT_PEACH;
            cout << "                                     >>> ADMINISTRATOR PANEL <<<                                 ";cout << RESET;cout << "|" << endl;
            cout << "|                                                                                                 |" << endl;
            cout << "+=================================================================================================+" << endl;
            cout << "|                                                                                                 |" << endl;
            
            string options[8] = {
                "Update Username",
                "Update Email Address",
                "Update Password",
                "Update Contact Number",
                "Update Telegram",
                "Update GitHub Username",
                "Update Biography",
                "Exit"
            };
            
            for (int i = 0; i < totalOptions; i++) {
                if (i == currentSelection) {
                    setConsoleTextColor(15); // Bold (White text on black background)
                    cout << "|  =>    " << options[i] << string(62 - options[i].length(), ' ') << "                           |" << endl;
                } else {
                    setConsoleTextColor(8); // Normal (Gray text on black background)
                    cout << "|        " << options[i] << string(62 - options[i].length(), ' ') << "                           |" << endl;
                }
            }

            setConsoleTextColor(7); // Reset to normal color
            cout << "|                                                                                                 |" << endl;
            cout << "+=================================================================================================+" << endl;
            cout << "|";cout << LIGHT_GREEN;
            cout << "                          >>>  Select an option by pressing Enter  <<<                           ";cout << RESET;
            cout << "|" << endl;
            cout << "+=================================================================================================+" << endl;

        }

        void updateUsername() {
            string newUsername;
            cout << CYAN << "[+] Enter your new Username : " << RESET;
            //cin.ignore();
            cout << LIGHT_GREEN;
            getline(cin, newUsername);
            cout << RESET;
            setUsername(newUsername);  // Use setter to update the username
            getLoadingBar();
            if (isUpdate)
                cout << LIGHT_GREEN << "Username updated" << RESET << endl;
        }

        void updateEmail() {
            string newEmail;
            cout << CYAN << "[+] Enter your new Email Address : " << RESET;
            //cin.ignore();
            cout << LIGHT_GREEN;
            getline(cin, newEmail);
            cout << RESET;
            setEmail(newEmail);  // Use setter to update the email
            getLoadingBar();
            if (isUpdate)
                cout << LIGHT_GREEN << "Email Address updated successfully." << RESET << endl; 
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

        void updatePassword() {
            string newPassword;
            cout << CYAN << "[+] Enter your new Password: " << RESET;
            //cin.ignore();
            cout << LIGHT_GREEN;
            //getline(cin, newPassword);
            newPassword = inputPassword();
            cout << RESET;

            string verPassword;
            cout << CYAN << "[+] Confirm your new Password: " << RESET;
            cout << LIGHT_GREEN;
            // getline(cin, verPassword);
            verPassword = inputPassword();
            cout << RESET;
            getLoadingBar();
            if (newPassword != verPassword) {
                do {
                    cerr << BRIGHT_RED << "Passwords do not match. Please re-enter to confirm your new Password: " << RESET;
                    //getline(cin, verPassword);
                    cout << LIGHT_GREEN;
                    verPassword = inputPassword();
                    cout << RESET;
                    getLoadingBar();
                } while (newPassword != verPassword);
            }
            setPassword(newPassword);  // Use setter to update the password
            cout << LIGHT_GREEN << "Password updated successfully." << RESET << endl;
        }

        void updateTel() {
            string newTel;
            cout << CYAN << "[+] Enter your new Contact Number : " << RESET;
            //cin.ignore();
            cout << LIGHT_GREEN;
            getline(cin, newTel);
            cout << RESET;
            setTel(newTel);  // Use setter to update the contact number
            getLoadingBar();
            if (isUpdate)
                cout << LIGHT_GREEN << "Contact Number updated successfully."<< RESET << endl;
        }

        void updateTelegram() {
            string newTelegram;
            cout << CYAN << "[+] Enter your new Telegram : " << RESET;
            //cin.ignore();
            cout << LIGHT_GREEN;
            getline(cin, newTelegram);
            cout << RESET;
            setTelegram(newTelegram);  // Use setter to update the telegram handle
            getLoadingBar();
            if (isUpdate)
                cout << LIGHT_GREEN << "Telegram updated successfully." << RESET << endl;
        }

        void updateGitHub() {
            string newGitHub;
            cout << CYAN << "[+] Enter your new GitHub Username : " << RESET;
            //cin.ignore();
            cout << LIGHT_GREEN;
            getline(cin, newGitHub);
            cout << RESET;
            setGitHub(newGitHub);  // Use setter to update the GitHub profile
            getLoadingBar();
            if (isUpdate)
                cout << LIGHT_GREEN << "GitHub Username updated successfully." << RESET << endl;
        }

        void updateBio() {
            string newBio;
            cout << CYAN << "[+] Enter your new Bio : " << RESET;
            //cin.ignore();
            cout << LIGHT_GREEN;
            getline(cin, newBio);
            cout << RESET;
            setBio(newBio);  // Use setter to update the bio
            getLoadingBar();
            if (isUpdate) 
                cout << LIGHT_GREEN << "Biography updated successfully." << RESET << endl;
        }
        
        void accountSetting() {
            int currentSelection = 0;
            const int totalOptions = 8;
            char key;
            do {
                system("cls");
                listForUpdate(currentSelection, totalOptions);
                key = _getch();
                switch (key) {
                    case UP:
                        if (currentSelection > 0) currentSelection--; // Move up
                        break;
                    case DOWN:
                        if (currentSelection < totalOptions - 1) currentSelection++; // Move down
                        break;
                    case ENTER:
                        switch (currentSelection) {
                            case 0: {
                                updateUsername();
                                system("pause");
                                break;
                            }
                            case 1: {
                                updateEmail();
                                system("pause");
                                break;
                            }
                            case 2: {
                                updatePassword();
                                system("pause");
                                break;
                            }
                            case 3 : {
                                updateTel();
                                system("pause");
                                break;
                            }
                            case 4 : {
                                updateTelegram();
                                system("pause");
                                break;
                            }
                            case 5 : {
                                updateGitHub();
                                system("pause");
                                break;
                            }
                            case 6 : {
                                updateBio();
                                system("pause");
                                break;
                            }
                            case 7 : {
                                return;
                            }
                        }
                        break;
            }
        this_thread::sleep_for(chrono::milliseconds(20));    
        } while (true); // Loop until "Exit" is selected and Enter is pressed

            }

    public:
        void profileSettings() {    
            int currentSelection = 0;
            const int totalOptions = 3;
            char key;
            do {
                system("cls");
                listUpdateOrShowDetails(currentSelection, totalOptions);
                key = _getch();
                switch (key) {
                    case UP:
                        if (currentSelection > 0) currentSelection--; // Move up
                        break;
                    case DOWN:
                        if (currentSelection < totalOptions - 1) currentSelection++; // Move down
                        break;
                    case ENTER:
                        switch (currentSelection) {
                            case 0: {
                                showDetails();
                                system("pause");
                                break;
                            }
                            case 1: {
                                accountSetting();
                                break;
                            }
                            case 2: {
                                return; // Exit the function when "Exit" is selected
                            }
                        }
                        break;
            }
        this_thread::sleep_for(chrono::milliseconds(20));    
        } while (true); // Loop until "Exit" is selected and Enter is pressed
        }
};  