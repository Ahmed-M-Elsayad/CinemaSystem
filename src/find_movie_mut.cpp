#include "find_movie.h"                // تضمين الهيدر

// تنفيذ نسخة التعديل (non-const) من دالة البحث
Movie* findMovieById(vector<Movie>& movies, int movieId) { // بداية الدالة
    for (auto& m : movies) {          // التكرار على الأفلام
        if (m.movieId == movieId) {   // مطابقة المعرف
            return &m;                // نعيد مؤشر قابل للتعديل
        }
    }
    return nullptr;                   // إن لم نجد الفيلم نعيد nullptr
}