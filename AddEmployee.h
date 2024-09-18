#pragma once

#include <iostream>
#include <vector>
#include <algorithm>  // for max_element
#include <fstream>
#include "Globals.h"

using namespace std;

// Vectors holding employee data
extern vector<string> employeeNames;
extern vector<double> employeeSalaries;
extern vector<int> employeeIDs;
extern vector<string> employeeRoles;

class AddEmployee {
private:
    string employeeName;
    int employeeID;
    double employeeSalary;
    string employeePosition;

    // Function to generate the next ID
    int generateNextID() {
        if (employeeIDs.empty()) {
            return 1; // Start from 1 if no IDs exist
        }
        return *max_element(employeeIDs.begin(), employeeIDs.end()) + 1;
    }

    // Functions to write data to files
    void setNameToFile(const string& name) {
        ofstream file("data/employeeNameFile.txt", ios::app);
        if (file.is_open()) {
            file << name << '\n';
            file.close();
        } else {
            cerr << "Error: Unable to open file employeeNameFile.txt" << endl;
        }
    }

    void setIDToFile(int id) {
        ofstream file("data/employeeIDFile.txt", ios::app);
        if (file.is_open()) {
            file << id << '\n';
            file.close();
        } else {
            cerr << "Error: Unable to open file employeeIDFile.txt" << endl;
        }
    }

    void setPositionToFile(const string& position) {
        ofstream file("data/employeePositionFile.txt", ios::app);
        if (file.is_open()) {
            file << position << '\n';
            file.close();
        } else {
            cerr << "Error: Unable to open file employeePositionFile.txt" << endl;
        }
    }

    void setSalaryToFile(double salary) {
        ofstream file("data/employeeSalaryFile.txt", ios::app);
        if (file.is_open()) {
            file << salary << '\n';
            file.close();
        } else {
            cerr << "Error: Unable to open file employeeSalaryFile.txt" << endl;
        }
    }

    // Function to validate salary input
    bool isValidSalary(double salary) {
        return salary >= 0; // Example validation: Salary should be non-negative
    }

public:
    // Function to read data from files and populate vectors
    void readDataEmployee() {
        ifstream readName("data/employeeNameFile.txt");
        if (readName.is_open()) {
            employeeNames.clear();
            while (getline(readName, employeeName)) {
                if (!employeeName.empty()) {
                    employeeNames.push_back(employeeName);
                }
            }
            readName.close();
        } else {
            cerr << "Error: Unable to open file employeeNameFile.txt" << endl;
        }

        ifstream readID("data/employeeIDFile.txt");
        if (readID.is_open()) {
            employeeIDs.clear();
            while (readID >> employeeID) {
                employeeIDs.push_back(employeeID);
            }
            readID.close();
        } else {
            cerr << "Error: Unable to open file employeeIDFile.txt" << endl;
        }

        ifstream readSalary("data/employeeSalaryFile.txt");
        if (readSalary.is_open()) {
            employeeSalaries.clear();
            while (readSalary >> employeeSalary) {
                employeeSalaries.push_back(employeeSalary);
            }
            readSalary.close();
        } else {
            cerr << "Error: Unable to open file employeeSalaryFile.txt" << endl;
        }

        ifstream readPosition("data/employeePositionFile.txt");
        if (readPosition.is_open()) {
            employeeRoles.clear();
            while (getline(readPosition, employeePosition)) {
                if (!employeePosition.empty()) {
                    employeeRoles.push_back(employeePosition);
                }
            }
            readPosition.close();
        } else {
            cerr << "Error: Unable to open file employeePositionFile.txt" << endl;
        }
    }

    // Constructor to initialize and read existing data
    AddEmployee() {
        readDataEmployee(); // Read all data to store in vectors
    }

    void setEmployeeData() {
        cout << "+============================================================================+" << endl;
        cout << "|                                                                            |" << endl;
        cout << "|                          | SET EMPLOYEE DATA |                             |" << endl;
        cout << "|                                                                            |" << endl;
        cout << "+============================================================================+" << endl;

        // Enter employee name
        cout << "[+] Enter employee Name: ";
        cin.ignore(); // To ignore any leftover newline characters from previous input
        getline(cin, employeeName);
        setNameToFile(employeeName);
        employeeNames.push_back(employeeName);

        // Generate employee ID automatically
        employeeID = generateNextID();
        setIDToFile(employeeID);
        employeeIDs.push_back(employeeID);
        cout << "[+] Generated employee ID: " << employeeID << endl;

        // Enter employee position
        cout << "[+] Enter employee Position: ";
        getline(cin, employeePosition);
        setPositionToFile(employeePosition);
        employeeRoles.push_back(employeePosition);

        // Enter employee salary
        cout << "[+] Enter employee Salary: ";
        cin >> employeeSalary;
        if (isValidSalary(employeeSalary)) {
            setSalaryToFile(employeeSalary);
            cout << "Employee added successfully." << endl;
            employeeSalaries.push_back(employeeSalary);
        } else {
            cerr << "Error: Invalid salary input." << endl;
        }
            system("pause");
    }

    // Update employee salary in the file
    void updateSalaryInFile(int index, double newSalary) {
        ifstream fileIn("data/employeeSalaryFile.txt");
        ofstream fileOut("data/tempSalaryFile.txt");
        string line;
        int currentIndex = 0;
        while (getline(fileIn, line)) {
            if (currentIndex == index) {
                fileOut << newSalary << '\n';
            } else {
                fileOut << line << '\n';
            }
            currentIndex++;
        }
        fileIn.close();
        fileOut.close();
        rename("data/tempSalaryFile.txt", "data/employeeSalaryFile.txt");
    }

    // Update employee role in the file
    void updateRoleInFile(int index, const string& newRole) {
        ifstream fileIn("data/employeePositionFile.txt");
        ofstream fileOut("data/tempPositionFile.txt");
        string line;
        int currentIndex = 0;
        while (getline(fileIn, line)) {
            if (currentIndex == index) {
                fileOut << newRole << '\n';
            } else {
                fileOut << line << '\n';
            }
            currentIndex++;
        }
        fileIn.close();
        fileOut.close();
        rename("data/tempPositionFile.txt", "data/employeePositionFile.txt");
    }
};
