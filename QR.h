#pragma once

#include <iostream>
#include <string>

using namespace std;

class qrGen{
    public : 
        void qrgen() {
            int choice;
            std::cout << "Select 1 for Check-in, 2 for Check-out: ";
            std::cin >> choice;

            std::string SERVER_URL;

            if (choice == 1) {
                SERVER_URL = "http://192.168.0.173:5466/checkin";  // Check-in URL
            } else if (choice == 2) {
                SERVER_URL = "http://192.168.0.173:5466/checkout";  // Check-out URL
            } else {
                std::cout << "Invalid choice!" << std::endl;
                return;
            }

            std::string command = "curl qrenco.de/" + SERVER_URL;
            system(command.c_str());

            std::cout << "\nQR Code generated for URL: " << SERVER_URL << std::endl;
        }
};