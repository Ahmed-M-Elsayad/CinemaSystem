#include "isValidSeat.h"

bool isValidSeat(const vector<vector<char>>& seats, int row, int col) {
    // 1. التأكد من أن المصفوفة ليست فارغة
    if (seats.empty()) {
        return false;
    }

    // 2. التأكد من أن الصف داخل الحدود
    if (row < 0 || row >= seats.size()) {
        return false;
    }

    // 3. التأكد من أن العمود داخل حدود هذا الصف تحديداً
    if (col < 0 || col >= seats[row].size()) {
        return false;
    }

    // إذا وصلنا هنا، فالإحداثيات صحيحة
    return true;
}