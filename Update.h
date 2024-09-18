#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

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
            cerr << "Error: One or more files could not be opened." << endl;
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
            cerr << "Error: Unable to open file employeeSalaryFile.txt" << endl;
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
            cerr << "Error: Unable to open file employeePositionFile.txt" << endl;
        }
    }

    // Function to update salary
    void updateSalary() {
        int id;
        cout << "[+] Enter employee ID: ";
        cin >> id;

        int index = findEmployeeIndexById(id);
        if (index != -1) {
            cout << "[+] Enter employee new Salary: ";
            cin >> employeeSalaries[index]; // Update in vector
            writeSalariesToFile(); // Write updated vector to file
            cout << "Employee with ID " << id << " updated successfully." << endl;
        } else {
            cout << "Employee with ID " << id << " is not found." << endl;
        }
        system("pause");
    }

    // Function to update role
    void updateRole() {
        int id;
        cout << "[+] Enter employee ID: ";
        cin >> id;

        int index = findEmployeeIndexById(id);
        if (index != -1) {
            cout << "[+] Enter employee new Position: ";
            cin.ignore(); // Ignore any newline characters
            getline(cin, employeeRoles[index]); // Update in vector
            writeRolesToFile(); // Write updated vector to file
            cout << "Employee with ID " << id << " updated successfully." << endl;
        } else {
            cout << "Employee with ID " << id << " is not found." << endl;
        }
        system("pause");
    }

    enum KEY { UP = 72, DOWN = 80, ENTER = 13 }; // Arrow keys and Enter key

    void setConsoleTextColor(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    void listForUpdate(int currentSelection, int totalOptions) {
        system("cls");
        cout << "+==============================================================================+" << endl;
        cout << "|                                                                              |" << endl;
        cout << "|                            >>>  UPDATE EMPLOYEE  <<<                         |" << endl;
        cout << "|                                                                              |" << endl;
        cout << "+==============================================================================+" << endl;
        cout << "|                                                                              |" << endl;
        
        string options[] = {
            "Update Employee Salary",
            "Update Employee Position",
            "Exit"
        };
        
        for (int i = 0; i < totalOptions; i++) {
            if (i == currentSelection) {
                setConsoleTextColor(15); // Bold (White text on black background)
                cout << "|  =>  " << options[i] << string(62 - options[i].length(), ' ') << "            |" << endl;
            } else {
                setConsoleTextColor(8); // Normal (Gray text on black background)
                cout << "|      " << options[i] << string(62 - options[i].length(), ' ') << "            |" << endl;
            }
        }

        setConsoleTextColor(7); // Reset to normal color
        cout << "|                                                                              |" << endl;
        cout << "+==============================================================================+" << endl;
        cout << "|                 >>>  Select an option by pressing Enter  <<<                 |" << endl;
        cout << "+==============================================================================+" << endl;
    }

public:
    // Function to handle the update options
    void update() {
        readEmployeeData(); // Read data before updating
        int currentSelection = 0;
        const int totalOptions = 3;
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
                        case 2: {
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
