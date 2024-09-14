#pragma once

#include <iostream>
#include <algorithm>
#include <limits>
#include <fstream>
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

        auto itID = find(employeeIDs.begin(), employeeIDs.end(), id);
        if (itID != employeeIDs.end()) {
            size_t index = distance(employeeIDs.begin(), itID);

            // Backup employee data to file before deleting
            backupEmployeeToFile(index);

            // Delete from vectors
            employeeIDs.erase(employeeIDs.begin() + index);
            employeeNames.erase(employeeNames.begin() + index);
            employeeSalaries.erase(employeeSalaries.begin() + index);
            employeeRoles.erase(employeeRoles.begin() + index);

            // Save updated vectors to the files
            updateEmployeeFiles();

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

        auto itName = find(employeeNames.begin(), employeeNames.end(), username);
        if (itName != employeeNames.end()) {
            size_t index = distance(employeeNames.begin(), itName);

            // Backup employee data to file before deleting
            backupEmployeeToFile(index);

            // Delete from vectors
            employeeIDs.erase(employeeIDs.begin() + index);
            employeeNames.erase(employeeNames.begin() + index);
            employeeSalaries.erase(employeeSalaries.begin() + index);
            employeeRoles.erase(employeeRoles.begin() + index);

            // Save updated vectors to the files
            updateEmployeeFiles();

            cout << "Employee with username \"" << username << "\" deleted successfully." << endl;
        } else {
            cout << "Employee with username \"" << username << "\" not found." << endl;
        }
    }

    void backupEmployeeToFile(size_t index) {
        ofstream nameFile("data/backupEmployeeNames.txt", ios::app);
        ofstream idFile("data/backupEmployeeIDs.txt", ios::app);
        ofstream salaryFile("data/backupEmployeeSalaries.txt", ios::app);
        ofstream roleFile("data/backupEmployeeRoles.txt", ios::app);

        if (nameFile.is_open() && idFile.is_open() && salaryFile.is_open() && roleFile.is_open()) {
            nameFile << employeeNames[index] << '\n';
            idFile << employeeIDs[index] << '\n';
            salaryFile << employeeSalaries[index] << '\n';
            roleFile << employeeRoles[index] << '\n';
        } else {
            cerr << "Error: Unable to open backup files for writing." << endl;
        }

        nameFile.close();
        idFile.close();
        salaryFile.close();
        roleFile.close();
    }

    void updateEmployeeFiles() {
        // Update employeeNameFile.txt
        ofstream nameFile("data/employeeNameFile.txt");
        for (const string& name : employeeNames) {
            nameFile << name << '\n';
        }
        nameFile.close();

        // Update employeeIDFile.txt
        ofstream idFile("data/employeeIDFile.txt");
        for (int id : employeeIDs) {
            idFile << id << '\n';
        }
        idFile.close();

        // Update employeeSalaryFile.txt
        ofstream salaryFile("data/employeeSalaryFile.txt");
        for (double salary : employeeSalaries) {
            salaryFile << salary << '\n';
        }
        salaryFile.close();

        // Update employeePositionFile.txt
        ofstream roleFile("data/employeePositionFile.txt");
        for (const string& role : employeeRoles) {
            roleFile << role << '\n';
        }
        roleFile.close();
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
