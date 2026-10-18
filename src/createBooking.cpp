#include "createBooking.h"
#include "bookingHelpers.h"
#include "displaySeats.h"
#include "getIntInput.h"
#include "getStringInput.h"
#include <algorithm>
#include <iostream>

using namespace std;

namespace {

constexpr int MAX_SEATS_PER_BOOKING = 10;

Movie& chooseMovie(vector<Movie>& movieList) {
    cout << "\n===== Movies =====\n";
    for (size_t i = 0; i < movieList.size(); i++) {
        cout << (i + 1) << ". " << movieList[i].name
             << " - " << movieList[i].price << " EGP\n";
    }

    cout << "\nChoose a movie (1-" << movieList.size() << "): ";
    const int choice = getIntInput(1, static_cast<int>(movieList.size()));
    return movieList[static_cast<size_t>(choice - 1)];
}

void readCustomer(Customer& customer) {
    cout << "\n===== Customer Information =====\n";
    cout << "Enter customer ID: ";
    customer.customerId = getIntInput(1, 999999);
    customer.fullName = getStringInput("Enter full name: ");
    customer.phone = getStringInput("Enter phone: ");
}

void readDate(Date& date) {
    cout << "\n===== Booking Date =====\n";
    cout << "Enter day (1-31): ";
    date.day = getIntInput(1, 31);
    cout << "Enter month (1-12): ";
    date.month = getIntInput(1, 12);
    cout << "Enter year (2020-2100): ";
    date.year = getIntInput(2020, 2100);
}

void printSummary(const Booking& b) {
    cout << "\n========================================\n";
    cout << "   Booking completed successfully!\n";
    cout << "========================================\n";
    cout << "Booking ID     : " << b.bookingId << "\n";
    cout << "Movie          : " << b.movieName << "\n";
    cout << "Customer       : " << b.customer.fullName << "\n";
    cout << "Number of Seats: " << b.seatCount << "\n";
    cout << "Total Price    : " << b.totalPrice << " EGP\n";
    cout << "========================================\n";
}

}  // namespace

void createBooking(vector<Movie>& movieList, vector<Booking>& bookingList) {
    if (movieList.empty()) {
        cout << "No movies available.\n";
        return;
    }

    Movie& movie = chooseMovie(movieList);
    cout << "\nYou selected: " << movie.name << "\n";

    // لو القاعة كلها محجوزة، الحلقة القديمة كانت هتفضل تدور للأبد
    const int freeSeats = countFreeSeats(movie);
    if (freeSeats == 0) {
        cout << "Sorry, this movie is fully booked.\n";
        return;
    }

    displaySeats(movie.seats);

    cout << "\nHow many seats do you want? ";
    const int wanted = getIntInput(1, min(MAX_SEATS_PER_BOOKING, freeSeats));

    Booking booking;
    booking.movieId = movie.movieId;
    booking.movieName = movie.name;
    booking.pricePerSeat = movie.price;

    selectSeats(movie, booking, wanted);
    applyPricing(booking);

    cout << "\n--- Price Details ---\n";
    cout << "Original Price: " << booking.originalPrice << " EGP\n";
    cout << "Discount: " << booking.discountAmount << " EGP\n";
    cout << "Total Price: " << booking.totalPrice << " EGP\n";

    readCustomer(booking.customer);

    booking.bookingId = bookingList.empty()
        ? STARTING_BOOKING_ID
        : bookingList.back().bookingId + 1;

    readDate(booking.bookingDate);

    bookingList.push_back(booking);
    printSummary(booking);
}
