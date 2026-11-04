#include "isValidSeat.h"

using namespace std;
bool isValidSeat(const vector<vector<char>>& seats, int row, int col) {
    // التعديل هنا: تم مسح الشرط المكرر
    if (seats.empty() || row < 0 || row >= static_cast<int>(seats.size())) {
        return false;
    }
    if (col < 0 || col >= static_cast<int>(seats[row].size())) {
        return false;
    }

    // إذا وصلنا هنا، فالإحداثيات صحيحة
    return true;
}
