#include "clear_screen.h"
#include <iostream>

void clearScreen() {
#ifdef _WIN32
    system("cls");                          // ويندوز
#else
    const char ESC = 27;                    // رمز الهروب ESC (27 = \033)
    std::cout << ESC << "[2J" << ESC << "[H"; // لينكس وماك
#endif
}
