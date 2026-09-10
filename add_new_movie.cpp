#include "add_new_movie.h"             // تضمين هيدر الدالة
#include <iostream>                    // تضمين للإدخال/الإخراج
#include <limits>                      // لتنظيف باف الإدخال

// تنفيذ دالة إضافة فيلم جديد
void addNewMovie(vector<Movie>& movies, const vector<Hall>& halls) { // تعريف الدالة
    Movie m;                          // إنشاء كائن فيلم مؤقت لتجميع المدخلات
    m.movieId = (movies.empty() ? 1 : movies.back().movieId + 1); // تعيين movieId بسيط (أبسط من nextMovieId)

    cout << "Enter movie name: ";     // طلب اسم الفيلم
    getline(cin, m.name);             // قراءة السطر كاسم الفيلم
    if (m.name.empty()) {             // تحقق من عدم فراغ الاسم
        cout << "Name cannot be empty. Aborted.\n"; // إخطار وإلغاء العملية
        return;                       // خروج من الدالة
    }                                

    cout << "Available halls:\n";     // عرض قائمة الصالات
    for (const auto& h : halls) {     // تكرار على الصالات
        cout << "  [" << h.hallId << "] " << h.name << " (" << h.rows << "x" << h.cols << ")"
            << (h.isVip ? " VIP" : "") << "\n";    // طباعة تفاصيل الصالة
    }

    cout << "Enter hall id to assign: "; // طلب معرف الصالة
    int hid;                          // متغير لحفظ المعرف المدخل
    if (!(cin >> hid)) {              // محاولة قراءة المعرف والتحقق من النجاح
        cin.clear();                  // إعادة تهيئة حالة التدفق لو حدث خطأ
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // تنظيف باف الإدخال
        cout << "Invalid hall id\n";  // إعلام المستخدم
        return;                       // خروج
    }

    const Hall* foundHall = nullptr;  // مؤشر للصالة المختارة
    for (const auto& h : halls) {     // البحث عن الصالة في القائمة
        if (h.hallId == hid) {        // إذا تطابقت المعرفات
            foundHall = &h;           // احتفظ بالمؤشر
            break;                    // أنهِ البحث
        }
    }
    if (!foundHall) {                 // إن لم نجد الصالة
        cout << "Hall not found\n";    // إعلام المستخدم
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // تنظيف باف
        return;                       // خروج
    }
    m.hallId = foundHall->hallId;     // ربط معرف الصالة بالفيلم

    cout << "Enter ticket price: ";   // طلب السعر
    if (!(cin >> m.price)) {          // محاولة قراءة السعر
        cin.clear();                  // إعادة تهيئة حالة الخطأ
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // تنظيف الباف
        cout << "Invalid price\n";    // إعلام المستخدم
        return;                       // خروج
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // تنظيف نهاية السطر قبل getline التالي

    cout << "Enter status (Now Showing / Coming Soon / Ended): "; // طلب الحالة
    getline(cin, m.status);            // قراءة الحالة
    if (m.status.empty()) m.status = "Coming Soon"; // قيمة افتراضية إن لم يُدخل المستخدم

    // تهيئة مقاعد الصالة بحسب أبعادها: 'O' يعني فارغ
    m.seats.assign(foundHall->rows, vector<char>(foundHall->cols, 'O')); // تعبئة المصفوفة

    movies.push_back(move(m));        // إضافة الفيلم إلى القائمة (نقل الموارد)
    cout << "Movie added successfully.\n"; // إعلام النجاح
}                         
 
  