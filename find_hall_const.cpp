#include "find_hall.h"              // تضمين التعاريف

// تنفيذ نسخة القراءة (const) من البحث عن صالة بالمعرف
const Hall* findHallById(const vector<Hall>& halls, int hallId) {
    for (const auto& h : halls) {   // التكرار على جميع الصالات
        if (h.hallId == hallId) {   // إذا تطابقت المعرفات
            return &h;              // نعيد مؤشر ثابت إلى الصالة
        }
    }
    return nullptr;                 // إن لم توجد الصالة نعيد nullptr
}