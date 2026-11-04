#include "createBooking.h"
#include "bookingHelpers.h"
#include "displaySeats.h"
#include "getIntInput.h"
#include "getStringInput.h"
#include "printTicket.h"
#include "exportTicketToFile.h"
#include <algorithm>
#include <iostream>

using namespace std;

namespace {
    constexpr int MAX_SEATS_PER_BOOKING = 10;

    Movie& chooseMovie(vector<Movie>& movieList) {
        vector<size_t> available;
        for (size_t i = 0; i < movieList.size(); ++i) {
            if (movieList[i].status == "Now Showing") {
                available.push_back(i);
            }
        }

        cout << "\n===== Now Showing Movies =====\n";
        for (size_t j = 0; j < available.size(); ++j) {
            const Movie& m = movieList[available[j]];
            cout << (j + 1) << ". " << m.name
                << " - " << m.price << " EGP\n";
        }

        cout << "\nChoose a movie (1-" << available.size() << "): ";
        const int choice = getIntInput(1, static_cast<int>(available.size()));
        return movieList[available[static_cast<size_t>(choice - 1)]];
    }

    // تم إصلاح هذه الدالة بالكامل وإغلاق القوس في مكانه الصحيح
    void readCustomer(Customer& customer, const vector<Booking>& bookingList) {
        int maxId = 0;
        for (const auto& b : bookingList) {
            if (b.customer.customerId > maxId) maxId = b.customer.customerId;
        }
        customer.customerId = maxId + 1;
        
        cout << "Customer ID (auto-generated): " << customer.customerId << "\n";
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

    bool hasShowing = false;
    for (const auto& m : movieList) {
        if (m.status == "Now Showing") { hasShowing = true; break; }
    }
    if (!hasShowing) {
        cout << "No 'Now Showing' movies available for booking.\n";
        return;
    }

    Movie& movie = chooseMovie(movieList);
    cout << "\nYou selected: " << movie.name << "\n";

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

    // إصلاح: تمرير bookingList كمعامل ثاني
    readCustomer(booking.customer, bookingList);

    int maxId = 0;
    for (const auto& b : bookingList) {
        if (b.bookingId > maxId) maxId = b.bookingId;
    }
    booking.bookingId = (maxId == 0) ? STARTING_BOOKING_ID : (maxId + 1);

    readDate(booking.bookingDate);
    
    // إصلاح: تحديد حالة الدفع
    booking.isPaid = true;

    bookingList.push_back(booking);

    printSummary(booking);
    printTicket(booking, movie);
    exportTicketToFile(booking, movie);
}