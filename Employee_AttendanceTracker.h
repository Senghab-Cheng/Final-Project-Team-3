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
            cout << "+==============================================================================+" << endl;
            cout << "|                                                                              |" << endl;
            cout << "|                            >>>  EMPLOYEE PANEL  <<<                          |" << endl;
            cout << "|                                                                              |" << endl;
            cout << "+==============================================================================+" << endl;
            cout << "|                                                                              |" << endl;
            
            string options[] = {
                "CHECK-IN",
                "CHECK-OUT",
                "Exit"
            };
            for (int i = 0; i < totalOptions; i++) {
                if (i == currentSelection) {
                    setConsoleTextColor(15); // Bold (White text on black background)
                    cout << "|  =>  " << options[i] << string(62 - options[i].length(), ' ') << "          |" << endl;
                } else {
                    setConsoleTextColor(8); // Normal (Gray text on black background)
                    cout << "|      " << options[i] << string(62 - options[i].length(), ' ') << "          |" << endl;
                }
            }

        setConsoleTextColor(7); // Reset to normal color
            
            cout << "|                                                                              |" << endl;
            cout << "+==============================================================================+" << endl;
            cout << "|              >>>  Select an option by entering the number  <<<               |" << endl;
            cout << "+==============================================================================+" << endl; 
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
                cout << "Unable to open the file!" << endl;
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
                cout << "Unable to open the file!" << endl;
            }
        }

        void checkIn() {
            // checkInStyle();
            cout << "+==============================================================================+" << endl;
            cout << "|                                                                              |" << endl;
            cout << "|                              >>>  CHECK-IN  <<<                              |" << endl;
            cout << "|                                                                              |" << endl;
            cout << "+==============================================================================+" << endl;
            // cout << "[+] Enter your ID to check-in : ";
            // cin >> this->id;

            // auto it = find(employeeIDs.begin(), employeeIDs.end(), id);
            // if (it != employeeIDs.end()) {
            //     size_t index = distance(employeeIDs.begin(), it);
            //     //getLoadingBar();
            //     system("cls");
            //     cout << "+------------+---------------------------------+-------------------------+" << endl;
            //     cout << "| ID         | NAME                            | ROLE                    |" << endl;
            //     cout << "+------------+---------------------------------+-------------------------+" << endl;
            //     cout << "| " << setw(10) << left << employeeIDs[index]
            //         << " | " << setw(32) << left << employeeNames[index]
            //         << "| " << setw(23) << left << employeeRoles[index]
            //         << " | "<< endl;
            //     cout << "+------------+---------------------------------+-------------------------+" << endl;
            //     cout << "Checked In successfully : ";
            //     getCurrentTime();
            //}

            //getLoadingBar();
            string SERVER_URL = "http://192.168.1.246:5466/checkin";  // Check-in URL
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
            cout << "+==============================================================================+" << endl;
            cout << "|                                                                              |" << endl;
            cout << "|                             >>>  CHECK-OUT  <<<                              |" << endl;
            cout << "|                                                                              |" << endl;
            cout << "+==============================================================================+" << endl;
            // cout << "[+] Enter your ID to check-in : ";
            // cin >> this->id;

            // auto it = find(employeeIDs.begin(), employeeIDs.end(), id);
            // if (it != employeeIDs.end()) {
            //     size_t index = distance(employeeIDs.begin(), it);
            //     //getLoadingBar();
            //     system("cls");
            //     cout << "+------------+---------------------------------+-------------------------+" << endl;
            //     cout << "| ID         | NAME                            | ROLE                    |" << endl;
            //     cout << "+------------+---------------------------------+-------------------------+" << endl;
            //     cout << "| " << setw(10) << left << employeeIDs[index]
            //         << "| " << setw(33) << left << employeeNames[index]
            //         << "| " << setw(25) << left << employeeRoles[index]
            //         << "| "<< endl;
            //     cout << "+------------+---------------------------------+-------------------------+" << endl;
            //     cout << "Checked Out successfully : ";
            //     getCurrentTime();
            // }

            //getLoadingBar();
            string SERVER_URL = "http://192.168.1.246:5466/checkout";  // Check-out URL
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
                cout << "+=====================================================+" << endl;
                cout << "|                       CHECK-IN                      |" << endl;
                cout << "+=====================================================+" << endl;
                while(getline(readCheckInRecords, record)) {
                    cout << "| " << record << setw(15) << "|" << endl;
                }
                cout << "+=====================================================+" << endl;
                readCheckInRecords.close();
            }
            else 
                cerr << "Error : Unable to open file checkInRecords.txt" << endl;
        }

        void checkOutAttendanceRecords() {
            ifstream readCheckOutRecords("data/checkOutRecords.txt");
            if (readCheckOutRecords.is_open()) {
                string record;
                cout << "+=====================================================+" << endl;
                cout << "|                      CHECK-OUT                      |" << endl;
                cout << "+=====================================================+" << endl;
                while(getline(readCheckOutRecords, record)) {
                    cout << "| " << record << setw(14) << "|" << endl;
                }
                cout << "+=====================================================+" << endl;
                readCheckOutRecords.close();
            }
            else 
                cerr << "Error : Unable to open file checkOutRecords.txt" << endl;
        }

        enum KEY { UP = 72, DOWN = 80, ENTER = 13 }; // Arrow keys and Enter key
        void setConsoleTextColor(int color) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        }
        void attendanceRecordsHighlight(int currentSelection, int totalOptions) {
            cout << "+==============================================================================+" << endl;
            cout << "|                                                                              |" << endl;
            cout << "|                        >>>  ATTENDANCE RECORDS  <<<                          |" << endl;
            cout << "|                                                                              |" << endl;
            cout << "+==============================================================================+" << endl;
            cout << "|                                                                              |" << endl;
            
            string options[] = {
                "Checked-In Records",
                "Checked-Out Records",
                "Exit"
            };

            for (int i = 0; i < totalOptions; i++) {
                if (i == currentSelection) {
                    setConsoleTextColor(15); // Bold (White text on black background)
                    cout << "|  =>  " << options[i] << string(62 - options[i].length(), ' ') << "          |" << endl;
                } else {
                    setConsoleTextColor(8); // Normal (Gray text on black background)
                    cout << "|      " << options[i] << string(62 - options[i].length(), ' ') << "          |" << endl;
                }
            }
            
            setConsoleTextColor(7);

            cout << "|                                                                              |" << endl;
            cout << "+==============================================================================+" << endl;
            cout << "|                 >>>  Select an option by pressing Enter  <<<                 |" << endl;
            cout << "+==============================================================================+" << endl; 
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
                                checkIn();
                                system("pause");
                                break;
                            }
                            case 1: {
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
