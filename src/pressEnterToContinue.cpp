#include "pressEnterToContinue.h"
#include <iostream>
#include <limits>

using namespace std;

void pressEnterToContinue() {
    cout << "Press Enter to continue...";
    cout.flush();
    cin.clear(); // تنظيف أي أخطاء سابقة في الإدخال
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // مسح أي \n متبقية
    cin.get(); // الانتظار الفعلي للمستخدم
}