#include "exportTicketToFile.h"
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;

void exportTicketToFile(const Booking& booking, const Movie& movie) {

    std::filesystem::create_directories("receipts");

    string filename = "receipts/Ticket_" + to_string(booking.bookingId) + ".txt";
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Cannot create file " << filename << "\n";
        return;
    }

    file << "========================================\n";
    file << "         CINEMA TICKET\n";
    file << "========================================\n";
    file << "Booking ID: " << booking.bookingId << "\n";
    file << "Customer: " << booking.customer.fullName << "\n";
    file << "Movie: " << movie.name << "\n";
    file << "Showtime: " << movie.showtime << "\n";
    file << "Seats: " << booking.seatCount << "\n";
    file << "Total Price: " << booking.totalPrice << " EGP\n";
    file << "========================================\n";

    file.close();
    cout << "Ticket exported to: " << filename << "\n";
}
