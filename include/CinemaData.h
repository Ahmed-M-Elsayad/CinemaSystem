#ifndef CINEMA_DATA_H
#define CINEMA_DATA_H

#include <string>
#include <utility>
#include <vector>
using namespace std;

// كل الحقول لها قيم ابتدائية عشان ما يبقاش في متغيرات غير مهيّأة (Reliability)

struct Date {
    int day = 0;
    int month = 0;
    int year = 0;
};

struct Hall {
    int hallId = 0;
    string name;
    int rows = 0;
    int cols = 0;
    bool isVip = false;
};

struct Movie {
    int movieId = 0;
    string name;
    string genre;
    string showtime;
    double price = 0.0;
    int hallId = 0;
    string status;                    // "Now Showing" / "Coming Soon" / "Ended"
    vector<vector<char>> seats;       // 'O' فاضي، 'X' محجوز
};

struct Customer {
    int customerId = 0;
    string fullName;
    string phone;
};

struct Booking {
    int bookingId = 0;
    int movieId = 0;
    string movieName;
    Customer customer;
    vector<pair<int, int>> seats;
    int seatCount = 0;
    double pricePerSeat = 0.0;
    double originalPrice = 0.0;
    double discountAmount = 0.0;
    double totalPrice = 0.0;
    Date bookingDate;
    bool isActive = true;
    bool isPaid = false;
};

// ملاحظة: تم حذف ADMIN_PASSWORD من هنا (hardcoded credential).
// كلمة السر دلوقتي بتتقرأ من adminLogin.cpp (متغير بيئة أو ملف محلي).
constexpr int ROWS_DEFAULT = 5;
constexpr int COLS_DEFAULT = 6;
constexpr int DISCOUNT_THRESHOLD = 4;
constexpr double DISCOUNT_RATE = 0.10;
constexpr int STARTING_BOOKING_ID = 1001;

extern vector<Hall> halls;
extern vector<Movie> movies;
extern vector<Booking> bookings;
extern int nextBookingId;

#endif
