<!-- SPDX-License-Identifier: Educational Use License -->
<!-- Copyright (c) 2026 CinemaSystem Team -->

# 🤝 اتفاقية الدوال (Functions Agreement)

هذا المستند يوثّق **جميع الدوال (Functions)** في مشروع **CinemaSystem**، موزّعة على أعضاء الفريق، مع التوقيعات (Signatures) المتفق عليها مسبقاً لضمان التوافق التام أثناء التجميع (Compilation).

> ⚠️ **ملاحظة هامة:** التوقيعات (Signatures) **ثابتة ومتفق عليها**. أي تعديل عليها يتطلب موافقة الفريق كاملاً وتحديث هذا المستند.

---

## 📋 جدول المحتويات
- [1. (Ahmed M. Elsayad) — المدير + الملفات + التجميع](#1-ahmed-m-elsayad--المدير--الملفات--التجميع)
- [2. (Reda) — الحجوزات والمقاعد](#2-reda--الحجوزات-والمقاعد)
- [3. (Omar) — الأفلام + الصالات + المساعدات](#3-omar--الأفلام--الصالات--المساعدات)
- [4. المتغيرات والثوابت العامة](#4-المتغيرات-والثوابت-العامة)
- [5. ملخص توزيع المهام](#5-ملخص-توزيع-المهام)

---

## 1. (Ahmed M. Elsayad) — المدير + الملفات + التجميع
**GitHub:** [@Ahmed-M-Elsayad](https://github.com/Ahmed-M-Elsayad)  
**عدد المهام:** 20 مهمة

| Task ID | Signature (Fixed) | Function Name | Description (الوصف) |
| :---: | :--- | :--- | :--- |
| 7 | `bool (vector<vector<char>>&, int, int)` | `bookSeat` | حجز مقعد (تحويل O إلى X) |
| 8 | `bool (vector<vector<char>>&, int, int)` | `unbookSeat` | إلغاء حجز مقعد (تحويل X إلى O) |
| 9 | `int (const vector<vector<char>>&)` | `getAvailableSeatsCount` | حساب عدد المقاعد الفاضية |
| 10 | `bool (const vector<vector<char>>&, int, int)` | `isValidSeat` | التحقق من صحة رقم المقعد |
| 30 | `bool ()` | `adminLogin` | التحقق من كلمة السر (3 محاولات) |
| 31 | `void (vector<Movie>&, vector<Hall>&, vector<Booking>&)` | `showAdminMenu` | عرض قائمة المدير |
| 32 | `void (vector<Movie>&, const vector<Hall>&)` | `adminAddMovie` | إضافة فيلم (بصلاحية المدير) |
| 33 | `void (vector<Movie>&)` | `adminEditMovie` | تعديل سعر أو حالة فيلم |
| 34 | `void (vector<Movie>&, const vector<Booking>&)` | `adminDeleteMovie` | حذف فيلم (مع التحقق من الحجوزات) |
| 35 | `void (const vector<Movie>&, const vector<Booking>&)` | `showSalesReport` | عرض إجمالي الأرباح وأعلى فيلم مبيعاً |
| 36 | `void (const vector<Hall>&, const vector<Movie>&, const vector<Booking>&)` | `saveAllData` | حفظ كل البيانات دفعة واحدة |
| 37 | `void (vector<Hall>&, vector<Movie>&, vector<Booking>&)` | `loadAllData` | تحميل كل البيانات دفعة واحدة |
| 38 | `void (const vector<Hall>&)` | `saveHallsToFile` | حفظ الصالات في `halls.txt` |
| 39 | `void (vector<Hall>&)` | `loadHallsFromFile` | تحميل الصالات من `halls.txt` |
| 40 | `void (const vector<Movie>&)` | `saveMoviesToFile` | حفظ الأفلام والمقاعد في ملفات |
| 41 | `void (vector<Movie>&)` | `loadMoviesFromFile` | تحميل الأفلام والمقاعد من ملفات |
| 42 | `void (const vector<Booking>&)` | `saveBookingsToFile` | حفظ الحجوزات في `bookings.txt` |
| 43 | `void (vector<Booking>&)` | `loadBookingsFromFile` | تحميل الحجوزات من `bookings.txt` |
| 44 | `int ()` | `main` | نقطة بداية البرنامج |
| 45 | `void (vector<Hall>&, vector<Movie>&)` | `seedData` | إضافة بيانات وهمية للتجربة |

---

## 2. (Reda) — الحجوزات والمقاعد
**GitHub:** [@Redaelkplawy](https://github.com/Redaelkplawy)  
**عدد المهام:** 12 مهمة

| Task ID | Signature (Fixed) | Function Name | Description (الوصف) |
| :---: | :--- | :--- | :--- |
| 4 | `vector<vector<char>> (int, int)` | `initializeSeats` | إنشاء مصفوفة مقاعد جديدة (كلها O) |
| 5 | `void (const vector<vector<char>>&)` | `displaySeats` | طباعة خريطة المقاعد بشكل منسق |
| 6 | `bool (const vector<vector<char>>&, int, int)` | `isSeatAvailable` | التحقق من توفر مقعد |
| 21 | `double (double, int, double&)` | `calculateTotalPrice` | حساب السعر مع خصم 10% (لو > 4 تذاكر) |
| 22 | `void (vector<Movie>&, vector<Booking>&)` | `createBooking` | تنفيذ عملية الحجز الكاملة |
| 23 | `void (vector<Booking>&, vector<Movie>&)` | `cancelBooking` | إلغاء حجز واسترجاع المقاعد |
| 24 | `void (vector<Booking>&, vector<Movie>&)` | `modifyBooking` | تعديل حجز (إضافة/إزالة مقاعد) |
| 25 | `void (const Booking&, const Movie&)` | `printTicket` | طباعة التذكرة على الشاشة |
| 26 | `void (const Booking&, const Movie&)` | `exportTicketToFile` | تصدير التذكرة كملف `Ticket_[ID].txt` |
| 27 | `Booking* (vector<Booking>&, int)` | `findBookingById` | البحث عن حجز برقمه |
| 28 | `int (int, int)` | `getIntInput` | قراءة رقم مع التحقق من النطاق |
| 29 | `string (const string&)` | `getStringInput` | قراءة سطر نصي كامل (بمسافات) |

---

## 3. (Omar) — الأفلام + الصالات + المساعدات
**GitHub:** [@omaralqblawy](https://github.com/omaralqblawy)  
**عدد المهام:** 13 مهمة

| Task ID | Signature (Fixed) | Function Name | Description (الوصف) |
| :---: | :--- | :--- | :--- |
| 1 | `void (vector<Hall>&)` | `addNewHall` | إضافة صالة جديدة |
| 2 | `void (const vector<Hall>&)` | `displayAllHalls` | عرض جميع الصالات في جدول |
| 3 | `const Hall* (const vector<Hall>&, int)` | `findHallById` | البحث عن صالة برقمها (للقراءة فقط) |
| 3 | `Hall* (vector<Hall>&, int)` | `findHallById` | البحث عن صالة برقمها (للتعديل) |
| 11 | `void (vector<Movie>&, const vector<Hall>&)` | `addNewMovie` | إضافة فيلم جديد وربطه بصالة |
| 12 | `void (const vector<Movie>&)` | `displayAllMovies` | عرض جميع الأفلام (حتى المنتهية) |
| 13 | `void (const vector<Movie>&)` | `displayActiveMovies` | عرض الأفلام النشطة فقط (Now Showing) |
| 14 | `const Movie* (const vector<Movie>&, int)` | `findMovieById` | البحث عن فيلم برقمه (للقراءة فقط) |
| 14 | `Movie* (vector<Movie>&, int)` | `findMovieById` | البحث عن فيلم برقمه (للتعديل) |
| 15 | `void (vector<Movie>&, int, double)` | `updateMoviePrice` | تغيير سعر تذكرة فيلم معين |
| 16 | `void (vector<Movie>&, int, const string&)` | `updateMovieStatus` | تغيير حالة الفيلم |
| 17 | `bool (vector<Movie>&, int, const vector<Booking>&)` | `deleteMovie` | حذف فيلم (بدون حجوزات نشطة) |
| 18 | `void ()` | `clearScreen` | مسح محتويات شاشة الكونسول |
| 19 | `void ()` | `pressEnterToContinue` | الانتظار حتى ضغط Enter |
| 20 | `void (const string&)` | `printHeader` | طباعة عنوان بتنسيق `===== العنوان =====` |

---

## 4. المتغيرات والثوابت العامة
تُعرَّف هذه العناصر في `include/CinemaData.h` (باستخدام `extern` للمتغيرات) وتُعرَّف فعلياً في `src/main.cpp`.

### 🌐 المتغيرات العامة (Global Variables)
| Variable | Type | Description |
| :--- | :--- | :--- |
| `halls` | `vector<Hall>` | قائمة كل الصالات |
| `movies` | `vector<Movie>` | قائمة كل الأفلام |
| `bookings` | `vector<Booking>` | قائمة كل الحجوزات |
| `nextBookingId` | `int` | الرقم التالي للحجز الجديد |

### 🔒 الثوابت العامة (Global Constants)
| Constant | Value | Description |
| :--- | :--- | :--- |
| `ADMIN_PASSWORD` | `"admin123"` | كلمة سر المدير |
| `ROWS_DEFAULT` | `5` | عدد الصفوف الافتراضي |
| `COLS_DEFAULT` | `6` | عدد الأعمدة الافتراضي |
| `DISCOUNT_THRESHOLD` | `4` | عدد التذاكر المؤهل للخصم |
| `DISCOUNT_RATE` | `0.10` | نسبة الخصم (10%) |
| `STARTING_BOOKING_ID` | `1001` | أول رقم حجز |

---

## 5. ملخص توزيع المهام
| العضو | GitHub | عدد المهام | النطاق الأساسي |
| :--- | :--- | :---: | :--- |
| **Ahmed M. Elsayad** | [@Ahmed-M-Elsayad](https://github.com/Ahmed-M-Elsayad) | **20** | المدير، الملفات، التجميع، `main` |
| **Reda Elkplawy** | [@Redaelkplawy](https://github.com/Redaelkplawy) | **12** | الحجوزات، المقاعد، التذاكر |
| **Omar** | [@omaralqblawy](https://github.com/omaralqblawy) | **13** | الأفلام، الصالات، المساعدات |
| **المجموع** | — | **45** | **تم تغطية جميع الوظائف بنجاح** |