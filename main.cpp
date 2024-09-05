#include <iostream>
#include "login.h"
#include "addEmployee.h"
#include "searchEmployee.h"

using namespace std;

void list() {
    cout << "===========================================================" << endl;
    cout << "";
}

void ui() {
    Login admin1;
    if (admin1.userLogin()) {
        system("cls");
        // AddEmployee employee1;
        // employee1.setEmployeeData();
        SearchEmployee employee1a;
        employee1a.searchEmployee();
    }
}

int main() {
    system("cls");

    ui();

    return 0;
}