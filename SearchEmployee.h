#pragma once 

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "AddEmployee.h"
#include "loadingBar.h"

using namespace std;

class SearchEmployee {
public:
    
    void searchEmployee() {
        short choice;
        do {
            listForSearchEmployee();
            cout << "[+] Enter your choice : ";
            cin >> choice;
            switch (choice) {
            case 1: {
                //system("cls");
                searchEmployeeByID();
                break;
            }
            case 2: {
                //system("cls");
                searchEmployeeByName();
                break;
            }
            case 0: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "INAVALID OPTION!" << endl;
                break;
            }
            }
        } while (choice);
    }

private:

    string employeeName;
    int id;
    string role;

    void searchEmployeeByName() {
        cout << "[+] Enter employee name (or partial name): ";
        cin.ignore();
        getline(cin, employeeName);

        // Convert input to lowercase for case-insensitive comparison
        transform(employeeName.begin(), employeeName.end(), employeeName.begin(), ::tolower);

        bool isFound = false;

        // Check if input is a single character
        if (employeeName.length() == 1) {
            char employeeNameLetter = employeeName[0]; // the single character input
            //getLoadingBar();
            system("cls");
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            
            for (int i = 0; i < employeeNames.size(); i++) {
                string lowerName = employeeNames[i];
                transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

                // Check if the letter is found in the employee's name
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
            }
            else {
                cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            }
        }
        // If the input is more than one character (full or partial name)
        else {
            //getLoadingBar();
            system("cls");
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;

            for (int i = 0; i < employeeNames.size(); i++) {
                string lowerName = employeeNames[i];
                transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

                // Check if the input is a substring of the employee's name
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
            }
            else {
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

        }
        else {
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
};