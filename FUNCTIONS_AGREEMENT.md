# أسماء الدوال المتفق عليها (Functions Agreement)
---

## (محمد): الصالات والمقاعد

| Task number | Signature (fixed) | Selected name | Brief function description |
| :--- | :--- | :--- | :--- |
| Task 1 | `void (vector<Hall>& halls)` | ________ | إضافة صالة جديدة |
| Task 2 | `void (const vector<Hall>& halls)` | ________ | عرض جميع الصالات في جدول |
| Task 3 | `const Hall* (const vector<Hall>&, int)` | ________ | البحث عن صالة برقمها (للقراءة فقط) |
| Task 3 | `Hall* (vector<Hall>&, int)` | ________ | البحث عن صالة برقمها (للتعديل) |
| Task 4 | `vector<vector<char>> (int, int)` | ________ | إنشاء مصفوفة مقاعد جديدة (كلها O) |
| Task 5 | `void (const vector<vector<char>>&)` | ________ | طباعة خريطة المقاعد بشكل منسق |
| Task 6 | `bool (const vector<vector<char>>&, int, int)` | ________ | التحقق من توفر مقعد (O أم لا) |
| Task 7 | `bool (vector<vector<char>>&, int, int)` | ________ | حجز مقعد (تحويل O إلى X) |
| Task 8 | `void (vector<vector<char>>&, int, int)` | ________ | إلغاء حجز مقعد (تحويل X إلى O) |
| Task 9 | `int (const vector<vector<char>>&)` | ________ | حساب عدد المقاعد الفاضية |
| Task 10 | `bool (const vector<vector<char>>&, int, int)` | ________ | التحقق من صحة رقم المقعد (ضمن النطاق) |

---

## (عمر): الأفلام + المساعدات

| Task number | Signature (fixed) | Selected name | Brief function description |
| :--- | :--- | :--- | :--- |
| Task 11 | `void (vector<Movie>&, const vector<Hall>&)` | ________ | إضافة فيلم جديد مع ربطه بصالة |
| Task 12 | `void (const vector<Movie>&)` | ________ | عرض جميع الأفلام (حتى المنتهية) |
| Task 13 | `void (const vector<Movie>&)` | ________ | عرض الأفلام النشطة فقط (Now Showing) |
| Task 14 | `const Movie* (const vector<Movie>&, int)` | ________ | البحث عن فيلم برقمه (للقراءة فقط) |
| Task 14 | `Movie* (vector<Movie>&, int)` | ________ | البحث عن فيلم برقمه (للتعديل) |
| Task 15 | `void (vector<Movie>&, int, double)` | ________ | تغيير سعر تذكرة فيلم معين |
| Task 16 | `void (vector<Movie>&, int, const string&)` | ________ | تغيير حالة الفيلم (Now/Coming/Ended) |
| Task 17 | `bool (vector<Movie>&, int, const vector<Booking>&)` | ________ | حذف فيلم (إذا لم يكن عليه حجوزات) |
| Task 18 | `void ()` | ________ | مسح محتويات شاشة الكونسول |
| Task 19 | `void ()` | ________ | إيقاف البرنامج لحين الضغط على Enter |
| Task 20 | `void (const string&)` | ________ | طباعة عنوان بتنسيق (===== العنوان =====) |

---

## (رضا): الحجوزات

| Task number | Signature (fixed) | Selected name | Brief function description |
| :--- | :--- | :--- | :--- |
| Task 21 | `double (double, int, double&)` | ________ | حساب السعر مع خصم 10% (لو > 4 تذاكر) |
| Task 22 | `void (vector<Movie>&, vector<Booking>&)` | ________ | تنفيذ عملية الحجز الكاملة (الأهم) |
| Task 23 | `void (vector<Booking>&, vector<Movie>&)` | ________ | إلغاء حجز (استرجاع المقاعد وتغيير الحالة) |
| Task 24 | `void (vector<Booking>&, vector<Movie>&)` | ________ | تعديل حجز (إضافة/إزالة مقاعد وإعادة الحساب) |
| Task 25 | `void (const Booking&, const Movie&)` | ________ | طباعة التذكرة على الشاشة بشكل منظم |
| Task 26 | `void (const Booking&, const Movie&)` | ________ | تصدير التذكرة كملف (Ticket_[ID].txt) |
| Task 27 | `Booking* (vector<Booking>&, int)` | ________ | البحث عن حجز برقمه |
| Task 28 | `int (int, int)` | ________ | قراءة رقم مع التحقق من النطاق |
| Task 29 | `string (const string&)` | ________ | قراءة سطر نصي كامل (بمسافات) |

---

## (Ahmed M. Elsayad): المدير، الملفات، التجميع

| Task number | Signature (fixed) | Selected name | Brief function description |
| :--- | :--- | :--- | :--- |
| Task 30 | `bool ()` | `adminLogin` | التحقق من كلمة السر (3 محاولات) |
| Task 31 | `void (vector<Movie>&, vector<Hall>&, vector<Booking>&)` | `showAdminMenu` | عرض قائمة المدير |
| Task 32 | `void (vector<Movie>&, const vector<Hall>&)` | `adminAddMovie` | إضافة فيلم (بصلاحية المدير) |
| Task 33 | `void (vector<Movie>&)` | `adminEditMovie` | تعديل سعر أو حالة الفيلم |
| Task 34 | `void (vector<Movie>&, const vector<Booking>&)` | `adminDeleteMovie` | حذف فيلم (مع التحقق من الحجوزات) |
| Task 35 | `void (const vector<Movie>&, const vector<Booking>&)` | `showSalesReport` | عرض إجمالي الأرباح وأعلى فيلم مبيعاً |
| Task 36 | `void (const vector<Hall>&, const vector<Movie>&, const vector<Booking>&)` | `saveAllData` | حفظ كل البيانات دفعة واحدة |
| Task 37 | `void (vector<Hall>&, vector<Movie>&, vector<Booking>&)` | `loadAllData` | تحميل كل البيانات دفعة واحدة |
| Task 38 | `void (const vector<Hall>&)` | `saveHallsToFile` | حفظ الصالات في `halls.txt` |
| Task 39 | `void (vector<Hall>&)` | `loadHallsFromFile` | تحميل الصالات من `halls.txt` |
| Task 40 | `void (const vector<Movie>&)` | `saveMoviesToFile` | حفظ الأفلام والمقاعد في ملفات |
| Task 41 | `void (vector<Movie>&)` | `loadMoviesFromFile` | تحميل الأفلام والمقاعد من ملفات |
| Task 42 | `void (const vector<Booking>&)` | `saveBookingsToFile` | حفظ الحجوزات في `bookings.txt` |
| Task 43 | `void (vector<Booking>&)` | `loadBookingsFromFile` | تحميل الحجوزات من `bookings.txt` |
| Task 44 | `int ()` | `main` | نقطة بداية البرنامج (ثابتة) |
| Task 45 | `void (vector<Hall>&, vector<Movie>&)` | `seedData` | إضافة بيانات وهمية للتجربة |
