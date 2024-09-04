
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Admin{
    private :
        string username = "ABC";
        string email = "abc123@gmail.com";
        string password = "12345";
        string bio = "No idea";
        string tel = "0123456789";
        string telegram = "ABC";
        string gitHub = "abc123";

    public :
         int id;
        string name;
        string role;
        float  salary;
    
        string getUsername() {
            return username;
        }
        string getEmail() {
            return email;
        }
        string getPassword() {
            return password;
        }
        string getBio() {
            return bio;
        }
        string getTel() {
            return tel;
        }
        string getTelegram() {
            return telegram;
        }
        string getGitHub() {
            return gitHub;
        }
};

vector<Admin> employees;
void insertEmployee() {
    cout << "=====|[+] Add Employee |=======" << endl;
    Admin employee;
    cout << "Enter employee ID: ";
    cin >> employee.id;
    cin.ignore(); // Clear the input buffer
    cout << "Enter employee name: ";
    getline(cin, employee.name);
    cout << "Enter employee role: ";
    getline(cin, employee.role);
    cout<<"Enter employee salary: ";
    cin>>employee.salary;
    employees.push_back(employee);
    cout << "Employee inserted successfully!" << endl;
}

int main(){
    system("cls");
    system("color a");
    insertEmployee();

    return 0;
}

