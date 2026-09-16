#include "pressEnterToContinue.h"                // تضمين الهيدر
#include <iostream>                     // تضمين للإخراج
#include <limits>                       // تضمين لتنظيف باف الإدخال
using namespace std;

// تنفيذ دالة انتظار الضغط على Enter
void pressEnterToContinue() {
    cout << "Press Enter to continue..."; // رسالة للمستخدم
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // تجاهل أي بيانات متبقية والانتظار
}