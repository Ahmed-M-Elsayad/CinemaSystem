#include "adminDeleteMovie.h"
#include <iostream>

using namespace std;

void adminDeleteMovie(vector<Movie>& movies, const vector<Booking>& bookings) {
    // 1. التأكد من وجود أفلام
    if (movies.empty()) {
        cout << "\nError: No movies registered to delete!\n";
        return;
    }

    // 2. عرض قائمة الأفلام الحالية
    cout << "\n=== List of current films ===\n";
    for (const auto& m : movies) {
        cout << "ID: " << m.movieId
            << " | name: " << m.name
            << " | status: " << m.status << endl;
    }

    // 3. طلب رقم الفيلم المطلوب حذفه
    cout << "\nEnter the ID of the movie you want to delete: ";
    int selectedMovieId;
    cin >> selectedMovieId;

    // 4. البحث عن الفيلم
    bool movieFound = false;
    int movieIndex = -1;

    for (size_t i = 0; i < movies.size(); i++) {
        if (movies[i].movieId == selectedMovieId) {
            movieFound = true;
            movieIndex = i;
            break;
        }
    }

    if (!movieFound) {
        cout << "Error: No movie found with this ID!\n";
        return;
    }

    // 5. التحقق من وجود حجوزات نشطة لهذا الفيلم
    bool hasActiveBookings = false;
    for (const auto& b : bookings) {
        // إذا كان الحجز لنفس الفيلم وكان نشطاً (غير ملغي)
        if (b.movieId == selectedMovieId && b.isActive) {
            hasActiveBookings = true;
            break;
        }
    }

    // 6. منع الحذف إذا وجدت حجوزات نشطة
    if (hasActiveBookings) {
        cout << "\nError: Cannot delete the movie \"" << movies[movieIndex].name
            << "\" because it has active bookings associated with it!\n";
        cout << "Please cancel the bookings first before attempting to delete the movie.\n";
        return;
    }

    // 7. حذف الفيلم إذا لم توجد حجوزات نشطة
    string deletedMovieName = movies[movieIndex].name;
    movies.erase(movies.begin() + movieIndex);

    cout << "\nSuccess: The movie \"" << deletedMovieName << "\" has been deleted successfully!\n";
}