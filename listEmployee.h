#pragma ocne 

#include <iostream>
#include <string>

using namespace std;

class ListEmployee{
    virtual void listEmployeeByPart() = 0;
    virtual void listAllEmployees() = 0;
};

class ListEmployeeByPart : public ListEmployee {
    private :
        string list;

    public :
        void listEmployeeByPart() override {
            cout << "[+] Enter employees' role : ";
        }

};