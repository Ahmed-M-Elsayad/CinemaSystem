#include "add_new_hall.h"           // تضمين إعلان الدالة
#include <iostream>                 // للإدخال والإخراج
#include <limits>                   // لتنظيف باف الإدخال

// تنفيذ دالة إضافة صالة جديدة
void addNewHall(vector<Hall>& halls) {
    Hall h;                        // كائن مؤقت لتجميع بيانات الصالة الجديدة

    // تعيين hallId: إما 1 إن كانت القائمة فارغة وإلا المعرف التالي
    h.hallId = (halls.empty() ? 1 : halls.back().hallId + 1);

    std::cout << "Enter hall name: "; // طلب اسم الصالة
    std::getline(std::cin, h.name);    // قراءة الاسم كسطر كامل
    if (h.name.empty()) {              // التحقق من أن الاسم غير فارغ
        std::cout << "Name cannot be empty. Aborted.\n";
        return;                        // إلغاء الإضافة في حالة فراغ الاسم
    }

    std::cout << "Enter number of rows: "; // طلب عدد الصفوف
    if (!(std::cin >> h.rows)) {            // قراءة عدد الصفوف والتحقق
        std::cin.clear();                    // إعادة تهيئة حالة الخطأ
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // تنظيف الباف
        std::cout << "Invalid rows\n";
        return;
    }

    std::cout << "Enter number of cols per row: "; // طلب عدد الأعمدة
    if (!(std::cin >> h.cols)) {                     // قراءة عدد الأعمدة والتحقق
        std::cin.clear();                            // إعادة تهيئة حالة الخطأ
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // تنظيف الباف
        std::cout << "Invalid cols\n";
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // تنظيف نهاية السطر قبل قراءة النص

    std::cout << "Is this a VIP hall? (y/n): ";     // سؤال عن حالة الـ VIP
    char vipChar;
    std::cin.get(vipChar);                          // قراءة حرف
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // تنظيف الباف المتبقي
    h.isVip = (vipChar == 'y' || vipChar == 'Y');  // تحويل الإدخال إلى قيمة منطقية

    // إضافة الصالة إلى المتجه
    halls.push_back(std::move(h));
    std::cout << "Hall added successfully.\n";
}