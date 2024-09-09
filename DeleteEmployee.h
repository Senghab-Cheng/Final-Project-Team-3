#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "AddEmployee.h"
#include "BackupEmployee.h"

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

    void manage() {
        short option;
        do {
            listForDelete();
            cout << "[+] Enter your option here: ";
            cin >> option;

            switch (option) {
                case 1:
                    system("cls");
                    deleteEmployeeById();
                    break;
                case 2:
                    system("cls");
                    deleteEmployeeByUsername();
                    break;
                case 0 : 
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "INVALID OPTION!" << endl;
                    break;
            }

        } while (option);
    }

    private :
            void deleteEmployeeById() {
                int id;
                cout << "[+] Enter employee's ID to delete: ";
                cin >> id;

                auto itID = find(employeeIDs.begin(), employeeIDs.end(), id);
                    if (itID != employeeIDs.end()) {
                        size_t index = distance(employeeIDs.begin(), itID);
                        
                        employeeIDsBackup.push_back(employeeIDs[index]);
                        employeeNamesBackup.push_back(employeeNames[index]);
                        employeeRolesBackup.push_back(employeeRoles[index]);
                        employeeSalariesBackup.push_back(employeeSalaries[index]);

                        employeeIDs.erase(employeeIDs.begin() + index);
                        employeeNames.erase(employeeNames.begin() + index);
                        employeeSalaries.erase(employeeSalaries.begin() + index);
                        employeeRoles.erase(employeeRoles.begin() + index);
                        
                        cout << "Employee with ID " << id << " deleted successfully." << endl;
                    } 
                    else {
                    cout << "Employee with ID " << id << " not found." << endl;
                    }
            }

            void deleteEmployeeByUsername() {
                string username;
                cout << "[+] Enter employee Username to delete: ";
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
                    } 
                    else {
                        cout << "Employee with username \"" << username << "\" not found." << endl;
                    }
            }

            void listForDelete() {
                cout << "=========================================================================" << endl;
                cout << ">                           | Delete Employee |                         <" << endl;
                cout << ">>=====================================================================<<" << endl;
                cout << ">>>                                                                   <<<" << endl;
                cout << ">>>>                                                                 <<<<" << endl;
                cout << ">>>>>                    1. Delete Employee By ID                   <<<<<" << endl;
                cout << ">>>>                     2. Delete Employee By Username              <<<<" << endl;
                cout << ">>>                      0. Exit                                      <<<" << endl;
                cout << ">>                                                                     <<" << endl;
                cout << ">                                                                       <" << endl;
                cout << "=========================================================================" << endl;
            }
};