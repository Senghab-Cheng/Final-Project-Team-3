#pragma once

#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include <string>

// Inline function to generate a color code for smooth transition
inline std::string getColor(int progress) {
    int r = (progress * 255) / 100; // Red component
    int g = 255 - r;                // Green component
    int b = 0;                      // Blue component
    std::ostringstream colorCode;
    colorCode << "\033[38;2;" << r << ";" << g << ";" << b << "m";
    return colorCode.str();
}

// Inline function to print the loading bar
inline void printLoadingBar(int progress, int width) {
    std::cout << "[";
    int pos = width * progress / 100;
    for (int i = 0; i < width; ++i) {
        if (i < pos)
            std::cout << getColor(progress) << "=";
        else
            std::cout << "\033[0m "; // Reset color for empty space
    }
    std::cout << "\033[0m] " << progress << "%\r"; // Reset color and print progress
    std::cout.flush();
}

// Inline function to simulate loading
inline void getLoadingBar() {
    int width = 50;
    for (int i = 0; i <= 100; ++i) {
        printLoadingBar(i, width);
        std::this_thread::sleep_for(std::chrono::milliseconds(13)); // Adjust speed of animation
    }
    std::cout << std::endl;
}
