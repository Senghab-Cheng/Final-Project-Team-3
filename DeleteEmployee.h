#pragma once

#include <iostream>
#include <algorithm>
#include <limits>
#include "AddEmployee.h"
#include "BackupEmployee.h"
#include "loadingBar.h"

using namespace std;

// Declaration of external backup vectors
extern vector<string> employeeNamesBackupX;
extern vector<string> employeeRolesBackupX;
extern vector<int> employeeIDsBackupX;
extern vector<double> employeeSalariesBackupX;

class DeleteEmployee {

public:
    void manage() {
        short option;
        do {
            listForDelete();
            cout << "[+] Enter your option: ";
            cin >> option;
            //getLoadingBar(); // LoadingBar

            switch (option) {
            case 1:
                deleteEmployeeById();
                break;
            case 2:
                deleteEmployeeByUsername();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "INVALID OPTION!" << endl;
                break;
            }
        } while (option);
    }

private:
    void deleteEmployeeById() {
        int id;
        cout << "[+] Enter employee ID to delete: ";
        cin >> id;
        //getLoadingBar(); // LoadingBar

        auto itID = find(employeeIDs.begin(), employeeIDs.end(), id);
        if (itID != employeeIDs.end()) {
            size_t index = distance(employeeIDs.begin(), itID);

            employeeIDsBackupX.push_back(employeeIDs[index]);
            employeeNamesBackupX.push_back(employeeNames[index]);
            employeeRolesBackupX.push_back(employeeRoles[index]);
            employeeSalariesBackupX.push_back(employeeSalaries[index]);

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
        cout << "[+] Enter employee Username to delete: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, username);
        //getLoadingBar(); // LoadingBar

        auto itName = find(employeeNames.begin(), employeeNames.end(), username);
        if (itName != employeeNames.end()) {
            size_t index = distance(employeeNames.begin(), itName);

            employeeIDsBackupX.push_back(employeeIDs[index]);
            employeeNamesBackupX.push_back(employeeNames[index]);
            employeeRolesBackupX.push_back(employeeRoles[index]);
            employeeSalariesBackupX.push_back(employeeSalaries[index]);

            employeeIDs.erase(employeeIDs.begin() + index);
            employeeNames.erase(employeeNames.begin() + index);
            employeeSalaries.erase(employeeSalaries.begin() + index);
            employeeRoles.erase(employeeRoles.begin() + index);

            cout << "Employee with username \"" << username << "\" deleted successfully." << endl;
        } else {
            cout << "Employee with username \"" << username << "\" not found." << endl;
        }
    }

    void listForDelete() {
        cout << "+================================================================================+" << endl;
        cout << "|                                                                                |" << endl;
        cout << "|                             >>>  DELETE EMPLOYEE  <<<                          |" << endl;
        cout << "|                                                                                |" << endl;
        cout << "+================================================================================+" << endl;
        cout << "|                                                                                |" << endl;
        cout << "|  [1]  =>  Delete Employee By ID                                                |" << endl;
        cout << "|  [2]  =>  Delete Employee By Username                                          |" << endl;
        cout << "|  [0]  =>  Exit                                                                 |" << endl;
        cout << "|                                                                                |" << endl;
        cout << "+================================================================================+" << endl;
        cout << "|                >>>  Select an option by entering the number  <<<               |" << endl;
        cout << "+================================================================================+" << endl;
    }
};
