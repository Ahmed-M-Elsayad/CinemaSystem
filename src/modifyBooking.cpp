#include "modifyBooking.h"
#include "findBookingById.h"
#include "isSeatAvailable.h"
#include "bookSeat.h"
#include "unbookSeat.h"
#include "calculateTotalPrice.h"
#include "getIntInput.h"
#include "displaySeats.h"
#include <iostream>

using namespace std;

void modifyBooking(vector<Booking>& bookingList, vector<Movie>& movieList) {
    //  التحقق من وجود حجوزات
    if (bookingList.empty()) {
        cout << "No bookings available.\n";
        return;
    }

    //  طلب رقم الحجز
    cout << "Enter booking ID to modify: ";
    int id = getIntInput(1, 999999);

    //  البحث عن الحجز
    Booking* booking = findBookingById(bookingList, id);
    if (booking == nullptr) {
        cout << "Booking not found.\n";
        return;
    }

    //  التحقق من أن الحجز نشط
    if (!booking->isActive) {
        cout << "Cannot modify a cancelled booking.\n";
        return;
    }

    //  البحث عن الفيلم
    Movie* movie = nullptr;
    for (auto& m : movieList) {
        if (m.movieId == booking->movieId) {
            movie = &m;
            break;
        }
    }
    if (movie == nullptr) {
        cout << "Movie not found.\n";
        return;
    }

    //  عرض الخيارات
    cout << "\n1. Add seats\n2. Remove seats\n3. Cancel\n";
    int choice = getIntInput(1, 3);
    if (choice == 3) {
        cout << "Modification cancelled.\n";
        return;
    }

    //  إضافة مقاعد
    if (choice == 1) {
        displaySeats(movie->seats);
        cout << "How many seats to add? ";
        int numToAdd = getIntInput(1, 10);
        int added = 0;

        while (added < numToAdd) {
            cout << "\n--- New Seat " << (added + 1) << " of " << numToAdd << " ---\n";
            cout << "Row: ";
            int row = getIntInput(1, (int)movie->seats.size()) - 1;
            cout << "Col: ";
            int col = getIntInput(1, (int)movie->seats[row].size()) - 1;

            if (!isSeatAvailable(movie->seats, row, col)) {
                cout << "Already booked. Choose another.\n";
                continue;
            }

            bookSeat(movie->seats, row, col);
            booking->seats.push_back({ row, col });
            added++;
            cout << "Seat added.\n";
        }
    }

    //  إزالة مقاعد (الكود الناقص)
    if (choice == 2) {
        if (booking->seats.empty()) {
            cout << "No seats to remove.\n";
            return;
        }

        // عرض المقاعد الحالية
        cout << "\n--- Current Seats ---\n";
        for (size_t i = 0; i < booking->seats.size(); i++) {
            cout << (i + 1) << ". Row " << (booking->seats[i].first + 1)
                << ", Col " << (booking->seats[i].second + 1) << "\n";
        }

        // طلب عدد المقاعد للإزالة
        cout << "How many seats to remove? ";
        int numToRemove = getIntInput(1, static_cast<int>(booking->seats.size()));

        for (int i = 0; i < numToRemove; i++) {
            cout << "\n--- Remove Seat " << (i + 1) << " of " << numToRemove << " ---\n";
            cout << "Enter seat number to remove (1-" << booking->seats.size() << "): ";
            int seatIndex = getIntInput(1, static_cast<int>(booking->seats.size())) - 1;

            // استرجاع المقعد في مصفوفة الفيلم
            int row = booking->seats[seatIndex].first;
            int col = booking->seats[seatIndex].second;
            unbookSeat(movie->seats, row, col);

            // حذف المقعد من قائمة الحجز
            booking->seats.erase(booking->seats.begin() + seatIndex);
            cout << "Seat removed.\n";
        }
    }

    //  إعادة حساب السعر
    booking->seatCount = static_cast<int>(booking->seats.size());
    booking->originalPrice = booking->pricePerSeat * booking->seatCount;

    double discount = 0.0;
    booking->totalPrice = calculateTotalPrice(
        booking->pricePerSeat,
        booking->seatCount,
        discount
    );
    booking->discountAmount = discount;

    //  عرض النتيجة
    cout << "\n========================================\n";
    cout << "   Booking modified successfully!\n";
    cout << "========================================\n";
    cout << "Booking ID     : " << booking->bookingId << "\n";
    cout << "New Seats Count: " << booking->seatCount << "\n";
    cout << "New Total Price: " << booking->totalPrice << " EGP\n";
    cout << "========================================\n";
}