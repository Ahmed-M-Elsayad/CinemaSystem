#include "display_halls.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayAllHalls(const vector<Hall>& halls) {
    if (halls.empty()) {
        cout << "No halls available.\n";
        return;
    }

    cout << left
        << setw(6) << "ID"
        << setw(20) << "Name"
        << setw(8) << "Rows"
        << setw(8) << "Cols"
        << setw(6) << "VIP" << "\n";
    cout << string(48, '-') << "\n";

    for (const auto& h : halls) {
        cout << left
            << setw(6) << h.hallId
            << setw(20) << h.name
            << setw(8) << h.rows
            << setw(8) << h.cols
            << setw(6) << (h.isVip ? "Yes" : "No") << "\n";
    }
}
