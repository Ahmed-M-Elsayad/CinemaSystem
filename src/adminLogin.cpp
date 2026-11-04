#include "sha256.h"
#include "adminLogin.h"
#include "fileUtils.h"
#include "getStringInput.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem> // تم إضافتها لاستخدام صلاحيات الملفات

using namespace std;

namespace {

    constexpr int MAX_ATTEMPTS = 3;
    constexpr size_t MIN_PASSWORD_LENGTH = 6;

    // تم إضافة // NOSONAR هنا لإخبار أداة الفحص أن هذا اسم متغير بيئة وليس كلمة مرور
    const char* const ADMIN_AUTH_ENV = "CINEMA_ADMIN_PASSWORD"; // NOSONAR

    const char* const ADMIN_AUTH_FILE = "data/admin.hash";   // ضيفه في .gitignore

    // 1) متغير البيئة  2) الملف المحلي  3) فاضي = لسه ما اتعملش إعداد
    string loadConfiguredPassword() {
        const char* env = getenv(ADMIN_AUTH_ENV);
        if (env != nullptr && *env != '\0') {
            return sha256Hex(env); // إصلاح هام: يجب تشفير القيمة القادمة من البيئة لتطابق نظام التشفير
        }

        string stored;
        ifstream file(ADMIN_AUTH_FILE);
        if (file.is_open() && readLine(file, stored)) {
            return stored;
        }
        return "";
    }

    // أول تشغيل: المدير بيختار كلمة السر بنفسه بدل ما تبقى مكتوبة في الكود
    bool createFirstPassword() {
        cout << "\nNo admin password is configured yet. Create one now.\n";
        const string first = getStringInput("New password (min 6 chars): ");
        if (first.size() < MIN_PASSWORD_LENGTH) {
            cout << "Password is too short.\n";
            return false;
        }
        if (first != getStringInput("Confirm password: ")) {
            cout << "Passwords do not match.\n";
            return false;
        }

        ensureDataDirectory();
        ofstream file(ADMIN_AUTH_FILE);
        if (!file.is_open()) {
            cout << "Error: Cannot save the password file.\n";
            return false;
        }

        file << sha256Hex(first) << "\n";
        file.close(); // إغلاق الملف قبل تغيير الصلاحيات

        // إضافة الصلاحيات الأمنية (تعمل على لينكس وماك) - chmod 600
#ifdef __unix__
        std::filesystem::permissions(ADMIN_AUTH_FILE,
            std::filesystem::perms::owner_read | std::filesystem::perms::owner_write,
            std::filesystem::perm_options::replace);
#endif

        cout << "Password saved. Please log in.\n";
        return true;
    }

}  // namespace

bool adminLogin() {
    string correctPassword = loadConfiguredPassword();
    if (correctPassword.empty()) {
        if (!createFirstPassword()) {
            return false;
        }
        correctPassword = loadConfiguredPassword();
    }

    for (int attempts = MAX_ATTEMPTS; attempts > 0; --attempts) {
        const string input = getStringInput(
            "\nEnter password (attempts left: " + to_string(attempts) + "): ");

        if (sha256Hex(input) == correctPassword) {
            cout << "\nLogin successful! Welcome, Admin.\n";
            return true;
        }
        cout << "Incorrect password!\n";
    }

    cout << "Access denied after " << MAX_ATTEMPTS << " failed attempts!\n";
    return false;
}
