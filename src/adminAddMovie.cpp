#include "adminAddMovie.h"
#include <iostream>

using namespace std;

void adminAddMovie(vector<Movie>& movies, const vector<Hall>& halls) {
    // 1. التأكد من وجود صالات قبل إضافة الفيلم
    if (halls.empty()) {
        cout << "\nError: No lounges are registered! Add a lounge first.\n";
        return;
    }

    // 2. عرض الصالات المتاحة للمدير
    cout << "\n=== Available Halls ===" << endl;
    for (const auto& hall : halls) {
        cout << "Hall ID: " << hall.hallId
            << " | Name: " << hall.name
            << " | Seats: " << hall.rows << "x" << hall.cols << endl;
    }

    // 3. إدخال بيانات الفيلم الجديد
    Movie newMovie;
    // توليد ID تلقائي بناءً على آخر فيلم مضاف
    newMovie.movieId = movies.size() + 1;

    cout << "\n--- Adding New Movie ---\n";
    cout << "Movie Name: ";
    cin.ignore(); // لتنظيف الـ newline المتبقي
    getline(cin, newMovie.name);

    cout << "Genre (Action/Drama/Comedy): ";
    getline(cin, newMovie.genre);

    cout << "Showtime (e.g., 8:00 PM): ";
    getline(cin, newMovie.showtime);

    cout << "Ticket Price: ";
    cin >> newMovie.price;

    cout << "Select Hall ID: ";
    int selectedHallId;
    cin >> selectedHallId;

    // 4. البحث عن الصالة المختارة وتجهيز مقاعدها
    bool hallFound = false;
    for (const auto& hall : halls) {
        if (hall.hallId == selectedHallId) {
            hallFound = true;
            newMovie.hallId = hall.hallId;

            // إنشاء مصفوفة 2D للمقاعد وملءها بحرف 'O' (فاضي) حسب أبعاد الصالة
            newMovie.seats.assign(hall.rows, vector<char>(hall.cols, 'O'));
            break;
        }
    }

    // لو الصالة غير موجودة، نوقف العملية
    if (!hallFound) {
        cout << "Error: Hall ID not found!\n";
        return;
    }

    // 5. إدخال الحالة (اختياري، مع قيمة افتراضية)
    cout << "Movie Status (Now Showing / Coming Soon / Ended): ";
    cin.ignore();
    getline(cin, newMovie.status);
    if (newMovie.status.empty()) newMovie.status = "Now Showing";

    // 6. إضافة الفيلم للقائمة
    movies.push_back(newMovie);

    cout << "\nMovie added successfully: \"" << newMovie.name << "\"!\n";
}