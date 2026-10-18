#include "modifyBooking.h"
#include "bookingHelpers.h"
#include "displaySeats.h"
#include "findBookingById.h"
#include "find_movie.h"
#include "getIntInput.h"
#include "unbookSeat.h"
#include <algorithm>
#include <iostream>

using namespace std;

namespace {

constexpr int MAX_SEATS_PER_BOOKING = 10;

bool addSeats(Movie& movie, Booking& booking) {
    const int freeSeats = countFreeSeats(movie);
    if (freeSeats == 0) {
        cout << "No free seats available.\n";
        return false;
    }

    displaySeats(movie.seats);
    cout << "How many seats to add? ";
    const int numToAdd = getIntInput(1, min(MAX_SEATS_PER_BOOKING, freeSeats));
    selectSeats(movie, booking, numToAdd);
    return true;
}

bool removeSeats(Movie& movie, Booking& booking) {
    if (booking.seats.empty()) {
        cout << "No seats to remove.\n";
        return false;
    }

    cout << "\n--- Current Seats ---\n";
    for (size_t i = 0; i < booking.seats.size(); i++) {
        cout << (i + 1) << ". Row " << (booking.seats[i].first + 1)
             << ", Col " << (booking.seats[i].second + 1) << "\n";
    }

    cout << "How many seats to remove? ";
    const int numToRemove = getIntInput(1, static_cast<int>(booking.seats.size()));

    for (int i = 0; i < numToRemove; i++) {
        cout << "\n--- Remove Seat " << (i + 1) << " of " << numToRemove << " ---\n";
        cout << "Enter seat number to remove (1-" << booking.seats.size() << "): ";
        const auto index = static_cast<size_t>(
            getIntInput(1, static_cast<int>(booking.seats.size())) - 1);

        unbookSeat(movie.seats, booking.seats[index].first, booking.seats[index].second);
        booking.seats.erase(booking.seats.begin() + static_cast<ptrdiff_t>(index));
        cout << "Seat removed.\n";
    }
    return true;
}

void printSummary(const Booking& b) {
    cout << "\n========================================\n";
    cout << "   Booking modified successfully!\n";
    cout << "========================================\n";
    cout << "Booking ID     : " << b.bookingId << "\n";
    cout << "New Seats Count: " << b.seatCount << "\n";
    cout << "New Total Price: " << b.totalPrice << " EGP\n";
    cout << "========================================\n";
}

}  // namespace

void modifyBooking(vector<Booking>& bookingList, vector<Movie>& movieList) {
    if (bookingList.empty()) {
        cout << "No bookings available.\n";
        return;
    }

    cout << "Enter booking ID to modify: ";
    const int id = getIntInput(1, 999999);

    Booking* booking = findBookingById(bookingList, id);
    if (booking == nullptr) {
        cout << "Booking not found.\n";
        return;
    }
    if (!booking->isActive) {
        cout << "Cannot modify a cancelled booking.\n";
        return;
    }

    Movie* movie = findMovieById(movieList, booking->movieId);
    if (movie == nullptr) {
        cout << "Movie not found.\n";
        return;
    }

    cout << "\n1. Add seats\n2. Remove seats\n3. Cancel\n";
    const int choice = getIntInput(1, 3);
    if (choice == 3) {
        cout << "Modification cancelled.\n";
        return;
    }

    const bool changed = (choice == 1) ? addSeats(*movie, *booking)
                                       : removeSeats(*movie, *booking);
    if (!changed) {
        return;
    }

    applyPricing(*booking);

    // لو شال كل المقاعد، الحجز يتلغي بدل ما يفضل نشط بصفر مقاعد
    if (booking->seatCount == 0) {
        booking->isActive = false;
        cout << "All seats removed: the booking has been cancelled.\n";
    }

    printSummary(*booking);
}
