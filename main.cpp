#include <iostream>
#include "login.h"
#include "addEmployee.h"
#include "DeleteEmployee.h"

using namespace std;

void list() {
    cout << "===========================================================" << endl;
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

    ui();

    return 0;
}