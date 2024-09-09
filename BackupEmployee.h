#pragma once

#include <iostream>
#include <vector>
#include "DeleteEmployee.h"
#include "AddEmployee.h"
#include "loadingBar.h"

using namespace std;

// Declaration of external backup vectors to avoid multiple definitions
extern vector<string> employeeNamesBackupX;
extern vector<string> employeeRolesBackupX;
extern vector<int> employeeIDsBackupX;
extern vector<double> employeeSalariesBackupX;

class BackupDataFunctions {
public:
    virtual void listBackupData() = 0;
    virtual void emptyData() = 0;
    virtual void restoreDataByID() = 0;
    virtual void restoreAllData() = 0;
};

class BackupEmployeeData : public BackupDataFunctions {
private:
    void listBackupData() override {
        for (int i = 0; i < employeeIDsBackupX.size(); i++) {
            cout << "Name: " << employeeNamesBackupX[i] << endl;
            cout << "ID: " << employeeIDsBackupX[i] << endl;
            cout << "Role: " << employeeRolesBackupX[i] << endl;
            cout << "Salary: " << employeeSalariesBackupX[i] << "$" << endl << endl;
        }
    }

    void emptyData() override {
        listBackupData();
        char choice;
        cout << "Are you sure you want to empty backup data? [Y/N] : ";
        cin >> choice;
        //getLoadingBar(); // LoadingBar
        if (choice == 'y' || choice == 'Y') {
            if (employeeIDsBackupX.empty()) {
                cout << "No backup data available." << endl;
                return;
            }
            employeeNamesBackupX.clear();
            employeeIDsBackupX.clear();
            employeeRolesBackupX.clear();
            employeeSalariesBackupX.clear();
            cout << "Backup data has been successfully emptied." << endl;
        } else {
            return;
        }
    }

    void restoreDataByID() override {
        listBackupData();
        int id;
        cout << "[+] Enter the employee ID to restore the data: ";
        cin >> id;
        //getLoadingBar(); // LoadingBar

        if (employeeIDsBackupX.empty()) {
            cout << "No backup data available." << endl;
            return;
        }

        auto it = find(employeeIDsBackupX.begin(), employeeIDsBackupX.end(), id);
        if (it != employeeIDsBackupX.end()) {
            size_t i = distance(employeeIDsBackupX.begin(), it);
            employeeNames.push_back(employeeNamesBackupX[i]);
            employeeIDs.push_back(employeeIDsBackupX[i]);
            employeeRoles.push_back(employeeRolesBackupX[i]);
            employeeSalaries.push_back(employeeSalariesBackupX[i]);
            cout << "Data has been successfully restored." << endl;
        } else {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }

    void restoreAllData() override {
        char choice;
        cout << "Are you sure you want to restore all data? [Y/N] : ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            getLoadingBar(); // LoadingBar
            if (employeeIDsBackupX.empty()) {
                cout << "No backup data available." << endl;
                return;
            }

            for (int i = 0; i < employeeIDsBackupX.size(); i++) {
                employeeNames.push_back(employeeNamesBackupX[i]);
                employeeIDs.push_back(employeeIDsBackupX[i]);
                employeeRoles.push_back(employeeRolesBackupX[i]);
                employeeSalaries.push_back(employeeSalariesBackupX[i]);
            }
            cout << "Data has been successfully restored." << endl;
        } else {
            return;
        }
    }

    void listMenuBackupData() {
        cout << "+================================================================================+" << endl;
        cout << "|                                                                                |" << endl;
        cout << "|                         >>>  BACKUP DATA MANAGEMENT  <<<                       |" << endl;
        cout << "|                                                                                |" << endl;
        cout << "|                                                                                |" << endl;
        cout << "+================================================================================+" << endl;
        cout << "|                                                                                |" << endl;
        cout << "|  [1]  =>  Restore Data by ID                                                   |" << endl;
        cout << "|  [2]  =>  Restore All Data                                                     |" << endl;
        cout << "|  [3]  =>  Empty Backup Data                                                    |" << endl;
        cout << "|  [0]  =>  Exit                                                                 |" << endl;
        cout << "|                                                                                |" << endl;
        cout << "+================================================================================+" << endl;
        cout << "|                >>>  Select an option by entering the number  <<<               |" << endl;
        cout << "+================================================================================+" << endl;
    }

public:
    void backupData() {
        short option;
        do {
            listBackupData();
            cout << "[+] Enter your option: ";
            cin >> option;

            switch (option) {
            case 1:
                restoreDataByID();
                break;
            case 2:
                restoreAllData();
                break;
            case 3:
                emptyData();
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
};
