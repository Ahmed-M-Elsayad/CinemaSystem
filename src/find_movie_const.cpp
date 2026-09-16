#include "find_movie.h"                // تضمين الهيدر

// تنفيذ نسخة القراءة (const) من دالة البحث
const Movie* findMovieById(const vector<Movie>& movies, int movieId) { // بداية الدالة
    for (const auto& m : movies) {    // التكرار على الأفلام
        if (m.movieId == movieId) {   // مطابقة المعرف
            return &m;                // نعيد مؤشر ثابت إلى الكائن
        }
    }
    return nullptr;                   // إن لم نجده نعيد nullptr
}