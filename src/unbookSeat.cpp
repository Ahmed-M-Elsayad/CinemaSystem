#include "unbookSeat.h"
using namespace std;

bool unbookSeat(vector<vector<char>>& seats, int row, int col) {
    // تحقق داخل النطاق ولا لا
    if (seats.empty() || row < 0 || row >= static_cast<int>(seats.size())) {
        return false;
    }
    if (col < 0 || col >= static_cast<int>(seats[row].size())) {
        return false;
    }

    // التحقق من الحالة الحالية للمقعد
    if (seats[row][col] == 'X') { // المقعد محجوز
        seats[row][col] = 'O';    // تحويله إلى فاضي
        return true;              // نجح الإلغاء
    }

    return false; // فشل الإلغاء
}
