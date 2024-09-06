#pragma once

#include <iostream>
#include <algorithm>
#include <iomanip>
#include "AddEmployee.h"

using namespace std;

class ListEmployees {

    private :
        string list;

        void listAllEmployees() {
                    //13          34                                26                        25
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            
            for (int i = 0; i < employeeNames.size(); i++) {

                cout << "| " << setw(10) << left << employeeIDs[i]
                << "| " << setw(33) << left << employeeNames[i]
                << "| " << setw(25) << left << employeeRoles[i]
                << "| " << right << fixed << setprecision(2) << employeeSalaries[i] << "$" << setw(15) << " |" << endl;
            }
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "Employee " << employeeIDs.size() << endl;

        }

        void listEmployeeByPart() {
            cout << "Enter employees'role : ";
            cin.ignore();
            getline(cin, this->list);

            int count = 0;
            bool isFound = 0;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            for (int i = 0; i < employeeNames.size(); i++) {
                if (list == employeeRoles[i]) {
                    count++;
                    isFound = 1;
                    cout << "| " << setw(10) << left << employeeIDs[i]
                    << "| " << setw(33) << left << employeeNames[i]
                    << "| " << setw(25) << left << employeeRoles[i]
                    << "| " << right << fixed << setprecision(2) << employeeSalaries[i] << "$" << setw(15) << " |" << endl;       
                }
            } 
            cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            if (isFound) cout << list << " " << count << endl;
            else cout << list << " not found." << endl;
        }

        void listMenu() {
            cout << "=========================================================================" << endl;
            cout << ">                           | List Employee |                         <" << endl;
            cout << ">>=====================================================================<<" << endl;
            cout << ">>>                                                                   <<<" << endl;
            cout << ">>>>                                                                 <<<<" << endl;
            cout << ">>>>>                    1. List Employees By Part                  <<<<<" << endl;
            cout << ">>>>                     2. List All Employees                       <<<<" << endl;
            cout << ">>>                      0. Exit                                      <<<" << endl;
            cout << ">>                                                                     <<" << endl;
            cout << ">                                                                       <" << endl;
            cout << "=========================================================================" << endl;
        }


    public :

        void listEmployee() {
            short op;
            do {
                listMenu();
                cout << "[+] Enter your option : "; cin >> op;
                switch(op) {
                    case 1 : {
                        system("cls");
                        listEmployeeByPart();
                        break;
                    }
                    case 2 : {
                        system("cls");
                        listAllEmployees();
                        break;
                    }
                    case 0 : {
                        cout << "Exiting..." << endl;
                        break;
                    }
                    default : {
                        cout << "INVALID OPTION!" << endl;
                        break;
                    }
                }
            } while(op);
        }  

        void listRoles() {
            vector<string> roles = employeeRoles; // pass values of employeeRoles to roles
            sort(roles.begin(), roles.end());
            auto it = unique(roles.begin(), roles.end());
            roles.erase(it, roles.end());

            int count = 0;
            cout << "Role : " << endl;
            for (int i = 0; i < roles.size(); i++) {
                cout << roles[i];
                for (int j = 0; j < employeeRoles.size(); j++) {
                    if (employeeRoles[j] == roles[i]) {
                    count++;
                    }
                }
                cout<< "\t\t" << count << endl;
                count = 0;
            }
            cout << endl << "Employee : " << employeeRoles.size() << endl;
        } 

};