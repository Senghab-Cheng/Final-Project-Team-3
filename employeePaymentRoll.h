#pragma once
#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    double baseSalary;
    int attendanceDays;
    int overtimeHours;
    double bonus;

public:
    Employee(string empName, double salary, int days, int overtime, double empBonus) {
        name = empName;
        baseSalary = salary;
        attendanceDays = days;
        overtimeHours = overtime;
        bonus = empBonus;
    }

    double calculateSalary() {
        double dailyRate = baseSalary / 30;  
        double attendanceSalary = dailyRate * attendanceDays;
        double overtimePay = overtimeHours * (dailyRate / 8);  
        double bonus = (attendanceDays / 100) * baseSalary;
        return attendanceSalary + overtimePay + bonus;
    }

    void displaySalary() {
        cout << "Employee: " << name << endl;
        cout << "Base Salary: $" << baseSalary << endl;
        cout << "Attendance Days: " << attendanceDays << endl;
        cout << "Overtime Hours: " << overtimeHours << endl;
        cout << "Bonus: $" << bonus << endl;
        cout << "Total Salary: $" << calculateSalary() << endl << endl;
    }
};

void test() {
    string empName;
    double salary;
    int days, overtime;
    double empBonus = 0.0;  

    cout << "Enter employee name: ";
    getline(cin, empName);
    cout << "Enter base salary: ";
    cin >> salary;
    cin.ignore();  
    cout << "Enter attendance days: ";
    cin >> days;
    cin.ignore();  
    cout << "Enter overtime hours: ";
    cin >> overtime;
    cin.ignore(); 
    cout << "Enter bonus: " << empBonus << endl;
    cin >> empBonus;
    cin.ignore();

    
    Employee emp1(empName, salary, days, overtime, empBonus);

   
    emp1.displaySalary();

}