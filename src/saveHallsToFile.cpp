#include "saveHallsToFile.h"
#include "fileUtils.h"
#include <fstream>
#include <iostream>

using namespace std;

void saveHallsToFile(const vector<Hall>& halls) {
    ensureDataDirectory();
    ofstream file("data/halls.txt");
    if (!file.is_open()) {
        cout << "Error: Cannot open the halls file for saving!\n";
        return;
    }

    for (const auto& h : halls) {
        file << h.hallId << "|" << h.name << "|" << h.rows << "|"
             << h.cols << "|" << h.isVip << "\n";
    }

    if (!file) {
        cout << "Error: Failed while writing the halls file!\n";
        return;
    }
    cout << "Halls saved successfully.\n";
}
