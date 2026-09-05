#include "adminEditMovie.h"
#include <iostream>

using namespace std;

void adminEditMovie(vector<Movie>& movies) {
    // 1. التأكد من وجود أفلام مسجلة
    if (movies.empty()) {
        cout << "\nError: No movies registered to edit!\n";
        return;
    }

    // 2. عرض قائمة الأفلام الحالية
    cout << "\n=== Current Movies List ===\n";
    for (const auto& m : movies) {
        cout << "ID: " << m.movieId
            << " | Name: " << m.name
            << " | Price: " << m.price
            << " | Status: " << m.status << endl;
    }

    // 3. طلب رقم الفيلم من المدير
    cout << "\nInput the ID of the movie you want to edit: ";
    int selectedMovieId;
    cin >> selectedMovieId;

    // 4. البحث عن الفيلم
    bool movieFound = false;
    for (auto& m : movies) {
        if (m.movieId == selectedMovieId) {
            movieFound = true;

            // 5. عرض قائمة الخيارات للتعديل
            cout << "\n--- Edit Movie: " << m.name << " ---\n";
            cout << "1. Edit Price\n";
            cout << "2. Edit Status (Now Showing / Coming Soon / Ended)\n";
            cout << "3. Cancel and Return\n";
            cout << "Choose the operation number: ";

            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Input the new price: ";
                cin >> m.price;
                cout << "\nThe movie price has been updated successfully!\n";
                break;
            case 2:
                cout << "Input the new status: ";
                cin.ignore(); // تنظيف الـ buffer قبل قراءة النصوص
                getline(cin, m.status);
                if (m.status.empty()) m.status = "Now Showing";
                cout << "\nThe movie status has been updated successfully!\n";
                break;
            case 3:
                cout << "Operation cancelled.\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
            }
            break; // خروج من اللوب بعد إيجاد الفيلم
        }
    }

    // لو الفيلم غير موجود
    if (!movieFound) {
        cout << "Error: No movie found with the specified ID!\n";
    }
}