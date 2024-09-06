#include <iostream>
#include <string>
#include <vector>

#include "Login.h"
#include "AddEmployee.h"
#include "SearchEmployee.h"
#include "DeleteEmployee.h"
#include "Update.h"
#include "ListEmployee.h"
#include "BackupEmployee.h"

using namespace std;

void listForAdminOrEmployee() {
    cout << "=========================================================================" << endl;
    cout << ">                          | Management System |                        <" << endl;
    cout << ">>=====================================================================<<" << endl;
    cout << ">>>                                                                   <<<" << endl;
    cout << ">>>>                                                                 <<<<" << endl;
    cout << ">>>>>                          1. Admin                             <<<<<" << endl;
    cout << ">>>>                           2. Employee                           <<<<" << endl;
    cout << ">>>                            0. Exit                                <<<" << endl;
    cout << ">>                                                                     <<" << endl;
    cout << ">                                                                       <" << endl;
    cout << "=========================================================================" << endl;
}

void listMenu() {
    cout << "=========================================================================" << endl;
    cout << ">                                | MENU |                               <" << endl;
    cout << ">>=====================================================================<<" << endl;
    cout << ">>>                  1. List Employees                                <<<" << endl;
    cout << ">>>>                 2. Check Attendance of Employees                <<<<" << endl;
    cout << ">>>>>                3. Employees Payroll                           <<<<<" << endl;
    cout << ">>>>                 4. Manipulate Employees                         <<<<" << endl;
    cout << ">>>                  5. Search Employees                              <<<" << endl;
    cout << ">>                   6. Profile Management - Setting                   <<" << endl;
    cout << ">                    0. Exit                                            <" << endl;
    cout << "=========================================================================" << endl;
}

void ui() {
    Login admin1;
    if (admin1.userLogin()) {
        system("cls");
        // AddEmployee employee1;
        // employee1.setEmployeeData();
        DeleteEmployee employee1c;
        employee1c.manage(); 
        
        SearchEmployee employee1a;
        employee1a.searchEmployee();


        // ListEmployees employee1b;
        // //employee1b.listRoles();   
        // employee1b.listEmployee();
    }
}

int main() {
    system("cls");

    ui();

    return 0;
}