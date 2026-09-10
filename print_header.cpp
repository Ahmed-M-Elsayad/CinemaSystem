#include "print_header.h"               // تضمين الهيدر
#include <iostream>                     // تضمين للإخراج

// تنفيذ دالة طباعة العنوان بتنسيق
void printHeader(const string& title) {
    string bar(title.size() + 10, '='); // إنشاء شريط طوله مرتبط بطول العنوان
    cout << bar << "\n";               // طباعة الشريط العلوي
    cout << "=== " << title << " ===\n"; // طباعة العنوان داخل علامات
    cout << bar << "\n";               // طباعة الشريط السفلي
}