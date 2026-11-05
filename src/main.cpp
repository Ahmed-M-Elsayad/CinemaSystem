#include <iostream>
#include "CinemaData.h"
#include "loadAllData.h"
#include "saveAllData.h"
#include "seedData.h"
#include "adminLogin.h"
#include "showAdminMenu.h"
#include "createBooking.h"
#include "modifyBooking.h"
#include "cancelBooking.h"
#include "clearScreen.h"
#include "getIntInput.h"
#include "pressEnterToContinue.h"
#include "printHeader.h"

using namespace std;

// المتغيرات العامة
vector<Hall> halls;
vector<Movie> movies;
vector<Booking> bookings;

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
        cout << "  1. Customer Mode\n";
        cout << "  2. Admin Mode\n";
        cout << "  3. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";

        const int choice = getIntInput(1, 3);
        // التعديل هنا: تم مسح سطر cin.ignore غير الضروري

        if (choice == 1) {
            clearScreen();
            printHeader("CUSTOMER MODE");
            cout << "1. Book a Ticket\n";
            cout << "2. Modify a Booking\n";
            cout << "3. Cancel a Booking\n";
            cout << "4. Back to Main Menu\n";
            cout << "Enter your choice: ";

            int custChoice = getIntInput(1, 4);

            if (custChoice == 1) createBooking(movies, bookings);
            else if (custChoice == 2) modifyBooking(bookings, movies);
            else if (custChoice == 3) cancelBooking(bookings, movies);
        }
        else if (choice == 2) {
            clearScreen();
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
