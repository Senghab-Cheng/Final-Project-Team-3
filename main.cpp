#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>

#include "Login.h"
#include "SearchEmployee.h"
#include "ListEmployee.h"
//#include "AddEmployee.h"
#include "BackupEmployee.h"
//#include "Update.h"
//#include "DeleteEmployee.h"
#include "EmployeeManagement.h"
#include "loadingBar.h"
#include "Employee_AttendanceTracker.h"
//#include "QR.h"

using namespace std;

vector<string> employeeNames;
vector<double> employeeSalaries;
vector<int> employeeIDs;
vector<string> employeeRoles;

vector<string> employeeNamesBackupX;
vector<string> employeeRolesBackupX;
vector<int> employeeIDsBackupX;
vector<double> employeeSalariesBackupX;

#define LIGHT_BLUE "\033[38;5;123m"
#define RESET "\033[0m"        // Reset definition

void listForAdminOrEmployee() {
    cout << LIGHT_BLUE;
    cout << "+============================================================================+" << endl;
    cout << "|                                                                            |" << endl;
    cout << "|                          | MANAGEMENT SYSTEM |                             |" << endl;
    cout << "|                                                                            |" << endl;
    cout << "+============================================================================+" << endl;
    cout << "|                                                                            |" << endl;
    cout << "|  [1]  =>  Administrator                                                    |" << endl;
    cout << "|  [2]  =>  Employee Portal                                                  |" << endl;
    cout << "|  [0]  =>  Exit                                                             |" << endl;
    cout << "|                                                                            |" << endl;
    cout << "+============================================================================+" << endl;
    cout << "|               >>>  Please select an option by entering a number  <<<       |" << endl;
    cout << "+============================================================================+" << endl;
    cout << RESET;
}

void adminMenu() {
    cout << "+===========================================================================+" << endl;
    cout << "|                                                                           |" << endl;
    cout << "|                                | ADMIN PANEL |                            |" << endl;
    cout << "|                                                                           |" << endl;
    cout << "+===========================================================================+" << endl;
    cout << "|                                                                           |" << endl;
    cout << "|  [1]  =>  View Employee List                                              |" << endl;
    cout << "|  [2]  =>  Employee Attendance Tracking                                    |" << endl;
    cout << "|  [3]  =>  Employee Management                                             |" << endl;
    cout << "|  [4]  =>  Search for Employees                                            |" << endl;
    cout << "|  [5]  =>  Admin Profile Settings                                          |" << endl;
    cout << "|  [0]  =>  Exit to Main Menu                                               |" << endl;
    cout << "|                                                                           |" << endl;
    cout << "+===========================================================================+" << endl;
    cout << "|            >>>  Please choose an option by entering a number  <<<         |" << endl;
    cout << "+===========================================================================+" << endl;

}

void adminPanel() {
    ifstream adminPanel("adminPanel.txt"); // Open the file for reading

    if(adminPanel.is_open()) {
        string line;
        // Read line by line from the file
        while(getline(adminPanel, line)) {
            cout << LIGHT_BLUE << line << RESET << endl; // Print each line to the console
            this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 100 milliseconds
        }
        adminPanel.close(); // Close the file
    } else {
        cout << "Unable to open the file!" << endl;
    }
}

void ManagementSystem() {
    ifstream employeeManagement("employeeManagement.txt"); // Open the file for reading

    if(employeeManagement.is_open()) {
        string line;
        // Read line by line from the file
        while(getline(employeeManagement, line)) {
            cout << LIGHT_BLUE << line << RESET<< endl; // Print each line to the console
            this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 80 milliseconds
        }
        employeeManagement.close(); // Close the file
    } else {
        cout << "Unable to open the file!" << endl;
    }
}

void ViewEmployeeList() {
   ifstream menuFile("viewEmployeeList.txt"); // Open the file for reading

    if(menuFile.is_open()) {
        string line;
        // Read line by line from the file
        while(getline(menuFile, line)) {
            cout << line << endl; // Print each line to the console
            this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 100 milliseconds
        }
        menuFile.close(); // Close the file
    } else {
        cout << "Unable to open the file!" << endl;
    }
}

void employeeManagement() {
    ifstream employeeManagement("employeeManagement.txt"); // Open the file for reading

    if(employeeManagement .is_open()) {
        string line;
        // Read line by line from the file
        while(getline(employeeManagement, line)) {
            cout << line << endl; // Print each line to the console
            this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 100 milliseconds
        }
        employeeManagement.close(); // Close the file
    } else {
        cout << "Unable to open the file!" << endl;
    }
}

void searchForEmployee() {
    ifstream searchForEmployee("searchForEmployee.txt"); // Open the file for reading

    if(searchForEmployee.is_open()) {
        string line;
        // Read line by line from the file
        while(getline(searchForEmployee, line)) {
            cout << line << endl; // Print each line to the console
            this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 100 milliseconds
        }
        searchForEmployee.close(); // Close the file
    } else {
        cout << "Unable to open the file!" << endl;
    }
}

void adminProfileSetting() {
    ifstream adminProfileSetting("adminProfileSetting.txt"); // Open the file for reading

    if(adminProfileSetting.is_open()) {
        string line;
        // Read line by line from the file
        while(getline(adminProfileSetting, line)) {
            cout << line << endl; // Print each line to the console
            this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 100 milliseconds
        }
        adminProfileSetting.close(); // Close the file
    } else {
        cout << "Unable to open the file!" << endl;
    }
}

void ui() {
    short op;
    do {
    ManagementSystem();
    listForAdminOrEmployee();
        cout << "[+] Enter your option : "; cin >> op;
        switch(op) {

            // Admin
            case 1 : {
                //getLoadingBar();
                system("cls");
                adminPanel();
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
                                employeeManagement();
                                Manipulate employee1d;
                                employee1d.manipulate();
                                break;
                            }
                            case 4 : {
                                searchForEmployee();
                                SearchEmployee employee1e;
                                employee1e.searchEmployee();
                                break;
                            }
                            case 5 : {
                                adminProfileSetting();
                                ProfileSetting p1;
                                p1.profileSettings();
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
                break;
            }
            
            // Employee
            case 2 : {
                system("cls");
                // checkIn, checkOut
                Employee employee1;
                employee1.checkInCheckOut();
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
    //ManagementSystemStyle();
    ui();
    //ViewEmployeeList();
    //employeeManagement();
    //SearchEmployee();
    //adminProfileSetting();

    return 0;
}