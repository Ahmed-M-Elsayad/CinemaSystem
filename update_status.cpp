#include "update_status.h"              // تضمين الهيدر
#include "find_movie.h"                 // استخدام دالة البحث
#include <iostream>                     // تضمين للإخراج

// تنفيذ دالة تحديث حالة الفيلم
void updateMovieStatus(vector<Movie>& movies, int movieId, const string& newStatus) {
    Movie* m = findMovieById(movies, movieId); // البحث عن الفيلم
    if (!m) {                          // إن لم نجده
        cout << "Movie not found\n";   // إخطار
        return;                        // خروج
    }
    m->status = newStatus;             // تعيين الحالة الجديدة
    cout << "Status updated for movie id " << movieId << ". New status: " << newStatus << "\n"; // إخطار
}