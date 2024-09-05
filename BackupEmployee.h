#pragma once 

#include <iostream>
#include <vector>
#include "DeleteEmployee.h"
#include "AddEmployee.h"

using namespace std;

vector<string> employeeNamesBackup;
vector<string> employeeRolesBackup;
vector<int> employeeIDsBackup;
vector<double> employeeSalariesBackup;

class BackupEmployeeData {
    private :
        void listBackupData() {
            for (int i = 0; i < employeeIDsBackup.size(); i++) {
                cout << "Name " << employeeNamesBackup[i] << endl;
                cout << "ID : " << employeeIDsBackup[i] << endl;
                cout << "Role : " << employeeRolesBackup[i] << endl;
                cout << "Salary : " << employeeSalariesBackup[i] << "$" << endl << endl;
            }
        }

        void emptyData() {
            listBackupData();
            char choice;
            cout << "Are you sure you want to empty backup data? [Y/N] : "; cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                employeeNamesBackup.erase(employeeNamesBackup.begin(), employeeNamesBackup.end());
                employeeIDsBackup.erase(employeeIDsBackup.begin(), employeeIDsBackup.end());
                employeeRolesBackup.erase(employeeRolesBackup.begin(), employeeRolesBackup.end());
                employeeSalariesBackup.erase(employeeSalariesBackup.begin(), employeeSalariesBackup.end());
                cout << "Backup data has been successfully emptied." << endl;
            }
            else return;
        }

        void restoreDataByID() {
            int id;
            cout << "[+] Enter employee ID to restore data : "; cin >> id;

            if (id < 0 && id > employeeIDsBackup.size()) {
                auto it = find(employeeIDsBackup.begin(), employeeIDsBackup.end(), id);
                if (it != employeeIDsBackup.end()) {
                    int i = distance(employeeIDsBackup.begin(), employeeIDsBackup.end());
                    employeeNamesBackup.push_back(employeeNamesBackup[i]);
                    employeeIDs.push_back(employeeIDsBackup[i]);
                    employeeRoles.push_back(employeeRolesBackup[i]);
                    employeeSalaries.push_back(employeeSalariesBackup[i]);
                    cout << "Data has been successfully restored." << endl;
                }
                else cout << "Employee with ID " << id << " not found." << endl;
            }
            else cout << "INVALID EMPLOYEE ID!" << endl;  
        }

        void restoreAllData() {
            char choice;
            cout << "Are you sure you want to restore all data? [Y/N] : "; cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                for (int i = 0; i < employeeIDsBackup.size(); i++) {
                    employeeNames.push_back(employeeNamesBackup[i]);
                    employeeIDs.push_back(employeeIDsBackup[i]);
                    employeeRoles.push_back(employeeRolesBackup[i]);
                    employeeSalaries.push_back(employeeSalariesBackup[i]);
                    cout << "Data has been successfully restored." << endl;
                }
            }
            else return;
        }

        public :
            void backupData() {
                
            }

};