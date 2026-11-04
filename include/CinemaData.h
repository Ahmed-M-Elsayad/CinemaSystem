#pragma once

#include <string>
#include <utility>
#include <vector>

struct Date {
    int day = 0;
    int month = 0;
    int year = 0;
};

struct Hall {
    int hallId = 0;
    std::string name;
    int rows = 0;
    int cols = 0;
    bool isVip = false;
};

struct Movie {
    int movieId = 0;
    std::string name;
    std::string genre;
    std::string showtime;
    double price = 0.0;
    int hallId = 0;
    std::string status;
    std::vector<std::vector<char>> seats;
};

struct Customer {
    int customerId = 0;
    std::string fullName;
    std::string phone;
};

struct Booking {
    int bookingId = 0;
    int movieId = 0;
    std::string movieName;
    Customer customer;
    std::vector<std::pair<int, int>> seats;
    int seatCount = 0;
    double pricePerSeat = 0.0;
    double originalPrice = 0.0;
    double discountAmount = 0.0;
    double totalPrice = 0.0;
    Date bookingDate;
    bool isActive = true;
    bool isPaid = false;
};

constexpr int ROWS_DEFAULT = 5;
constexpr int COLS_DEFAULT = 6;
constexpr int DISCOUNT_THRESHOLD = 4;
constexpr double DISCOUNT_RATE = 0.10;
constexpr int STARTING_BOOKING_ID = 1;

extern std::vector<Hall> halls;
extern std::vector<Movie> movies;
extern std::vector<Booking> bookings;
