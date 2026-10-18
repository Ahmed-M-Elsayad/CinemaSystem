#include "delete_movie.h"   // تضمين الهيدر
#include <iostream>     // تضمين للإخراج
#include <algorithm>     // تضمين للبحث والحذف

// تنفيذ دالة حذف الفيلم إذا لم يكن عليه حجوزات نشطة
bool deleteMovie(std::vector<Movie>& movies, int movieId, const std::vector<Booking>& bookings) {
    for (const auto& b : bookings) {     // التحقق من وجود حجوزات متعلقة بالفيلم
        if (b.movieId == movieId && b.isActive) {  // إن وُجد حجز نشط
            std::cout << "Cannot delete movie " << movieId << ": active bookings exist.\n";  // منع الحذف
            return false;    // إرجاع false
        }
    }

    auto it = std::ranges::find_if(movies, [&](const Movie& m) {    // إيجاد الفيلم
        return m.movieId == movieId;
    });

    if (it == movies.end()) {    // إن لم يوجد الفيلم
        std::cout << "Movie not found\n";   // إخطار
        return false;     // إرجاع false
    }

    movies.erase(it);    // حذف الفيلم من القائمة
    std::cout << "Movie " << movieId << " deleted successfully.\n"; // إخطار النجاح
    return true;  // إرجاع true
}
