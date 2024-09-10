#pragma once 

#include <iostream>
#include <iomanip>  // For setw
#include <string>

using namespace std;

class Admin {
    private:
        string username = "ABC";
        string email = "abc123@gmail.com";
        string password = "12345";
        string bio = "No idea";
        string tel = "0123456789";
        string telegram = "ABC";
        string gitHub = "abc123";

    public:
        // Getters
        string getUsername() {
            return username;
        }
        string getEmail() {
            return email;
        }
        string getPassword() {
            return password;
        }
        string getBio() {
            return bio;
        }
        string getTel() {
            return tel;
        }
        string getTelegram() {
            return telegram;
        }
        string getGitHub() {
            return gitHub;
        }

        // Setters
        void setUsername(const string& newUsername) {
            username = newUsername;
        }
        void setEmail(const string& newEmail) {
            email = newEmail;
        }
        void setPassword(const string& newPassword) {
            password = newPassword;
        }
        void setBio(const string& newBio) {
            bio = newBio;
        }
        void setTel(const string& newTel) {
            tel = newTel;
        }
        void setTelegram(const string& newTelegram) {
            telegram = newTelegram;
        }
        void setGitHub(const string& newGitHub) {
            gitHub = newGitHub;
        }
};

class ProfileSetting : public Admin {
    private :
        void listUpdateOrShowDetials() {
            cout << "+===========================================================================+" << endl;
            cout << "|                                                                           |" << endl;
            cout << "|                         | Admin Profile Settings |                        |" << endl;
            cout << "|                                                                           |" << endl;
            cout << "+============================================================================+" << endl;
            cout << "|                                                                           |" << endl;
            cout << "|  [1]  =>  Show Admin Informations                                         |" << endl;
            cout << "|  [2]  =>  Account Settings                                                |" << endl;
            cout << "|  [0]  =>  Exit                                                            |" << endl;
            cout << "|                                                                           |" << endl;
            cout << "+===========================================================================+" << endl;
            cout << "|            >>>  Please choose an option by entering a number  <<<         |" << endl;
            cout << "+===========================================================================+" << endl;
        }

        void showDetials() {
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

        void listForUpdate() {
            cout << "+===========================================================================+" << endl;
            cout << "|                                                                           |" << endl;
            cout << "|                           | ADMINISTRATOR PANEL |                         |" << endl;
            cout << "|                                                                           |" << endl;
            cout << "+============================================================================+" << endl;
            cout << "|                                                                           |" << endl;
            cout << "|  [1]  =>  Update Username                                                 |" << endl;
            cout << "|  [2]  =>  Update Email Address                                            |" << endl;
            cout << "|  [3]  =>  Update Password                                                 |" << endl;
            cout << "|  [4]  =>  Update Contact Number                                           |" << endl;
            cout << "|  [5]  =>  Update Telegram Handle                                          |" << endl;
            cout << "|  [6]  =>  Update GitHub Profile                                           |" << endl;
            cout << "|  [7]  =>  Update Biography                                                |" << endl;
            cout << "|  [0]  =>  Exit                                                            |" << endl;
            cout << "|                                                                           |" << endl;
            cout << "+===========================================================================+" << endl;
            cout << "|            >>>  Please choose an option by entering a number  <<<         |" << endl;
            cout << "+===========================================================================+" << endl;
        }

        void updateUsername() {
            string newUsername;
            cout << "[+] Enter your new Username : ";
            cin.ignore();
            getline(cin, newUsername);
            setUsername(newUsername);  // Use setter to update the username
        }

        void updateEmail() {
            string newEmail;
            cout << "[+] Enter your new Email Address : ";
            cin.ignore();
            getline(cin, newEmail);
            setEmail(newEmail);  // Use setter to update the email
        }

        void updatePassword() {
            string newPassword;
            cout << "[+] Enter your new Password: ";
            cin.ignore();
            getline(cin, newPassword);

            string verPassword;
            do {
                cout << "[+] Confirm your new Password: ";
                getline(cin, verPassword);

                if (newPassword == verPassword) {
                    setPassword(newPassword);  // Use setter to update the password
                    cout << "Password updated successfully." << endl;
                } else {
                    cout << "Passwords do not match. Please re-enter to confirm your new Password: ";
                }
            } while (newPassword != verPassword);
        }

        void updateTel() {
            string newTel;
            cout << "[+] Enter your new Contact Number : ";
            cin.ignore();
            getline(cin, newTel);
            setTel(newTel);  // Use setter to update the contact number
        }

        void updateTelegram() {
            string newTelegram;
            cout << "[+] Enter your new Telegram Handle : ";
            cin.ignore();
            getline(cin, newTelegram);
            setTelegram(newTelegram);  // Use setter to update the telegram handle
        }

        void updateGitHub() {
            string newGitHub;
            cout << "[+] Enter your new GitHub Profile : ";
            cin.ignore();
            getline(cin, newGitHub);
            setGitHub(newGitHub);  // Use setter to update the GitHub profile
        }

        void updateBio() {
            string newBio;
            cout << "[+] Enter your new Bio : ";
            cin.ignore();
            getline(cin, newBio);
            setBio(newBio);  // Use setter to update the bio
        }
        
    void accountSetting() {
        short option;
        do {
            listForUpdate();
            cout << "[+] Enter your option : "; cin >> option;
            switch(option) {
                case 1 : {
                    updateUsername();
                    break;
                }
                case 2 : {
                    updateEmail();
                    break;
                }
                case 3 : {
                    updatePassword();
                    break;
                }
                case 4 : {
                    updateTel(); 
                    break;
                }
                case 5 : {
                    updateTelegram();
                    break;
                }
                case 6 : {
                    updateGitHub();
                    break;
                }
                case 0 : {
                    cout << "Exiting..." << endl;
                    break;
                }
                default : {
                    cout << "INVALID OPTION!" << endl;
                    break;
                }
            }
        } while(option);
    }
    public :
    
        void profileSettings() {    
            short op;
            do {
                listUpdateOrShowDetials();
                cout << "[+] Enter your option : "; cin >> op;
                switch(op) {
                    case 1 : {
                        showDetials();
                        break;
                    }
                    case 2 : {
                        accountSetting();
                        break;
                    }
                    case 0 : {
                        cout << "Exiting..." << endl;
                        break;
                    }
                    default : {
                        cout << "INVALID OPTION!" << endl;
                        break;
                    }
                }
            } while (op);
        }
};  
