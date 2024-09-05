#pragma ocne 

#include <iostream>
#include "AddEmployee.h"

using namespace std;

class ListEmployees {

    private :
        string list;

        void listAllEmployees() {
            for (int i = 0; i < employeeNames.size(); i++) {
                cout << "Name : " << employeeNames[i] << endl;
                cout << "ID : " << employeeIDs[i] << endl;
                cout << "Role : " << employeeRoles[i] << endl;
                cout << "Salary : " << employeeSalaries[i] << "$" << endl << endl; 
            }
        }

        void listEmployeeByPart() {
            cout << "Enter employees'role : ";
            cin.ignore();
            getline(cin, this->list);

            for (int i = 0; i < employeeNames.size(); i++) {
                if (list == employeeRoles[i]) {
                    cout << "Name : " << employeeNames[i] << endl;
                    cout << "ID : " << employeeIDs[i] << endl;
                    cout << "Role : " << employeeRoles[i] << endl;
                    cout << "Salary : " << employeeSalaries[i] << "$" << endl << endl; 
                }
            } 
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

};