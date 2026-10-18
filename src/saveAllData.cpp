#include "saveAllData.h"
#include "saveHallsToFile.h"     
#include "saveMoviesToFile.h"      
#include "saveBookingsToFile.h"    
#include <iostream>

using namespace std;

void saveAllData(const vector<Hall>& halls, const vector<Movie>& movies, const vector<Booking>& bookings) {
    // 1. استدعاء دالة حفظ الصالات
    saveHallsToFile(halls);

    // 2. استدعاء دالة حفظ الأفلام
    saveMoviesToFile(movies);

    // 3. استدعاء دالة حفظ الحجوزات
    saveBookingsToFile(bookings);

    // 4. طباعة رسالة نجاح عامة
    cout << "\n✅ All data saved successfully!\n";
}