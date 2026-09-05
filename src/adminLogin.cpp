#include "adminLogin.h"
#include <iostream>

using namespace std;

bool adminLogin() {
    string password;
    const string correctPassword = "admin123";
    int attempts = 3;

    while (attempts > 0) {
        cout << "\nEnter password (attempts left: " << attempts << "): ";
        cin >> password;

        if (password == correctPassword) {
            cout << "\nLogin successful! Welcome, Admin.\n";
            return true;
        }
        else {
            attempts--;
            if (attempts > 0) {
                cout << "Incorrect password! You have " << attempts << " attempts left.\n";
            }
        }
    }

    cout << "Access denied after 3 failed attempts!\n";
    return false;
}