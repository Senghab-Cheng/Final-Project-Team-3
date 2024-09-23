#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "loadingBar.h"

using namespace std;

#define LIGHT_BLUE "\033[38;5;123m"
#define BRIGHT_GREEN "\033[38;5;122m"
#define LIGHT_GREEN "\033[92m"
#define LIGHT_PINK "\033[38;5;217m"
#define LIGHT_PEACH "\033[38;5;223m"
#define CYAN "\033[36m"
#define GREEN "\033[38;5;46m"
#define BRIGHT_RED "\033[91m"
#define RESET "\033[0m"        // Reset definition

// Assuming global vectors
extern vector<string> employeeNames;
extern vector<double> employeeSalaries;
extern vector<int> employeeIDs;
extern vector<string> employeeRoles;

class Update {
private:
    // Function to read all employee data from files
    void readEmployeeData() {
        ifstream idFile("data/employeeIDFile.txt");
        ifstream nameFile("data/employeeNameFile.txt");
        ifstream salaryFile("data/employeeSalaryFile.txt");
        ifstream roleFile("data/employeePositionFile.txt");

        if (!idFile || !nameFile || !salaryFile || !roleFile) {
            cerr << BRIGHT_RED << "Error: One or more files could not be opened." << RESET << endl;
            return;
        }

        employeeIDs.clear();
        employeeNames.clear();
        employeeSalaries.clear();
        employeeRoles.clear();

        int id;
        double salary;
        string name, role;

        while (idFile >> id && getline(nameFile, name) && salaryFile >> salary && getline(roleFile, role)) {
            employeeIDs.push_back(id);
            employeeNames.push_back(name);
            employeeSalaries.push_back(salary);
            employeeRoles.push_back(role);
        }

        idFile.close();
        nameFile.close();
        salaryFile.close();
        roleFile.close();
    }

    // Function to find index by employee ID
    int findEmployeeIndexById(int id) {
        auto it = find(employeeIDs.begin(), employeeIDs.end(), id);
        if (it != employeeIDs.end()) {
            return distance(employeeIDs.begin(), it); // Return index if found
        } else {
            return -1; // Return -1 if not found
        }
    }

    // Function to write all salaries back to the file after an update
    void writeSalariesToFile() {
        ofstream file("data/employeeSalaryFile.txt");
        if (file.is_open()) {
            for (double salary : employeeSalaries) {
                file << salary << '\n';
            }
            file.close();
        } else {
            cerr << BRIGHT_RED << "Error: Unable to open file employeeSalaryFile.txt" << RESET << endl;
        }
    }

    // Function to write all roles back to the file after an update
    void writeRolesToFile() {
        ofstream file("data/employeePositionFile.txt");
        if (file.is_open()) {
            for (const string& role : employeeRoles) {
                file << role << '\n';
            }
            file.close();
        } else {
            cerr << BRIGHT_RED << "Error: Unable to open file employeePositionFile.txt" << RESET << endl;
        }
    }

    void writeNameToFile() {
        ofstream file("data/employeeNameFile.txt");
        if (file.is_open()) {
            for (const string& name : employeeNames) {
                file << name << '\n';
            }
            file.close();
        }
        else 
            cerr << BRIGHT_RED << "Error : Unable to open file employeeNameFile.txt" << RESET << endl;
    }

    // Function to update salary
    void updateSalary() {
        int id;
        cout << CYAN << "[+] Enter employee ID: " << RESET;
        cout << LIGHT_GREEN;
        cin >> id;
        cout << RESET;

        int index = findEmployeeIndexById(id);
        getLoadingBar();
        if (index != -1) {
            cout << CYAN << "[+] Enter employee new Salary: " << RESET;
            cout << LIGHT_GREEN;
            cin >> employeeSalaries[index]; // Update in vector
            cout << RESET;
            writeSalariesToFile(); // Write updated vector to file
            cout << LIGHT_GREEN << "Employee with ID " << id << " updated successfully." << RESET << endl;
        } else {
            cout << BRIGHT_RED << "Employee with ID " << id << " is not found." << RESET << endl;
        }
        system("pause");
    }

    // Function to update role
    void updateRole() {
        int id;
        cout << CYAN << "[+] Enter employee ID: " << RESET;
        cout << LIGHT_GREEN;
        cin >> id;
        cout << RESET;
        int index = findEmployeeIndexById(id);
        getLoadingBar();
        if (index != -1) {
            cout << CYAN << "[+] Enter employee new Position: " << RESET;
            cin.ignore(); // Ignore any newline characters
            cout << LIGHT_GREEN;
            getline(cin, employeeRoles[index]); // Update in vector
            cout << RESET;
            writeRolesToFile(); // Write updated vector to file
            cout << LIGHT_GREEN << "Employee with ID " << id << " updated successfully." << RESET << endl;
        } else {
            cout << BRIGHT_RED << "Employee with ID " << id << " is not found." << RESET << endl;
        }
        system("pause");
    }

    // function update name
    void updateName() {
        int id;
        cout << CYAN << "[+] Enter employee ID: " << RESET;
        cout << LIGHT_GREEN;
        cin >> id;
        cout << RESET;

        int index = findEmployeeIndexById(id);
        getLoadingBar();
        if (index != -1) {
            cin.ignore();
            cout << CYAN << "[+] Enter employee new Name: " << RESET;
            cout << LIGHT_GREEN;
            cin >> employeeNames[index]; // Update in vector
            cout << RESET;
            writeNameToFile(); // Write updated vector to file
            cout << LIGHT_GREEN << "Employee with ID " << id << " updated successfully." << RESET << endl;
        } else {
            cout << BRIGHT_RED << "Employee with ID " << id << " is not found." << RESET << endl;
        }
        system("pause");
    } 

    enum KEY { UP = 72, DOWN = 80, ENTER = 13 }; // Arrow keys and Enter key

    void setConsoleTextColor(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    void listForUpdate(int currentSelection, int totalOptions) {
        system("cls");
        cout << "+=================================================================================================+" << endl;
        cout << "|                                                                                                 |" << endl;
        cout << "|";cout << LIGHT_PEACH;
        cout << "                                     >>>  UPDATE EMPLOYEE  <<<                                   ";cout << RESET;cout << "|" << endl;
        cout << "|                                                                                                 |" << endl;
        cout << "+=================================================================================================+" << endl;
        cout << "|                                                                                                 |" << endl;
        
        string options[] = {
            "Update Employee Salary",
            "Update Employee Job Title",
            "Update Employee Name",
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

        setConsoleTextColor(7); // Reset to normal color
        cout << "|                                                                                                 |" << endl;
        cout << "+=================================================================================================+" << endl;
        cout << "|";cout << LIGHT_GREEN;
        cout << "                          >>>  Select an option by pressing Enter  <<<                           ";cout << RESET;
        cout << "|" << endl;
        cout << "+=================================================================================================+" << endl;
    }

public:
    // Function to handle the update options
    void update() {
        readEmployeeData(); // Read data before updating
        int currentSelection = 0;
        const int totalOptions = 4;
        char key;
        do {
            listForUpdate(currentSelection, totalOptions);
            key = _getch(); // Capture key press
            switch (key) {
                case UP:
                    if (currentSelection > 0) currentSelection--; // Move up
                    break;
                case DOWN:
                    if (currentSelection < totalOptions - 1) currentSelection++; // Move down
                    break;
                case ENTER:
                    switch (currentSelection) {
                        case 0: {
                            updateSalary();
                            break;
                        }
                        case 1: {
                            updateRole();
                            break;
                        }
                        case 2 : {
                            updateName();
                            break;
                        }
                        case 3: {
                            //cout << "Exiting..." << endl;
                            return; // Exit the function when "Exit" is selected
                        }
                    }
                    break;
            }
        this_thread::sleep_for(chrono::milliseconds(20));    
        } while (true); // Loop until "Exit" is selected and Enter is pressed
    }
};
