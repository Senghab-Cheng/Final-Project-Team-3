#pragma once

#include <iostream>
#include <vector>
#include "AddEmployee.h"
#include "AdminInfo.h"

using namespace std;

class Update{
    private :
            void updateSalary(){
                int id;
                cout << "[+] Enter employee's id : ";
                cin >> id;
                for (int i=0; i<employeeIDs.size(); i++){
                    if(id == employeeIDs[i]){
                        cout << "[+] Enter employee's new salary : ";
                        cin >> employeeSalaries[i];
                        cout << "Employee with ID " << id << " updated successfully." << endl;
                    }else{
                        cout << "Employee with ID " << id << "is not found.";
                    }
                }
            }

            void updateRole(){
                int id;
                cout << "[+] Enter employee's id : ";
                cin >> id;
                for (int i=0; i<employeeIDs.size(); i++){
                    if(id == employeeIDs[i]){
                        cout << "[+] Enter employee's new role : ";
                        cin >> employeeRoles[i];
                        cout << "Employee with ID " << id << " updated successfully." << endl;
                        break;
                    }else{
                        cout << "Employee with ID " << id << "is not found.";
                    }
                }
            } 

    public : 
            
            void update(){
                short option;
                do{
                //int option;
                    cout << "Select one to update" << endl;
                    cout << "1.Update Salary" << endl;
                    cout << "2.Update Role" << endl;
                    cout << "0.Exit"<< endl;
                    cout << "[+] Enter your option : ";
                    cin >> option;

                    switch(option){
                        case 1 :{
                            updateSalary();
                            break;
                        }
                        case 2 :{
                            updateRole();
                            break;
                        }
                        case 0: {
                            cout << "Exiting..." << endl;
                            break;
                        }
                        default : {
                            cout << "INVALID OPTION!" << endl;
                            break;
                        }
                    }
                } while(option);
            }
};