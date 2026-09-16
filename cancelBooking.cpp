#include "cancelBooking.h"
#include "findBookingById.h"
#include "unbookSeat.h"
#include "getIntInput.h"
#include <iostream>

using namespace std;

void cancelBooking(vector<Booking>& bookingList, vector<Movie>& movieList) {
         //  التحقق من وجود حجوزات
    if (bookingList.empty()) {
        cout << "No bookings available.\n";
        return;
    }
    //  طلب رقم الحجز (مع تحقق)
    cout << "Enter booking ID to cancel: ";
    int bookingId = getIntInput(1, 999999);
    //  البحث عن الحجز
    Booking* booking = findBookingById(bookingList, bookingId);
    if (booking == nullptr) {
        cout << "Booking not found.\n";
        return;
    }
    //  التحقق من أن الحجز نشط
    if (!booking->isActive) {
        cout << "This booking is already cancelled.\n";
        return;
    }
    //  استرجاع المقاعد
    for (auto& movie : movieList) {
        if (movie.movieId == booking->movieId) {
            for (const auto& [row, col] : booking->seats) {
                unbookSeat(movie.seats, row, col);
            }
            break;
        }
    }
    //  تغيير حالة الحجز
    booking->isActive = false;
    cout << "Booking cancelled successfully.\n";
}
