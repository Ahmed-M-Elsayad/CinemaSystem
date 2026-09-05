#include "saveHallsToFile.h"
#include <fstream>
#include <iostream>

using namespace std;

void saveHallsToFile(const vector<Hall>& halls) {
    // فتح الملف للكتابة (لو مش موجود هيقوم بإنشائه)
    ofstream hallsFile("data/halls.txt");

    if (hallsFile.is_open()) {
        for (const auto& h : halls) {
            // نفس الصيغة: hallId|name|rows|cols|isVip
            hallsFile << h.hallId << "|" << h.name << "|" << h.rows << "|" << h.cols << "|" << h.isVip << "\n";
        }
        hallsFile.close();
        cout << "Data saved successfully in the file.\n";
    }
    else {
        cout << "Error: Cannot open the halls file for saving!\n";
    }
}