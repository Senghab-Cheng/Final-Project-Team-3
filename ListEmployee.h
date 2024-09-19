#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>
#include <Windows.h>

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

class ListEmployees {
private:
    vector<string> employeeNames;
    vector<int> employeeIDs;
    vector<string> employeeRoles;
    vector<double> employeeSalaries;

    void loadEmployeeData() {
        ifstream nameFile("data/employeeNameFile.txt");
        ifstream idFile("data/employeeIDFile.txt");
        ifstream salaryFile("data/employeeSalaryFile.txt");
        ifstream roleFile("data/employeePositionFile.txt");

        if (!nameFile || !idFile || !salaryFile || !roleFile) {
            cerr << "Error opening employee data files." << endl;
            return;
        }

        employeeNames.clear();
        employeeRoles.clear();
        employeeIDs.clear();
        employeeSalaries.clear();

        string name, role;
        int id;
        double salary;

        while (getline(nameFile, name) && idFile >> id && salaryFile >> salary && getline(roleFile, role)) {
            employeeNames.push_back(name);
            employeeIDs.push_back(id);
            employeeSalaries.push_back(salary);
            employeeRoles.push_back(role);
        }
    }

    void listAllEmployees() {
        getLoadingBar();
        cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
        cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
        cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;

        for (size_t i = 0; i < employeeNames.size(); i++) {
            cout << "| " << setw(11) << left << employeeIDs[i]
                 << "| " << setw(32) << left << employeeNames[i]
                 << "| " << setw(24) << left << employeeRoles[i]
                 << "| " << right << fixed << setprecision(2) << employeeSalaries[i] << "$" << setw(16) << " |" << endl;
        cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
        }

        vector<string> roles = employeeRoles;
        sort(roles.begin(), roles.end());
        roles.erase(unique(roles.begin(), roles.end()), roles.end());
        cout << "===================================================================================================" << endl;
        cout << "Department : " << endl;
        for (const auto& role : roles) {
            int count = count_if(employeeRoles.begin(), employeeRoles.end(), [&role](const string& r) { return r == role; });
            cout << role << " " << count << endl;
        }
        cout << "===================================================================================================" << endl;
        cout << "Employee : " << employeeRoles.size() << endl;
        cout << "===================================================================================================" << endl;
    }

    // Function to convert a string to uppercase
    void toUpperCase(std::string &input) {
        std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    }

    void listEmployeeByPart(/*const std::vector<std::string>& employeeRoles, 
                                      const std::vector<std::string>& employeeNames,
                                      const std::vector<int>& employeeIDs, 
                                      const std::vector<double>& employeeSalaries*/) {
        // Remove duplicate roles and sort
        std::vector<std::string> roles = employeeRoles;
        sort(roles.begin(), roles.end());
        roles.erase(unique(roles.begin(), roles.end()), roles.end());

        // Display department options
        std::cout << std::endl;
        std::cout << "===================================================================================================" << std::endl;
        std::cout << "Department : ";
        for (const auto& role : roles) {
            std::cout << role << "   ";
        }
        std::cout << std::endl;
        std::cout << "===================================================================================================" << std::endl;

        // Get department input from the user
        std::string department;
        std::cout << CYAN << "Enter employee department: " << RESET;
        cout << LIGHT_GREEN;
        getline(std::cin, department);
        cout << RESET;

        // Convert department input to uppercase
        toUpperCase(department);
        getLoadingBar();
        // Display table header
        std::cout << "+------------+---------------------------------+-------------------------+------------------------+" << std::endl;
        std::cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << std::endl;
        std::cout << "+------------+---------------------------------+-------------------------+------------------------+" << std::endl;

        int count = 0;
        bool isFound = false;

        // Iterate through the employees and display those that match the department
        for (size_t i = 0; i < employeeNames.size(); i++) {
            std::string roleUpperCase = employeeRoles[i];  // Copy the current role
            toUpperCase(roleUpperCase);  // Convert role to uppercase

            if (department == roleUpperCase) {
                count++;
                isFound = true;
                std::cout << "| " << std::setw(11) << std::left << employeeIDs[i]
                          << "| " << std::setw(32) << std::left << employeeNames[i]
                          << "| " << std::setw(24) << std::left << employeeRoles[i]
                          << "| " << std::right << std::fixed << std::setprecision(2) << employeeSalaries[i] << "$" << std::setw(16) << " |" << std::endl;
            std::cout << "+------------+---------------------------------+-------------------------+------------------------+" << std::endl;
            }
        }

        if (isFound) 
            std::cout << department << " department has " << count << " employees." << std::endl;
        else 
            std::cout << BRIGHT_RED << department << " department not found." << RESET << std::endl;
    }

    enum KEY { UP = 72, DOWN = 80, ENTER = 13 }; // Arrow keys and Enter key

    void setConsoleTextColor(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    void highlightListMenu(int currentSelection, int totalOptions) {
        
        cout << "+=================================================================================================+" << endl;
        cout << "|                                                                                                 |" << endl;
        cout << "|";cout << LIGHT_PEACH;
        cout << "                                    >>>  LIST EMPLOYEES  <<<                                     ";cout << RESET;cout << "|" << endl;
        cout << "|                                                                                                 |" << endl;
        cout << "+=================================================================================================+" << endl;
        cout << "|                                                                                                 |" << endl;

        string options[] = {
            "List Employees By Departments",
            "List All Employees",
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

    void department() {
        ifstream department("department.txt");

        if (department) {
            string line;
            while (getline(department, line)) {
                cout << line << endl;
                this_thread::sleep_for(chrono::milliseconds(80));
            }
        } else {
            cerr << BRIGHT_RED << "Unable to open the file!" << RESET << endl;
        }
    }

    void allEmployees() {
        ifstream allEmployees("allEmployee.txt");

        if (allEmployees) {
            string line;
            while (getline(allEmployees, line)) {
                cout << line << endl;
                this_thread::sleep_for(chrono::milliseconds(80));
            }
        } else {
            cerr << BRIGHT_RED << "Unable to open the file!" << RESET << endl;
        }
    }

public:
    void listEmployee() {
        int currentSelection = 0;
        const int totalOptions = 3; // List by Department, List All, Exit
        char key;
        loadEmployeeData();
        do {
            system("cls");
            highlightListMenu(currentSelection, totalOptions);
            key = _getch(); // Capture key press

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
                            listEmployeeByPart();
                            system("pause");
                            break;
                        }
                        case 1: {
                            listAllEmployees();
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
        } while (true); // Loop until "Exit" is selected and Enter is pressed
    }
};
