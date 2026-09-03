# 📋 قائمة التاسكات (Tasks) – مشروع السينما 🎬

**إجمالي عدد التاسكات:** 45 تاسكاً  
**توزيع التاسكات:** 4 مجوعات.

---

##  محمد (Mohammed): الصالات والمقاعد. 
| Task number | Function name (suggested) | Signature (fixed) | Description |
| :--- | :--- | :--- | :--- |
| Task 1 | ________ | `void (vector<Hall>& halls)` | إضافة صالة جديدة |
| Task 2 | ________ | `void (const vector<Hall>& halls)` | عرض جميع الصالات |
| Task 3 | ________ | `const Hall* (const vector<Hall>&, int)` | البحث عن صالة (للقراءة) |
| Task 3 | ________ | `Hall* (vector<Hall>&, int)` | البحث عن صالة (للتعديل) |
| Task 4 | ________ | `vector<vector<char>> (int, int)` | تهيئة مصفوفة مقاعد جديدة |
| Task 5 | ________ | `void (const vector<vector<char>>&)` | عرض خريطة المقاعد |
| Task 6 | ________ | `bool (const vector<vector<char>>&, int, int)` | التحقق من توفر مقعد |
| Task 7 | ________ | `bool (vector<vector<char>>&, int, int)` | حجز مقعد |
| Task 8 | ________ | `void (vector<vector<char>>&, int, int)` | إلغاء حجز مقعد |
| Task 9 | ________ | `int (const vector<vector<char>>&)` | حساب عدد المقاعد الفاضية |
| Task 10 | ________ | `bool (const vector<vector<char>>&, int, int)` | التحقق من صحة رقم المقعد |

---

##  عمر (Omar): الأفلام + المساعدات.
| Task number | Function name (suggested) | Signature (fixed) | Description |
| :--- | :--- | :--- | :--- |
| Task 11 | addNewMovie | `void (vector<Movie>&, const vector<Hall>&)` | إضافة فيلم جديد |
| Task 12 | displayAllMovies | `void (const vector<Movie>&)` | عرض جميع الأفلام |
| Task 13 | displayActiveMovies | `void (const vector<Movie>&)` | عرض الأفلام النشطة فقط |
| Task 14 | findMovieById | `const Movie* (const vector<Movie>&, int)` | البحث عن فيلم (للقراءة) |
| Task 14 | findMovieById | `Movie* (vector<Movie>&, int)` | البحث عن فيلم (للتعديل) |
| Task 15 | updateMoviePrice | `void (vector<Movie>&, int, double)` | تحديث سعر الفيلم |
| Task 16 | updateMovieStatus | `void (vector<Movie>&, int, const string&)` | تحديث حالة الفيلم |
| Task 17 | deleteMovie | `bool (vector<Movie>&, int, const vector<Booking>&)` | حذف فيلم |
| Task 18 | clearScreen | `void ()` | مسح الشاشة |
| Task 19 | pressEnterToContinue | `void ()` | الانتظار (Enter) |
| Task 20 | printHeader | `void (const string&)` | طباعة عنوان |


---

## رضا (Reda): الحجوزات.
| Task number | Function name (suggested) | Signature (fixed) | Description |
| :--- | :--- | :--- | :--- |
| Task 21 | calculateTotalPrice | `double (double, int, double&)` | حساب السعر مع خصم 10% |
| Task 22 | createBooking | `void (vector<Movie>&, vector<Booking>&)` | الحجز الرئيسي (الأهم) |
| Task 23 | cancelBooking | `void (vector<Booking>&, vector<Movie>&)` | إلغاء حجز |
| Task 24 | modifyBooking | `void (vector<Booking>&, vector<Movie>&)` | تعديل حجز |
| Task 25 | printTicket | `void (const Booking&, const Movie&)` | طباعة التذكرة |
| Task 26 | exportTicketToFile | `void (const Booking&, const Movie&)` | تصدير التذكرة كملف |
| Task 27 | findBookingById | `Booking* (vector<Booking>&, int)` | البحث عن حجز برقمه |
| Task 28 | getIntInput | `int (int, int)` | إدخال رقم صحيح مع التحقق |
| Task 29 | getStringInput | `string (const string&)` | إدخال نص |

---

## أحمد (Ahmed M. Elsayad): المدير، الملفات، التجميع.
| Task number | Function name (suggested) | Signature (fixed) | Description |
| :--- | :--- | :--- | :--- |
| Task 30 | `adminLogin` | `bool ()` | تسجيل دخول المدير |
| Task 31 | `showAdminMenu` | `void (vector<Movie>&, vector<Hall>&, vector<Booking>&)` | عرض قائمة المدير |
| Task 32 | `adminAddMovie` | `void (vector<Movie>&, const vector<Hall>&)` | إضافة فيلم (مدير) |
| Task 33 | `adminEditMovie` | `void (vector<Movie>&)` | تعديل فيلم (مدير) |
| Task 34 | `adminDeleteMovie` | `void (vector<Movie>&, const vector<Booking>&)` | حذف فيلم (مدير) |
| Task 35 | `showSalesReport` | `void (const vector<Movie>&, const vector<Booking>&)` | عرض تقرير المبيعات |
| Task 36 | `saveAllData` | `void (const vector<Hall>&, const vector<Movie>&, const vector<Booking>&)` | حفظ كل البيانات |
| Task 37 | `loadAllData` | `void (vector<Hall>&, vector<Movie>&, vector<Booking>&)` | تحميل كل البيانات |
| Task 38 | `saveHallsToFile` | `void (const vector<Hall>&)` | حفظ الصالات في ملف |
| Task 39 | `loadHallsFromFile` | `void (vector<Hall>&)` | تحميل الصالات من ملف |
| Task 40 | `saveMoviesToFile` | `void (const vector<Movie>&)` | حفظ الأفلام في ملف |
| Task 41 | `loadMoviesFromFile` | `void (vector<Movie>&)` | تحميل الأفلام من ملف |
| Task 42 | `saveBookingsToFile` | `void (const vector<Booking>&)` | حفظ الحجوزات في ملف |
| Task 43 | `loadBookingsFromFile` | `void (vector<Booking>&)` | تحميل الحجوزات من ملف |
| Task 44 | `main` | `int ()` | الملف الرئيسي (ثابت) |
| Task 45 | `seedData` | `void (vector<Hall>&, vector<Movie>&)` | بيانات وهمية للتجربة |


## 📌 تعليمات هامة للفريق

1. **الخانات الفارغة (________)** هتتحدد في الاجتماع.
2. **التوقيعات ثابتة** ومش مسموح تغييرها عشان الدوال ترتبط ببعضها.
3. **بعد ما كل جزء يخلص، هنتجمع عشان نربطهم ببعض.**
---

## ✅ الخلاصة النهائية للتوزيع

| Member | Number of Tasks | Task Numbers |
| :--- | :--- | :--- |
| **محمد (Mohammed)** | 10 | Task 1 → Task 10 |
| **عمر (Omar)** | 10 | Task 11 → Task 20 |
| **رضا (Reda)** | 9 | Task 21 → Task 29 |
| **Ahmed M. Elsayad** | 16 | Task 30 → Task 45 |
