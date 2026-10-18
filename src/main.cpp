#include <iostream>
#include "CinemaData.h"
#include "loadAllData.h"
#include "saveAllData.h"
#include "seedData.h"
#include "adminLogin.h"
#include "showAdminMenu.h"
#include "createBooking.h"
#include "clearScreen.h"
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

    int choice;

    while (true) {
        clearScreen();                    
        printHeader("CINEMA SYSTEM");  

        cout << "========================================\n";
        cout << "  1. Customer Mode (Booking)\n";
        cout << "  2. Admin Mode\n";
        cout << "  3. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // تنظيف المخزن المؤقت

        switch (choice) {
        case 1:
            cout << "\nCustomer Mode selected.\n";
            createBooking(movies, bookings); 
            break;

        case 2:
            cout << "\nAdmin Mode selected.\n";
            if (adminLogin()) {            
                showAdminMenu(movies, halls, bookings); 
            }
            else {
                cout << "Access denied. Returning to main menu.\n";
            }
            break;

        case 3:
            cout << "\nSaving data before exit...\n";
            saveAllData(halls, movies, bookings); 
            cout << "Data saved. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice! Please enter 1, 2, or 3.\n";
        }

        pressEnterToContinue(); 
    }

    return 0;
}