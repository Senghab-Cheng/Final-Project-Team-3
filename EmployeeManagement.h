#pragma once 

#include <iostream>
#include "BackupEmployee.h"
#include "AddEmployee.h"
#include "DeleteEmployee.h"
#include "Update.h"

using namespace std;

class Manipulate{
    private :
        void listManipulate() {
            cout << "=============================================================================" << endl;
            cout << "|                                                                           |" << endl;
            cout << "|                          | EMPLOYEE MANAGEMENT |                          |" << endl;
            cout << "|                                                                           |" << endl;
            cout << "+============================================================================+" << endl;
            cout << "|                                                                           |" << endl;
            cout << "|  [1]  =>  Add New Employee                                                |" << endl;
            cout << "|  [2]  =>  Update Existing Employee                                        |" << endl;
            cout << "|  [3]  =>  Remove Employee                                                 |" << endl;
            cout << "|  [4]  =>  Backup Employee Records                                         |" << endl;
            cout << "|  [0]  =>  Exit                                                            |" << endl;
            cout << "|                                                                           |" << endl;
            cout << "+===========================================================================+" << endl;
            cout << "|           >>>  Please choose an option by entering a number  <<<          |" << endl;
            cout << "+===========================================================================+" << endl;
        }

        void addEmployee() {
            ifstream addEmployee("addNewEmployee.txt"); // Open the file for reading

            if(addEmployee.is_open()) {
                string line;
                // Read line by line from the file
                while(getline(addEmployee, line)) {
                    cout << line << endl; // Print each line to the console
                    this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 100 milliseconds
                }
                addEmployee.close(); // Close the file
            } else {
                cout << "Unable to open the file!" << endl;
            }
        }

    public :
        void manipulate() {
            short option;
            do {
                listManipulate();
                cout << "[+] Enter your option : "; cin >> option;
                switch(option) {
                    case 1 : {
                        AddEmployee employee1a;
                        employee1a.setEmployeeData();
                        break;
                    }
                    case 2 : {
                        Update employee1b;
                        employee1b.update();
                        break;
                    }
                    case 3 : {
                        DeleteEmployee employee1c;
                        employee1c.manage();
                        break;
                    }
                    case 4 : {
                        BackupEmployeeData employee1d;
                        employee1d.backupData();
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
            }while(option);
        }
};