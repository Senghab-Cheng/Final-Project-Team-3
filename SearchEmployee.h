#pragma once  

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "AddEmployee.h"
#include "loadingBar.h"

using namespace std;

class SearchEmployee {
private:
    vector<string> employeeNames;
    vector<int> employeeIDs;
    vector<string> employeeRoles;
    vector<double> employeeSalaries;

    void loadEmployeeData() {
        ifstream namesFile("data/employeeNameFile.txt");
        ifstream idsFile("data/employeeIDFile.txt");
        ifstream rolesFile("data/employeePositionFIle.txt");
        ifstream salariesFile("data/employeeSalaryFile.txt");

        if (!namesFile.is_open() || !idsFile.is_open() || !rolesFile.is_open() || !salariesFile.is_open()) {
            cerr << "Error: Unable to open one or more employee data files." << endl;
            return;
        }

        string name;
        int id;
        string role;
        double salary;

        while (getline(namesFile, name) && idsFile >> id && getline(rolesFile, role) && salariesFile >> salary) {
            employeeNames.push_back(name);
            employeeIDs.push_back(id);
            employeeRoles.push_back(role);
            employeeSalaries.push_back(salary);
            idsFile.ignore(); // Ignore the newline character after ID
        }

        namesFile.close();
        idsFile.close();
        rolesFile.close();
        salariesFile.close();
    }

    void searchEmployeeByName() {
        cout << "[+] Enter employee name (or partial name): ";
        cin.ignore();
        string employeeName;
        getline(cin, employeeName);

        // Convert input to lowercase for case-insensitive comparison
        transform(employeeName.begin(), employeeName.end(), employeeName.begin(), ::tolower);

        bool isFound = false;

        if (employeeName.length() == 1) {
            char employeeNameLetter = employeeName[0];
            //getLoadingBar();
            system("cls");
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            
            for (size_t i = 0; i < employeeNames.size(); i++) {
                string lowerName = employeeNames[i];
                transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

                if (lowerName.find(employeeNameLetter) != string::npos) {
                    cout << "| " << setw(10) << left << employeeIDs[i]
                        << "| " << setw(33) << left << employeeNames[i]
                        << "| " << setw(25) << left << employeeRoles[i]
                        << "| " << right << fixed << setprecision(2) << employeeSalaries[i] << "$" << setw(15) << " |" << endl;
                    isFound = true;
                }
            }

            if (!isFound) {
                cout << "No employee names contain the letter '" << employeeNameLetter << "'." << endl;
            } else {
                cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            }
        } else {
            //getLoadingBar();
            system("cls");
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;

            for (size_t i = 0; i < employeeNames.size(); i++) {
                string lowerName = employeeNames[i];
                transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

                if (lowerName.find(employeeName) != string::npos) {
                    cout << "| " << setw(10) << left << employeeIDs[i]
                        << "| " << setw(33) << left << employeeNames[i]
                        << "| " << setw(25) << left << employeeRoles[i]
                        << "| " << right << fixed << setprecision(2) << employeeSalaries[i] << "$" << setw(15) << " |" << endl;
                    isFound = true;
                }
            }

            if (!isFound) {
                cout << "Employee with name / " << employeeName << " / not found." << endl;
            } else {
                cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            }
        }
    }

    void searchEmployeeByID() {
        int id;
        cout << "[+] Enter employee ID : ";
        cin >> id;

        auto it = find(employeeIDs.begin(), employeeIDs.end(), id);
        if (it != employeeIDs.end()) {
            size_t index = distance(employeeIDs.begin(), it);
            cin.ignore();
            getLoadingBar();
            system("cls");
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| " << setw(10) << left << employeeIDs[index]
                << "| " << setw(33) << left << employeeNames[index]
                << "| " << setw(25) << left << employeeRoles[index]
                << "| " << right << fixed << setprecision(2) << employeeSalaries[index] << "$" << setw(13) << " |" << endl;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
        } else {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }

    void listForSearchEmployee() {
        cout << "+==============================================================================+" << endl;
        cout << "|                                                                              |" << endl;
        cout << "|                            >>>  SEARCH EMPLOYEE  <<<                         |" << endl;
        cout << "|                                                                              |" << endl;
        cout << "+==============================================================================+" << endl;
        cout << "|                                                                              |" << endl;
        cout << "|  [1]  =>  Search Employee By ID                                              |" << endl;
        cout << "|  [2]  =>  Search Employee By Name                                            |" << endl;
        cout << "|  [0]  =>  Exit                                                               |" << endl;
        cout << "|                                                                              |" << endl;
        cout << "+==============================================================================+" << endl;
        cout << "|                 >>>  Select an option by entering the number  <<<            |" << endl;
        cout << "+==============================================================================+" << endl;  
    }

public:
    void searchEmployee() {
        loadEmployeeData(); // Load data from files
        short choice;
        do {
            listForSearchEmployee();
            cout << "[+] Enter your choice : ";
            cin >> choice;
            switch (choice) {
                case 1: {
                    searchEmployeeByID();
                    break;
                }
                case 2: {
                    searchEmployeeByName();
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
        } while (choice != 0);
    }
};
