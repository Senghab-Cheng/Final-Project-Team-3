#pragma once 

#include <iostream>
#include <iomanip>
#include "AdminInfo.h"

using namespace std;

class ProfileManagement {
    private : 
        string username;
        string email;
        string password;
        string bio;
        string tel;
        string telegram;
        string gitHub;

        void showAdminInfo() {
            cout << "+------------+----------------------------------------+" << endl;
            cout << "| USERNAME   | " << setw(38) << left << admin1.getUsername() << " |" << endl;
            cout << "+------------+----------------------------------------+" << endl;
            cout << "| EMAIL      | " << setw(38) << left << admin1.getEmail() << " |" << endl;
            cout << "+------------+----------------------------------------+" << endl;
            cout << "| BIO        | " << setw(38) << left << admin1.getBio() << " |" << endl;
            cout << "+------------+----------------------------------------+" << endl;
            cout << "| TEL        | " << setw(38) << left << admin1.getTel() << " |" << endl;
            cout << "+------------+----------------------------------------+" << endl;
            cout << "| TELEGRAM   | " << setw(38) << left << admin1.getTelegram() << " |" << endl;
            cout << "+------------+----------------------------------------+" << endl;
            cout << "| GITHUB     | " << setw(38) << left << admin1.getGitHub() << " |" << endl;
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

    public :
        Admin admin1;

        void updateAdminInfo() {
            short option;
            do {
                listForUpdate();
                cout << "[+] Enter your option : "; cin >> option;
                switch(option) {
                    case 1 : {}
                }

            } while(option);
        }
};