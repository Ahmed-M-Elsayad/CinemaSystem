#include "getStringInput.h"
#include <iostream>

std::string getStringInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin >> std::ws, input);
    return input;
}