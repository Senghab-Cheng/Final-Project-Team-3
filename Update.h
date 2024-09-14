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
    }

    void listForUpdate() {
        cout << "+==============================================================================+" << endl;
        cout << "|                            >>>  UPDATE EMPLOYEE  <<<                         |" << endl;
        cout << "+==============================================================================+" << endl;
        cout << "|  [1]  =>  Update Salary                                                      |" << endl;
        cout << "|  [2]  =>  Update Position                                                    |" << endl;
        cout << "|  [0]  =>  Exit                                                               |" << endl;
        cout << "+==============================================================================+" << endl;
        cout << "|                 >>>  Select an option by entering the number  <<<            |" << endl;
        cout << "+==============================================================================+" << endl;
    }

public:
    // Function to handle the update options
    void update() {
        readEmployeeData(); // Read data before updating
        short option;
        do {
            listForUpdate();
            cout << "[+] Enter your option: ";
            cin >> option;

            switch (option) {
                case 1: {
                    updateSalary();
                    break;
                }
                case 2: {
                    updateRole();
                    break;
                }
                case 0: {
                    cout << "Exiting..." << endl;
                    break;
                }
                default: {
                    cout << "INVALID OPTION!" << endl;
                    break;
                }
            }
        } while (option != 0);
    }
};
