#include "cancelBooking.h"
#include "findBookingById.h"
#include "unbookSeat.h"
#include "getIntInput.h"
#include <iostream>

using namespace std;

void cancelBooking(vector<Booking>& bookingList, vector<Movie>& movieList) {
    // 1. التحقق من وجود حجوزات
    if (bookingList.empty()) {
        cout << "No bookings available.\n";
        return;
    }

    // 2. طلب رقم الحجز (مع تحقق)
    cout << "Enter booking ID to cancel: ";
    int bookingId = getIntInput(1, 999999);

    // 3. البحث عن الحجز
    Booking* booking = findBookingById(bookingList, bookingId);
    if (booking == nullptr) {
        cout << "Booking not found.\n";
        return;
    }

    // 4. التحقق من أن الحجز نشط
    if (!booking->isActive) {
        cout << "This booking is already cancelled.\n";
        return;
    }

    // 5. استرجاع المقاعد (التعديل الجديد هنا)
    bool movieFound = false;
    for (auto& movie : movieList) {
        if (movie.movieId == booking->movieId) {
            movieFound = true;
            for (const auto& [row, col] : booking->seats) {
                if (!unbookSeat(movie.seats, row, col)) {
                    cerr << "Warning: Failed to unbook seat at row " << row << ", col " << col << "\n";
                }
            }
            break;
        }
    }

    // التحقق: لو الفيلم مش موجود في القائمة (اتحذف مثلاً)
    if (!movieFound) {
        cerr << "Warning: Movie not found, seats cannot be unbooked.\n";
    }

    // 6. تغيير حالة الحجز
    booking->isActive = false;
    cout << "Booking cancelled successfully.\n";
}
