#include "getStringInput.h"
#include <iostream>

std::string getStringInput(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin >> std::ws, input);

        // التحقق من عدم وجود رمز | الذي يفسد ملفات البيانات
        if (input.find('|') == std::string::npos) {
            return input;
        }
        std::cout << "Invalid character '|'. Please try again.\n";
    }
}
