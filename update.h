#pragma once

#include <iostream>
#include <vector>
#include "addEmployee.h"
#include "userInfo.h"

using namespace std;

class Update{
    public : 
            void updateSalary(){
                int id;
                cout << "[+] Enter employee's id : ";
                cin >> id;
                for (int i=0; i<employeeIDs.size(); i++){
                    if(id == employeeIDs[i]){
                        cout << "[+] Enter new salary : ";
                        cin >> employeeSalaries[i];
                    }else{
                        cout << "This Id not found...";
                    }
                }
            }

            void updateRole(){
                int id;
                cout << "[+] Enter employee's id : ";
                cin >> id;
                for (int i=0; i<employeeIDs.size(); i++){
                    if(id == employeeIDs[i]){
                        cout << "[+] Enter new role : ";
                        cin >> employeeRoles[i];
                    }else{
                        cout << "This Id not found...";
                    }
                }
            } 

            void update(){
                short option;
             do{
             //int option;
             cout << "Select one to update" << endl;
             cout << "1.Update Salary" << endl;
             cout << "2.Update Role" << endl;
             cout << "0.exit..."<< endl;
             cout << "[+] Enter your option here : ";
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
                    cout << "exit..." << endl;
                }
                default : {
                    cout << "Invalid option..." << endl;
                    break;
                }
              }
             }while(option);
            }
};