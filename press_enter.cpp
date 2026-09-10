#include "press_enter.h"                // تضمين الهيدر
#include <iostream>                     // تضمين للإخراج
#include <limits>                       // تضمين لتنظيف باف الإدخال

// تنفيذ دالة انتظار الضغط على Enter
void pressEnterToContinue() {
    cout << "Press Enter to continue..."; // رسالة للمستخدم
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // تجاهل أي بيانات متبقية والانتظار
}