#include "saveBookingsToFile.h"
#include <fstream>
#include <iostream>

using namespace std;

void saveBookingsToFile(const vector<Booking>& bookings) {
    
    ofstream bookingsFile("data/bookings.txt");

    if (bookingsFile.is_open()) {
        for (const auto& b : bookings) {  
            //  حفظ البيانات وفصلها بـ |
            bookingsFile << b.bookingId << "|" << b.movieId << "|" << b.movieName << "|"
                << b.seatCount << "|" << b.pricePerSeat << "|" << b.originalPrice << "|"
                << b.discountAmount << "|" << b.totalPrice << "|" << b.isActive << "|" << b.isPaid << "\n";

            // حفظ بيانات العميل
            bookingsFile << b.customer.customerId << "|" << b.customer.fullName << "|" << b.customer.phone << "\n";

            // حفظ المقاعد المحجوزة
            for (const auto& seat : b.seats) {
                bookingsFile << seat.first << " " << seat.second << "\n";
            }

            // حفظ تاريخ الحجز
            bookingsFile << b.bookingDate.day << " " << b.bookingDate.month << " " << b.bookingDate.year << "\n";
        }
        bookingsFile.close();
        cout << "Saved. Open the bookings file to view the data.\n";
    }
    else {
        cout << "Error: Cannot open bookings file for saving!\n";
    }
}