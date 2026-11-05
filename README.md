# 🎬 نظام حجز تذاكر السينما (CinemaSystem)

**نظام متكامل لإدارة وحجز تذاكر السينما** — مشروع تعاوني متميز بلغة **C++20** يوفر واجهتين منفصلتين (للعملاء والمديرين)، مع إدارة كاملة للأفلام، الصالات، الحجوزات، والتقارير المالية.

[![C++](https://img.shields.io/badge/C%2B%2B-20-blue)](https://en.cppreference.com/w/cpp/20)
[![License](https://img.shields.io/badge/License-Educational-yellow)](LICENSE)
[![Build and SonarCloud Analysis](https://github.com/Ahmed-M-Elsayad/CinemaSystem/actions/workflows/ci.yml/badge.svg)](https://github.com/Ahmed-M-Elsayad/CinemaSystem/actions/workflows/ci.yml)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=Ahmed-M-Elsayad_CinemaSystem&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=Ahmed-M-Elsayad_CinemaSystem)
[![Security Rating](https://sonarcloud.io/api/project_badges/measure?project=Ahmed-M-Elsayad_CinemaSystem&metric=security_rating)](https://sonarcloud.io/summary/new_code?id=Ahmed-M-Elsayad_CinemaSystem)

---

## 🎯 نظرة عامة (Overview)

**CinemaSystem** هو تطبيق سطح مكتب (Console-Based) تم بناؤه باستخدام **C++ المعاصر (C++20)**، مع التركيز على البرمجة الهيكلية (Structured Programming) بدون استخدام الكائنات (No OOP) لتبسيط المنطق البرمجي.

يتميز المشروع بـ:
- 🏗️ **هندسة نظيفة:** فصل كامل بين ملفات الهيدر (`include/`) وملفات التنفيذ (`src/`).
- 🔒 **أمان صارم (Security by Design):** لا توجد كلمات مرور مكتوبة في الكود (Hard-coded)، واستخدام تشفير `SHA-256` مع حماية صلاحيات الملفات.
- 💾 **موثوقية البيانات (Reliability):** نظام حفظ واسترجاع (File I/O) يعتمد على صيغة `Pipe-separated`، مع تخطي السطور التالفة بدلاً من انهيار البرنامج.
- ✅ **جودة الكود (CI/CD):** دمج GitHub Actions مع SonarCloud لضمان جودة الكود (Quality Gate) وخلوه من الثغرات الأمنية.

---

## ✨ المميزات الرئيسية

### 👤 واجهة الزبون (Customer Mode)
| الميزة | الوصف |
| :--- | :--- |
| 🎭 **عرض الأفلام** | مشاهدة جميع الأفلام المتاحة (Now Showing). |
| 🪑 **خريطة المقاعد** | عرض تفاعلي لشاشة السينما (`O` = متاح، `X` = محجوز) مع منع حجز مقعد محجوز مسبقاً. |
| 🎫 **حجز التذاكر** | إمكانية حجز حتى 10 تذاكر دفعة واحدة، مع إدخال رقم المقعد والصف. |
| 💰 **الخصومات** | خصم تلقائي (10%) في حال حجز أكثر من 4 تذاكر في نفس العملية. |
| 🔄 **تعديل وإلغاء الحجز** | إمكانية إضافة أو إزالة مقاعد من الحجز (مع تحديث السعر تلقائياً)، أو إلغاء الحجز بالكامل. |
| 📄 **التذاكر** | طباعة التذكرة على الشاشة وتصديرها كملف نصي في مجلد `receipts/`. |

### 🔐 واجهة المدير (Admin Mode)
| الميزة | الوصف |
| :--- | :--- |
| 🔑 **تسجيل دخول آمن** | 3 محاولات فقط. يتم قراءة كلمة السر من متغير بيئة (`CINEMA_ADMIN_PASSWORD`) أو من ملف مشفر `data/admin.hash`. |
| 🎬 **إدارة الأفلام** | إضافة فيلم جديد، تعديل سعر/حالة فيلم، أو حذف فيلم (بشرط عدم وجود حجوزات نشطة عليه). |
| 📊 **التقارير** | عرض إجمالي الأرباح بناءً على الحجوزات النشطة والمدفوعة، واستخراج أعلى فيلم من حيث المبيعات. |
| 💾 **إدارة الملفات** | حفظ وتحميل بيانات الصالات، الأفلام، والحجوزات يدوياً من القائمة. |

---

## 🏗️ الهندسة المعمارية (Architecture)

يعتمد المشروع على التنظيم الصارم للملفات:
- `include/`: يحتوي على ملفات الهيدر (`.h`) وتعاريف الهياكل (`Structs`) في ملف واحد مركزي `CinemaData.h`.
- `src/`: يحتوي على ملفات التنفيذ (`.cpp`)، بحيث تكون كل دالة رئيسية في ملف منفصل لسهولة الصيانة والمراجعة.
- `data/`: مجلد يُنشأ تلقائياً، يحتوي على ملفات `.txt` التي تعمل كقاعدة بيانات بسيطة.
- `receipts/`: مجلد يُنشأ تلقائياً لحفظ تذاكر العملاء كملفات نصية.

### 📁 هيكل المشروع
```text
CinemaSystem/
├── .github/workflows/ci.yml     # GitHub Actions (Build + SonarCloud)
├── include/
│   └── CinemaData.h             # الـ Structs وتصريحات الدوال
├── src/                         # ملفات التنفيذ (.cpp)
├── tests/                       # اختبارات الوحدة (Unit Tests)
├── data/                        # يُنشأ تلقائياً (قاعدة البيانات)
├── receipts/                    # يُنشأ تلقائياً (التذاكر)
├── FUNCTIONS_AGREEMENT.md       # عقد الدوال بين الفريق
├── FILE_FORMAT_AGREEMENT.md     # تنسيق ملفات البيانات
├── CONTRIBUTING.md              # دليل المساهمة
├── SECURITY.md                  # سياسة الأمان
├── LICENSE                      # الترخيص التعليمي
├── sonar-project.properties     # إعدادات SonarCloud
└── README.md
```

### هيكل البيانات الأساسي
تم تصميم الـ `Structs` بعناية لضمان وجود قيم افتراضية لكل حقل لتجنب مشاكل المتغيرات غير المهيأة (Uninitialized Variables).
```cpp
struct Movie {
    int movieId = 0;
    std::string name;
    std::string genre;
    std::string showtime;
    double price = 0.0;
    int hallId = 0;
    std::string status;              // "Now Showing" / "Coming Soon" / "Ended"
    std::vector<std::vector<char>> seats; // 'O' = متاح، 'X' = محجوز
};
```

### تنسيق الملفات (Data Format)
تعتمد الملفات على الفاصل `|` (Pipe) لسهولة القراءة الآلية:
```text
movieId|name|genre|showtime|price|hallId|status
rows|cols
XXXXXX
OOOOOO
... (بقية المقاعد)
```

---

## 🔐 الأمان (Security)

نأخذ الأمان في هذا المشروع بجدية تامة:
1. **لا كلمات مرور مكتوبة في الكود:** يبحث البرنامج عن كلمة السر في متغير البيئة، أو ملف `data/admin.hash`.
2. **تشفير قوي:** تُحفظ كلمة السر باستخدام خوارزمية `SHA-256`.
3. **حماية الملفات:** في بيئات Linux/macOS، يتم تطبيق صلاحيات `chmod 600` على ملف الـ `admin.hash` بعد إنشائه، بحيث لا يستطيع قراءته إلا صاحب الجهاز الحالي.
4. **منع حقن البيانات:** دالة `getStringInput` تمنع المستخدم من إدخال الرمز `|` في أسماء الأفلام أو العملاء، مما يمنع إفساد ملفات البيانات.

*(يرجى مراجعة ملف [`SECURITY.md`](SECURITY.md) لمعرفة كيفية الإبلاغ عن الثغرات).*

---

## 🚀 التثبيت والبناء (Build & Run)

### المتطلبات
- مترجم C++ يدعم **C++20** أو أحدث (مثل `g++ 10.0+` أو `MSVC 2019+`).

### 1️⃣ بناء المشروع (GCC / Clang)
```bash
# بناء بسيط
g++ -std=c++20 -I include src/*.cpp -o cinema

# بناء مع تحذيرات كاملة (موصى به)
g++ -std=c++20 -Wall -Wextra -I include src/*.cpp -o cinema
```

### 2️⃣ التشغيل
```bash
./cinema          # Linux / macOS / MinGW
cinema.exe        # Windows (CMD / PowerShell)
```

### 3️⃣ تشغيل الاختبارات (Unit Tests)
```bash
g++ -std=c++20 -Wall -Wextra -I include $(find src -name "*.cpp" ! -name "main.cpp") tests/*.cpp -o cinema_tests
./cinema_tests
```

---

## 👥 أعضاء الفريق وتوزيع المهام

| الاسم | GitHub | الدور الأساسي | عدد المهام |
| :--- | :--- | :--- | :---: |
| **Ahmed M. Elsayad** | [@Ahmed-M-Elsayad](https://github.com/Ahmed-M-Elsayad) | القائد، واجهة المدير، إدارة الملفات، التجميع | **20 مهمة** |
| **Reda Elkplawy** | [@Redaelkplawy](https://github.com/Redaelkplawy) | نظام الحجوزات، إدارة المقاعد، التذاكر | **12 مهمة** |
| **Omar** | [@omaralqblawy](https://github.com/omaralqblawy) | إدارة الأفلام، الصالات، الدوال المساعدة | **10 مهام** |

📖 للتفاصيل الكاملة حول أسماء الدوال وتوقيعاتها: راجع [`FUNCTIONS_AGREEMENT.md`](FUNCTIONS_AGREEMENT.md).

---

## 🛠️ التكامل المستمر (CI/CD)

عند كل `push` على الفرع `main` أو عند فتح `Pull Request`، يتم تشغيل **GitHub Actions**:
1. يتم بناء المشروع باستخدام `g++` مع `-Wall -Wextra`.
2. يتم تشغيل الاختبارات (`tests/`) مع قياس **تغطية الكود (Coverage)** عبر `gcovr`.
3. يتم تشغيل تحليل ساكن (Static Analysis) عبر **SonarCloud** مع تقرير التغطية.
4. يجب أن يمر الكود من **Quality Gate** (خلوه من الـ Bugs، الثغرات، وتقليل تكرار الكود) قبل قبول أي دمج.

---

## 📄 الترخيص (License)
هذا المشروع مخصص **للأغراض التعليمية والأكاديمية فقط**. يُمنع الاستخدام التجاري. يرجى مراجعة ملف [`LICENSE`](LICENSE) للتفاصيل.

<div align="center">
  <b>صُنع بـ ❤️ من قبل فريق CinemaSystem</b>
</div>
