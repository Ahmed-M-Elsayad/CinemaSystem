#include "displaySeats.h"
#include <iostream>

void displaySeats(const std::vector<std::vector<char>>& seats) {
    std::cout << "\n===== Seat Map =====\n";
    int rowNum = 1;
    for (const auto& row : seats) {
        std::cout << "Row " << rowNum++ << ": ";
        for (char seat : row) {
            std::cout << seat << " ";
        }
        std::cout << "\n";
    }
}
