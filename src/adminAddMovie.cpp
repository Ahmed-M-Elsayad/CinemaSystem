#include "adminAddMovie.h"
#include "getStringInput.h" 
#include "getIntInput.h"    // تم إضافتها لاستخدام دالة إدخال الأرقام الآمنة
#include <iostream>
#include <limits>

using namespace std;

void adminAddMovie(vector<Movie>& movies, const vector<Hall>& halls) {
    if (halls.empty()) {
        cout << "\nError: No halls are registered! Add a hall first.\n";
        return;
    }

    cout << "\n=== Available Halls ===" << endl;
    for (const auto& hall : halls) {
        cout << "Hall ID: " << hall.hallId
            << " | Name: " << hall.name
            << " | Seats: " << hall.rows << "x" << hall.cols << endl;
    }

    Movie newMovie;

    // إصلاح مشكلة تكرار الـ ID
    int maxId = 0;
    for (const auto& m : movies) {
        if (m.movieId > maxId) maxId = m.movieId;
    }
    newMovie.movieId = maxId + 1;

    cout << "\n--- Adding New Movie ---\n";

    // استخدام getStringInput للنصوص (آمن ضد المسافات و \n ورمز |)
    newMovie.name = getStringInput("Movie Name: ");
    newMovie.genre = getStringInput("Genre (Action/Drama/Comedy): ");
    newMovie.showtime = getStringInput("Showtime (e.g., 8:00 PM): ");

    cout << "Ticket Price: ";
    // حماية: منع إدخال حروف أو أرقام سالبة (السعر من نوع double، فلا توجد دالة جاهزة له)
    while (!(cin >> newMovie.price) || newMovie.price <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid positive number for the price: ";
    }

    // التعديل الجديد: استخدام getIntInput بدلاً من حلقة while و cin.ignore
    // نضع حداً أقصى كبيراً (مثلاً 9999) لأننا لا نعرف أرقام الصالات مسبقاً
    cout << "Select Hall ID: ";
    int selectedHallId = getIntInput(1, 9999);

    bool hallFound = false;
    for (const auto& hall : halls) {
        if (hall.hallId == selectedHallId) {
            hallFound = true;
            newMovie.hallId = hall.hallId;
            // إنشاء مقاعد الصالة بحرف 'O' (فاضي)
            newMovie.seats.assign(hall.rows, vector<char>(hall.cols, 'O'));
            break;
        }
    }

    if (!hallFound) {
        cout << "Error: Hall ID not found!\n";
        return;
    }

    // استخدام getStringInput للحالة
    newMovie.status = getStringInput("Movie Status (Now Showing / Coming Soon / Ended): ");
    if (newMovie.status.empty()) newMovie.status = "Now Showing";

    movies.push_back(newMovie);
    cout << "\nMovie added successfully: \"" << newMovie.name << "\"!\n";
}
