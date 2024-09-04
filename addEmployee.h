#pragma once

#include <iostream>
#include <vector>

using namespace std;

vector<string> employeeNames;
vector<double> employeeSalaries;
vector<int> employeeIDs;
vector<string> employeeRoles;

class AddEmployee{
    private :
        string employeeName;
        int employeeID;
        double employeeSalary;
        string employeeRole;

    public :
        void setEmployeeData() {
            cout << "[+] Enter employee's name : ";
            getline(cin, this->employeeName);
            employeeNames.push_back(this->employeeName);

            cout << "[+] Enter employee's ID : ";
            cin >> this->employeeID;
            employeeIDs.push_back(this->employeeID);

            cout << "[+] Enter employee's role : ";
            cin.ignore();
            getline(cin, this->employeeRole);
            employeeRoles.push_back(this->employeeRole);

            cout << "[+] Enter employee's salary : ";
            cin >> this->employeeSalary;
            employeeSalaries.push_back(this->employeeSalary);
        }
        
};