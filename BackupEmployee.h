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

class BackupDataFunctions {
    public : 
        virtual void listBackupData() = 0;
        virtual void emptyData() = 0;
        virtual void restoreDataByID() = 0;
        virtual void restoreAllData() = 0;
};

class BackupEmployeeData : private BackupDataFunctions{
    private :
        void listBackupData() override{
            for (int i = 0; i < employeeIDsBackup.size(); i++) {
                cout << "Name " << employeeNamesBackup[i] << endl;
                cout << "ID : " << employeeIDsBackup[i] << endl;
                cout << "Role : " << employeeRolesBackup[i] << endl;
                cout << "Salary : " << employeeSalariesBackup[i] << "$" << endl << endl;
            }
        }

        void emptyData() override{
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

        void restoreDataByID() override{
            listBackupData();
            int id;
            cout << "[+] Enter the employee ID to restore the data : "; cin >> id;

            if (id > 0 && id <= employeeIDsBackup.size()) {
                auto it = find(employeeIDsBackup.begin(), employeeIDsBackup.end(), id);
                if (it != employeeIDsBackup.end()) {
                    int i = distance(employeeIDsBackup.begin(), employeeIDsBackup.end());
                    employeeNames.push_back(employeeNamesBackup[i]);
                    employeeIDs.push_back(employeeIDsBackup[i]);
                    employeeRoles.push_back(employeeRolesBackup[i]);
                    employeeSalaries.push_back(employeeSalariesBackup[i]);
                    cout << "Data has been successfully restored." << endl;
                }
                else cout << "Employee with ID " << id << " not found." << endl;
            }
            else cout << "INVALID EMPLOYEE ID!" << endl;  
        }

        void restoreAllData() override{
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

        void listMenuBackupData() {
            cout << "=========================================================================" << endl;
            cout << ">                            | Backup Data |                            <" << endl;
            cout << ">>=====================================================================<<" << endl;
            cout << ">>>                                                                   <<<" << endl;
            cout << ">>>>                      1. Restore Data by ID                      <<<<" << endl;
            cout << ">>>>>                     2. Restore All Data                       <<<<<" << endl;
            cout << ">>>>                      3. Empty Data                              <<<<" << endl;
            cout << ">>>                       0. Exit                                     <<<" << endl;
            cout << ">>                                                                     <<" << endl;
            cout << ">                                                                       <" << endl;
            cout << "=========================================================================" << endl;
        }

        public :

            void backupData() {
                short option;
                do {        
                    listBackupData();
                    cout << "[+] Enter your option : "; cin >> option;

                    switch(option) {
                        case 1 : {
                            system("cls");
                            restoreDataByID();
                            break;
                        }
                        case 2 : {
                            system("cls");
                            restoreAllData();
                            break;
                        }
                        case 3 : {
                            system("cls");
                            emptyData();
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

                } while (option);
            }
};