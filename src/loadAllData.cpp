#include "loadAllData.h"
#include <fstream> // لقراءة الملفات
#include <sstream> // لتقسيم النصوص
#include <iostream>
#include <string>

using namespace std;

void loadAllData(vector<Hall>& halls, vector<Movie>& movies, vector<Booking>& bookings) {

    // مسح أي بيانات قديمة موجودة في الذاكرة حتى لا نكرر البيانات عند التحميل
    halls.clear();
    movies.clear();
    bookings.clear();

    // 1. تحميل الصالات
    ifstream hallsFile("halls");
    if (hallsFile.is_open()) {
        string line;
        while (getline(hallsFile, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string segment;

            Hall h;
            getline(ss, segment, '|'); h.hallId = stoi(segment);
            getline(ss, segment, '|'); h.name = segment;
            getline(ss, segment, '|'); h.rows = stoi(segment);
            getline(ss, segment, '|'); h.cols = stoi(segment);
            getline(ss, segment, '|'); h.isVip = stoi(segment); // يقرأ 0 أو 1

            halls.push_back(h);
        }
        hallsFile.close();
        cout << "Number of halls: " << halls.size() << endl;
    }
    else {
        cout << "No halls file found!\n";
    }

    // 2. تحميل الأفلام (مع مصفوفة المقاعد)
    ifstream moviesFile("movies");
	if (moviesFile.is_open()) { // فتح ملف الأفلام
        string line;
		while (getline(moviesFile, line)) { // قراءة كل سطر من ملف الأفلام
            if (line.empty()) continue;
			stringstream ss(line); // تقسيم السطر إلى أجزاء باستخدام '|' كفاصل
            string segment;

            Movie m;
			getline(ss, segment, '|'); m.movieId = stoi(segment); // تحويل النص إلى عدد صحيح
            getline(ss, segment, '|'); m.name = segment;
            getline(ss, segment, '|'); m.genre = segment;
            getline(ss, segment, '|'); m.showtime = segment;
            getline(ss, segment, '|'); m.price = stod(segment);
            getline(ss, segment, '|'); m.hallId = stoi(segment);
            getline(ss, segment, '|'); m.status = segment;

            // قراءة أبعاد المقاعد (سطر الأبعاد)
            string dimLine;
            getline(moviesFile, dimLine);
            stringstream dimss(dimLine);
            string dimSegment;
            int rows, cols;
			getline(dimss, dimSegment, '|'); rows = stoi(dimSegment); // قراءة عدد الصفوف
            getline(dimss, dimSegment, '|'); cols = stoi(dimSegment);

            // قراءة صفوف المقاعد 'O' و 'X'
            m.seats.clear();
            for (int i = 0; i < rows; ++i) {
                string rowStr;
                getline(moviesFile, rowStr);
                vector<char> rowVec(rowStr.begin(), rowStr.end());
				m.seats.push_back(rowVec); // تحويل السطر إلى مصفوفة من الأحرف
            }

            movies.push_back(m);
        }
        moviesFile.close();
        cout << "The movies were downloaded successfully.\n";
    }
    else {
        cout << "No movies file found!\n";
    }

    // 3. تحميل الحجوزات (مع العميل والمقاعد والتاريخ)
    ifstream bookingsFile("bookings");
    if (bookingsFile.is_open()) {
        string line;
        while (getline(bookingsFile, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string segment;

            Booking b;
            getline(ss, segment, '|'); b.bookingId = stoi(segment); // قراءة معرف الحجز
            getline(ss, segment, '|'); b.movieId = stoi(segment);
            getline(ss, segment, '|'); b.movieName = segment;
            getline(ss, segment, '|'); b.seatCount = stoi(segment);
            getline(ss, segment, '|'); b.pricePerSeat = stod(segment);
            getline(ss, segment, '|'); b.originalPrice = stod(segment);
            getline(ss, segment, '|'); b.discountAmount = stod(segment);
            getline(ss, segment, '|'); b.totalPrice = stod(segment);
            getline(ss, segment, '|'); b.isActive = stoi(segment);
            getline(ss, segment, '|'); b.isPaid = stoi(segment);

            // قراءة بيانات العميل
            string custLine;
            getline(bookingsFile, custLine);
            stringstream css(custLine);
            getline(css, segment, '|'); b.customer.customerId = stoi(segment);
            getline(css, segment, '|'); b.customer.fullName = segment;
            getline(css, segment, '|'); b.customer.phone = segment;

            // قراءة المقاعد المحجوزة (row col)
            b.seats.clear();
            for (int i = 0; i < b.seatCount; ++i) {
                int row, col;
                bookingsFile >> row >> col;
                b.seats.push_back({ row, col });
            }
            // تجاهل الـ newline المتبقي بعد آخر مقعد
            bookingsFile.ignore();

            // قراءة تاريخ الحجز
            string dateLine;
            getline(bookingsFile, dateLine);
            stringstream dss(dateLine);
            dss >> b.bookingDate.day >> b.bookingDate.month >> b.bookingDate.year;

            bookings.push_back(b);
        }
        bookingsFile.close();
		cout << "Number of bookings: " << bookings.size() << endl;// عرض عدد الحجوزات التي تم تحميلها
    }
    else {
        cout << "No bookings file found!\n";
    }
}