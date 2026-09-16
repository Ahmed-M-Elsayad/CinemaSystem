#include "display.h"               // تضمين الهيدر
#include <iostream>                    // تضمين للإخراج

// تنفيذ دالة عرض جميع الأفلام (بما في ذلك المنتهية)
void displayAllMovies(const vector<Movie>& movies) { // بداية الدالة
    if (movies.empty()) {             // إذا لم توجد أفلام
        cout << "No movies available.\n"; // إخطار
        return;                       // نهاية الدالة
    }
    for (const auto& m : movies) {    // التكرار على كل فيلم
        cout << "ID: " << m.movieId << " | Name: " << m.name
            << " | Hall: " << m.hallId
            << " | Price: " << m.price
            << " | Status: " << m.status << "\n"; // طباعة تفاصيل الفيلم
    }
}