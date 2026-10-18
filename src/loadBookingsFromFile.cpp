#include "loadBookingsFromFile.h"
#include "fileUtils.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

static constexpr int MAX_SEATS_PER_BOOKING = 1000;

static bool parseBookingHeader(const string& line, Booking& b) {
    const auto f = splitLine(line);
    int active = 0;
    int paid = 0;
    if (f.size() < 10
        || !parseInt(f[0], b.bookingId) || !parseInt(f[1], b.movieId)
        || !parseInt(f[3], b.seatCount)
        || !parseDouble(f[4], b.pricePerSeat) || !parseDouble(f[5], b.originalPrice)
        || !parseDouble(f[6], b.discountAmount) || !parseDouble(f[7], b.totalPrice)
        || !parseInt(f[8], active) || !parseInt(f[9], paid)
        || b.seatCount < 0 || b.seatCount > MAX_SEATS_PER_BOOKING) {
        return false;
    }
    b.movieName = f[2];
    b.isActive = (active != 0);
    b.isPaid = (paid != 0);
    return true;
}

static bool parseCustomer(const string& line, Customer& c) {
    const auto f = splitLine(line);
    if (f.size() < 3 || !parseInt(f[0], c.customerId)) {
        return false;
    }
    c.fullName = f[1];
    c.phone = f[2];
    return true;
}

static bool readSeats(istream& in, Booking& b) {
    b.seats.clear();
    string line;
    for (int i = 0; i < b.seatCount; ++i) {
        int row = 0;
        int col = 0;
        if (!readLine(in, line)) return false;
        istringstream ss(line);
        if (!(ss >> row >> col)) return false;
        b.seats.emplace_back(row, col);
    }
    return true;
}

static bool readDate(istream& in, Date& d) {
    string line;
    if (!readLine(in, line)) return false;
    istringstream ss(line);
    return static_cast<bool>(ss >> d.day >> d.month >> d.year);
}

static bool readBooking(istream& in, const string& header, Booking& b) {
    string line;
    return parseBookingHeader(header, b)
        && readLine(in, line) && parseCustomer(line, b.customer)
        && readSeats(in, b)
        && readDate(in, b.bookingDate);
}

void loadBookingsFromFile(vector<Booking>& bookings) {
    bookings.clear();

    ifstream file("data/bookings.txt");
    if (!file.is_open()) {
        cout << "Error: Cannot open bookings file for reading!\n";
        return;
    }

    string line;
    while (readLine(file, line)) {
        if (line.empty()) continue;

        Booking b;
        if (!readBooking(file, line, b)) {
            cerr << "Warning: bookings file is corrupted, stopped loading.\n";
            break;
        }
        bookings.push_back(b);
    }
    cout << "The bookings were successfully loaded from the bookings file.\n";
}
