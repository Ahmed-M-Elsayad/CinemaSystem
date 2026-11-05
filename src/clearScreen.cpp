#include "clearScreen.h"
#include <iostream>

void clearScreen() {
    // كود ANSI لمسح الشاشة (آمن ومتوافق مع كل الأنظمة)
    std::cout << "\033[2J\033[1;1H";
}
