#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
    // Load backup data from file into vectors
    void loadBackupData() {
        ifstream nameFile("data/backupEmployeeNames.txt");
        ifstream idFile("data/backupEmployeeIDs.txt");
        ifstream salaryFile("data/backupEmployeeSalaries.txt");
        ifstream roleFile("data/backupEmployeeRoles.txt");

        string name, role;
        int id;
        double salary;

        employeeNamesBackupX.clear();
        employeeRolesBackupX.clear();
        employeeIDsBackupX.clear();
        employeeSalariesBackupX.clear();

        // Load data into vectors
        while (getline(nameFile, name) && idFile >> id && salaryFile >> salary && getline(roleFile, role)) {
            employeeNamesBackupX.push_back(name);
            employeeIDsBackupX.push_back(id);
            employeeSalariesBackupX.push_back(salary);
            employeeRolesBackupX.push_back(role);
        }

        nameFile.close();
        idFile.close();
        salaryFile.close();
        roleFile.close();
    }

    // Save backup data to file
    void saveBackupData() {
        ofstream nameFile("data/backupEmployeeNames.txt");
        ofstream idFile("data/backupEmployeeIDs.txt");
        ofstream salaryFile("data/backupEmployeeSalaries.txt");
        ofstream roleFile("data/backupEmployeeRoles.txt");

        for (size_t i = 0; i < employeeNamesBackupX.size(); ++i) {
            nameFile << employeeNamesBackupX[i] << '\n';
            idFile << employeeIDsBackupX[i] << '\n';
            salaryFile << employeeSalariesBackupX[i] << '\n';
            roleFile << employeeRolesBackupX[i] << '\n';
        }

        nameFile.close();
        idFile.close();
        salaryFile.close();
        roleFile.close();
    }

    // Save restored data back to AddEmployee files
    void saveRestoredDataToAddFiles(const string& name, int id, double salary, const string& role) {
        ofstream nameFile("data/employeeNameFile.txt", ios::app);
        ofstream idFile("data/employeeIDFile.txt", ios::app);
        ofstream salaryFile("data/employeeSalaryFile.txt", ios::app);
        ofstream roleFile("data/employeePositionFile.txt", ios::app);

        // Append restored data
        nameFile << name << '\n';
        idFile << id << '\n';
        salaryFile << salary << '\n';
        roleFile << role << '\n';

        nameFile.close();
        idFile.close();
        salaryFile.close();
        roleFile.close();
    }

    void listBackupData() override {
        loadBackupData();
        if (employeeIDsBackupX.empty()) {
            //cout << "No backup data available." << endl;
            return;
        }
        for (size_t i = 0; i < employeeIDsBackupX.size(); ++i) {
            cout << "Name: " << employeeNamesBackupX[i] << endl;
            cout << "ID: " << employeeIDsBackupX[i] << endl;
            cout << "Role: " << employeeRolesBackupX[i] << endl;
            cout << "Salary: " << employeeSalariesBackupX[i] << "$" << endl << endl;
        }
    }

    void emptyData() override {
        listBackupData();
        if (employeeIDsBackupX.empty()) {
            cout << "No backup data available." << endl;
            return;
        }
        char choice;
        cout << "Are you sure you want to empty backup data? [Y/N] : ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            employeeNamesBackupX.clear();
            employeeIDsBackupX.clear();
            employeeRolesBackupX.clear();
            employeeSalariesBackupX.clear();
            saveBackupData(); // Clear the backup files
            cout << "Backup data has been successfully emptied." << endl;
        }
    }

    void restoreDataByID() override {
        //loadBackupData();
        listBackupData();
        if (employeeIDsBackupX.empty()) {
            cout << "No backup data available." << endl;
            return;
        }
        int id;
        cout << "[+] Enter the employee ID to restore the data: ";
        cin >> id;


        auto it = find(employeeIDsBackupX.begin(), employeeIDsBackupX.end(), id);
        if (it != employeeIDsBackupX.end()) {
            size_t i = distance(employeeIDsBackupX.begin(), it);
            saveRestoredDataToAddFiles(employeeNamesBackupX[i], employeeIDsBackupX[i], employeeSalariesBackupX[i], employeeRolesBackupX[i]);

            cout << "Data has been successfully restored back to AddEmployee files." << endl;

            // Remove the restored employee from the backup
            employeeNamesBackupX.erase(employeeNamesBackupX.begin() + i);
            employeeIDsBackupX.erase(employeeIDsBackupX.begin() + i);
            employeeRolesBackupX.erase(employeeRolesBackupX.begin() + i);
            employeeSalariesBackupX.erase(employeeSalariesBackupX.begin() + i);

            saveBackupData(); // Save the updated backup data
        } else {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }

    void restoreAllData() override {
        listBackupData();
        if (employeeIDsBackupX.empty()) {
            cout << "No backup data available." << endl;
            return;
        }
        char choice;
        cout << "Are you sure you want to restore all data? [Y/N] : ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            // if (employeeIDsBackupX.empty()) {
            //     cout << "No backup data available." << endl;
            //     return;
            // }

            for (size_t i = 0; i < employeeIDsBackupX.size(); ++i) {
                saveRestoredDataToAddFiles(employeeNamesBackupX[i], employeeIDsBackupX[i], employeeSalariesBackupX[i], employeeRolesBackupX[i]);
            }

            cout << "All data has been successfully restored back to AddEmployee files." << endl;

            employeeNamesBackupX.clear();
            employeeIDsBackupX.clear();
            employeeRolesBackupX.clear();
            employeeSalariesBackupX.clear();

            saveBackupData(); // Save the updated (empty) backup data
        }
    }

public:
    void backupData() {
        short option;
        do {
            listMenuBackupData();
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
        } while (option != 0);
    }

    void listMenuBackupData() {
        cout << "+================================================================================+" << endl;
        cout << "|                                                                                |" << endl;
        cout << "|                         >>>  BACKUP DATA MANAGEMENT  <<<                       |" << endl;
        cout << "|                                                                                |" << endl;
        cout << "+================================================================================+" << endl;
        cout << "|                                                                                |" << endl;
        cout << "|  [1]  =>  Restore Data by ID                                                   |" << endl;
        cout << "|  [2]  =>  Restore All Data                                                     |" << endl;
        cout << "|  [3]  =>  Empty Backup Data                                                    |" << endl;
        cout << "|  [0]  =>  Exit                                                                 |" << endl;
        cout << "+================================================================================+" << endl;
        cout << "|                >>>  Select an option by entering the number  <<<               |" << endl;
        cout << "+================================================================================+" << endl;
    }
};
