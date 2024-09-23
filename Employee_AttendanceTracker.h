#pragma once 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <conio.h>
#include <Windows.h>

#include "AddEmployee.h"
#include "loadingBar.h"
//#include "QR.h"

using namespace std;

#define LIGHT_BLUE "\033[38;5;123m"
#define BRIGHT_GREEN "\033[38;5;122m"
#define LIGHT_GREEN "\033[92m"
#define LIGHT_PINK "\033[38;5;217m"
#define LIGHT_PEACH "\033[38;5;223m"
#define CYAN "\033[36m"
#define GREEN "\033[38;5;46m"
#define BRIGHT_RED "\033[91m"
#define RESET "\033[0m"        // Reset definition

class Employee{
    private :
        int id;

        void employeePanel() {
            ifstream employeePanel("employeePanel.txt"); // Open the file for reading

            if(employeePanel.is_open()) {
                string line;
                // Read line by line from the file
                while(getline(employeePanel, line)) {
                    cout << line << endl; // Print each line to the console
                    this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 100 milliseconds
                }
                employeePanel.close(); // Close the file
            } else {
                cout << "Unable to open the file!" << endl;
            }
        }
        
        void list(int currentSelection, int totalOptions) {
            // employeePanel();
            cout << "+=================================================================================================+" << endl;
            cout << "|                                                                                                 |" << endl;
            cout << "|";cout << LIGHT_PEACH;
            cout << "                                      >>>  EMPLOYEE PANEL  <<<                                   ";cout << RESET;cout << "|" << endl;
            cout << "|                                                                                                 |" << endl;
            cout << "+=================================================================================================+" << endl;
            cout << "|                                                                                                 |" << endl;
            
            string options[] = {
                "CHECK-IN",
                "CHECK-OUT",
                "Exit"
            };
            for (int i = 0; i < totalOptions; i++) {
                if (i == currentSelection) {
                    setConsoleTextColor(15); // Bold (White text on black background)
                    cout << "|  =>    " << options[i] << string(62 - options[i].length(), ' ') << "                           |" << endl;
                } else {
                    setConsoleTextColor(8); // Normal (Gray text on black background)
                    cout << "|        " << options[i] << string(62 - options[i].length(), ' ') << "                           |" << endl;
                }
            }

        setConsoleTextColor(7); // Reset to normal color
            
        cout << "|                                                                                                 |" << endl;
        cout << "+=================================================================================================+" << endl;
        cout << "|";cout << LIGHT_GREEN;
        cout << "                          >>>  Select an option by pressing Enter  <<<                           ";cout << RESET;
        cout << "|" << endl;
        cout << "+=================================================================================================+" << endl;
        }

        void getCurrentTime() {
            // Get current time
            time_t now = time(0);

            // Convert to local time
            tm* localTime = localtime(&now);

            // Print the current date and time
            cout << 1900 + localTime->tm_year << "-"
                      << 1 + localTime->tm_mon << "-"
                      << localTime->tm_mday << " "
                      << localTime->tm_hour << ":"
                      << localTime->tm_min << ":"
                      << localTime->tm_sec << endl;
        }

        void checkInStyle() {
            ifstream checkInStyle("checkIn.txt"); // Open the file for reading

            if(checkInStyle.is_open()) {
                string line;
                // Read line by line from the file
                while(getline(checkInStyle, line)) {
                    cout << line << endl; // Print each line to the console
                    this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 100 milliseconds
                }
                checkInStyle.close(); // Close the file
            } else {
                cerr << BRIGHT_RED << "Unable to open the file!" << RESET << endl;
            } 
        }

        void checkOutStyle() {
            ifstream checkOutStyle("checkOut.txt"); // Open the file for reading

            if(checkOutStyle.is_open()) {
                string line;
                // Read line by line from the file
                while(getline(checkOutStyle, line)) {
                    cout << line << endl; // Print each line to the console
                    this_thread::sleep_for(chrono::milliseconds(80)); // Delay of 100 milliseconds
                }
                checkOutStyle.close(); // Close the file
            } else {
                cerr << BRIGHT_RED << "Unable to open the file!" << RESET << endl;
            }
        }

        void checkIn() {
            // checkInStyle();
            cout << "+=================================================================================================+" << endl;
            cout << "|                                                                                                 |" << endl;
            cout << "|";cout << LIGHT_PEACH;
            cout << "                                       >>>  CHECK-IN  <<<                                        ";cout << RESET;cout << "|" << endl;
            cout << "|                                                                                                 |" << endl;
            cout << "+=================================================================================================+" << endl;
            //getLoadingBar();
            string SERVER_URL = "http://192.168.1.102:5466/checkin";  // Check-in URL
            string command = "curl qrenco.de/" + SERVER_URL;
            system(command.c_str());
            this_thread::sleep_for(chrono::seconds(4));


            // Get current time
            time_t now = time(0);

            // Convert to local time
            tm* localTime = localtime(&now);

            ofstream checkInRecords("data/checkInRecords.txt", ios::app);
            if (checkInRecords.is_open()) {
                // Print the current date and time
                checkInRecords << "Employee Checked-In at " 
                                << 1900 + localTime->tm_year << "-"
                                << 1 + localTime->tm_mon << "-"
                                << localTime->tm_mday << " "
                                << localTime->tm_hour << ":"
                                << localTime->tm_min << '\n';
                checkInRecords.close();
            }
        }

        void checkOut() {
            // checkOutStyle();
            cout << "+=================================================================================================+" << endl;
            cout << "|                                                                                                 |" << endl;
            cout << "|";cout << LIGHT_PEACH;
            cout << "                                      >>>  CHECK-OUT  <<<                                        ";cout << RESET;cout << "|" << endl;
            cout << "|                                                                                                 |" << endl;
            cout << "+=================================================================================================+" << endl;

            //getLoadingBar();
            string SERVER_URL = "http://192.168.1.102:5466/checkout";  // Check-out URL
            string command = "curl qrenco.de/" + SERVER_URL;
            system(command.c_str());
            this_thread::sleep_for(chrono::seconds(4));

            // Get current time
            time_t now = time(0);

            // Convert to local time
            tm* localTime = localtime(&now);

            ofstream checkOutRecords("data/checkOutRecords.txt", ios::app);
            if (checkOutRecords.is_open()) {
                // Print the current date and time
                checkOutRecords << "Employee Checked-Out at " 
                                << 1900 + localTime->tm_year << "-"
                                << 1 + localTime->tm_mon << "-"
                                << localTime->tm_mday << " "
                                << localTime->tm_hour << ":"
                                << localTime->tm_min << '\n';
                checkOutRecords.close();
            }
        }

                // print checked-in records
        void checkInAttendanceRecords() {
            ifstream readCheckInRecords("data/checkInRecords.txt");
            if (readCheckInRecords.is_open()) {
                string record;
                cout << "+=================================================================================================+" << endl;
                cout << "|                                                                                                 |" << endl;
                cout << "|";cout << LIGHT_PEACH;
                cout << "                                       >>>  CHECK-IN  <<<                                        ";cout << RESET;cout << "|" << endl;
                cout << "|                                                                                                 |" << endl;
                cout << "+=================================================================================================+" << endl;
                while(getline(readCheckInRecords, record)) {
                    cout << "| " << record << setw(59) << "|" << endl;
                }
                cout << "+=================================================================================================+" << endl;
                readCheckInRecords.close();
            }
            else 
                cerr << BRIGHT_RED << "Error : Unable to open file checkInRecords.txt" << RESET << endl;
        }

        void checkOutAttendanceRecords() {
            ifstream readCheckOutRecords("data/checkOutRecords.txt");
            if (readCheckOutRecords.is_open()) {
                string record;
                cout << "+=================================================================================================+" << endl;
                cout << "|                                                                                                 |" << endl;
                cout << "|";cout << LIGHT_PEACH;
                cout << "                                      >>>  CHECK-OUT  <<<                                        ";cout << RESET;cout << "|" << endl;
                cout << "|                                                                                                 |" << endl;
                cout << "+=================================================================================================+" << endl;

                while(getline(readCheckOutRecords, record)) {
                    cout << "| " << record << setw(58) << "|" << endl;
                }
                cout << "+=================================================================================================+" << endl;
                readCheckOutRecords.close();
            }
            else 
                cerr << BRIGHT_RED << "Error : Unable to open file checkOutRecords.txt" << RESET << endl;
        }

        enum KEY { UP = 72, DOWN = 80, ENTER = 13 }; // Arrow keys and Enter key
        void setConsoleTextColor(int color) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        }
        void attendanceRecordsHighlight(int currentSelection, int totalOptions) {
            cout << "+=================================================================================================+" << endl;
            cout << "|                                                                                                 |" << endl;
            cout << "|";cout << LIGHT_PEACH;
            cout << "                                  >>>  ATTENDANCE RECORDS  <<<                                   ";cout << RESET;cout << "|" << endl;
            cout << "|                                                                                                 |" << endl;
            cout << "+=================================================================================================+" << endl;
            cout << "|                                                                                                 |" << endl;
            
            string options[] = {
                "Checked-In Records",
                "Checked-Out Records",
                "Exit"
            };

            for (int i = 0; i < totalOptions; i++) {
                if (i == currentSelection) {
                    setConsoleTextColor(15); // Bold (White text on black background)
                    cout << "|  =>    " << options[i] << string(62 - options[i].length(), ' ') << "                           |" << endl;
                } else {
                    setConsoleTextColor(8); // Normal (Gray text on black background)
                    cout << "|        " << options[i] << string(62 - options[i].length(), ' ') << "                           |" << endl;
                }
            }
            
            setConsoleTextColor(7);

            cout << "|                                                                                                 |" << endl;
            cout << "+=================================================================================================+" << endl;
            cout << "|";cout << LIGHT_GREEN;
            cout << "                          >>>  Select an option by pressing Enter  <<<                           ";cout << RESET;
            cout << "|" << endl;
            cout << "+=================================================================================================+" << endl;

        }

    public :
        void checkInCheckOut() {
            int currentSelection = 0;
            const int totalOptions = 3;
            do {
                system("cls");
                list(currentSelection, totalOptions);
                char key = _getch(); // Capture key press

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
                                getLoadingBar();
                                checkIn();
                                system("pause");
                                break;
                            }
                            case 1: {
                                getLoadingBar();
                                checkOut();
                                system("pause");
                                break;
                            }
                            case 2: {
                                //cout << "Exiting..." << endl;
                                return; // Exit the function when "Exit" is selected
                            }
                        }
                        break;
                }
            this_thread::sleep_for(chrono::milliseconds(20));    
            } while (true); // Loop until "Exit" is selected and Enter is pressed
        }

        void checkAttendacneRecords() {
            int currentSelection = 0;
            const int totalOptions = 3;
            char key;

        do {
            system("cls");
            attendanceRecordsHighlight(currentSelection, totalOptions);
            key = _getch(); // Capture key press
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
                            checkInAttendanceRecords();
                            system("pause");
                            break;
                        }
                        case 1: {
                            checkOutAttendanceRecords();
                            system("pause");
                            break;
                        }
                        case 2: {
                            //cout << "Exiting..." << endl;
                            return; // Exit the function when "Exit" is selected
                        }
                    }
                    break;
            }
        this_thread::sleep_for(chrono::milliseconds(20));    
        } while (true); // Loop until "Exit" is selected and Enter is pressed
        }
};
