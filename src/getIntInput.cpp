#include "getIntInput.h"
#include <iostream>
#include <limits>

int getIntInput(int min, int max) {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number: ";
        }
        else if (value < min || value > max) {
            std::cout << "Out of range. Enter between " << min << " and " << max << ": ";
        }
        else {
            return value;
        }
    }
}
