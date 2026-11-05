#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "calculateTotalPrice.h"
#include "sha256.h"
#include "fileUtils.h"
#include "bookSeat.h"
#include "unbookSeat.h"
#include "initializeSeats.h"
#include "isSeatAvailable.h"
#include "isValidSeat.h"
#include "getAvailableSeatsCount.h"
#include "bookingHelpers.h" 
#include "find_movie.h"       
#include "find_hall.h"        
#include "findBookingById.h"  

// اختبار حساب الأسعار والخصومات
void testCalculateTotalPrice() {
    double discount = 0.0;
    double total1 = calculateTotalPrice(100.0, 3, discount);
    assert(total1 == 300.0);
    assert(discount == 0.0);

    double total4 = calculateTotalPrice(100.0, 4, discount);
    assert(total4 == 400.0);
    assert(discount == 0.0);

    double total2 = calculateTotalPrice(100.0, 5, discount);
    assert(total2 == 450.0);
    assert(discount == 50.0);
    std::cout << "[PASS] testCalculateTotalPrice" << std::endl;
}

// اختبار التشفير
void testSha256() {
    std::string hash = sha256Hex("hello");
    assert(hash == "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824");
    assert(sha256Hex("") == "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
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

// اختبار دوال الـ Parsing
void testFileUtilsParsing() {
    int intVal = 0;
    double doubleVal = 0.0;

    assert(parseInt("123", intVal) == true);
    assert(intVal == 123);
    assert(parseInt("-50", intVal) == true);
    assert(intVal == -50);
    assert(parseInt("abc", intVal) == false);
    assert(parseInt("12.5", intVal) == false);

    assert(parseDouble("99.99", doubleVal) == true);
    assert(parseDouble("abc", doubleVal) == false);

    std::cout << "[PASS] testFileUtilsParsing" << std::endl;
}

// اختبار دوال الـ Booking Helpers
void testBookingHelpersFunctions() {
    Movie movie;
    movie.seats = { { 'O', 'X' },{ 'O', 'O' } };
    assert(countFreeSeats(movie) == 3);

    Booking booking;
    booking.pricePerSeat = 100.0;
    booking.seats = { { 0, 0 },{ 1, 0 } };
    applyPricing(booking);
    assert(booking.seatCount == 2);
    assert(booking.originalPrice == 200.0);
    assert(booking.totalPrice == 200.0);

    std::cout << "[PASS] testBookingHelpersFunctions" << std::endl;
}

// اختبار إنشاء مصفوفة المقاعد
void testInitializeSeats() {
    auto seats = initializeSeats(3, 4);
    assert(seats.size() == 3);
    for (const auto& row : seats) {
        assert(row.size() == 4);
        for (char seat : row) {
            assert(seat == 'O');
        }
    }
    std::cout << "[PASS] testInitializeSeats" << std::endl;
}

// اختبار التحقق من صحة رقم المقعد
void testIsValidSeat() {
    std::vector<std::vector<char>> seats = { { 'O', 'O', 'O' },{ 'O', 'O', 'O' } };
    assert(isValidSeat(seats, 0, 0) == true);
    assert(isValidSeat(seats, 1, 2) == true);
    assert(isValidSeat(seats, 2, 0) == false);
    assert(isValidSeat(seats, 0, 3) == false);
    assert(isValidSeat(seats, -1, 0) == false);
    assert(isValidSeat(seats, 0, -1) == false);
    std::cout << "[PASS] testIsValidSeat" << std::endl;
}

// اختبار توفر المقاعد وعدد المقاعد الفاضية
void testSeatAvailability() {
    std::vector<std::vector<char>> seats = { { 'O', 'X' },{ 'O', 'O' } };
    assert(isSeatAvailable(seats, 0, 0) == true);
    assert(isSeatAvailable(seats, 0, 1) == false);
    assert(getAvailableSeatsCount(seats) == 3);
    bookSeat(seats, 1, 1);
    assert(getAvailableSeatsCount(seats) == 2);
    std::cout << "[PASS] testSeatAvailability" << std::endl;
}

// اختبار حجز وإلغاء حجز المقاعد
void testSeatBooking() {
    std::vector<std::vector<char>> seats = { { 'O', 'O' },{ 'O', 'O' } };
    assert(bookSeat(seats, 0, 0) == true);
    assert(seats[0][0] == 'X');
    assert(bookSeat(seats, 0, 0) == false);
    assert(unbookSeat(seats, 0, 0) == true);
    assert(seats[0][0] == 'O');
    std::cout << "[PASS] testSeatBooking" << std::endl;
}

// اختبار حالة المصفوفة الفارغة (لتغطية الفروع الشرطية)
void testEmptySeats() {
    std::vector<std::vector<char>> emptySeats;

    // التأكد من أن الدوال تتعامل بأمان مع المصفوفات الفارغة
    assert(isValidSeat(emptySeats, 0, 0) == false);
    assert(bookSeat(emptySeats, 0, 0) == false);
    assert(unbookSeat(emptySeats, 0, 0) == false);
    assert(isSeatAvailable(emptySeats, 0, 0) == false);
    assert(getAvailableSeatsCount(emptySeats) == 0);

    std::cout << "[PASS] testEmptySeats" << std::endl;
}

// اختبارات الـ Finders
void testFinders() {
    // 1. تجهيز بيانات وهمية
    std::vector<Movie> movies;
    Movie m1; m1.movieId = 1; m1.name = "Action";
    Movie m2; m2.movieId = 2; m2.name = "Drama";
    movies.push_back(m1);
    movies.push_back(m2);

    std::vector<Hall> halls;
    Hall h1; h1.hallId = 1; h1.name = "VIP";
    halls.push_back(h1);

    std::vector<Booking> bookings;
    Booking b1; b1.bookingId = 10;
    bookings.push_back(b1);

    // 2. اختبار البحث عن فيلم
    assert(findMovieById(movies, 1) != nullptr);
    assert(findMovieById(movies, 1)->name == "Action");
    assert(findMovieById(movies, 99) == nullptr); // غير موجود

    const std::vector<Movie>& constMovies = movies;
    assert(findMovieById(constMovies, 2) != nullptr);

    // 3. اختبار البحث عن صالة
    assert(findHallById(halls, 1) != nullptr);
    assert(findHallById(halls, 99) == nullptr);

    const std::vector<Hall>& constHalls = halls;
    assert(findHallById(constHalls, 1) != nullptr);

    // 4. اختبار البحث عن حجز
    assert(findBookingById(bookings, 10) != nullptr);
    assert(findBookingById(bookings, 99) == nullptr);

    std::cout << "[PASS] testFinders" << std::endl;
}

int main() {
    std::cout << "Running Unit Tests...\n" << std::endl;

    testCalculateTotalPrice();
    testSha256();
    testFileUtils();
    testInitializeSeats();
    testIsValidSeat();
    testSeatAvailability();
    testSeatBooking();
    testFileUtilsParsing();
    testBookingHelpersFunctions();
    testEmptySeats(); // الاختبار الجديد
    testFinders();

    std::cout << "\nAll tests passed successfully!" << std::endl;
    return 0;
}
