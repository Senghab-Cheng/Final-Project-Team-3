#include <iostream>
#include "login.h"
#include "addEmployee.h"
#include "update.h"
#include "searchEmployee.h"

using namespace std;

void list() {
    cout << "==========================" << endl;
    cout << "";
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

    // ui();

    int i,n;
    cout << "[+] Enter number of employee to add : ";
    cin >> n;
    for(i=0; i<n; i++){
        AddEmployee add;
        add.setEmployeeData();
    }
     
    // Login lo;
    // lo.userLogin();

    SearchEmployee sea;
    sea.searchEmployee();

    Update u;
    u.update();
    
    return 0;
}