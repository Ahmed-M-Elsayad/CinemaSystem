# 📋 قائمة المهام (Tasks List)

**إجمالي المهام:** 45 مهمة  
**التوزيع:** 3 مجموعات  
**الحالة:** ✅ مكتمل 100%

---

## 📊 ملخص التوزيع

| العضو | عدد المهام | النطاق |
| :--- | :---: | :--- |
| **Omar** | 13 | الأفلام + الصالات + المساعدات |
| **Reda** | 12 | الحجوزات + المقاعد + التذاكر |
| **Ahmed M. Elsayad** | 20 | المدير + الملفات + التجميع + `main` |
| **المجموع** | **45** | — |

---

## 1️⃣ مهام Omar (13 مهمة)

### الأفلام + الصالات

| # | اسم الدالة | التوقيع | الوصف | الحالة |
| :---: | :--- | :--- | :--- | :---: |
| 1 | `addNewHall` | `void (vector<Hall>&)` | إضافة صالة جديدة | ✅ |
| 2 | `displayAllHalls` | `void (const vector<Hall>&)` | عرض جميع الصالات | ✅ |
| 3 | `findHallById` | `const Hall* (const vector<Hall>&, int)` | البحث عن صالة (قراءة) | ✅ |
| 3 | `findHallById` | `Hall* (vector<Hall>&, int)` | البحث عن صالة (تعديل) | ✅ |
| 11 | `addNewMovie` | `void (vector<Movie>&, const vector<Hall>&)` | إضافة فيلم جديد | ✅ |
| 12 | `displayAllMovies` | `void (const vector<Movie>&)` | عرض جميع الأفلام | ✅ |
| 13 | `displayActiveMovies` | `void (const vector<Movie>&)` | عرض الأفلام النشطة فقط | ✅ |
| 14 | `findMovieById` | `const Movie* (const vector<Movie>&, int)` | البحث عن فيلم (قراءة) | ✅ |
| 14 | `findMovieById` | `Movie* (vector<Movie>&, int)` | البحث عن فيلم (تعديل) | ✅ |
| 15 | `updateMoviePrice` | `void (vector<Movie>&, int, double)` | تحديث سعر الفيلم | ✅ |
| 16 | `updateMovieStatus` | `void (vector<Movie>&, int, const string&)` | تحديث حالة الفيلم | ✅ |
| 17 | `deleteMovie` | `bool (vector<Movie>&, int, const vector<Booking>&)` | حذف فيلم | ✅ |
| 18 | `clearScreen` | `void ()` | مسح الشاشة | ✅ |
| 19 | `pressEnterToContinue` | `void ()` | الانتظار (Enter) | ✅ |
| 20 | `printHeader` | `void (const string&)` | طباعة عنوان | ✅ |

**المجموع الفعلي:** 15 سطر (Task 3 و Task 14 مكررين بنسختين).

---

## 2️⃣ مهام Reda (12 مهمة)

### الحجوزات + المقاعد + التذاكر

| # | اسم الدالة | التوقيع | الوصف | الحالة |
| :---: | :--- | :--- | :--- | :---: |
| 4 | `initializeSeats` | `vector<vector<char>> (int, int)` | تهيئة مصفوفة مقاعد جديدة | ✅ |
| 5 | `displaySeats` | `void (const vector<vector<char>>&)` | عرض خريطة المقاعد | ✅ |
| 6 | `isSeatAvailable` | `bool (const vector<vector<char>>&, int, int)` | التحقق من توفر مقعد | ✅ |
| 21 | `calculateTotalPrice` | `double (double, int, double&)` | حساب السعر مع خصم 10% | ✅ |
| 22 | `createBooking` | `void (vector<Movie>&, vector<Booking>&)` | الحجز الرئيسي (الأهم) | ✅ |
| 23 | `cancelBooking` | `void (vector<Booking>&, vector<Movie>&)` | إلغاء حجز | ✅ |
| 24 | `modifyBooking` | `void (vector<Booking>&, vector<Movie>&)` | تعديل حجز | ✅ |
| 25 | `printTicket` | `void (const Booking&, const Movie&)` | طباعة التذكرة | ✅ |
| 26 | `exportTicketToFile` | `void (const Booking&, const Movie&)` | تصدير التذكرة كملف | ✅ |
| 27 | `findBookingById` | `Booking* (vector<Booking>&, int)` | البحث عن حجز برقمه | ✅ |
| 28 | `getIntInput` | `int (int, int)` | إدخال رقم صحيح مع التحقق | ✅ |
| 29 | `getStringInput` | `string (const string&)` | إدخال نص | ✅ |

---

## 3️⃣ مهام Ahmed M. Elsayad (20 مهمة)

### المدير + الملفات + التجميع

| # | اسم الدالة | التوقيع | الوصف | الحالة |
| :---: | :--- | :--- | :--- | :---: |
| 7 | `bookSeat` | `bool (vector<vector<char>>&, int, int)` | حجز مقعد | ✅ |
| 8 | `unbookSeat` | `bool (vector<vector<char>>&, int, int)` | إلغاء حجز مقعد | ✅ |
| 9 | `getAvailableSeatsCount` | `int (const vector<vector<char>>&)` | حساب عدد المقاعد الفاضية | ✅ |
| 10 | `isValidSeat` | `bool (const vector<vector<char>>&, int, int)` | التحقق من صحة رقم المقعد | ✅ |
| 30 | `adminLogin` | `bool ()` | تسجيل دخول المدير | ✅ |
| 31 | `showAdminMenu` | `void (vector<Movie>&, vector<Hall>&, vector<Booking>&)` | عرض قائمة المدير | ✅ |
| 32 | `adminAddMovie` | `void (vector<Movie>&, const vector<Hall>&)` | إضافة فيلم (مدير) | ✅ |
| 33 | `adminEditMovie` | `void (vector<Movie>&)` | تعديل فيلم (مدير) | ✅ |
| 34 | `adminDeleteMovie` | `void (vector<Movie>&, const vector<Booking>&)` | حذف فيلم (مدير) | ✅ |
| 35 | `showSalesReport` | `void (const vector<Movie>&, const vector<Booking>&)` | عرض تقرير المبيعات | ✅ |
| 36 | `saveAllData` | `void (const vector<Hall>&, const vector<Movie>&, const vector<Booking>&)` | حفظ كل البيانات | ✅ |
| 37 | `loadAllData` | `void (vector<Hall>&, vector<Movie>&, vector<Booking>&)` | تحميل كل البيانات | ✅ |
| 38 | `saveHallsToFile` | `void (const vector<Hall>&)` | حفظ الصالات | ✅ |
| 39 | `loadHallsFromFile` | `void (vector<Hall>&)` | تحميل الصالات | ✅ |
| 40 | `saveMoviesToFile` | `void (const vector<Movie>&)` | حفظ الأفلام | ✅ |
| 41 | `loadMoviesFromFile` | `void (vector<Movie>&)` | تحميل الأفلام | ✅ |
| 42 | `saveBookingsToFile` | `void (const vector<Booking>&)` | حفظ الحجوزات | ✅ |
| 43 | `loadBookingsFromFile` | `void (vector<Booking>&)` | تحميل الحجوزات | ✅ |
| 44 | `main` | `int ()` | الملف الرئيسي | ✅ |
| 45 | `seedData` | `void (vector<Hall>&, vector<Movie>&)` | بيانات وهمية للتجربة | ✅ |

---

## ✅ قواعد العمل

1. **التوقيعات ثابتة** — أي تعديل يتطلب موافقة الفريق.
2. **مراجعة الكود** — كل PR يمر بمراجعة.
3. **التوثيق** — أي دالة جديدة تُضاف لـ `FUNCTIONS_AGREEMENT.md`.
4. **الاختبار** — كل دالة تُختبر قبل الدمج.

---

## 📌 تعليمات هامة للفريق

1. **التسمية:** كل الدوال بـ **camelCase** (مثل `addNewHall`).
2. **الملفات:** كل دالة في ملفين: `.h` (إعلان) و `.cpp` (تنفيذ).
3. **المسار:** ملفات `.h` في `include/`، ملفات `.cpp` في `src/`.
4. **الـ includes:** تُكتب بدون مسار (المترجم يبحث في `include/` عبر `-I`).
5. **التعليقات:** بالعربية أو الإنجليزية (لكن موحّدة داخل الملف).

---

## 📊 إحصائيات الإنجاز

| الحالة | العدد | النسبة |
| :--- | :---: | :---: |
| ✅ مكتمل | 45 | 100% |
| ⏳ قيد العمل | 0 | 0% |
| ❌ متأخر | 0 | 0% |

---

## 🎯 الخطوات التالية (Post-MVP)

أفكار لتحسينات مستقبلية:
- [ ] إضافة نظام تسجيل عملاء دائم (Customer accounts).
- [ ] دعم عدة صالات في نفس الوقت.
- [ ] واجهة رسومية (GUI) باستخدام Qt أو SFML.
- [ ] دعم اللغات المتعددة (i18n).
- [ ] تقارير متقدمة (PDF export).
- [ ] اختبارات آلية (Unit Tests).

---

**آخر تحديث:** 2026-09-16