#pragma once
#ifndef CINEMA_DATA_H                 // إذا لم يكن CINEMA_DATA_H معرف من قبل
#define CINEMA_DATA_H                 // فعرفها (منع إعادة التضمين)

#include <string>                     // مكتبة النصوص (string)
#include <vector>                     // مكتبة القوائم الديناميكية (vector)
using namespace std;                  // للاختصار (عدم كتابة std::)


// 1. هيكل التاريخ
struct Date {
    int day;                          // اليوم (1-31)
    int month;                        // الشهر (1-12)
    int year;                         // السنة 
};

// 2. هيكل الصالة
struct Hall {
    int hallId;                       // رقم الصالة 
    string name;                      // اسم الصالة
    int rows;                         // عدد الصفوف
    int cols;                         // عدد المقاعد في الصف
    bool isVip;                       // هل الصالة VIP؟
};

// 3. هيكل الفيلم (قلب المشروع)
struct Movie {
    int movieId;                      // رقم الفيلم 
    string name;                      // اسم الفيلم
    string genre;                     // التصنيف 
    string showtime;                  // وقت العرض 
    double price;                     // سعر التذكرة
    int hallId;                       // رقم الصالة التي يُعرض فيها
    string status;                    // حالته: "Now Showing" / "Coming Soon" / "Ended"
    vector<vector<char>> seats;       // مصفوفة 2D للمقاعد: 'O' فاضي، 'X' محجوز
};

// 4. هيكل العميل
struct Customer {
    int customerId;                   // رقم العميل 
    string fullName;                  // الاسم الكامل
    string phone;                     // رقم الهاتف
};

// 5. هيكل الحجز
struct Booking {
    int bookingId;                    // رقم الحجز يبدأ من 1001
    int movieId;                      // رقم الفيلم المحجوز
    string movieName;                 // اسم الفيلم (للطباعة السريعة)
    Customer customer;                // بيانات العميل (كائن كامل)
    vector<pair<int, int>> seats;     // قائمة المقاعد المحجوزة (زوج: صف، عمود)
    int seatCount;                    // عدد المقاعد المحجوزة
    double pricePerSeat;              // سعر التذكرة الواحدة
    double originalPrice;             // السعر قبل الخصم
    double discountAmount;            // قيمة الخصم المطبق
    double totalPrice;                // السعر النهائي بعد الخصم
    Date bookingDate;                 // تاريخ الحجز
    bool isActive;                    // true = نشط، false = ملغي
    bool isPaid;                      // true = مدفوع، false = غير مدفوع

    // المُنشئ (Constructor) لتهيئة القيم الافتراضية
    Booking() : isActive(true), isPaid(false),
        discountAmount(0), seatCount(0) {
    }
};

// 6. الثوابت العامة (قيم ثابتة تستخدم في كل البرنامج)
const string ADMIN_PASSWORD = "admin123";   // كلمة سر المدير
const int ROWS_DEFAULT = 5;                 // عدد الصفوف الافتراضي للصالة
const int COLS_DEFAULT = 6;                 // عدد الأعمدة الافتراضي
const int DISCOUNT_THRESHOLD = 4;           // عدد التذاكر المؤهل للخصم (أكثر من 4)
const double DISCOUNT_RATE = 0.10;          // نسبة الخصم (10%)
const int STARTING_BOOKING_ID = 1001;       // أول رقم حجز

// 7. المتغيرات العامة (سيتم تعريفها فعلياً في main.cpp)
extern vector<Hall> halls;          // قائمة كل الصالات
extern vector<Movie> movies;        // قائمة كل الأفلام
extern vector<Booking> bookings;    // قائمة كل الحجوزات
extern int nextBookingId;           // الرقم التالي للحجز الجديد

#endif // نهاية الحماية (لو الملف تضمن مرة واحدة فقط)