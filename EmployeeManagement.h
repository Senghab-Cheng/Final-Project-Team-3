#pragma once 

#include <iostream>
#include "BackupEmployee.h"
#include "AddEmployee.h"
#include "DeleteEmployee.h"
#include "Update.h"

using namespace std;

class Manipulate{
    private :
        enum KEY { UP = 72, DOWN = 80, ENTER = 13 }; // Arrow keys and Enter key

        void setConsoleTextColor(int color) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        }
        void listManipulate(int currentSelection, int totalOptions) {
            system("cls");
            cout << "+===========================================================================+" << endl;
            cout << "|                                                                           |" << endl;
            cout << "|                          | EMPLOYEE MANAGEMENT |                          |" << endl;
            cout << "|                                                                           |" << endl;
            cout << "+===========================================================================+" << endl;
            cout << "|                                                                           |" << endl;
            
            string options[] = {
                "Add New Employee",
                "Update Existing Employee",
                "Remove Employee",
                "Backup Employee",
                "Exit"
            };
            
            for (int i = 0; i < totalOptions; i++) {
                if (i == currentSelection) {
                    setConsoleTextColor(15); // Bold (White text on black background)
                    cout << "|  =>  " << options[i] << string(62 - options[i].length(), ' ') << "       |" << endl;
                } else {
                    setConsoleTextColor(8); // Normal (Gray text on black background)
                    cout << "|      " << options[i] << string(62 - options[i].length(), ' ') << "       |" << endl;
                }
            }

            setConsoleTextColor(7); // Reset to normal color
            cout << "|                                                                           |" << endl;
            cout << "+===========================================================================+" << endl;
            cout << "|           >>>  Please choose an option by entering a number  <<<          |" << endl;
            cout << "+===========================================================================+" << endl;
        }

        void addEmployee() {
            ifstream addEmployee("addNewEmployee.txt"); // Open the file for reading

            if(addEmployee.is_open()) {
                string line;
                // Read line by line from the file
                while(getline(addEmployee, line)) {
                    cout << line << endl; // Print each line to the console
                    this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 100 milliseconds
                }
                addEmployee.close(); // Close the file
            } else {
                cout << "Unable to open the file!" << endl;
            }
        }

    public :
        void manipulate() {
            int currentSelection = 0;
            const int totalOptions = 5;
            do {
                listManipulate(currentSelection, totalOptions);
                char key = _getch();
                switch (key) {
                    case UP:
                        if (currentSelection > 0) currentSelection--; // Move up
                        break;
                    case DOWN:
                        if (currentSelection < totalOptions - 1) currentSelection++; // Move down
                        break;
                    case ENTER:
                        switch (currentSelection) {
                            case 0: {
                                AddEmployee emp1;
                                emp1.setEmployeeData();
                                break;
                            }
                            case 1: {
                                Update emp2;
                                emp2.update();
                                break;
                            }
                            case 2: {
                                DeleteEmployee emp3;
                                emp3.manage();
                                break;
                            }
                            case 3 : {
                                BackupEmployeeData emp4;
                                emp4.backupData();
                            }
                            case 4 : {
                                return;
                            }
                        }
                        break;
                }
            this_thread::sleep_for(chrono::milliseconds(20));    
            } while (true); // Loop until "Exit" is selected and Enter is pressed
        }
};


                // switch(key) {
                //     case 1 : {
                //         AddEmployee employee1a;
                //         employee1a.setEmployeeData();
                //         break;
                //     }
                //     case 2 : {
                //         Update employee1b;
                //         employee1b.update();
                //         break;
                //     }
                //     case 3 : {
                //         DeleteEmployee employee1c;
                //         employee1c.manage();
                //         break;
                //     }
                //     case 4 : {
                //         BackupEmployeeData employee1d;
                //         employee1d.backupData();
                //         break;
                //     }
                //     case 0 : {
                //         cout << "Exiting..." << endl;
                //         break;
                //     }
                //     default : {
                //         cout << "INVALID OPTION!" << endl;
                //         break;
                //     }
                // }