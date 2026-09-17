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

```
data/
├── halls.txt
├── movies.txt
└── bookings.txt
```

**ملاحظة:** المجلد ده **مستثنى جزئياً** من Git (فقط `bookings.txt`)، بينما `halls.txt` و `movies.txt` تُرفع كبيانات تجريبية (seed data).

---

## ملف `halls.txt`

**الغرض:** تخزين كل الصالات.

**التنسيق:** كل صالة في **سطر واحد**، الحقول مفصولة بـ `|`.

```
hallId|name|rows|cols|isVip
```

| الحقل | النوع | مثال | الوصف |
| :--- | :--- | :--- | :--- |
| `hallId` | int | `1` | رقم الصالة (فريد) |
| `name` | string | `Main Hall` | اسم الصالة |
| `rows` | int | `5` | عدد الصفوف |
| `cols` | int | `6` | عدد المقاعد في كل صف |
| `isVip` | int (0/1) | `1` | هل الصالة VIP؟ |

**مثال كامل:**
```
1|Main Hall|5|6|0
2|VIP Hall|4|5|1
```

**الدوال المرتبطة:**
- **الحفظ:** `saveHallsToFile` (Task 38)
- **التحميل:** `loadHallsFromFile` (Task 39)

---

## ملف `movies.txt`

**الغرض:** تخزين كل الأفلام + مصفوفة المقاعد الخاصة بها.

**التنسيق:** لكل فيلم **عدة أسطر**:
1. سطر بيانات الفيلم (7 حقول مفصولة بـ `|`)
2. سطر أبعاد المقاعد (حقلان مفصولان بـ `|`)
3. صفوف المقاعد (كل صف سطر منفصل)

```
movieId|name|genre|showtime|price|hallId|status
rows|cols
XXXXXX
OOOOOO
...
```

### سطر بيانات الفيلم (7 حقول)

| الحقل | النوع | مثال | الوصف |
| :--- | :--- | :--- | :--- |
| `movieId` | int | `1` | رقم الفيلم (فريد) |
| `name` | string | `Action Movie` | اسم الفيلم |
| `genre` | string | `Action` | التصنيف |
| `showtime` | string | `8:00 PM` | وقت العرض |
| `price` | double | `100.0` | سعر التذكرة |
| `hallId` | int | `1` | رقم الصالة |
| `status` | string | `Now Showing` | الحالة (`Now Showing` / `Coming Soon` / `Ended`) |

### سطر أبعاد المقاعد (حقلان)

| الحقل | النوع | مثال |
| :--- | :--- | :--- |
| `rows` | int | `5` |
| `cols` | int | `6` |

### صفوف المقاعد

- كل صف = **سطر واحد** من الأحرف.
- الطول = `cols`.
- `O` = مقعد فاضي، `X` = مقعد محجوز.

**مثال كامل:**
```
1|Action Movie|Action|8:00 PM|100|1|Now Showing
5|6
XOOOOO
OOOOOO
OOOOOO
OOOOOO
OOOOOO
2|Romance Film|Drama|9:30 PM|80|2|Coming Soon
4|5
OOOOO
OOOOO
OOOOO
OOOOO
```

**الدوال المرتبطة:**
- **الحفظ:** `saveMoviesToFile` (Task 40)
- **التحميل:** `loadMoviesFromFile` (Task 41)

---

## ملف `bookings.txt`

**الغرض:** تخزين كل الحجوزات + بيانات العملاء + المقاعد + التاريخ.

**التنسيق:** لكل حجز **عدة أسطر**:
1. سطر بيانات الحجز (10 حقول مفصولة بـ `|`)
2. سطر بيانات العميل (3 حقول مفصولة بـ `|`)
3. أسطر المقاعد المحجوزة (سطر لكل مقعد: `row col`)
4. سطر التاريخ (`day month year`)

```
bookingId|movieId|movieName|seatCount|pricePerSeat|originalPrice|discountAmount|totalPrice|isActive|isPaid
customerId|customerName|phone
row col
row col
...
day month year
```

### سطر بيانات الحجز (10 حقول)

| الحقل | النوع | مثال | الوصف |
| :--- | :--- | :--- | :--- |
| `bookingId` | int | `1001` | رقم الحجز (يبدأ من 1001) |
| `movieId` | int | `1` | رقم الفيلم |
| `movieName` | string | `Action Movie` | اسم الفيلم (للطباعة) |
| `seatCount` | int | `3` | عدد المقاعد |
| `pricePerSeat` | double | `100.0` | سعر التذكرة الواحدة |
| `originalPrice` | double | `300.0` | السعر قبل الخصم |
| `discountAmount` | double | `0.0` | قيمة الخصم |
| `totalPrice` | double | `300.0` | السعر النهائي |
| `isActive` | int (0/1) | `1` | هل الحجز نشط؟ |
| `isPaid` | int (0/1) | `1` | هل مدفوع؟ |

### سطر بيانات العميل (3 حقول)

| الحقل | النوع | مثال |
| :--- | :--- | :--- |
| `customerId` | int | `501` |
| `customerName` | string | `Ahmed Mohamed` |
| `phone` | string | `01034168403` |

### أسطر المقاعد

- كل سطر: `row col`
- عدد الأسطر = `seatCount`
- الأرقام **0-indexed**

### سطر التاريخ

- التنسيق: `day month year`
- مثال: `3 9 2026`

**مثال كامل:**
```
1001|1|Action Movie|2|100|200|0|200|1|1
501|Ahmed Mohamed|01034168403
0 0
0 1
3 9 2026
1002|2|Romance Film|5|80|400|40|360|1|1
502|Sara Ali|01234567890
1 2
1 3
1 4
2 0
2 1
5 9 2026
```

**الدوال المرتبطة:**
- **الحفظ:** `saveBookingsToFile` (Task 42)
- **التحميل:** `loadBookingsFromFile` (Task 43)

---

## مجلد `receipts/`

**الغرض:** حفظ التذاكر المُصدَّرة كملفات نصية.

**اسم الملف:** `Ticket_[bookingId].txt`

**المحتوى:** نص منسق (مش pipe-separated) — التذكرة للطباعة للعميل.

**مثال:** `receipts/Ticket_1001.txt`
```
========================================
         CINEMA TICKET
========================================
Booking ID: 1001
Customer: Ahmed Mohamed
Movie: Action Movie
Showtime: 8:00 PM
Seats: 2
Total Price: 200 EGP
========================================
```

**الدوال المرتبطة:**
- **التصدير:** `exportTicketToFile` (Task 26)

**ملاحظة:** المجلد ده **مستثنى** من Git (في `.gitignore`).

---

## ⚠️ ملاحظات عامة

1. **الفواصل:** كل الحقول مفصولة بـ `|` (pipe) — **مفيش مسافات** حول الفاصل.
2. **النهايات:** كل سطر ينتهي بـ `\n` (Unix newline).
3. **الترميز:** الملفات بترميز **UTF-8** (مهم للتعليقات العربية).
4. **الفولدرات:** البرنامج بيفترض إن `data/` و `receipts/` موجودين. لو مش موجودين، لازم ينشئوهم تلقائياً.
5. **التحقق:** دوال `load*` لازم تتحقق من وجود الملفات قبل القراءة، وتطبع رسالة واضحة لو مش موجودة.

---

## 📊 ملخص التنسيقات

| الملف | نوع السطر | الفاصل | دوال مرتبطة |
| :--- | :--- | :---: | :--- |
| `halls.txt` | 1 سطر / صالة | `\|` | 38, 39 |
| `movies.txt` | 3+ أسطر / فيلم | `\|` + سطر منفصل | 40, 41 |
| `bookings.txt` | 3+ أسطر / حجز | `\|` + مسافات | 42, 43 |
| `receipts/\*.txt` | نص منسق | — | 26 |