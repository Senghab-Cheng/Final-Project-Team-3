#pragma once 

#include <iostream>
#include <iomanip>
#include <ctime>
#include "AddEmployee.h"
#include "loadingBar.h"
//#include "QR.h"

using namespace std;

class Employee{
    private :
        int id;

        void employeePanel() {
            ifstream employeePanel("employeePanel.txt"); // Open the file for reading

            if(employeePanel.is_open()) {
                string line;
                // Read line by line from the file
                while(getline(employeePanel, line)) {
                    cout << line << endl; // Print each line to the console
                    this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 100 milliseconds
                }
                employeePanel.close(); // Close the file
            } else {
                cout << "Unable to open the file!" << endl;
            }
        }
        
        void list() {
            employeePanel();
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

        void checkInStyle() {
            ifstream checkInStyle("checkIn.txt"); // Open the file for reading

            if(checkInStyle.is_open()) {
                string line;
                // Read line by line from the file
                while(getline(checkInStyle, line)) {
                    cout << line << endl; // Print each line to the console
                    this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 100 milliseconds
                }
                checkInStyle.close(); // Close the file
            } else {
                cout << "Unable to open the file!" << endl;
            } 
        }

        void checkOutStyle() {
            ifstream checkOutStyle("checkOut.txt"); // Open the file for reading

            if(checkOutStyle.is_open()) {
                string line;
                // Read line by line from the file
                while(getline(checkOutStyle, line)) {
                    cout << line << endl; // Print each line to the console
                    this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 100 milliseconds
                }
                checkOutStyle.close(); // Close the file
            } else {
                cout << "Unable to open the file!" << endl;
            }
        }

        void checkIn() {
            checkInStyle();
            cout << "+==============================================================================+" << endl;
            cout << "|                                                                              |" << endl;
            cout << "|                              >>>  CHECK-IN  <<<                              |" << endl;
            cout << "|                                                                              |" << endl;
            cout << "+==============================================================================+" << endl;
            // cout << "[+] Enter your ID to check-in : ";
            // cin >> this->id;

            // auto it = find(employeeIDs.begin(), employeeIDs.end(), id);
            // if (it != employeeIDs.end()) {
            //     size_t index = distance(employeeIDs.begin(), it);
            //     //getLoadingBar();
            //     system("cls");
            //     cout << "+------------+---------------------------------+-------------------------+" << endl;
            //     cout << "| ID         | NAME                            | ROLE                    |" << endl;
            //     cout << "+------------+---------------------------------+-------------------------+" << endl;
            //     cout << "| " << setw(10) << left << employeeIDs[index]
            //         << " | " << setw(32) << left << employeeNames[index]
            //         << "| " << setw(23) << left << employeeRoles[index]
            //         << " | "<< endl;
            //     cout << "+------------+---------------------------------+-------------------------+" << endl;
            //     cout << "Checked In successfully : ";
            //     getCurrentTime();
            //}

            //getLoadingBar();
            string SERVER_URL = "http://192.168.29.98:5466/checkin";  // Check-in URL
            string command = "curl qrenco.de/" + SERVER_URL;
            system(command.c_str());
        }

        void checkOut() {
            checkOutStyle();
            cout << "+==============================================================================+" << endl;
            cout << "|                                                                              |" << endl;
            cout << "|                             >>>  CHECK-OUT  <<<                              |" << endl;
            cout << "|                                                                              |" << endl;
            cout << "+==============================================================================+" << endl;
            // cout << "[+] Enter your ID to check-in : ";
            // cin >> this->id;

            // auto it = find(employeeIDs.begin(), employeeIDs.end(), id);
            // if (it != employeeIDs.end()) {
            //     size_t index = distance(employeeIDs.begin(), it);
            //     //getLoadingBar();
            //     system("cls");
            //     cout << "+------------+---------------------------------+-------------------------+" << endl;
            //     cout << "| ID         | NAME                            | ROLE                    |" << endl;
            //     cout << "+------------+---------------------------------+-------------------------+" << endl;
            //     cout << "| " << setw(10) << left << employeeIDs[index]
            //         << "| " << setw(33) << left << employeeNames[index]
            //         << "| " << setw(25) << left << employeeRoles[index]
            //         << "| "<< endl;
            //     cout << "+------------+---------------------------------+-------------------------+" << endl;
            //     cout << "Checked Out successfully : ";
            //     getCurrentTime();
            // }

            //getLoadingBar();
            string SERVER_URL = "http://192.168.29.98:5466/checkout";  // Check-out URL
            string command = "curl qrenco.de/" + SERVER_URL;
            system(command.c_str());
        }

    public :
        void checkInCheckOut() {
            short option;
            do {
                list();
                cout << "[+] Enter your option : "; cin >> option;
                switch(option) {
                    case 1 : {
                        system("cls");
                        checkIn();
                        break;
                    }
                    case 2 : {
                        system("cls");
                        checkOut();
                        break;
                    }
                    case 0 : {
                        cout << "Exiting..." << endl;
                        //getLoadingBar();
                        system("cls");
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
