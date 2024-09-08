#include <iostream>
#include <string>
#include <vector>

#include "Login.h"
#include "SearchEmployee.h"
#include "ListEmployee.h"
#include "AddEmployee.h"
#include "BackupEmployee.h"
#include "Update.h"
#include "DeleteEmployee.h"
#include "Manipulate.h"
#include "loadingBar.h"

using namespace std;

vector<string> employeeNamesBackupX;
vector<string> employeeRolesBackupX;
vector<int> employeeIDsBackupX;
vector<double> employeeSalariesBackupX;

void listForAdminOrEmployee() {
    cout << "+=======================================================================+" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|                          | Management System |                        |" << endl;
    cout << "|                                                                       |" << endl;
    cout << "+=======================================================================+" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|  [1]  =>  Admin                                                       |" << endl;
    cout << "|  [2]  =>  Employee                                                    |" << endl;
    cout << "|  [0]  =>  Exit                                                        |" << endl;
    cout << "|                                                                       |" << endl;
    cout << "+=======================================================================+" << endl;
    cout << "|           >>>  Select an option by entering the number  <<<           |" << endl;
    cout << "+=======================================================================+" << endl;
}

void adminMenu() {
    cout << "=========================================================================" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|                                | ADMIN |                              |" << endl;
    cout << "|                                                                       |" << endl;
    cout << "+=======================================================================+" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|  [1]  =>  List Employees                                              |" << endl;
    cout << "|  [2]  =>  Check Attendance of Employees                               |" << endl;
    cout << "|  [3]  =>  Employees Payroll                                           |" << endl;
    cout << "|  [4]  =>  Manipulate Employees                                        |" << endl;
    cout << "|  [5]  =>  Search Employees                                            |" << endl;
    cout << "|  [6]  =>  Profile Management - Setting                                |" << endl;
    cout << "|  [0]  =>  Exit                                                        |" << endl;
    cout << "|                                                                       |" << endl;
    cout << "+=======================================================================+" << endl;
    cout << "|           >>>  Select an option by entering the number  <<<           |" << endl;
    cout << "+=======================================================================+" << endl;
}

void ui() {
    listForAdminOrEmployee();
    short op;
    do {
        cout << "[+] Enter your option : "; cin >> op;
        switch(op) {

            // Admin
            case 1 : {
                getLoadingBar();
                system("cls");
                Login admin1;
                if (admin1.userLogin()) {
                    system("cls");
                    short option;
                    do {
                        adminMenu();
                        cout << "[+] Enter your option : "; cin >> option;
                        switch(option) {
                            case 1 : {
                                ListEmployees employee1a;
                                employee1a.listEmployee();
                                break;
                            }
                            case 2 : {
                                // check attendance employees
                                break;
                            }
                            case 3 : {
                                // paymentroll employee
                                break;
                            }
                            case 4 : {
                                Manipulate employee1d;
                                employee1d.manipulate();
                                break;
                            }
                            case 5 : {
                                SearchEmployee employee1e;
                                employee1e.searchEmployee();
                                break;
                            }
                            case 6 : {
                                // profile - management
                                break;
                            }
                            case 0 : {
                                cout << "Exting..." << endl;
                                break;
                            }
                            default : {
                                cout << "INVALID OPTION!" << endl;
                                break;
                            }
                        }
                    }while(option);
                } 
            }
            
            // Employee
            case 2 : {
                // checkIn, checkOut
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
    }while(op);  
}
  

int main() {
    system("cls");

    ui();

    return 0;
}