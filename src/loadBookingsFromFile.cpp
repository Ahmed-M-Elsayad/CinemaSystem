#include "loadBookingsFromFile.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

void loadBookingsFromFile(vector<Booking>& bookings) {

    bookings.clear();

    // فتح الملف للقراءة (نفس الاسم بدون امتداد)
    ifstream bookingsFile("data/bookings.txt");

    if (bookingsFile.is_open()) {
        string line;
        while (getline(bookingsFile, line)) {
            if (line.empty()) continue; // تخطي الأسطر الفارغة

            stringstream ss(line);
            string segment;
            Booking b;

            // قراءة بيانات الحجز 
            getline(ss, segment, '|'); b.bookingId = stoi(segment);
            getline(ss, segment, '|'); b.movieId = stoi(segment);
            getline(ss, segment, '|'); b.movieName = segment;
            getline(ss, segment, '|'); b.seatCount = stoi(segment);
            getline(ss, segment, '|'); b.pricePerSeat = stod(segment);
            getline(ss, segment, '|'); b.originalPrice = stod(segment);
            getline(ss, segment, '|'); b.discountAmount = stod(segment);
            getline(ss, segment, '|'); b.totalPrice = stod(segment);
            getline(ss, segment, '|'); b.isActive = stoi(segment); // 0 أو 1
            getline(ss, segment, '|'); b.isPaid = stoi(segment);   // 0 أو 1

            // قراءة بيانات العميل
            string custLine;
            getline(bookingsFile, custLine);
            stringstream css(custLine);
            getline(css, segment, '|'); b.customer.customerId = stoi(segment);
            getline(css, segment, '|'); b.customer.fullName = segment;
            getline(css, segment, '|'); b.customer.phone = segment;

            // قراءة المقاعد المحجوزة
            b.seats.clear();
            for (int i = 0; i < b.seatCount; ++i) {
                int row, col;
                bookingsFile >> row >> col;
                b.seats.push_back({ row, col });
            }
            bookingsFile.ignore();

            // قراءة تاريخ الحجز
            string dateLine;
            getline(bookingsFile, dateLine);
            stringstream dss(dateLine);
            dss >> b.bookingDate.day >> b.bookingDate.month >> b.bookingDate.year;

            // إضافة الحجز للقائمة
            bookings.push_back(b);
        }
        bookingsFile.close();
        cout << "The bookings were successfully loaded from the bookings file.\n";
    }
    else {
        cout << "Error: Cannot open bookings file for reading!\n";
    }
}