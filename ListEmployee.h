#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <thread>
#include <chrono>
#include "AddEmployee.h"
#include "loadingBar.h"

using namespace std;

class ListEmployees {
private:
    // These vectors should be populated with data from the files
    vector<string> employeeNames;
    vector<int> employeeIDs;
    vector<string> employeeRoles;
    vector<double> employeeSalaries;

    // Load employee data from files into vectors
    void loadEmployeeData() {
        ifstream nameFile("data/employeeNameFile.txt");
        ifstream idFile("data/employeeIDFile.txt");
        ifstream salaryFile("data/employeeSalaryFile.txt");
        ifstream roleFile("data/employeePositionFile.txt");

        if (!nameFile || !idFile || !salaryFile || !roleFile) {
            cout << "Error opening employee data files." << endl;
            return;
        }

        string name, role;
        int id;
        double salary;

        employeeNames.clear();
        employeeRoles.clear();
        employeeIDs.clear();
        employeeSalaries.clear();

        while (getline(nameFile, name) && idFile >> id && salaryFile >> salary && getline(roleFile, role)) {
            employeeNames.push_back(name);
            employeeIDs.push_back(id);
            employeeSalaries.push_back(salary);
            employeeRoles.push_back(role);
        }

        nameFile.close();
        idFile.close();
        salaryFile.close();
        roleFile.close();
    }

    void listAllEmployees() {
        cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
        cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
        cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;

        for (size_t i = 0; i < employeeNames.size(); i++) {
            cout << "| " << setw(10) << left << employeeIDs[i]
                 << "| " << setw(33) << left << employeeNames[i]
                 << "| " << setw(25) << left << employeeRoles[i]
                 << "| " << right << fixed << setprecision(2) << employeeSalaries[i] << "$" << setw(15) << " |" << endl;
        }

        cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
        
        vector<string> roles = employeeRoles; // pass values of employeeRoles to roles
        sort(roles.begin(), roles.end());
        auto it = unique(roles.begin(), roles.end());
        roles.erase(it, roles.end());

        int count = 0;
        cout << "Department : " << endl;
        for (const auto& role : roles) {
            count = count_if(employeeRoles.begin(), employeeRoles.end(), [&role](const string& r) { return r == role; });
            cout << role << " " << count << endl;
        }
        cout << endl << "Employee : " << employeeRoles.size() << endl;
    }

    void listEmployeeByPart() {
        string list;
        cout << "Enter employee department: ";
        cin.ignore();
        getline(cin, list);
        system("cls");

        int count = 0;
        bool isFound = false;

        cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
        cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
        cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;

        for (size_t i = 0; i < employeeNames.size(); i++) {
            if (list == employeeRoles[i]) {
                count++;
                isFound = true;
                cout << "| " << setw(10) << left << employeeIDs[i]
                     << "| " << setw(33) << left << employeeNames[i]
                     << "| " << setw(25) << left << employeeRoles[i]
                     << "| " << right << fixed << setprecision(2) << employeeSalaries[i] << "$" << setw(15) << " |" << endl;
            }
        }

        cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
        if (isFound) 
            cout << list << " " << count << endl;
        else 
            cout << list << " not found." << endl;
    }

    void listMenu() {
        cout << "+==============================================================================+" << endl;
        cout << "|                                                                              |" << endl;
        cout << "|                            >>>  LIST EMPLOYEES  <<<                          |" << endl;
        cout << "|                                                                              |" << endl;
        cout << "+==============================================================================+" << endl;
        cout << "|                                                                              |" << endl;
        cout << "|  [1]  =>  List Employees By Departments                                      |" << endl;
        cout << "|  [2]  =>  List All Employees                                                 |" << endl;
        cout << "|  [0]  =>  Exit                                                               |" << endl;
        cout << "|                                                                              |" << endl;
        cout << "+==============================================================================+" << endl;
        cout << "|              >>>  Select an option by entering the number  <<<               |" << endl;
        cout << "+==============================================================================+" << endl;
    }

    void department() {
        ifstream department("department.txt");

        if (department.is_open()) {
            string line;
            while (getline(department, line)) {
                cout << line << endl;
                this_thread::sleep_for(chrono::milliseconds(80));
            }
            department.close();
        } else {
            cout << "Unable to open the file!" << endl;
        }
    }

    void allEmployees() {
        ifstream allEmployees("allEmployee.txt");

        if (allEmployees.is_open()) {
            string line;
            while (getline(allEmployees, line)) {
                cout << line << endl;
                this_thread::sleep_for(chrono::milliseconds(80));
            }
            allEmployees.close();
        } else {
            cout << "Unable to open the file!" << endl;
        }
    }

public:
    void listEmployee() {
        short op;
        loadEmployeeData(); // Load employee data from files
        do {
            listMenu();
            cout << "[+] Enter your option: "; 
            cin >> op;
            switch (op) {
            case 1:
                department();
                listRoles();
                listEmployeeByPart();
                break;
            case 2:
                system("cls");
                allEmployees();
                listAllEmployees();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "INVALID OPTION!" << endl;
                break;
            }
        } while (op);
    }

    void listRoles() {
        vector<string> roles = employeeRoles;
        sort(roles.begin(), roles.end());
        auto it = unique(roles.begin(), roles.end());
        roles.erase(it, roles.end());

        cout << "Department: ";
        for (size_t i = 0; i < roles.size(); i++) {
            cout << roles[i];
            if (i != roles.size() - 1) 
                cout << ", ";
        }
        cout << endl << "Employee: " << employeeRoles.size() << endl;
    }
};
