#include "display_active.h"            // تضمين الهيدر
#include <iostream>                    // تضمين للإخراج

// تنفيذ دالة عرض الأفلام النشطة فقط (Now Showing)
void displayActiveMovies(const vector<Movie>& movies) { // بداية الدالة
    bool found = false;               // علم لمعرفة ما إذا وُجد فيلم نشط
    for (const auto& m : movies) {    // التكرار على الأفلام
        if (m.status == "Now Showing") { // التحقق من الحالة
            cout << "ID: " << m.movieId << " | Name: " << m.name
                << " | Hall: " << m.hallId
                << " | Price: " << m.price << "\n"; // طباعة معلومات الفيلم النشط
            found = true;              // تعيين العلم
        }
    }
    if (!found) cout << "No 'Now Showing' movies found.\n"; // إن لم يوجد أي فيلم نشط
}