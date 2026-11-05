#include <iostream>
#include <cassert>
#include <vector>
#include "calculateTotalPrice.h"
#include "sha256.h"
#include "fileUtils.h"
#include "bookSeat.h"
#include "unbookSeat.h"

// اختبار حساب الأسعار والخصومات
void testCalculateTotalPrice() {
    double discount = 0.0;

    // حالة 1: 3 تذاكر (أقل من حد الخصم)
    double total1 = calculateTotalPrice(100.0, 3, discount);
    assert(total1 == 300.0);
    assert(discount == 0.0);

    // حالة 2: 5 تذاكر (أكبر من حد الخصم 4)
    double total2 = calculateTotalPrice(100.0, 5, discount);
    assert(total2 == 450.0); // 500 - 10% خصم
    assert(discount == 50.0);
    std::cout << "[PASS] testCalculateTotalPrice" << std::endl;
}

// اختبار التشفير
void testSha256() {
    std::string hash = sha256Hex("hello");
    // الهاش المعروف لكلمة hello
    assert(hash == "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824");
    std::cout << "[PASS] testSha256" << std::endl;
}

// اختبار قراءة وتقسيم النصوص
void testFileUtils() {
    std::string line = "1|Ahmed|100.50";
    auto parts = splitLine(line, '|');
    assert(parts.size() == 3);
    assert(parts[0] == "1");
    assert(parts[1] == "Ahmed");
    assert(parts[2] == "100.50");
    std::cout << "[PASS] testFileUtils" << std::endl;
}

// اختبار حجز وإلغاء حجز المقاعد
void testSeatBooking() {
    std::vector<std::vector<char>> seats = { { 'O', 'O' },{ 'O', 'O' } };

    // اختبار حجز ناجح
    assert(bookSeat(seats, 0, 0) == true);
    assert(seats[0][0] == 'X');

    // اختبار حجز مقعد محجوز مسبقاً (لازم يفشل)
    assert(bookSeat(seats, 0, 0) == false);

    // اختبار إلغاء حجز ناجح
    assert(unbookSeat(seats, 0, 0) == true);
    assert(seats[0][0] == 'O');
    std::cout << "[PASS] testSeatBooking" << std::endl;
}

int main() {
    std::cout << "Running Unit Tests...\n" << std::endl;
    testCalculateTotalPrice();
    testSha256();
    testFileUtils();
    testSeatBooking();
    std::cout << "\nAll tests passed successfully!" << std::endl;
    return 0;
}
