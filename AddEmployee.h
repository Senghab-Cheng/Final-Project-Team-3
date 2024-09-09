#pragma once

#include <iostream>
#include <vector>

using namespace std;

vector<string> employeeNames {"Senghab Cheng", "Pech Rattanakmony", "Thouern Chanthat", "Phorn Sotheara", "Ey Channim", "Chheng Panharath"};
vector<double> employeeSalaries {2300.5, 2200.75, 3100.25, 2575.25, 2785.75, 2200.5};
vector<int> employeeIDs {1, 2, 3, 4, 5, 6};
vector<string> employeeRoles {"Manager", "Manager", "Cyber Security", "Cyber Security", "Developer", "Developer"};

class AddEmployee{
    private :
        string employeeName;
        int employeeID;
        double employeeSalary;
        string employeeRole;

    public :
        void setEmployeeData() {
            cout << "[+] Enter employee's name : ";
            cin.ignore();
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