#include "getAvailableSeatsCount.h"

int getAvailableSeatsCount(const vector<vector<char>>& seats) {
    int availableCount = 0;

    for (const auto& row : seats) {

        for (char seat : row) {

            if (seat == 'O') {
                availableCount++;
            }
        }
    }

    return availableCount;
}