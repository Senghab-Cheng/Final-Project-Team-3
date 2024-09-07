#pragma once

#include <iostream>
#include <vector>




std::vector<std::string> employeeNames {"Senghab Cheng", "Pech Rattanakmony", "Thouern Chanthat", "Phorn Sotheara", "Ey Channim", "Chheng Panharath"};
std::vector<double> employeeSalaries {2300.5, 2200.75, 3100.25, 2575.25, 2785.75, 2200.5};
std::vector<int> employeeIDs {1, 2, 3, 4, 5, 6};
std::vector<std::string> employeeRoles {"Manager", "Manager", "Cyber Security", "Cyber Security", "Developer", "Developer"};

class AddEmployee {
private:
    std::string employeeName;
    int employeeID;
    double employeeSalary;
    std::string employeeRole;

public:
    void setEmployeeData() {
        std::cout << "[+] Enter employee's name : ";
        std::getline(std::cin, this->employeeName);
        employeeNames.push_back(this->employeeName);

        std::cout << "[+] Enter employee's ID : ";
        std::cin >> this->employeeID;
        employeeIDs.push_back(this->employeeID);

        std::cout << "[+] Enter employee's role : ";
        std::cin.ignore();
        std::getline(std::cin, this->employeeRole);
        employeeRoles.push_back(this->employeeRole);

        std::cout << "[+] Enter employee's salary : ";
        std::cin >> this->employeeSalary;
        employeeSalaries.push_back(this->employeeSalary);
    }
};