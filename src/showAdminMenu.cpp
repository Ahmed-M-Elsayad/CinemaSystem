#include "showAdminMenu.h"
#include "adminAddMovie.h"
#include "adminEditMovie.h"
#include "adminDeleteMovie.h"
#include "showSalesReport.h"
#include "saveAllData.h"
#include "loadAllData.h"
#include <iostream>

using namespace std;

void showAdminMenu(vector<Movie>& movies,
    vector<Hall>& halls,
    vector<Booking>& bookings) {
    int choice;

    while (true) {
        cout << "\n========== ADMIN MENU ==========\n";
        cout << "1. Add Movie\n";
        cout << "2. Edit Movie\n";
        cout << "3. Delete Movie\n";
        cout << "4. Sales Report\n";
        cout << "5. Save All Data\n";
        cout << "6. Load All Data\n";
        cout << "7. Exit Admin Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            adminAddMovie(movies, halls);
            break;
        case 2:
            adminEditMovie(movies);
            break;
        case 3:
            adminDeleteMovie(movies, bookings);
            break;
        case 4:
            showSalesReport(movies, bookings);
            break;
        case 5:
            saveAllData(halls, movies, bookings);
            break;
        case 6:
            loadAllData(halls, movies, bookings);
            break;
        case 7:
            cout << " Exiting Admin Menu.\n";
            return;
        default:
            cout << " Invalid choice! Please enter a number between 1 and 7.\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
}