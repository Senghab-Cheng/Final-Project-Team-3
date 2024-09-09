#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "Login.h"
#include "SearchEmployee.h"
#include "ListEmployee.h"
#include "AddEmployee.h"
#include "BackupEmployee.h"
#include "Update.h"
#include "DeleteEmployee.h"
#include "EmployeeManagement.h"
#include "loadingBar.h"
#include "Employee.h"

using namespace std;

vector<string> employeeNamesBackupX;
vector<string> employeeRolesBackupX;
vector<int> employeeIDsBackupX;
vector<double> employeeSalariesBackupX;

void listForAdminOrEmployee() {
    cout << "+============================================================================+" << endl;
    cout << "|                                                                            |" << endl;
    cout << "|                          | MANAGEMENT SYSTEM |                             |" << endl;
    cout << "|                                                                            |" << endl;
    cout << "+============================================================================+" << endl;
    cout << "|                                                                            |" << endl;
    cout << "|  [1]  =>  Administrator                                                    |" << endl;
    cout << "|  [2]  =>  Employee Portal                                                  |" << endl;
    cout << "|  [0]  =>  Exit                                                             |" << endl;
    cout << "|                                                                            |" << endl;
    cout << "+============================================================================+" << endl;
    cout << "|               >>>  Please select an option by entering a number  <<<       |" << endl;
    cout << "+============================================================================+" << endl;
}

void adminMenu() {
    cout << "+===========================================================================+" << endl;
    cout << "|                                                                           |" << endl;
    cout << "|                                | ADMIN PANEL |                            |" << endl;
    cout << "|                                                                           |" << endl;
    cout << "+===========================================================================+" << endl;
    cout << "|                                                                           |" << endl;
    cout << "|  [1]  =>  View Employee List                                              |" << endl;
    cout << "|  [2]  =>  Employee Attendance Tracking                                    |" << endl;
    cout << "|  [3]  =>  Employee Payroll Management                                     |" << endl;
    cout << "|  [4]  =>  Employee Management                                             |" << endl;
    cout << "|  [5]  =>  Search for Employees                                            |" << endl;
    cout << "|  [6]  =>  Admin Profile Settings                                          |" << endl;
    cout << "|  [0]  =>  Exit to Main Menu                                               |" << endl;
    cout << "|                                                                           |" << endl;
    cout << "+===========================================================================+" << endl;
    cout << "|            >>>  Please choose an option by entering a number  <<<         |" << endl;
    cout << "+===========================================================================+" << endl;

}

void ui() {
    Login admin1;
    if (admin1.userLogin()) {
        AddEmployee employee1;
        employee1.setEmployeeData();
    }
}

int main() {
    system("cls");

    ui();
    system("pause");
    return 0;
}