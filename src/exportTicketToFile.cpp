#include "exportTicketToFile.h"
#include <fstream>
#include <iostream>

void exportTicketToFile(const Booking& booking, const Movie& movie) {
    std::string filename = "receipts/Ticket_" + std::to_string(booking.bookingId) + ".txt";
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Cannot create file " << filename << "\n";
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
    std::cout << "Ticket exported to: " << filename << "\n";
}