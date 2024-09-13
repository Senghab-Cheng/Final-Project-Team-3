#pragma once

#include <iostream>
#include <vector>
#include <algorithm>  // for max_element

using namespace std;

// Vectors holding employee data
vector<string> employeeNames {"Senghab Cheng", "Pech Rattanakmony", "Thouern Chanthat", "Phorn Sotheara", "Ey Channim", "Chheng Panharath"};
vector<double> employeeSalaries {2300.5, 2200.75, 3100.25, 2575.25, 2785.75, 2200.5};
vector<int> employeeIDs {1, 2, 3, 4, 5, 6};
vector<string> employeeRoles {"Manager", "Manager", "Cyber Security", "Cyber Security", "Developer", "Developer"};

class AddEmployee {
    private:
        string employeeName;
        int employeeID;
        double employeeSalary;
        string employeeRole;

        // Function to generate the next ID
        int generateNextID() {
            if (employeeIDs.empty()) {
                return 1; // Start from 1 if no IDs exist
            }
            return *max_element(employeeIDs.begin(), employeeIDs.end()) + 1;
        }

    public:
        void setEmployeeData() {
            // Enter employee name
            cout << "[+] Enter employee Name: ";
            cin.ignore(); // To ignore any leftover newline characters from previous input
            getline(cin, employeeName);
            employeeNames.push_back(employeeName);

            // Generate employee ID automatically
            employeeID = generateNextID();
            employeeIDs.push_back(employeeID);
            cout << "[+] Generated employee ID: " << employeeID << endl;

            // Enter employee position
            cout << "[+] Enter employee Position: ";
            getline(cin, employeeRole);
            employeeRoles.push_back(employeeRole);

            // Enter employee salary
            cout << "[+] Enter employee Salary: ";
            cin >> employeeSalary;
            employeeSalaries.push_back(employeeSalary);
        }
};
