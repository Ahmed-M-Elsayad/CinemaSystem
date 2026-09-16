#include "display_halls.h"    // تضمين إعلان الدالة
#include <iostream>    // للإخراج
#include <format>   //  C++20

void displayAllHalls(const std::vector<Hall>& halls) {
    if (halls.empty()) {    // إن لم توجد صالات
        std::cout << "No halls available.\n";
        return;
    }

    // طباعة رأس جدول مبسط
    std::cout << std::format("{:<6}{:<20}{:<8}{:<8}{:<6}\n", "ID", "Name", "Rows", "Cols", "VIP");
    std::cout << std::string(48, '-') << "\n";

    // صفوف الصالات
    for (const auto& h : halls) {
        std::cout << std::format("{:<6}{:<20}{:<8}{:<8}{:<6}\n",
            h.hallId,
            h.name,
            h.rows,
            h.cols,
            (h.isVip ? "Yes" : "No"));
    }
}
