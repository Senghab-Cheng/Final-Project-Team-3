#pragma once 

#include <iostream>
#include <iomanip>
#include <ctime>
#include "AddEmployee.h"
#include "loadingBar.h"

using namespace std;

class Employee{
    private :
        int id;
        
        void list() {
            cout << "+==============================================================================+" << endl;
            cout << "|                                                                              |" << endl;
            cout << "|                            >>>  EMPLOYEE PANEL  <<<                          |" << endl;
            cout << "|                                                                              |" << endl;
            cout << "+==============================================================================+" << endl;
            cout << "|                                                                              |" << endl;
            cout << "|  [1]  =>  CHECK-IN                                                           |" << endl;
            cout << "|  [2]  =>  CHECK-OUT                                                          |" << endl;
            cout << "|  [0]  =>  Exit                                                               |" << endl;
            cout << "|                                                                              |" << endl;
            cout << "+==============================================================================+" << endl;
            cout << "|              >>>  Select an option by entering the number  <<<               |" << endl;
            cout << "+==============================================================================+" << endl; 
        }

        void getCurrentTime() {
            // Get current time
            time_t now = time(0);

            // Convert to local time
            tm* localTime = localtime(&now);

            // Print the current date and time
            cout << 1900 + localTime->tm_year << "-"
                      << 1 + localTime->tm_mon << "-"
                      << localTime->tm_mday << " "
                      << localTime->tm_hour << ":"
                      << localTime->tm_min << ":"
                      << localTime->tm_sec << endl;
        }

        void checkIn() {
            cout << "+==============================================================================+" << endl;
            cout << "|                                                                              |" << endl;
            cout << "|                              >>>  CHECK-IN  <<<                              |" << endl;
            cout << "|                                                                              |" << endl;
            cout << "+==============================================================================+" << endl;
            cout << "[+] Enter your ID to check-in : ";
            cin >> this->id;

            auto it = find(employeeIDs.begin(), employeeIDs.end(), id);
            if (it != employeeIDs.end()) {
                size_t index = distance(employeeIDs.begin(), it);
                //getLoadingBar();
                system("cls");
                cout << "+------------+---------------------------------+-------------------------+" << endl;
                cout << "| ID         | NAME                            | ROLE                    |" << endl;
                cout << "+------------+---------------------------------+-------------------------+" << endl;
                cout << "| " << setw(10) << left << employeeIDs[index]
                    << " | " << setw(32) << left << employeeNames[index]
                    << "| " << setw(23) << left << employeeRoles[index]
                    << " | "<< endl;
                cout << "+------------+---------------------------------+-------------------------+" << endl;
                cout << "Checked In successfully : ";
                getCurrentTime();
            }
        }

        void checkOut() {
            cout << "+==============================================================================+" << endl;
            cout << "|                                                                              |" << endl;
            cout << "|                             >>>  CHECK-OUT  <<<                              |" << endl;
            cout << "|                                                                              |" << endl;
            cout << "+==============================================================================+" << endl;
            cout << "[+] Enter your ID to check-in : ";
            cin >> this->id;

            auto it = find(employeeIDs.begin(), employeeIDs.end(), id);
            if (it != employeeIDs.end()) {
                size_t index = distance(employeeIDs.begin(), it);
                //getLoadingBar();
                system("cls");
                cout << "+------------+---------------------------------+-------------------------+" << endl;
                cout << "| ID         | NAME                            | ROLE                    |" << endl;
                cout << "+------------+---------------------------------+-------------------------+" << endl;
                cout << "| " << setw(10) << left << employeeIDs[index]
                    << "| " << setw(33) << left << employeeNames[index]
                    << "| " << setw(25) << left << employeeRoles[index]
                    << "| "<< endl;
                cout << "+------------+---------------------------------+-------------------------+" << endl;
                cout << "Checked Out successfully : ";
                getCurrentTime();
            }
        }

    public :
        void checkInCheckOut() {
            short option;
            do {
                list();
                cout << "[+] Enter your option : "; cin >> option;
                switch(option) {
                    case 1 : {
                        checkIn();
                        break;
                    }
                    case 2 : {
                        checkOut();
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
};
