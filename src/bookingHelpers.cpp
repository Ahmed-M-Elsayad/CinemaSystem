#include "bookingHelpers.h"
#include "bookSeat.h"
#include "calculateTotalPrice.h"
#include "getIntInput.h"
#include "isSeatAvailable.h"
#include <algorithm>
#include <iostream>

using namespace std;

int countFreeSeats(const Movie& movie) {
    int free = 0;
    for (const auto& row : movie.seats) {
        free += static_cast<int>(count(row.begin(), row.end(), 'O'));
    }
    return free;
}

void selectSeats(Movie& movie, Booking& booking, int count) {
    int picked = 0;
    while (picked < count) {
        cout << "\n--- Seat " << (picked + 1) << " of " << count << " ---\n";

        cout << "Enter row (1-" << movie.seats.size() << "): ";
        const int row = getIntInput(1, static_cast<int>(movie.seats.size())) - 1;
        const auto& rowSeats = movie.seats[static_cast<size_t>(row)];

        cout << "Enter column (1-" << rowSeats.size() << "): ";
        const int col = getIntInput(1, static_cast<int>(rowSeats.size())) - 1;

        if (!isSeatAvailable(movie.seats, row, col)) {
            cout << "This seat is already booked. Please choose another.\n";
            continue;
        }

        bookSeat(movie.seats, row, col);
        booking.seats.emplace_back(row, col);
        ++picked;
        cout << "Seat booked successfully.\n";
    }
}

void applyPricing(Booking& booking) {
    booking.seatCount = static_cast<int>(booking.seats.size());
    booking.originalPrice = booking.pricePerSeat * booking.seatCount;

    double discount = 0.0;
    booking.totalPrice = calculateTotalPrice(booking.pricePerSeat, booking.seatCount, discount);
    booking.discountAmount = discount;
}
