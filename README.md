# 🎬 نظام حجز تذاكر السينما

**نظام متكامل لإدارة وحجز تذاكر السينما** — مشروع تعاوني بلغة **C++20** يوفر واجهتين منفصلتين للعملاء والمديرين، مع إدارة كاملة للأفلام والصالات والحجوزات.

[![C++](https://img.shields.io/badge/C%2B%2B-20-blue)](https://en.cppreference.com/w/cpp/20)
[![License](https://img.shields.io/badge/License-Educational-yellow)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Complete-brightgreen)]()

---

## 🎯 نظرة عامة

نظام سطح مكتب شامل يسمح بـ:
- 🎭 **إدارة الأفلام** والصالات بكفاءة
- 🎫 **نظام حجز متقدم** مع خريطة مقاعد تفاعلية
- 💰 **نظام خصومات** تلقائي (10% لأكثر من 4 تذاكر)
- 📊 **تقارير مبيعات** مفصلة للمدير
- 💾 **حفظ واسترجاع** البيانات تلقائياً من الملفات

**تم البناء باستخدام C++ المعاصر (C++20)** بدون OOP، مع التركيز على البساطة والوضوح في الكود.

---

## ✨ المميزات الرئيسية

### 👤 واجهة الزبون

| الميزة | الوصف |
| :--- | :--- |
| 🎭 **عرض الأفلام** | مشاهدة جميع الأفلام المتاحة (Now Showing) |
| 🪑 **خريطة المقاعد** | عرض منسق لتوفر المقاعد (`O` = متاح، `X` = محجوز) |
| 🎫 **حجز التذاكر** | حجز عدة تذاكر دفعة واحدة |
| 💰 **الخصومات** | خصم تلقائي 10% عند حجز أكثر من 4 تذاكر |
| 🔄 **التعديل والإلغاء** | تعديل الحجز (إضافة/إزالة مقاعد) أو إلغاؤه |
| 📄 **التذاكر** | طباعة على الشاشة أو تصديرها كملف نصي |

### 🔐 واجهة المدير

| الميزة | الوصف |
| :--- | :--- |
| 🔑 **تسجيل آمن** | كلمة سر محمية بـ 3 محاولات فقط |
| 🎬 **إدارة الأفلام** | إضافة، تعديل (سعر/حالة)، حذف |
| 📊 **التقارير** | إجمالي الأرباح + أعلى فيلم مبيعاً |
| 🔍 **التحقق الذكي** | منع حذف الأفلام التي عليها حجوزات نشطة |
| 💾 **إدارة الملفات** | حفظ/تحميل كل البيانات دفعة واحدة |

---

## 👥 أعضاء الفريق

| الاسم | GitHub | الدور | المسؤوليات |
| :--- | :--- | :--- | :--- |
| **Ahmed M. Elsayad** | [@Ahmed-M-Elsayad](https://github.com/Ahmed-M-Elsayad) | 👨‍💼 القائد | واجهة المدير، إدارة الملفات، التجميع، `main` |
| **Reda Elkplawy** | [@Redaelkplawy](https://github.com/Redaelkplawy) | 👨‍💻 عضو تطوير | نظام الحجوزات، إدارة المقاعد، التذاكر |
| **Omar** | [@omaralqblawy](https://github.com/omaralqblawy) | 👨‍💻 عضو تطوير | إدارة الأفلام والصالات والمساعدات |

---

## 📋 المتطلبات

- **مترجم C++** يدعم **C++20** أو أحدث:
  - `g++ 10.0+` (Linux/macOS/MinGW)
  - `MSVC 2019+` (Windows)
- **نظام التشغيل**: Windows / Linux / macOS
- **Git** (اختياري، للتطوير التعاوني)

---

## 🚀 التثبيت والبناء

### 1️⃣ استنساخ المستودع

```bash
git clone https://github.com/Ahmed-M-Elsayad/CinemaSystem.git
cd CinemaSystem
```

### 2️⃣ البناء باستخدام GCC/Clang

```bash
# بناء بسيط
g++ -std=c++20 -I include src/*.cpp -o cinema

# مع تحسينات
g++ -std=c++20 -O2 -I include src/*.cpp -o cinema

# مع تحذيرات كاملة
g++ -std=c++20 -Wall -Wextra -I include src/*.cpp -o cinema
```

### 3️⃣ البناء على Visual Studio

```
1. File → New → Project → Empty Project
2. Add Existing Items → اختر كل ملفات src/*.cpp
3. Project Properties:
   - C/C++ → Language → C++ Language Standard → ISO C++20
   - C/C++ → General → Additional Include Directories → ./include/
4. Build → Build Solution (Ctrl+Shift+B)
5. Debug → Start Without Debugging (Ctrl+F5)
```

### 4️⃣ التشغيل

```bash
./cinema          # Linux / macOS / MinGW
cinema.exe        # Windows (CMD / PowerShell)
```

---

## 💻 الاستخدام

### القائمة الرئيسية

عند تشغيل البرنامج، تظهر القائمة التالية:

```
╔════════════════════════════════════╗
║   🎬 نظام حجز تذاكر السينما       ║
╠════════════════════════════════════╣
║  1. دخول الزبون                    ║
║  2. دخول المدير                    ║
║  3. خروج                           ║
╚════════════════════════════════════╝
```

### 🎫 كزبون

```
1. اختر "دخول الزبون"
2. اختر الفيلم المرغوب
3. اختر المقاعد من الخريطة
4. أدخل بياناتك (ID، الاسم، الهاتف)
5. أتمم الحجز واحصل على التذكرة
6. احفظ أو اطبع التذكرة
```

### 🔐 كمدير

```
1. اختر "دخول المدير"
2. أدخل كلمة السر (3 محاولات مسموحة)
3. استخدم القائمة الإدارية:
   - إضافة/تعديل/حذف الأفلام
   - عرض التقارير المالية
   - حفظ/تحميل البيانات
```

---

## 📁 هيكل المشروع

```
CinemaSystem/
│
├── 📄 README.md                    # هذا الملف
├── 📄 LICENSE                      # رخصة المشروع
├── 📄 .gitignore                   # ملفات Git المستبعدة
├── 📄 FUNCTIONS_AGREEMENT.md       # اتفاقية أسماء الدوال
│
├── 📂 include/                     # ملفات الهيدر (.h)
│   ├── CinemaData.h                # ⭐ تعريف كل الـ Structs والثوابت
│   ├── adminAddMovie.h
│   ├── adminDeleteMovie.h
│   ├── adminEditMovie.h
│   ├── adminLogin.h
│   ├── bookSeat.h
│   ├── calculateTotalPrice.h
│   ├── cancelBooking.h
│   ├── clearScreen.h
│   ├── createBooking.h
│   ├── delete_movie.h
│   ├── display.h
│   ├── displaySeats.h
│   ├── display_active.h
│   ├── display_halls.h
│   ├── exportTicketToFile.h
│   ├── findBookingById.h
│   ├── find_hall.h
│   ├── find_movie.h
│   ├── getAvailableSeatsCount.h
│   ├── getIntInput.h
│   ├── getStringInput.h
│   ├── initializeSeats.h
│   ├── isSeatAvailable.h
│   ├── isValidSeat.h
│   ├── loadAllData.h
│   ├── loadBookingsFromFile.h
│   ├── loadHallsFromFile.h
│   ├── loadMoviesFromFile.h
│   ├── modifyBooking.h
│   ├── pressEnterToContinue.h
│   ├── printHeader.h
│   ├── printTicket.h
│   ├── saveAllData.h
│   ├── saveBookingsToFile.h
│   ├── saveHallsToFile.h
│   ├── saveMoviesToFile.h
│   ├── seedData.h
│   ├── showAdminMenu.h
│   ├── showSalesReport.h
│   ├── unbookSeat.h
│   ├── update_price.h
│   └── update_status.h
│
├── 📂 src/                         # ملفات السورس (.cpp)
│   ├── main.cpp                    # ⭐ نقطة بداية البرنامج
│   ├── adminAddMovie.cpp
│   ├── adminDeleteMovie.cpp
│   ├── adminEditMovie.cpp
│   ├── adminLogin.cpp
│   ├── bookSeat.cpp
│   ├── calculateTotalPrice.cpp
│   ├── cancelBooking.cpp
│   ├── clearScreen.cpp
│   ├── createBooking.cpp
│   ├── delete_movie.cpp
│   ├── display.cpp
│   ├── displaySeats.cpp
│   ├── display_active.cpp
│   ├── display_halls.cpp
│   ├── exportTicketToFile.cpp
│   ├── findBookingById.cpp
│   ├── find_hall_const.cpp
│   ├── find_hall_mut.cpp
│   ├── find_movie_const.cpp
│   ├── find_movie_mut.cpp
│   ├── getAvailableSeatsCount.cpp
│   ├── getIntInput.cpp
│   ├── getStringInput.cpp
│   ├── initializeSeats.cpp
│   ├── isSeatAvailable.cpp
│   ├── isValidSeat.cpp
│   ├── loadAllData.cpp
│   ├── loadBookingsFromFile.cpp
│   ├── loadHallsFromFile.cpp
│   ├── loadMoviesFromFile.cpp
│   ├── modifyBooking.cpp
│   ├── pressEnterToContinue.cpp
│   ├── printHeader.cpp
│   ├── printTicket.cpp
│   ├── saveAllData.cpp
│   ├── saveBookingsToFile.cpp
│   ├── saveHallsToFile.cpp
│   ├── saveMoviesToFile.cpp
│   ├── seedData.cpp
│   ├── showAdminMenu.cpp
│   ├── showSalesReport.cpp
│   ├── unbookSeat.cpp
│   ├── update_price.cpp
│   └── update_status.cpp
│
├── 📂 data/                        # ملفات البيانات (تُنشأ تلقائياً)
│   ├── halls.txt
│   ├── movies.txt
│   └── bookings.txt
│
├── 📂 receipts/                    # التذاكر المُصدَّرة كملفات
│
└── 📂 docs/                        # التوثيق
    ├── FUNCTIONS_AGREEMENT.md
    ├── TASKS_LIST.md
    ├── MEETING_AGENDA.md
    └── FILE_FORMAT_AGREEMENT.md
```

---

## 🏗️ الهندسة المعمارية

### هيكل البيانات الأساسي

**`include/CinemaData.h`** يحتوي على تعريف كل الـ Structs والثوابت:

```cpp
// ─── التاريخ ───
struct Date {
    int day, month, year;
};

// ─── الصالة ───
struct Hall {
    int hallId;
    string name;
    int rows, cols;
    bool isVip;
};

// ─── الفيلم ───
struct Movie {
    int movieId;
    string name;
    string genre;
    string showtime;
    double price;
    int hallId;
    string status;              // "Now Showing" / "Coming Soon" / "Ended"
    vector<vector<char>> seats; // 'O' = فاضي، 'X' = محجوز
};

// ─── العميل ───
struct Customer {
    int customerId;
    string fullName;
    string phone;
};

// ─── الحجز ───
struct Booking {
    int bookingId;              // يبدأ من 1001
    int movieId;
    string movieName;
    Customer customer;
    vector<pair<int, int>> seats;
    int seatCount;
    double pricePerSeat;
    double originalPrice;
    double discountAmount;
    double totalPrice;
    Date bookingDate;
    bool isActive;
    bool isPaid;
};
```

### الثوابت العامة

```cpp
const string ADMIN_PASSWORD = "admin123";
const int    ROWS_DEFAULT   = 5;
const int    COLS_DEFAULT   = 6;
const int    DISCOUNT_THRESHOLD = 4;      // خصم عند > 4 تذاكر
const double DISCOUNT_RATE  = 0.10;       // 10%
const int    STARTING_BOOKING_ID = 1001;
```

### تنسيق الملفات

كل ملفات البيانات تستخدم صيغة **pipe-separated** (`|`):

**`data/halls.txt`**:
```
hallId|name|rows|cols|isVip
1|Main Hall|5|6|1
```

**`data/movies.txt`**:
```
movieId|name|genre|showtime|price|hallId|status
rows|cols
XXXXXX
OOOOOO
...
```

**`data/bookings.txt`**:
```
bookingId|movieId|movieName|seatCount|pricePerSeat|originalPrice|discountAmount|totalPrice|isActive|isPaid
customerId|customerName|phone
row col
row col
day month year
```

---

## 📊 توزيع المهام

### Ahmed M. Elsayad — 20 مهمة
- إدارة المشروع والتجميع
- واجهة المدير (Login، Menu، Add/Edit/Delete Movie، Report)
- إدارة الملفات (Save/Load)
- دالة `main` والبيانات التجريبية
- دوال المساعدة (`bookSeat`, `unbookSeat`, إلخ)

### Reda Elkplawy — 12 مهمة
- نظام الحجوزات (`createBooking`, `cancelBooking`, `modifyBooking`)
- إدارة المقاعد (`initializeSeats`, `displaySeats`, `isSeatAvailable`)
- حساب الأسعار (`calculateTotalPrice`)
- التذاكر (`printTicket`, `exportTicketToFile`)

### Omar — 13 مهمة
- إدارة الأفلام (`addNewMovie`, `displayAllMovies`, `deleteMovie`)
- إدارة الصالات (`addNewHall`, `displayAllHalls`, `findHallById`)
- دوال مساعدة (`clearScreen`, `printHeader`, `pressEnterToContinue`)

📖 للتفاصيل الكاملة: راجع [`FUNCTIONS_AGREEMENT.md`](FUNCTIONS_AGREEMENT.md) و `docs/TASKS_LIST.md`

---

## 🤝 المساهمة

نرحب بالمساهمات! اتبع الخطوات:

### 1. أنشئ فرع جديد

```bash
git checkout -b feature/اسم-الميزة
# أو
git checkout -b bugfix/اسم-المشكلة
```

### 2. اعمل تعديلاتك

```bash
git add .
git commit -m "وصف واضح للتغييرات"
git push origin feature/اسم-الميزة
```

### 3. افتح Pull Request

- اذهب إلى GitHub
- افتح PR مع وصف مفصل
- انتظر المراجعة

### معايير الكود

- ✨ **الأسلوب**: اتبع نفس أسلوب `CinemaData.h`
- 📝 **التعليقات**: أضف تعليقات واضحة بالعربية أو الإنجليزية
- 🧪 **الاختبار**: تأكد أن الكود يُبنى بدون أخطاء
- 📖 **التوثيق**: حدّث `FUNCTIONS_AGREEMENT.md` عند إضافة دوال جديدة

---

## 📄 الترخيص

هذا المشروع **للأغراض التعليمية فقط**.

- ✅ الاستخدام التعليمي والأكاديمي
- ❌ الاستخدام التجاري
- ⚠️ بدون أي ضمانات

راجع ملف [`LICENSE`](LICENSE) للتفاصيل الكاملة.

---

## 🙏 شكر خاص

- 👨‍🏫 المشرف على المشروع
- 👥 أعضاء الفريق المتعاونون
- 💪 كل من راجع واختبر الكود

---

<div align="center">

### 🎬 استمتع بتجربة نظام السينما! 🍿

**صُنع بـ ❤️ من قبل فريق طلابي متحمس**

</div>