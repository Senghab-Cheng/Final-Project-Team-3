#pragma once

#include <iostream>
#include <vector>
#include <algorithm> // for std::find
#include "AddEmployee.h"
#include "AdminInfo.h"

using namespace std;

class Update {
private:
    // Function to find index by employee ID
    int findEmployeeIndexById(int id) {
        auto it = find(employeeIDs.begin(), employeeIDs.end(), id);
        if (it != employeeIDs.end()) {
            return distance(employeeIDs.begin(), it); // Return index if found
        } else {
            return -1; // Return -1 if not found
        }
    }

    void updateSalary() {
        int id;
        cout << "[+] Enter employee ID: ";
        cin >> id;
        
        int index = findEmployeeIndexById(id);
        if (index != -1) {
            cout << "[+] Enter employee new Salary: ";
            cin >> employeeSalaries[index];
            cout << "Employee with ID " << id << " updated successfully." << endl;
        } else {
            cout << "Employee with ID " << id << " is not found." << endl;
        }
    }

    void updateRole() {
        int id;
        cout << "[+] Enter employee ID: ";
        cin >> id;

        int index = findEmployeeIndexById(id);
        if (index != -1) {
            cout << "[+] Enter employee new Position: ";
            cin >> employeeRoles[index];
            cout << "Employee with ID " << id << " updated successfully." << endl;
        } else {
            cout << "Employee with ID " << id << " is not found." << endl;
        }
    }

    void listForUpdate() {
        cout << "+==============================================================================+" << endl;
        cout << "|                                                                              |" << endl;
        cout << "|                            >>>  SEARCH EMPLOYEE  <<<                         |" << endl;
        cout << "|                                                                              |" << endl;
        cout << "+==============================================================================+" << endl;
        cout << "|                                                                              |" << endl;
        cout << "|  [1]  =>  Update Salary                                                      |" << endl;
        cout << "|  [2]  =>  Update Position                                                    |" << endl;
        cout << "|  [0]  =>  Exit                                                               |" << endl;
        cout << "|                                                                              |" << endl;
        cout << "+==============================================================================+" << endl;
        cout << "|                 >>>  Select an option by entering the number  <<<            |" << endl;
        cout << "+==============================================================================+" << endl;  
    }

public:
    void update() {
        short option;
        do {
            listForUpdate();
            cout << "[+] Enter your option: ";
            cin >> option;

            switch (option) {
                case 1: {
                    updateSalary();
                    break;
                }
                case 2: {
                    updateRole();
                    break;
                }
                case 0: {
                    cout << "Exiting..." << endl;
                    break;
                }
                default: {
                    cout << "INVALID OPTION!" << endl;
                    break;
                }
            }
        } while (option);
    }
};
