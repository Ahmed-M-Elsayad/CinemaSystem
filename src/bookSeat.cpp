#include "bookSeat.h"

bool bookSeat(vector<vector<char>>& seats, int row, int col) {

    if (seats.empty() || row < 0 || row >= seats.size()) {
        return false; // خارج الحدود أو مصفوفة فارغة
    }

    if (col < 0 || col >= seats[row].size()) {
        return false;
    }

    //  التحقق من حالة المقعد
    if (seats[row][col] == 'O') { // المقعد فاضي
        seats[row][col] = 'X';    // حجز المقعد
        return true;              // نجاح الحجز
    }

    return false;
}