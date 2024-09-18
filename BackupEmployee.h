#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <Windows.h>

#include "DeleteEmployee.h"
#include "AddEmployee.h"
#include "loadingBar.h"

using namespace std;

#define LIGHT_BLUE "\033[38;5;123m"
#define BRIGHT_GREEN "\033[38;5;122m"
#define LIGHT_GREEN "\033[92m"
#define LIGHT_PINK "\033[38;5;217m"
#define LIGHT_PEACH "\033[38;5;223m"
#define CYAN "\033[36m"
#define GREEN "\033[38;5;46m"
#define BRIGHT_RED "\033[91m"
#define RESET "\033[0m"        // Reset definition

// Declaration of external backup vectors to avoid multiple definitions
extern vector<string> employeeNamesBackupX;
extern vector<string> employeeRolesBackupX;
extern vector<int> employeeIDsBackupX;
extern vector<double> employeeSalariesBackupX;

class BackupDataFunctions {
protected:
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
        
        cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
        cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
        cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;

        for (size_t i = 0; i < employeeIDsBackupX.size(); ++i) {
            cout << "| " << setw(11) << left << employeeIDsBackupX[i]
                 << "| " << setw(32) << left << employeeNamesBackupX[i]
                 << "| " << setw(24) << left << employeeRolesBackupX[i]
                 << "| " << right << fixed << setprecision(2) << employeeSalariesBackupX[i] << "$" << setw(16) << " |" << endl;
        }

        cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;

        vector<string> roles = employeeRolesBackupX;
        sort(roles.begin(), roles.end());
        roles.erase(unique(roles.begin(), roles.end()), roles.end());
        cout << "===================================================================================================" << endl;
        cout << "Department : " << endl;
        for (const auto& role : roles) {
            int count = count_if(employeeRolesBackupX.begin(), employeeRolesBackupX.end(), [&role](const string& r) { return r == role; });
            cout << role << " " << count << endl;
        }
        cout << "===================================================================================================" << endl;
        cout << "Employee : " << employeeRolesBackupX.size() << endl;
        cout << "===================================================================================================" << endl;
            // cout << "Name: " << employeeNamesBackupX[i] << endl;
            // cout << "ID: " << employeeIDsBackupX[i] << endl;
            // cout << "Role: " << employeeRolesBackupX[i] << endl;
            // cout << "Salary: " << employeeSalariesBackupX[i] << "$" << endl << endl;
        
    }

    void emptyData() override {
        listBackupData();
        if (employeeIDsBackupX.empty()) {
            cerr << BRIGHT_RED << "No backup data available." << RESET << endl;
            return;
        }
        char choice;
        cout << CYAN;
        cout << "Are you sure you want to empty backup data? [Y/N] : ";
        cout << RESET;
        cout << LIGHT_GREEN;
        cin >> choice;
        cout << RESET;

        if (choice == 'y' || choice == 'Y') {
            employeeNamesBackupX.clear();
            employeeIDsBackupX.clear();
            employeeRolesBackupX.clear();
            employeeSalariesBackupX.clear();
            saveBackupData(); // Clear the backup files
            getLoadingBar();
            cerr << LIGHT_GREEN << "Backup data has been successfully emptied." << RESET << endl;
        }
        else return;
    }

    void restoreDataByID() override {
        loadBackupData();
        listBackupData();
        if (employeeIDsBackupX.empty()) {
            cerr << BRIGHT_RED << "No backup data available."<< RESET << endl;
            return;
        }
        int id;
        cout << CYAN;
        cout << "[+] Enter the employee ID to restore the data: ";
        cout << RESET;
        cout << LIGHT_GREEN;
        cin >> id;
        cout << RESET;


        auto it = find(employeeIDsBackupX.begin(), employeeIDsBackupX.end(), id);
        getLoadingBar();
        if (it != employeeIDsBackupX.end()) {
            size_t i = distance(employeeIDsBackupX.begin(), it);
            saveRestoredDataToAddFiles(employeeNamesBackupX[i], employeeIDsBackupX[i], employeeSalariesBackupX[i], employeeRolesBackupX[i]);
            cout << LIGHT_GREEN << "Data has been successfully restored back to AddEmployee files." << RESET << endl;

            // Remove the restored employee from the backup
            employeeNamesBackupX.erase(employeeNamesBackupX.begin() + i);
            employeeIDsBackupX.erase(employeeIDsBackupX.begin() + i);
            employeeRolesBackupX.erase(employeeRolesBackupX.begin() + i);
            employeeSalariesBackupX.erase(employeeSalariesBackupX.begin() + i);

            saveBackupData(); // Save the updated backup data
        } else {
            cerr << BRIGHT_RED << "Employee with ID " << id << " not found." << RESET << endl;
        }
    }

    void restoreAllData() override {
        listBackupData();
        if (employeeIDsBackupX.empty()) {
            cerr << BRIGHT_RED << "No backup data available." << RESET << endl;
            return;
        }
        char choice;
        cout << CYAN;
        cout << "Are you sure you want to restore all data? [Y/N] : ";
        cout << RESET;
        cout << LIGHT_GREEN;
        cin >> choice;
        cout << RESET;

        if (choice == 'Y' || choice == 'y') {
            // if (employeeIDsBackupX.empty()) {
            //     cout << "No backup data available." << endl;
            //     return;
            // }

            for (size_t i = 0; i < employeeIDsBackupX.size(); ++i) {
                saveRestoredDataToAddFiles(employeeNamesBackupX[i], employeeIDsBackupX[i], employeeSalariesBackupX[i], employeeRolesBackupX[i]);
            }
            getLoadingBar();
            cout << LIGHT_GREEN << "All data has been successfully restored back to AddEmployee files." << RESET << endl;

            employeeNamesBackupX.clear();
            employeeIDsBackupX.clear();
            employeeRolesBackupX.clear();
            employeeSalariesBackupX.clear();

            saveBackupData(); // Save the updated (empty) backup data
        }
        else return;
    }

public:
    void backupData() {
        int currentSelection = 0;
        const int totalOptions = 4;
        char key;
        do {
            system("cls");
            listMenuBackupData(currentSelection, totalOptions);
            key = _getch();
            switch (key) {
                case UP:
                    if (currentSelection > 0) currentSelection--; // Move up
                    break;
                case DOWN:
                    if (currentSelection < totalOptions - 1) currentSelection++; // Move down
                    break;
                case ENTER:
                    switch (currentSelection) {
                        case 0: {
                            restoreDataByID();
                            system("pause");
                            break;
                        }
                        case 1: {
                            restoreAllData();
                            system("pause");
                            break;
                        }
                        case 2: {
                            emptyData();
                            system("pause");
                            break;
                        }
                        case 3 : {
                            return;
                        }
                    }
                    break;
            }
        this_thread::sleep_for(chrono::milliseconds(20));    
        } while (true); // Loop until "Exit" is selected and Enter is pressed
    }


    enum KEY { UP = 72, DOWN = 80, ENTER = 13 }; // Arrow keys and Enter key

    void setConsoleTextColor(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
    void listMenuBackupData(int currentSelection, int totalOptions) {
        cout << "+=================================================================================================+" << endl;
        cout << "|                                                                                                 |" << endl;
        cout << "|";cout << LIGHT_PEACH;
        cout << "                                 >>>  BACKUP DATA MANAGEMENT  <<<                                ";cout << RESET;;cout << "|" << endl;
        cout << "|                                                                                                 |" << endl;
        cout << "+=================================================================================================+" << endl;
        cout << "|                                                                                                 |" << endl;
       
        string options[] = {
            "Restore Data By ID",
            "Restore All Data",
            "Empty Backup Data",
            "Exit"
        };

        for (int i = 0; i < totalOptions; i++) {
            if (i == currentSelection) {
                setConsoleTextColor(15); // Bold (White text on black background)
                cout << "|  =>    " << options[i] << string(62 - options[i].length(), ' ') << "                           |" << endl;
            } else {
                setConsoleTextColor(8); // Normal (Gray text on black background)
                cout << "|        " << options[i] << string(62 - options[i].length(), ' ') << "                           |" << endl;
            }
        }

        setConsoleTextColor(7); // Reset to normal color
        cout << "|                                                                                                 |" << endl;
        cout << "+=================================================================================================+" << endl;
        cout << "|";cout << LIGHT_GREEN;
        cout << "                          >>>  Select an option by pressing Enter  <<<                           ";cout << RESET;
        cout << "|" << endl;
        cout << "+=================================================================================================+" << endl;
       }
};