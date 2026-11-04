# 📜 اتفاقية الدوال (Functions Agreement)

هذا الملف هو **العقد البرمجي** بين أعضاء الفريق: أسماء الدوال وتوقيعاتها (Signatures) ثابتة، ولا يجوز تغييرها دون موافقة الفريق، حتى يعمل كل شخص على جزئه بشكل مستقل ثم يتم الدمج بدون مشاكل.

**إجمالي الدوال: 42 مهمة** — أحمد (20) • رضا (12) • عمر (10)

> جميع التعاريف (Structs) موجودة في `include/CinemaData.h`، وكل دالة رئيسية في ملف `.cpp` منفصل داخل `src/`.

---

## 👤 Omar — إدارة الأفلام والصالات والدوال المساعدة (10 مهام)

| # | الدالة (Signature) | الوصف |
| :-: | :--- | :--- |
| 1 | `void displayAllHalls(const std::vector<Hall>& halls)` | عرض جميع الصالات في جدول منسق. |
| 2 | `const Hall* findHallById(const std::vector<Hall>& halls, int hallId)` | البحث عن صالة برقمها (للقراءة فقط). |
| 3 | `Hall* findHallById(std::vector<Hall>& halls, int hallId)` | البحث عن صالة برقمها (للتعديل). |
| 4 | `void displayAllMovies(const std::vector<Movie>& movies)` | عرض جميع الأفلام (حتى المنتهية). |
| 5 | `void displayActiveMovies(const std::vector<Movie>& movies)` | عرض الأفلام النشطة فقط (Now Showing). |
| 6 | `const Movie* findMovieById(const std::vector<Movie>& movies, int movieId)` | البحث عن فيلم برقمه (للقراءة فقط). |
| 7 | `Movie* findMovieById(std::vector<Movie>& movies, int movieId)` | البحث عن فيلم برقمه (للتعديل). |
| 8 | `void clearScreen()` | مسح محتويات شاشة الكونسول. |
| 9 | `void pressEnterToContinue()` | الانتظار حتى ضغط Enter (مع تنظيف البافر). |
| 10 | `void printHeader(const std::string& title)` | طباعة عنوان بتنسيق `===== العنوان =====`. |

---

## 🎫 Reda — نظام الحجوزات والمقاعد والتذاكر (12 مهمة)

| # | الدالة (Signature) | الوصف |
| :-: | :--- | :--- |
| 11 | `std::vector<std::vector<char>> initializeSeats(int rows, int cols)` | إنشاء مصفوفة مقاعد جديدة (كلها 'O'). |
| 12 | `void displaySeats(const std::vector<std::vector<char>>& seats)` | طباعة خريطة المقاعد بشكل منسق. |
| 13 | `bool isSeatAvailable(const std::vector<std::vector<char>>& seats, int row, int col)` | التحقق من توفر مقعد. |
| 14 | `double calculateTotalPrice(double pricePerSeat, int numTickets, double& discountAmount)` | حساب السعر مع خصم 10% (لو > 4 تذاكر). |
| 15 | `void createBooking(std::vector<Movie>& movieList, std::vector<Booking>& bookingList)` | تنفيذ عملية الحجز الكاملة (حتى 10 تذاكر). |
| 16 | `void cancelBooking(std::vector<Booking>& bookingList, std::vector<Movie>& movieList)` | إلغاء حجز واسترجاع المقاعد. |
| 17 | `void modifyBooking(std::vector<Booking>& bookingList, std::vector<Movie>& movieList)` | تعديل حجز (إضافة/إزالة مقاعد). |
| 18 | `void printTicket(const Booking& booking, const Movie& movie)` | طباعة التذكرة على الشاشة. |
| 19 | `void exportTicketToFile(const Booking& booking, const Movie& movie)` | تصدير التذكرة كملف `Ticket_[ID].txt`. |
| 20 | `Booking* findBookingById(std::vector<Booking>& bookingList, int bookingId)` | البحث عن حجز برقمه. |
| 21 | `int getIntInput(int min, int max)` | قراءة رقم صحيح مع التحقق من النطاق. |
| 22 | `std::string getStringInput(const std::string& prompt)` | قراءة سطر نصي كامل (مع منع الرمز `\|`). |

---

## 🔐 Ahmed — واجهة المدير وإدارة الملفات والتجميع (20 مهمة)

| # | الدالة (Signature) | الوصف |
| :-: | :--- | :--- |
| 23 | `bool bookSeat(std::vector<std::vector<char>>& seats, int row, int col)` | حجز مقعد (تحويل O إلى X). |
| 24 | `bool unbookSeat(std::vector<std::vector<char>>& seats, int row, int col)` | إلغاء حجز مقعد (تحويل X إلى O). |
| 25 | `int getAvailableSeatsCount(const std::vector<std::vector<char>>& seats)` | حساب عدد المقاعد الفاضية. |
| 26 | `bool isValidSeat(const std::vector<std::vector<char>>& seats, int row, int col)` | التحقق من صحة رقم المقعد. |
| 27 | `bool adminLogin()` | التحقق من كلمة السر (3 محاولات، بيئة أو ملف). |
| 28 | `void showAdminMenu(std::vector<Movie>& movies, std::vector<Hall>& halls, std::vector<Booking>& bookings)` | عرض قائمة المدير. |
| 29 | `void adminAddMovie(std::vector<Movie>& movies, const std::vector<Hall>& halls)` | إضافة فيلم (بصلاحية المدير). |
| 30 | `void adminEditMovie(std::vector<Movie>& movies)` | تعديل سعر أو حالة فيلم. |
| 31 | `void adminDeleteMovie(std::vector<Movie>& movies, const std::vector<Booking>& bookings)` | حذف فيلم (مع التحقق من الحجوزات). |
| 32 | `void showSalesReport(const std::vector<Movie>& movies, const std::vector<Booking>& bookings)` | عرض إجمالي الأرباح وأعلى فيلم مبيعاً. |
| 33 | `void saveAllData(const std::vector<Hall>& halls, const std::vector<Movie>& movies, const std::vector<Booking>& bookings)` | حفظ كل البيانات دفعة واحدة. |
| 34 | `void loadAllData(std::vector<Hall>& halls, std::vector<Movie>& movies, std::vector<Booking>& bookings)` | تحميل كل البيانات دفعة واحدة. |
| 35 | `void saveHallsToFile(const std::vector<Hall>& halls)` | حفظ الصالات في `halls.txt`. |
| 36 | `void loadHallsFromFile(std::vector<Hall>& halls)` | تحميل الصالات من `halls.txt`. |
| 37 | `void saveMoviesToFile(const std::vector<Movie>& movies)` | حفظ الأفلام والمقاعد في `movies.txt`. |
| 38 | `void loadMoviesFromFile(std::vector<Movie>& movies)` | تحميل الأفلام والمقاعد من `movies.txt`. |
| 39 | `void saveBookingsToFile(const std::vector<Booking>& bookings)` | حفظ الحجوزات في `bookings.txt`. |
| 40 | `void loadBookingsFromFile(std::vector<Booking>& bookings)` | تحميل الحجوزات من `bookings.txt`. |
| 41 | `int main()` | نقطة بداية البرنامج. |
| 42 | `void seedData(std::vector<Hall>& halls, std::vector<Movie>& movies)` | إضافة بيانات وهمية للتجربة. |

---

## 🛠️ الدوال المساعدة (Helpers) — غير محسوبة في الـ 42

| الملف | الدالة | الوظيفة |
| :--- | :--- | :--- |
| `bookingHelpers.h/.cpp` | `countFreeSeats`, `selectSeats`, `applyPricing` | دوال مشتركة بين إنشاء الحجز وتعديله. |
| `fileUtils.h/.cpp` | `splitLine`, `readLine`, `parseInt`, `parseDouble`, `ensureDataDirectory` | قراءة آمنة للملفات وإنشاء المجلدات. |
| `sha256.h/.cpp` | `sha256Hex` | تشفير كلمات السر باستخدام SHA-256. |

---

## 🌐 المتغيرات والثوابت العامة

### المتغيرات العامة (Global Variables)
تُعرَّف هذه العناصر في `include/CinemaData.h` (باستخدام `extern`) وتُعرَّف فعلياً في `src/main.cpp`.

| Variable | Type | Description |
| :--- | :--- | :--- |
| `halls` | `std::vector<Hall>` | قائمة كل الصالات. |
| `movies` | `std::vector<Movie>` | قائمة كل الأفلام. |
| `bookings` | `std::vector<Booking>` | قائمة كل الحجوزات. |

### الثوابت العامة (Global Constants)

| Constant | Value | Description |
| :--- | :--- | :--- |
| `ROWS_DEFAULT` | `5` | عدد الصفوف الافتراضي. |
| `COLS_DEFAULT` | `6` | عدد الأعمدة الافتراضي. |
| `DISCOUNT_THRESHOLD` | `4` | عدد التذاكر المؤهل للخصم. |
| `DISCOUNT_RATE` | `0.10` | نسبة الخصم (10%). |
| `STARTING_BOOKING_ID` | `1` | أول رقم حجز. |

> 🔐 تم حذف `ADMIN_PASSWORD` من الكود لحماية أمنية. (يُقرأ الآن من متغير بيئة أو ملف `data/admin.hash` المحلي).

---

## ✅ قواعد الالتزام

1. لا تغيّر اسم دالة أو توقيعها دون إبلاغ الفريق وتحديث هذا الملف.
2. كل دالة في ملف `.cpp` مستقل داخل `src/` والتصريح بها في `include/`.
3. كل متغير يُهيأ بقيمة افتراضية.
4. الكود يجب أن يمر من `g++ -std=c++20 -Wall -Wextra` بدون تحذيرات قبل الدمج.
5. أي Pull Request يجب أن يجتاز SonarCloud Quality Gate.
