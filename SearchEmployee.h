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
        //cin.ignore();
        string employeeName;
        getline(cin, employeeName);

        // Convert input to lowercase for case-insensitive comparison
        transform(employeeName.begin(), employeeName.end(), employeeName.begin(), ::tolower);

        bool isFound = false;

        if (employeeName.length() == 1) {
            char employeeNameLetter = employeeName[0];
            //getLoadingBar();
            //system("cls");
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            
            for (size_t i = 0; i < employeeNames.size(); i++) {
                string lowerName = employeeNames[i];
                transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

                if (lowerName.find(employeeNameLetter) != string::npos) {
                    cout << "| " << setw(11) << left << employeeIDs[i]
                         << "| " << setw(32) << left << employeeNames[i]
                         << "| " << setw(24) << left << employeeRoles[i]
                         << "| " << right << fixed << setprecision(2) << employeeSalaries[i] << "$" << setw(16) << " |" << endl;
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
            //system("cls");
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;

            for (size_t i = 0; i < employeeNames.size(); i++) {
                string lowerName = employeeNames[i];
                transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

                if (lowerName.find(employeeName) != string::npos) {
                    cout << "| " << setw(11) << left << employeeIDs[i]
                         << "| " << setw(32) << left << employeeNames[i]
                         << "| " << setw(24) << left << employeeRoles[i]
                         << "| " << right << fixed << setprecision(2) << employeeSalaries[i] << "$" << setw(16) << " |" << endl;
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
            //getLoadingBar();
            //system("cls");
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| " << setw(11) << left << employeeIDs[index]
                 << "| " << setw(32) << left << employeeNames[index]
                 << "| " << setw(24) << left << employeeRoles[index]
                 << "| " << right << fixed << setprecision(2) << employeeSalaries[index] << "$" << setw(16) << " |" << endl;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
        } else {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }


    enum KEY { UP = 72, DOWN = 80, ENTER = 13 }; // Arrow keys and Enter key
    void setConsoleTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
    void listForSearchEmployee(int currentSelection, int totalOptions) {
        cout << "+==============================================================================+" << endl;
        cout << "|                                                                              |" << endl;
        cout << "|                            >>>  SEARCH EMPLOYEE  <<<                         |" << endl;
        cout << "|                                                                              |" << endl;
        cout << "+==============================================================================+" << endl;
        cout << "|                                                                              |" << endl;
        
        string options[] = {
            "Search Employee By ID",
            "Search Employee By Name",
            "Exit"
        };

        for (int i = 0; i < totalOptions; i++) {
            if (i == currentSelection) {
                setConsoleTextColor(15); // Bold (White text on black background)
                cout << "|  =>  " << options[i] << string(62 - options[i].length(), ' ') << "          |" << endl;
            } else {
                setConsoleTextColor(8); // Normal (Gray text on black background)
                cout << "|      " << options[i] << string(62 - options[i].length(), ' ') << "          |" << endl;
            }
        }
        
    setConsoleTextColor(7);
    cout << "|                                                                              |" << endl;
    cout << "+==============================================================================+" << endl;
    cout << "|                  >>>  Select an option by pressing Enter  <<<                |" << endl;
    cout << "+==============================================================================+" << endl;
    }

public:
    void searchEmployee() {
        loadEmployeeData(); // Load data from files
        int currentSelection = 0;
        const int totalOptions = 3;
        char key;
        do {
            system("cls");
            listForSearchEmployee(currentSelection, totalOptions);
            key = _getch();
            switch (key) {
                case UP:
                    if (currentSelection > 0) currentSelection--; // Move up
                    break;
                case DOWN:
                    if (currentSelection < totalOptions - 1) currentSelection++; // Move down
                    break;
                case ENTER:
                    //system("cls");
                    switch (currentSelection) {
                        case 0: {
                            searchEmployeeByID();
                            system("pause");
                            break;
                        }
                        case 1: {
                            searchEmployeeByName();
                            system("pause");
                            break;
                        }
                        case 2: {
                            //cout << "Exiting..." << endl;
                            return; // Exit the function when "Exit" is selected
                        }
                    }
                    break;
            }
        this_thread::sleep_for(chrono::milliseconds(20));  
        } while (true);
    }
};
