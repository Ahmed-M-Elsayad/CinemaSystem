#include "loadHallsFromFile.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

void loadHallsFromFile(vector<Hall>& halls) {
    // مسح البيانات القديمة
    halls.clear();

    // فتح الملف للقراءة
    ifstream hallsFile("data/halls.txt");

    if (hallsFile.is_open()) {
        string line;
        while (getline(hallsFile, line)) {
            if (line.empty()) continue; // تخطي الأسطر الفارغة

            stringstream ss(line);
            string segment;

            Hall h;

            // قراءة البيانات بالترتيب الذي حفظتها به (مفصولة بـ |)
			getline(ss, segment, '|'); h.hallId = stoi(segment); // تحويل النص إلى عدد صحيح
            getline(ss, segment, '|'); h.name = segment;
            getline(ss, segment, '|'); h.rows = stoi(segment);
            getline(ss, segment, '|'); h.cols = stoi(segment);
            getline(ss, segment, '|'); h.isVip = stoi(segment); // 0 أو 1

            // إضافة الصالة للقائمة
            halls.push_back(h);
        }
		hallsFile.close(); // إغلاق الملف بعد الانتهاء
        cout << "The halls were successfully loaded from the halls file.\n";
    }
    else {
        cout << "Error: Unable to open the halls file (halls) for loading!\n";
    }
}