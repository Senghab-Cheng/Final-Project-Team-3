#pragma once 

#include <iostream>
#include <vector>
#include "addEmployee.h"

using namespace std;

class SearchEmployee{
    public :
        string employeeName;
        int id;
        string role;

        void searchEmployee() {
            cout << "[+] Enter employee's name : ";
            getline(cin, employeeName);

            cout << "[+] Enter employee's ID : ";
            cin >> id;

            char employeeNameLetter;
            if (employeeName.length() == 1) {
                employeeNameLetter = employeeName[0];
                for (int i = 0; i < employeeNames.size(); i++) {
                    string name = employeeNames[i];
                    for (int j = 0; j < name.length(); j++) {
                        if (name[j] == employeeNameLetter) {
                            cout << "Employee's Name : " << name << endl;
                            cout << "Employee's ID : " << employeeIDs[i] << endl;
                            cout << "Employee's Role : " << employeeRoles[i] << endl;
                            cout << "Employee's Salary : " << employeeSalaries[i] << "$" << endl;
                            break;
                        }
                    }
                }
            }
            else {
                for (int i = 0; i < employeeNames.size(); i++) {
                    if (employeeName == employeeNames[i]) {
                        cout << "Employee's Name : " << employeeNames[i] << endl;
                        cout << "Employee's ID : " << employeeIDs[i] << endl;
                        cout << "Employee's Role : " << employeeRoles[i] << endl;
                        cout << "Employee's Salary : " << employeeSalaries[i] << "$" << endl;
                        break;
                    }
                }
            }
        } 

};
