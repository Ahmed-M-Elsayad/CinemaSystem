# اتفاقية تنسيق الملفات (File Format Agreement)

هذا المستند يوثّق **تنسيق كل ملفات البيانات** في المشروع، لضمان التوافق بين دوال `save*` و `load*`.

> ⚠️ **مهم:** أي تعديل على تنسيق الملفات يتطلب تحديث كل من: دوال الحفظ، دوال التحميل، وهذا المستند.

---

## 📋 جدول المحتويات

- [مجلد `data/`](#مجلد-data)
- [ملف `halls.txt`](#ملف-hallstxt)
- [ملف `movies.txt`](#ملف-moviestxt)
- [ملف `bookings.txt`](#ملف-bookingstxt)
- [مجلد `receipts/`](#مجلد-receipts)

---

## مجلد `data/`

كل ملفات البيانات تُحفظ في مجلد `data/`، **وتُنشأ تلقائياً** عند أول تشغيل للبرنامج.

**ملاحظة:** المجلد ده **مستثنى جزئياً** من Git (فقط `bookings.txt`)، بينما `halls.txt` و `movies.txt` تُرفع كبيانات تجريبية (seed data).

---

## ملف `halls.txt`

**الغرض:** تخزين كل الصالات.

**التنسيق:** كل صالة في **سطر واحد**، الحقول مفصولة بـ `|`.

**الحقول:**
- `hallId` (int) — رقم الصالة
- `name` (string) — اسم الصالة
- `rows` (int) — عدد الصفوف
- `cols` (int) — عدد المقاعد
- `isVip` (int 0/1) — هل VIP؟

**مثال:**
1|Main Hall|5|6|0
2|VIP Hall|4|5|1

**الدوال:** `saveHallsToFile` (38)، `loadHallsFromFile` (39).

---

## ملف `movies.txt`

**الغرض:** تخزين كل الأفلام + مصفوفة المقاعد.

**التنسيق:** لكل فيلم عدة أسطر:
1. سطر بيانات الفيلم (7 حقول مفصولة بـ `|`)
2. سطر أبعاد المقاعد (`rows|cols`)
3. صفوف المقاعد (كل صف سطر منفصل)

**حقول الفيلم:** `movieId`, `name`, `genre`, `showtime`, `price`, `hallId`, `status`.

**الحالة:** `Now Showing` / `Coming Soon` / `Ended`.

**المقاعد:** `O` = فاضي، `X` = محجوز.

**مثال:**
1|Action Movie|Action|8:00 PM|100|1|Now Showing
5|6
XOOOOO
OOOOOO
OOOOOO
OOOOOO
OOOOOO

**الدوال:** `saveMoviesToFile` (40)، `loadMoviesFromFile` (41).

---

## ملف `bookings.txt`

**الغرض:** تخزين كل الحجوزات + العميل + المقاعد + التاريخ.

**التنسيق:** لكل حجز عدة أسطر:
1. سطر بيانات الحجز (10 حقول مفصولة بـ `|`)
2. سطر بيانات العميل (3 حقول مفصولة بـ `|`)
3. أسطر المقاعد (`row col`)
4. سطر التاريخ (`day month year`)

**حقول الحجز:** `bookingId`, `movieId`, `movieName`, `seatCount`, `pricePerSeat`, `originalPrice`, `discountAmount`, `totalPrice`, `isActive`, `isPaid`.

**حقول العميل:** `customerId`, `customerName`, `phone`.

**مثال:**
1001|1|Action Movie|2|100|200|0|200|1|1
501|Ahmed Mohamed|01034168403
0 0
0 1
3 9 2026

**الدوال:** `saveBookingsToFile` (42)، `loadBookingsFromFile` (43).

---

## مجلد `receipts/`

**الغرض:** حفظ التذاكر المُصدَّرة كملفات نصية.

**اسم الملف:** `Ticket_[bookingId].txt`

**الدوال:** `exportTicketToFile` (26).

**ملاحظة:** المجلد ده **مستثنى** من Git.

---

## ⚠️ ملاحظات عامة

1. **الفواصل:** كل الحقول مفصولة بـ `|` (pipe) — مفيش مسافات حول الفاصل.
2. **النهايات:** كل سطر ينتهي بـ Unix newline.
3. **الترميز:** الملفات بترميز **UTF-8**.
4. **الفولدرات:** `data/` و `receipts/` يُنشأوا تلقائياً.
5. **التحقق:** دوال `load*` تتحقق من وجود الملفات قبل القراءة.
