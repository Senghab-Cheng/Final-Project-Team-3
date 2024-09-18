#pragma once

#include <iostream>
#include <vector>
#include <algorithm>  // for max_element
#include <fstream>
#include "Globals.h"
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
            cerr << BRIGHT_RED << "Error: Unable to open file employeeNameFile.txt" << RESET << endl;
        }
    }

    void setIDToFile(int id) {
        ofstream file("data/employeeIDFile.txt", ios::app);
        if (file.is_open()) {
            file << id << '\n';
            file.close();
        } else {
            cerr << BRIGHT_RED << "Error: Unable to open file employeeIDFile.txt" << RESET << endl;
        }
    }

    void setPositionToFile(const string& position) {
        ofstream file("data/employeePositionFile.txt", ios::app);
        if (file.is_open()) {
            file << position << '\n';
            file.close();
        } else {
            cerr << BRIGHT_RED << "Error: Unable to open file employeePositionFile.txt" << RESET << endl;
        }
    }

    void setSalaryToFile(double salary) {
        ofstream file("data/employeeSalaryFile.txt", ios::app);
        if (file.is_open()) {
            file << salary << '\n';
            file.close();
        } else {
            cerr << BRIGHT_RED << "Error: Unable to open file employeeSalaryFile.txt" << RESET << endl;
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
            cerr << BRIGHT_RED << "Error: Unable to open file employeeNameFile.txt" << RESET << endl;
        }

        ifstream readID("data/employeeIDFile.txt");
        if (readID.is_open()) {
            employeeIDs.clear();
            while (readID >> employeeID) {
                employeeIDs.push_back(employeeID);
            }
            readID.close();
        } else {
            cerr << BRIGHT_RED << "Error: Unable to open file employeeIDFile.txt" << RESET << endl;
        }

        ifstream readSalary("data/employeeSalaryFile.txt");
        if (readSalary.is_open()) {
            employeeSalaries.clear();
            while (readSalary >> employeeSalary) {
                employeeSalaries.push_back(employeeSalary);
            }
            readSalary.close();
        } else {
            cerr << BRIGHT_RED << "Error: Unable to open file employeeSalaryFile.txt" << RESET << endl;
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
            cerr << BRIGHT_RED << "Error: Unable to open file employeePositionFile.txt" << RESET << endl;
        }
    }

    // Constructor to initialize and read existing data
    AddEmployee() {
        readDataEmployee(); // Read all data to store in vectors
    }

    void setEmployeeData() {
        cout << "+=================================================================================================+" << endl;
        cout << "|                                                                                                 |" << endl;
        cout << "|";cout << LIGHT_PEACH;
        cout << "                                       | SET EMPLOYEE DATA |                                     ";cout << RESET;cout << "|" << endl;
        cout << "|                                                                                                 |" << endl;
        cout << "+=================================================================================================+" << endl;

        // Enter employee name
        cout << CYAN;
        cout << "[+] Enter employee Name: ";
        cout << RESET;
        //cin.ignore(); // To ignore any leftover newline characters from previous input
        cout << LIGHT_GREEN;
        getline(cin, employeeName);
        cout << RESET;
        setNameToFile(employeeName);
        employeeNames.push_back(employeeName);

        // Generate employee ID automatically
        employeeID = generateNextID();
        setIDToFile(employeeID);
        employeeIDs.push_back(employeeID);
        cout << CYAN << "[+] Generated employee ID: " << RESET << LIGHT_GREEN << employeeID <<  RESET << endl;

        // Enter employee position
        cout << CYAN;
        cout << "[+] Enter employee Position: ";
        cout << RESET;
        cout << LIGHT_GREEN;
        getline(cin, employeePosition);
        cout << RESET;
        setPositionToFile(employeePosition);
        employeeRoles.push_back(employeePosition);

        // Enter employee salary
        cout << CYAN << "[+] Enter employee Salary: " << RESET;
        cout << LIGHT_GREEN;
        cin >> employeeSalary;
        cout << RESET;
        getLoadingBar();
        if (isValidSalary(employeeSalary)) {
            setSalaryToFile(employeeSalary);
            cout << LIGHT_GREEN << "Employee added successfully." << RESET << endl;
            employeeSalaries.push_back(employeeSalary);
        } else {
            cerr << BRIGHT_RED << "Error: Invalid salary input." << RESET << endl;
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
