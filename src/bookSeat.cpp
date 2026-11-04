#include "bookSeat.h"
using namespace std;

bool bookSeat(vector<vector<char>>& seats, int row, int col) {

    if (seats.empty() || row < 0 || row >= static_cast<int>(seats.size())) {
        return false;
    }
    if (col < 0 || col >= static_cast<int>(seats[row].size())) {
        return false;
    }

    // التحقق من حالة المقعد
    if (seats[row][col] == 'O') { // المقعد فاضي
        seats[row][col] = 'X';    // حجز المقعد
        return true;              // نجاح الحجز
    }

    return false;
}
