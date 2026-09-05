#include "saveMoviesToFile.h"
#include <fstream>
#include <iostream>

using namespace std;

void saveMoviesToFile(const vector<Movie>& movies) {
    // فتح الملف للكتابة
    ofstream moviesFile("data/movies.txt");

    if (moviesFile.is_open()) {
		for (const auto& m : movies) { // لكل فيلم في المصفوفة
            // 1. حفظ البيانات الأساسية للفيلم (مفصولة بـ |)
            moviesFile << m.movieId << "|" << m.name << "|" << m.genre << "|"
                << m.showtime << "|" << m.price << "|" << m.hallId << "|" << m.status << "\n";

            // 2. حفظ أبعاد مصفوفة المقاعد (صفوف | أعمدة)
            int rows = m.seats.size();
			int cols = (rows > 0) ? m.seats[0].size() : 0; // التحقق من وجود صفوف لتجنب الوصول إلى عنصر غير موجود
            moviesFile << rows << "|" << cols << "\n";

            // 3. حفظ كل صف من المقاعد كسطر (مثال: OOOXXX)
			for (const auto& row : m.seats) { // لكل صف في مصفوفة المقاعد
				for (char seat : row) { // لكل مقعد في الصف
                    moviesFile << seat;
                }
                moviesFile << "\n";
            }
        }
        moviesFile.close();
        cout << "Movies saved successfully in the file.\n";
    }
    else {
        cout << "Error: Cannot open the movies file for saving!\n";
    }
}