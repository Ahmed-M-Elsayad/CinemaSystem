#include "showAdminMenu.h"
#include <iostream>

using namespace std;

void showAdminMenu(vector<Movie>& movies,
    vector<Hall>& halls,
    vector<Booking>& bookings) {
    int choice;

    while (true) {
        cout << "\n========== ADMIN MENU ==========\n";
        cout << "1. Add Movie (coming soon)\n";
        cout << "2. Edit Movie (coming soon)\n";
        cout << "3. Delete Movie (coming soon)\n";
        cout << "4. Sales Report (coming soon)\n";
        cout << "5. Save All Data (coming soon)\n";
        cout << "6. Load All Data (coming soon)\n";
        cout << "7. Exit Admin Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << " Add Movie feature will be available soon.\n";
            break;
        case 2:
            cout << " Edit Movie feature will be available soon.\n";
            break;
        case 3:
            cout << " Delete Movie feature will be available soon.\n";
            break;
        case 4:
            cout << " Sales Report feature will be available soon.\n";
            break;
        case 5:
            cout << " Save All Data feature will be available soon.\n";
            break;
        case 6:
            cout << " Load All Data feature will be available soon.\n";
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