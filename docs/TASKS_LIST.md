# 📋 قائمة التاسكات (Tasks) – مشروع السينما 🎬

**إجمالي عدد التاسكات:** 45 تاسكاً  
**توزيع التاسكات:** 4 مجوعات.

---

##  رضا (Reda): الصالات والمقاعد. 
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

##  محمد (Mohamed): الأفلام + المساعدات.
| Task number | Function name (suggested) | Signature (fixed) | Description |
| :--- | :--- | :--- | :--- |
| Task 11 | ________ | `void (vector<Movie>&, const vector<Hall>&)` | إضافة فيلم جديد |
| Task 12 | ________ | `void (const vector<Movie>&)` | عرض جميع الأفلام |
| Task 13 | ________ | `void (const vector<Movie>&)` | عرض الأفلام النشطة فقط |
| Task 14 | ________ | `const Movie* (const vector<Movie>&, int)` | البحث عن فيلم (للقراءة) |
| Task 14 | ________ | `Movie* (vector<Movie>&, int)` | البحث عن فيلم (للتعديل) |
| Task 15 | ________ | `void (vector<Movie>&, int, double)` | تحديث سعر الفيلم |
| Task 16 | ________ | `void (vector<Movie>&, int, const string&)` | تحديث حالة الفيلم |
| Task 17 | ________ | `bool (vector<Movie>&, int, const vector<Booking>&)` | حذف فيلم |
| Task 18 | ________ | `void ()` | مسح الشاشة |
| Task 19 | ________ | `void ()` | الانتظار (Enter) |
| Task 20 | ________ | `void (const string&)` | طباعة عنوان |


---

## عمر (Omar): الحجوزات.
| Task number | Function name (suggested) | Signature (fixed) | Description |
| :--- | :--- | :--- | :--- |
| Task 21 | ________ | `double (double, int, double&)` | حساب السعر مع خصم 10% |
| Task 22 | ________ | `void (vector<Movie>&, vector<Booking>&)` | الحجز الرئيسي (الأهم) |
| Task 23 | ________ | `void (vector<Booking>&, vector<Movie>&)` | إلغاء حجز |
| Task 24 | ________ | `void (vector<Booking>&, vector<Movie>&)` | تعديل حجز |
| Task 25 | ________ | `void (const Booking&, const Movie&)` | طباعة التذكرة |
| Task 26 | ________ | `void (const Booking&, const Movie&)` | تصدير التذكرة كملف |
| Task 27 | ________ | `Booking* (vector<Booking>&, int)` | البحث عن حجز برقمه |
| Task 28 | ________ | `int (int, int)` | إدخال رقم صحيح مع التحقق |
| Task 29 | ________ | `string (const string&)` | إدخال نص |

---

## (أحمد): المدير، الملفات، التجميع.
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

**ملاحظات:**
- **Tasks 36-43**: كلها دوال حفظ وتحميل، بتحتاج `CinemaData.h` بس. مش محتاجة حد تاني.
- **Tasks 30-35**: بتعتمد على دوال محمد وعمر ورضا (لأنها بتستديهم).
- **Task 44 (`main.cpp`)**: هي اللي هتجمع كل حاجة في الآخر.

---

## 📌 تعليمات هامة للفريق

1. **الخانات الفارغة (________)** هتتحدد في الاجتماع.
2. **التوقيعات ثابتة** ومش مسموح تغييرها عشان الدوال ترتبط ببعضها.
3. **بعد ما كل جزء يخلص، هنتجمع عشان نربطهم ببعض.**
---

## ✅ الخلاصة النهائية للتوزيع

| Member | Number of Tasks | Task Numbers |
| :--- | :--- | :--- |
| **رضا (Reda)** | 10 | Task 1 → Task 10 |
| **محمد (Mohamed)** | 10 | Task 11 → Task 20 |
| **عمر (Omar)** | 9 | Task 21 → Task 29 |
| **Ahmed M. Elsayad** | 16 | Task 30 → Task 45 |
