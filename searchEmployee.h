#pragma once 

#include <iostream>
#include <vector>
#include <iomanip>
#include "AddEmployee.h"

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

            cout << "[+] Enter employee name : ";
            cin.ignore();
            getline(cin, employeeName);

            char employeeNameLetter;
            bool isFound = 0;
            if (employeeName.length() == 1) {
                employeeNameLetter = employeeName[0];
               
                cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
                cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
                cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
               
                for (int i = 0; i < employeeNames.size(); i++) {
                    string name = employeeNames[i];
                    for (int j = 0; j < name.length(); j++) {
                        if (name[j] == employeeNameLetter) {
                            cout << "| " << setw(10) << left << employeeIDs[i]
                            << "| " << setw(33) << left << employeeNames[i]
                            << "| " << setw(25) << left << employeeRoles[i]
                            << "| " << right << fixed << setprecision(2) << employeeSalaries[i] << "$" << setw(15) << " |" << endl;
                            isFound = 1;
                            break;
                        }
                    }
                }
                if (!isFound) cout << "Employee with name / " << employeeName << " / not found." << endl;
                else cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;

            }
            else {
                
                cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
                cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
                cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
                
                for (int i = 0; i < employeeNames.size(); i++) {
                    if (employeeName == employeeNames[i]) {
                        cout << "| " << setw(10) << left << employeeIDs[i]
                        << "| " << setw(33) << left << employeeNames[i]
                        << "| " << setw(25) << left << employeeRoles[i]
                        << "| " << right << fixed << setprecision(2) << employeeSalaries[i] << "$"<< setw(15) << " |" << endl;
                        isFound = 1;
                        break;
                    }
                }
                if (!isFound) cout << "Employee with name / " << employeeName << " / not found." << endl;
                else cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
            }
        } 

        void searchEmployeeByID() {
            int id;
            cout << "[+] Enter employee ID : ";
            cin >> id;
    
            if (id == employeeIDs[id-1]) {
                cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
                cout << "| ID         | NAME                            | ROLE                    | SALARY                 |" << endl;
                cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;
                cout << "| " << setw(10) << left << employeeIDs[id-1]
                << "| " << setw(33) << left << employeeNames[id-1]
                << "| " << setw(25) << left << employeeRoles[id-1]
                << "| " << right << fixed << setprecision(2) << employeeSalaries[id-1] << "$" << setw(15) << " |" << endl;
                cout << "+------------+---------------------------------+-------------------------+------------------------+" << endl;

            }
            else cout << "Employee with ID " << id << " not found" << endl;
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