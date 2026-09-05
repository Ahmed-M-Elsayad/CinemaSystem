#include "unbookSeat.h"

bool unbookSeat(vector<vector<char>>& seats, int row, int col) {
    // تحقق داخل النطاق ولا لا
    if (seats.empty() || row < 0 || row >= seats.size()) {
        return false; // خارج الحدود، فشل الإلغاء
    }

    //  التحقق من أن العمود موجود داخل هذا الصف تحديداً
    if (col < 0 || col >= seats[row].size()) {
        return false; // خارج الحدود، فشل الإلغاء
    }

    //  التحقق من الحالة الحالية للمقعد
    if (seats[row][col] == 'X') { // المقعد محجوز
        seats[row][col] = 'O';    // تحويله إلى فاضي
        return true;              // نجح الإلغاء
    }

    return false; // فشل الإلغاء
}