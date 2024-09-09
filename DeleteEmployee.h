#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "addEmployee.h"

using namespace std;

class DeleteEmployee {
    private:
        vector<string>& employeeNames;
        vector<double>& employeeSalaries;
        vector<int>& employeeIDs;
        vector<string>& employeeRoles;
    public:
        DeleteEmployee(vector<string>& names, vector<double>& salaries, vector<int>& ids, vector<string>& roles) 
        : employeeNames(names), employeeSalaries(salaries), employeeIDs(ids), employeeRoles(roles) {}

    void deleteEmployeeById() {
        int id;
        cout << "[+] Enter employee's ID to delete: ";
        cin >> id;

        auto itID = find(employeeIDs.begin(), employeeIDs.end(), id);
        if (itID != employeeIDs.end()) {
            size_t index = distance(employeeIDs.begin(), itID);
            employeeIDs.erase(employeeIDs.begin() + index);
            employeeNames.erase(employeeNames.begin() + index);
            employeeSalaries.erase(employeeSalaries.begin() + index);
            employeeRoles.erase(employeeRoles.begin() + index);
            cout << "Employee with ID " << id << " deleted successfully." << endl;
        } else {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }

    void deleteEmployeeByUsername() {
        string username;
        cout << "[+] Enter employee's username to delete: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, username);

        auto itName = find(employeeNames.begin(), employeeNames.end(), username);
        if (itName != employeeNames.end()) {
            size_t index = distance(employeeNames.begin(), itName);
            employeeIDs.erase(employeeIDs.begin() + index);
            employeeNames.erase(employeeNames.begin() + index);
            employeeSalaries.erase(employeeSalaries.begin() + index);
            employeeRoles.erase(employeeRoles.begin() + index);
            cout << "Employee with username \"" << username << "\" deleted successfully." << endl;
        } else {
            cout << "Employee with username \"" << username << "\" not found." << endl;
        }
    }

    void manage() {
        short option;
        do {
            cout << "Select an option" << endl;
            cout << "1. Delete Employee by ID" << endl;
            cout << "2. Delete Employee by Username" << endl;
            cout << "[+] Enter your option here: ";
            cin >> option;

            switch (option) {
                char confirm;
                case 1:
                    deleteEmployeeById();
                    break;
                case 2:
                    deleteEmployeeByUsername();
                    break;
                default:
                    cout << "Invalid option." << endl;
                    break;
            }
        } while (option != 0);
    }
};