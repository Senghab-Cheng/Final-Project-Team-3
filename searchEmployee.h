#pragma once 

#include <iostream>
#include <vector>
#include "addEmployee.h"

using namespace std;

class SearchEmployee{
    public :




        void searchEmployee() {
            short choice;
            do {
                listForSearchEmployee();
                cout << "[+] Enter your choice : ";
                cin >> choice;
                switch(choice) {
                    case 1 : {
                        system("cls");
                        searchEmployeeByID();
                        break;
                    }
                    case 2 : {
                        system("cls");
                        searchEmployeeByName();
                        break;
                    }
                    case 0 : {
                        cout << "Exiting..." << endl;
                        break; 
                    }
                    default : {
                        cout << "INAVALID OPTION!" << endl;
                        break;
                    }
                }
            } while(choice);
        }

        private :

            string employeeName;
            int id;
            string role;

            void searchEmployeeByName() {
            cout << "[+] Enter employee's name : ";
            cin.ignore();
            getline(cin, employeeName);

            char employeeNameLetter;
            bool isFound = 0;
            if (employeeName.length() == 1) {
                employeeNameLetter = employeeName[0];
                for (int i = 0; i < employeeNames.size(); i++) {
                    string name = employeeNames[i];
                    for (int j = 0; j < name.length(); j++) {
                        if (name[j] == employeeNameLetter) {
                            cout << "Employee's Name : " << name << endl;
                            cout << "Employee's ID : " << employeeIDs[i] << endl;
                            cout << "Employee's Role : " << employeeRoles[i] << endl;
                            cout << "Employee's Salary : " << employeeSalaries[i] << "$" << endl << endl;
                            isFound = 1;
                            break;
                        }
                    }
                }
                if (!isFound) cout << "Name is not in the list." << endl;
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

        void searchEmployeeByID() {
            int id;
            cout << "[+] Enter employee's ID : ";
            cin >> id;

            if (id == employeeIDs[id-1]) {
                cout << "Employee's Name : " << employeeNames[id-1] << endl;
                cout << "Employee's ID : " << employeeIDs[id-1] << endl;
                cout << "Employee's Role : " << employeeRoles[id-1] << endl;
                cout << "Employee's Salary : " << employeeSalaries[id-1] << "$" << endl;
            }
            else cout << "Name is not in the list." << endl;
        }

            void listForSearchEmployee() {
            cout << "=========================================================================" << endl;
            cout << ">                           | Search Employee |                         <" << endl;
            cout << ">>=====================================================================<<" << endl;
            cout << ">>>                                                                   <<<" << endl;
            cout << ">>>>                                                                 <<<<" << endl;
            cout << ">>>>>                    1. Search Employee By ID                   <<<<<" << endl;
            cout << ">>>>                     2. Search Employee By Name                  <<<<" << endl;
            cout << ">>>                      0. Exit                                      <<<" << endl;
            cout << ">>                                                                     <<" << endl;
            cout << ">                                                                       <" << endl;
            cout << "=========================================================================" << endl;
        }
};