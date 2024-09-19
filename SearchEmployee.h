#pragma once  

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
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
            cerr << BRIGHT_RED << "Error: Unable to open one or more employee data files." << RESET << endl;
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
        cout << CYAN << "[+] Enter employee name (or partial name): " << RESET;
        //cin.ignore();
        string employeeName;
        cout << LIGHT_GREEN;
        getline(cin, employeeName);
        cout << RESET;
        // Convert input to lowercase for case-insensitive comparison
        transform(employeeName.begin(), employeeName.end(), employeeName.begin(), ::tolower);

        bool isFound = false;
        getLoadingBar();

        if (employeeName.length() == 1) {
            char employeeNameLetter = employeeName[0];
            //getLoadingBar();
            //system("cls");
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| ID         | NAME                            | JOB TITLE               | SALARY                 |" << endl;
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
                cout << BRIGHT_RED << "No employee names contain the letter '" << employeeNameLetter << "'." << RESET << endl;
            } else {
                cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            }
        } else {
            //getLoadingBar();
            //system("cls");
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| ID         | NAME                            | JOB TITLE               | SALARY                 |" << endl;
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
                cout << LIGHT_GREEN << "Employee with name / " << employeeName << " / not found." << RESET << endl;
            } else {
                cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            }
        }
    }

    void searchEmployeeByID() {
        int id;
        cout << CYAN << "[+] Enter employee ID : " << RESET;
        cout << LIGHT_GREEN;
        cin >> id;
        cout << RESET;

        auto it = find(employeeIDs.begin(), employeeIDs.end(), id);
        getLoadingBar();
        if (it != employeeIDs.end()) {
            size_t index = distance(employeeIDs.begin(), it);
            cin.ignore();
            //getLoadingBar();
            //system("cls");
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| ID         | NAME                            | JOB TITLE               | SALARY                 |" << endl;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| " << setw(11) << left << employeeIDs[index]
                 << "| " << setw(32) << left << employeeNames[index]
                 << "| " << setw(24) << left << employeeRoles[index]
                 << "| " << right << fixed << setprecision(2) << employeeSalaries[index] << "$" << setw(16) << " |" << endl;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
        } else {
            cout << BRIGHT_RED << "Employee with ID " << id << " not found." << RESET << endl;
        }
    }


    enum KEY { UP = 72, DOWN = 80, ENTER = 13 }; // Arrow keys and Enter key
    void setConsoleTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
    void listForSearchEmployee(int currentSelection, int totalOptions) {
        cout << "+=================================================================================================+" << endl;
        cout << "|                                                                                                 |" << endl;
        cout << "|";cout << LIGHT_PEACH;
        cout << "                                      >>>  SEARCH EMPLOYEE  <<<                                  ";cout << RESET;cout << "|" << endl;
        cout << "|                                                                                                 |" << endl;
        cout << "+=================================================================================================+" << endl;
        cout << "|                                                                                                 |" << endl;
        
        string options[] = {
            "Search Employee By ID",
            "Search Employee By Name",
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
        
        setConsoleTextColor(7);
        cout << "|                                                                                                 |" << endl;
        cout << "+=================================================================================================+" << endl;
        cout << "|";cout << LIGHT_GREEN;
        cout << "                          >>>  Select an option by pressing Enter  <<<                           ";cout << RESET;
        cout << "|" << endl;
        cout << "+=================================================================================================+" << endl;

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
