#include <iostream>
#include <limits>
#include "CinemaData.h"
#include "loadAllData.h"
#include "saveAllData.h"
#include "seedData.h"
#include "adminLogin.h"
#include "showAdminMenu.h"
#include "createBooking.h"
#include "clearScreen.h"
#include "getIntInput.h"
#include "pressEnterToContinue.h"
#include "printHeader.h"

using namespace std;

vector<Hall> halls;
vector<Movie> movies;
vector<Booking> bookings;
int nextBookingId = STARTING_BOOKING_ID;

int main() {

    cout << "\nLoading data...\n";
    loadAllData(halls, movies, bookings);

    if (halls.empty() && movies.empty()) {
        cout << "\nNo data found. Adding sample data...\n";
        seedData(halls, movies);
        saveAllData(halls, movies, bookings);
        cout << "Sample data added and saved.\n";
    }

    cout << "\nSystem ready! (Halls: " << halls.size()
         << ", Movies: " << movies.size()
         << ", Bookings: " << bookings.size() << ")\n";

    while (true) {
        clearScreen();
        printHeader("CINEMA SYSTEM");

        cout << "========================================\n";
        cout << "  1. Customer Mode (Booking)\n";
        cout << "  2. Admin Mode\n";
        cout << "  3. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";

        // getIntInput بيتعامل مع الإدخال الغلط (قبل كده cin >> choice كان ممكن يعمل حلقة لا نهائية)
        const int choice = getIntInput(1, 3);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            cout << "\nCustomer Mode selected.\n";
            createBooking(movies, bookings);
        }
        else if (choice == 2) {
            cout << "\nAdmin Mode selected.\n";
            if (adminLogin()) {
                showAdminMenu(movies, halls, bookings);
            }
            else {
                cout << "Access denied. Returning to main menu.\n";
            }
        }
        else {
            cout << "\nSaving data before exit...\n";
            saveAllData(halls, movies, bookings);
            cout << "Data saved. Goodbye!\n";
            return 0;
        }

        pressEnterToContinue();
    }
}
