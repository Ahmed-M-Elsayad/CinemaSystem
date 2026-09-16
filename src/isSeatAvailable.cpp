#include "isSeatAvailable.h"

bool isSeatAvailable(const std::vector<std::vector<char>>& seats, int row, int col) {
    if (row < 0 || row >= static_cast<int>(seats.size())) return false;
    if (col < 0 || col >= static_cast<int>(seats[row].size())) return false;
    return seats[row][col] == 'O';
}
