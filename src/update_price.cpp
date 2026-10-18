#include "update_price.h"               // تضمين الهيدر
#include "find_movie.h"                 // استخدام دالة البحث
#include <iostream>                     // تضمين للإخراج

// تنفيذ دالة تحديث سعر الفيلم
void updateMoviePrice(vector<Movie>& movies, int movieId, double newPrice) { // بداية
    Movie* m = findMovieById(movies, movieId); // البحث عن الفيلم (قابل للتعديل)
    if (!m) {                          // إن لم يُعثر على الفيلم
        cout << "Movie not found\n";   // إخطار المستخدم
        return;                        // إنهاء الدالة
    }
    m->price = newPrice;               // تحديث السعر
    cout << "Price updated for movie id " << movieId << ". New price: " << newPrice << "\n"; // إخطار النجاح
}