#include "find_hall.h"              // تضمين التعاريف

// تنفيذ نسخة التعديل (non-const) من البحث عن صالة بالمعرف
Hall* findHallById(vector<Hall>& halls, int hallId) {
    for (auto& h : halls) {         // التكرار على الصالات (قابلة للتعديل)
        if (h.hallId == hallId) {   // مطابقة المعرف
            return &h;              // نعيد مؤشر قابل للتعديل
        }
    }
    return nullptr;                 // إن لم توجد الصالة نعيد nullptr
}