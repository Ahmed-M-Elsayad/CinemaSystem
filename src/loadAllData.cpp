#include "loadAllData.h"
#include "loadHallsFromFile.h"
#include "loadMoviesFromFile.h"
#include "loadBookingsFromFile.h"

using namespace std;

void loadAllData(vector<Hall>& halls, vector<Movie>& movies, vector<Booking>& bookings) {
    // استدعاء دوال التحميل الآمنة (اللي بتتخطى السطور التالفة)
    loadHallsFromFile(halls);
    loadMoviesFromFile(movies);
    loadBookingsFromFile(bookings);
}
