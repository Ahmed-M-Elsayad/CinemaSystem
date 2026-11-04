#include "adminEditMovie.h"
#include "getStringInput.h" // تمت إضافتها لاستخدام الدالة الآمنة
#include <iostream>
#include <limits>

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

    // 3. طلب رقم الفيلم من المدير (مع حماية من الحروف)
    cout << "\nInput the ID of the movie you want to edit: ";
    int selectedMovieId;
    while (!(cin >> selectedMovieId)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number for the ID: ";
    }

    // 4. البحث عن الفيلم
    bool movieFound = false;
    for (auto& m : movies) {
        if (m.movieId == selectedMovieId) {
            movieFound = true;

            // 5. عرض قائمة الخيارات للتعديل (مع حماية من الحروف)
            cout << "\n--- Edit Movie: " << m.name << " ---\n";
            cout << "1. Edit Price\n";
            cout << "2. Edit Status (Now Showing / Coming Soon / Ended)\n";
            cout << "3. Cancel and Return\n";
            cout << "Choose the operation number: ";

            int choice;
            while (!(cin >> choice) || choice < 1 || choice > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Enter a number between 1 and 3: ";
            }

            switch (choice) {
            case 1:
                cout << "Input the new price: ";
                // حماية عند إدخال السعر
                while (!(cin >> m.price) || m.price <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid positive number for the price: ";
                }
                cout << "\nThe movie price has been updated successfully!\n";
                break;
            case 2:
                // التعديل هنا: استخدام getStringInput بدلاً من getline
                m.status = getStringInput("Input the new status: ");
                if (m.status.empty()) m.status = "Now Showing";
                cout << "\nThe movie status has been updated successfully!\n";
                break;
            case 3:
                cout << "Operation cancelled.\n";
                break;
            }
            break; // خروج من اللوب بعد إيجاد الفيلم وتعديله
        }
    }

    // لو الفيلم غير موجود
    if (!movieFound) {
        cout << "Error: No movie found with the specified ID!\n";
    }
}
