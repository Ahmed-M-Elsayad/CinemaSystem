#include "showSalesReport.h"
#include <iostream>

using namespace std;

void showSalesReport(const vector<Movie>& movies, const vector<Booking>& bookings) {
    if (bookings.empty()) {
        cout << "\nThere are currently no reservations to view the sales report.\n";
        return;
    }

    double totalRevenue = 0.0;
    int topMovieId = -1;
    double maxSales = 0.0;
    string topMovieName = "";

    //  حساب إجمالي الأرباح 
    for (const auto& b : bookings) {
        if (b.isActive) {
            totalRevenue += b.totalPrice;
        }
    }

    //  إيجاد أعلى فيلم مبيعاً (لوب على الأفلام، وجواه لوب على الحجوزات)
    for (const auto& m : movies) {
        double currentMovieSales = 0.0;

        // نجمع مبيعات هذا الفيلم المحدد فقط من كل الحجوزات
        for (const auto& b : bookings) {
            if (b.movieId == m.movieId && b.isActive) {
                currentMovieSales += b.totalPrice;
            }
        }

        // لو مبيعات الفيلم ده أعلى من اللي قبله، نحدث أعلى فيلم
        if (currentMovieSales > maxSales) {
            maxSales = currentMovieSales;
            topMovieId = m.movieId;
            topMovieName = m.name;
        }
    }

    // عرض التقرير
    cout << "\n================ Sales Report ================\n";
    cout << "Total Revenue (from active reservations): " << totalRevenue << " EGP\n";

    if (topMovieId != -1) {
        cout << "Top Selling Movie: " << topMovieName << " (ID: " << topMovieId << ")\n";
        cout << "Total Sales: " << maxSales << " EGP\n";
    }
    else {
        cout << "No sales data available to determine the top selling movie.\n";
    }

    //   تفاصيل مبيعات كل فيلم
    cout << "\n--- Film Sales Details ---\n";
    for (const auto& m : movies) {
        double currentMovieSales = 0.0;
        for (const auto& b : bookings) {
            if (b.movieId == m.movieId && b.isActive) {
                currentMovieSales += b.totalPrice;
            }
        }
        if (currentMovieSales > 0) {
            cout << "Movie: " << m.name << " | Total Sales: " << currentMovieSales << " EGP\n";
        }
    }
}