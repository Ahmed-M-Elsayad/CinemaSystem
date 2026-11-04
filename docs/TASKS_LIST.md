# 📋 قائمة المهام (Tasks List)

**إجمالي المهام:** 42 مهمة (بعد إعادة الهيكلة والدمج)  
**التوزيع:** 3 مجموعات  
**الحالة:** ✅ مكتمل 100%

---

## 📊 ملخص التوزيع

| العضو | عدد المهام | النطاق |
| :--- | :---: | :--- |
| **Ahmed M. Elsayad** | 20 | المدير + الملفات + التجميع + `main` |
| **Reda Elkplawy** | 12 | الحجوزات + المقاعد + التذاكر |
| **Omar** | 10 | عرض الأفلام + الصالات + المساعدات |
| **المجموع** | **42** | — |

---

## 1️⃣ مهام Omar (10 مهام)

### الأفلام + الصالات + المساعدات

| # | اسم الدالة | التوقيع | الوصف | الحالة |
| :---: | :--- | :--- | :--- | :---: |
| 1 | `displayAllHalls` | `void (const vector<Hall>&)` | عرض جميع الصالات | ✅ |
| 2 | `findHallById` | `const Hall* (const vector<Hall>&, int)` | البحث عن صالة (قراءة) | ✅ |
| 3 | `findHallById` | `Hall* (vector<Hall>&, int)` | البحث عن صالة (تعديل) | ✅ |
| 4 | `displayAllMovies` | `void (const vector<Movie>&)` | عرض جميع الأفلام | ✅ |
| 5 | `displayActiveMovies` | `void (const vector<Movie>&)` | عرض الأفلام النشطة فقط | ✅ |
| 6 | `findMovieById` | `const Movie* (const vector<Movie>&, int)` | البحث عن فيلم (قراءة) | ✅ |
| 7 | `findMovieById` | `Movie* (vector<Movie>&, int)` | البحث عن فيلم (تعديل) | ✅ |
| 8 | `clearScreen` | `void ()` | مسح الشاشة | ✅ |
| 9 | `pressEnterToContinue` | `void ()` | الانتظار (Enter) | ✅ |
| 10 | `printHeader` | `void (const string&)` | طباعة عنوان | ✅ |

*(ملاحظة: تم دمج إدارة الأفلام بالكامل في واجهة المدير (`adminAddMovie`، `adminEditMovie`، `adminDeleteMovie`) لضمان مركزية الصلاحيات).*

---

## 2️⃣ مهام Reda (12 مهمة)

### الحجوزات + المقاعد + التذاكر

| # | اسم الدالة | التوقيع | الوصف | الحالة |
| :---: | :--- | :--- | :--- | :---: |
| 11 | `initializeSeats` | `vector<vector<char>> (int, int)` | تهيئة مصفوفة مقاعد جديدة | ✅ |
| 12 | `displaySeats` | `void (const vector<vector<char>>&)` | عرض خريطة المقاعد | ✅ |
| 13 | `isSeatAvailable` | `bool (const vector<vector<char>>&, int, int)` | التحقق من توفر مقعد | ✅ |
| 14 | `calculateTotalPrice` | `double (double, int, double&)` | حساب السعر مع خصم 10% | ✅ |
| 15 | `createBooking` | `void (vector<Movie>&, vector<Booking>&)` | الحجز الرئيسي (الأهم) | ✅ |
| 16 | `cancelBooking` | `void (vector<Booking>&, vector<Movie>&)` | إلغاء حجز | ✅ |
| 17 | `modifyBooking` | `void (vector<Booking>&, vector<Movie>&)` | تعديل حجز | ✅ |
| 18 | `printTicket` | `void (const Booking&, const Movie&)` | طباعة التذكرة | ✅ |
| 19 | `exportTicketToFile` | `void (const Booking&, const Movie&)` | تصدير التذكرة كملف | ✅ |
| 20 | `findBookingById` | `Booking* (vector<Booking>&, int)` | البحث عن حجز برقمه | ✅ |
| 21 | `getIntInput` | `int (int, int)` | إدخال رقم صحيح مع التحقق | ✅ |
| 22 | `getStringInput` | `string (const string&)` | إدخال نص | ✅ |

---

## 3️⃣ مهام Ahmed M. Elsayad (20 مهمة)

### المدير + الملفات + التجميع + المساعدات

| # | اسم الدالة | التوقيع | الوصف | الحالة |
| :---: | :--- | :--- | :--- | :---: |
| 23 | `bookSeat` | `bool (vector<vector<char>>&, int, int)` | حجز مقعد | ✅ |
| 24 | `unbookSeat` | `bool (vector<vector<char>>&, int, int)` | إلغاء حجز مقعد | ✅ |
| 25 | `getAvailableSeatsCount` | `int (const vector<vector<char>>&)` | حساب عدد المقاعد الفاضية | ✅ |
| 26 | `isValidSeat` | `bool (const vector<vector<char>>&, int, int)` | التحقق من صحة رقم المقعد | ✅ |
| 27 | `adminLogin` | `bool ()` | تسجيل دخول المدير الآمن | ✅ |
| 28 | `showAdminMenu` | `void (vector<Movie>&, vector<Hall>&, vector<Booking>&)` | عرض قائمة المدير | ✅ |
| 29 | `adminAddMovie` | `void (vector<Movie>&, const vector<Hall>&)` | إضافة فيلم (مدير) | ✅ |
| 30 | `adminEditMovie` | `void (vector<Movie>&)` | تعديل فيلم (مدير) | ✅ |
| 31 | `adminDeleteMovie` | `void (vector<Movie>&, const vector<Booking>&)` | حذف فيلم (مدير) | ✅ |
| 32 | `showSalesReport` | `void (const vector<Movie>&, const vector<Booking>&)` | عرض تقرير المبيعات | ✅ |
| 33 | `saveAllData` | `void (const vector<Hall>&, const vector<Movie>&, const vector<Booking>&)` | حفظ كل البيانات | ✅ |
| 34 | `loadAllData` | `void (vector<Hall>&, vector<Movie>&, vector<Booking>&)` | تحميل كل البيانات | ✅ |
| 35 | `saveHallsToFile` | `void (const vector<Hall>&)` | حفظ الصالات | ✅ |
| 36 | `loadHallsFromFile` | `void (vector<Hall>&)` | تحميل الصالات | ✅ |
| 37 | `saveMoviesToFile` | `void (const vector<Movie>&)` | حفظ الأفلام | ✅ |
| 38 | `loadMoviesFromFile` | `void (vector<Movie>&)` | تحميل الأفلام | ✅ |
| 39 | `saveBookingsToFile` | `void (const vector<Booking>&)` | حفظ الحجوزات | ✅ |
| 40 | `loadBookingsFromFile` | `void (vector<Booking>&)` | تحميل الحجوزات | ✅ |
| 41 | `main` | `int ()` | الملف الرئيسي | ✅ |
| 42 | `seedData` | `void (vector<Hall>&, vector<Movie>&)` | بيانات وهمية للتجربة | ✅ |

---

## ✅ قواعد العمل

1. **التوقيعات ثابتة** — أي تعديل يتطلب موافقة الفريق.
2. **مراجعة الكود** — كل PR يمر بمراجعة.
3. **التوثيق** — أي دالة جديدة تُضاف لـ `FUNCTIONS_AGREEMENT.md`.
4. **الاختبار** — كل دالة تُختبر قبل الدمج.

---

## 📌 تعليمات هامة للفريق

1. **التسمية:** كل الدوال بـ **camelCase** (مثل `displayAllHalls`).
2. **الملفات:** كل دالة في ملفين: `.h` (إعلان) و `.cpp` (تنفيذ).
3. **المسار:** ملفات `.h` في `include/`، ملفات `.cpp` في `src/`.
4. **الـ includes:** تُكتب بدون مسار (المترجم يبحث في `include/` عبر `-I`).
5. **التعليقات:** بالعربية أو الإنجليزية (لكن موحّدة داخل الملف).

---

## 📊 إحصائيات الإنجاز

| الحالة | العدد | النسبة |
| :--- | :---: | :---: |
| ✅ مكتمل | 42 | 100% |
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

**آخر تحديث:** 2026-10-19