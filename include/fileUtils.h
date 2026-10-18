#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <istream>
#include <string>
#include <vector>

// تقسيم سطر على فاصل (الحقول الفاضية بتتحفظ)
std::vector<std::string> splitLine(const std::string& line, char delim = '|');

// قراءة سطر مع إزالة '\r' (ملفات Windows)
bool readLine(std::istream& in, std::string& line);

// تحويل آمن (بدون exceptions). بيرجع false لو النص مش رقم صالح بالكامل
bool parseInt(const std::string& text, int& out);
bool parseDouble(const std::string& text, double& out);

// إنشاء فولدر data لو مش موجود
void ensureDataDirectory();

#endif
