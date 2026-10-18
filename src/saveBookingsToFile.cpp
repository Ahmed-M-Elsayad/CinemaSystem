#include "saveBookingsToFile.h"
#include "fileUtils.h"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void saveBookingsToFile(const vector<Booking>& bookings) {
    ensureDataDirectory();
    ofstream file("data/bookings.txt");
    if (!file.is_open()) {
        cout << "Error: Cannot open bookings file for saving!\n";
        return;
    }

    file << fixed << setprecision(2);

    for (const auto& b : bookings) {
        file << b.bookingId << "|" << b.movieId << "|" << b.movieName << "|"
             << b.seatCount << "|" << b.pricePerSeat << "|" << b.originalPrice << "|"
             << b.discountAmount << "|" << b.totalPrice << "|"
             << b.isActive << "|" << b.isPaid << "\n";

        file << b.customer.customerId << "|" << b.customer.fullName << "|"
             << b.customer.phone << "\n";

        for (const auto& seat : b.seats) {
            file << seat.first << " " << seat.second << "\n";
        }

        file << b.bookingDate.day << " " << b.bookingDate.month << " "
             << b.bookingDate.year << "\n";
    }

    if (!file) {
        cout << "Error: Failed while writing the bookings file!\n";
        return;
    }
    cout << "Bookings saved successfully.\n";
}
