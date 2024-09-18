#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <conio.h>
#include <Windows.h>

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
vector<double> employeeSalariesBackupX;
vector<int> employeeIDsBackupX;
vector<string> employeeRolesBackupX;

#define LIGHT_BLUE "\033[38;5;123m"
#define BRIGHT_GREEN "\033[38;5;122m"
#define LIGHT_GREEN "\033[92m"
#define LIGHT_PINK "\033[38;5;217m"
#define LIGHT_PEACH "\033[38;5;223m"
#define CYAN "\033[36m"
#define GREEN "\033[38;5;46m"
#define BRIGHT_RED "\033[91m"
#define RESET "\033[0m"        // Reset definition

enum KEY { UP = 72, DOWN = 80, ENTER = 13 }; // Arrow keys and Enter key
void setConsoleTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void listForAdminOrEmployee(int currentSelection, int totalOptions) {
    
    cout << "+=================================================================================================+" << endl;
    cout << "|                                                                                                 |" << endl;
    cout << "|"; cout << LIGHT_PEACH; 
    cout << "                                   >>> MANAGEMENT SYSTEM <<<                                     ";cout << RESET;
    cout << "|" << endl;
    cout << "|                                                                                                 |" << endl;
    cout << "+=================================================================================================+" << endl;
    cout << "|                                                                                                 |" << endl;
   
    string options[] = {
        "Administrator",
        "Employee Portal",
        "Exit"
    };

    for (int i = 0; i < totalOptions; i++) {
            if (i == currentSelection) {
                setConsoleTextColor(15); // Bold (White text on black background)
                cout << "|  =>    " << options[i] << string(62 - options[i].length(), ' ') << "                           |" << endl;
            } else {
                setConsoleTextColor(8); // Normal (Gray text on black background)
                cout << "|        " << options[i] << string(62 - options[i].length(), ' ') << "                           |" << endl;
            }
        }

    setConsoleTextColor(7);
    cout << "|                                                                                                 |" << endl;
    cout << "+=================================================================================================+" << endl;
    cout << "|";cout << LIGHT_GREEN;
    cout << "                          >>>  Select an option by pressing Enter  <<<                           ";cout << RESET;
    cout << "|" << endl;
    cout << "+=================================================================================================+" << endl;
    
}

void adminMenu(int currentSelection, int totalOptions) {
    cout << "+=================================================================================================+" << endl;
    cout << "|                                                                                                 |" << endl;
    cout << "|";cout << LIGHT_PEACH;
    cout << "                                       >>> ADMIN PANEL <<<                                       ";cout << RESET; cout << "|" << endl;
    cout << "|                                                                                                 |" << endl;
    cout << "+=================================================================================================+" << endl;
    cout << "|                                                                                                 |" << endl;
    
    string options[] = {
        "View Employee List",
        "Employee Attencedance Records",
        "Employee Management",
        "Search For Employee",
        "Admin Profile Settings",
        "Exit"
    };
    
    for (int i = 0; i < totalOptions; i++) {
        if (i == currentSelection) {
            setConsoleTextColor(15); // Bold (White text on black background)
            cout << "|  =>    " << options[i] << string(62 - options[i].length(), ' ') << "                           |" << endl;
        } else {
            setConsoleTextColor(8); // Normal (Gray text on black background)
            cout << "|        " << options[i] << string(62 - options[i].length(), ' ') << "                           |" << endl;
        }
    }
    
    setConsoleTextColor(7);

    cout << "|                                                                                                 |" << endl;
    cout << "+=================================================================================================+" << endl;
    cout << "|";cout << LIGHT_GREEN;
    cout << "                          >>>  Select an option by pressing Enter  <<<                           ";cout << RESET;
    cout << "|" << endl;
    cout << "+=================================================================================================+" << endl;


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
        cerr << BRIGHT_RED << "Unable to open the file!" << RESET << endl;
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
        cerr << BRIGHT_RED << "Unable to open the file!" << RESET << endl;
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
        cerr << BRIGHT_RED << "Unable to open the file!" << RESET << endl;
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
        cerr << BRIGHT_RED << "Unable to open the file!" << RESET << endl;
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
        cerr << BRIGHT_RED << "Unable to open the file!" << RESET << endl;
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
        cerr << BRIGHT_RED << "Unable to open the file!" << RESET << endl;
    }
}

void istad() {
    ifstream istad("style/istad.txt"); // Open the file for reading

    if(istad.is_open()) {
        string line;
        // Read line by line from the file
        cout << BRIGHT_GREEN;
        while(getline(istad, line)) {
            cout << line << endl; // Print each line to the console
            //this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 100 milliseconds
        }
        istad.close(); // Close the file
        cout << RESET;
    } else {
        cerr << BRIGHT_RED << "Unable to open the file!" << RESET << endl;
    }
}

void ui() {
    int currentSelection = 0;
    const int totalOptions = 3;
    char key;
    
    while (true) {
        system("cls"); // Clear the console
        istad();
        listForAdminOrEmployee(currentSelection, totalOptions);
        key = _getch(); // Capture key press

        switch(key) {
            case UP: {
                if (currentSelection > 0) currentSelection--; // Move up
                break;
            }
            case DOWN: {
                if (currentSelection < totalOptions - 1) currentSelection++; // Move down
                break;
            }
            case ENTER: {
                system("cls"); // Clear the console before showing the next screen
                if (currentSelection == 0) { // Administrator
                    Login admin1;
                    if (admin1.userLogin()) { // Check if login is successful
                        cout << LIGHT_GREEN << "Login successful. Displaying admin menu..." << RESET << endl; // Debug output
                        getLoadingBar();
                        system("cls"); // Clear the console before showing the admin menu
                        int currentSelection2 = 0;
                        const int totalOptions2 = 6;
                        char key2;
                        bool isExit = 0;
                        while (!isExit) {
                            system("cls");
                            adminMenu(currentSelection2, totalOptions2); // Show admin menu
                            key2 = _getch(); // Capture key press

                            switch(key2) {
                                case UP: {
                                    if (currentSelection2 > 0) currentSelection2--; // Move up
                                    break;
                                }
                                case DOWN: {
                                    if (currentSelection2 < totalOptions2 - 1) currentSelection2++; // Move down
                                    break;
                                }
                                case ENTER: {
                                    switch (currentSelection2) {
                                        case 0: {
                                            ListEmployees emp1;
                                            emp1.listEmployee();
                                            break;
                                        }
                                        case 1: {
                                            Employee empRecords;
                                            empRecords.checkAttendacneRecords();
                                            break;
                                        }
                                        case 2: {
                                            //employeeManagement();
                                            Manipulate emp2;
                                            emp2.manipulate();
                                            break;
                                        }
                                        case 3: {
                                            //searchForEmployee();
                                            //this_thread::sleep_for(chrono::milliseconds(700));
                                            SearchEmployee emp3;
                                            emp3.searchEmployee();
                                            break;
                                        }
                                        case 4: {
                                            //adminProfileSetting();
                                            ProfileSetting emp4;
                                            emp4.profileSettings();
                                            break;
                                        }
                                        case 5: {
                                            //cout << "Exiting..." << endl;
                                            isExit = 1;
                                            break;
                                            //break; // Exit the program
                                        }
                                    }
                                    break;
                                }
                                default:
                                    break; // Ignore other keys
                            }
                            this_thread::sleep_for(chrono::milliseconds(15));    
                            // if (key2 == 5) break; // Break the loop if "Exiting" is selected
                        }
                    } else {
                        cout << BRIGHT_RED << "Login failed. Please try again." << RESET << endl;
                        this_thread::sleep_for(chrono::seconds(2)); // Pause before retry
                    }
                } else if (currentSelection == 1) { // Employee Portal
                    Employee emp;
                    emp.checkInCheckOut();
                } else if (currentSelection == 2) { // Exit
                    cout << "Exiting..." << endl;
                    return; // Exit the program
                }
                break;
            }
            default:
                break; // Ignore other keys
        }
        // Add a small delay to ensure the console has time to update
        this_thread::sleep_for(chrono::milliseconds(15));
    }
}

int main() {
    system("cls");
    //ManagementSystemStyle();
    ui();
    //ViewEmployeeList();
    //employeeManagement();
    //SearchEmployee();
    //adminProfileSetting();
    // Employee empRecord;
    // empRecord.checkAttendanceRecords();
    // ProfileSetting emp;
    // emp.profileSettings();

    return 0;
}