#include "seedData.h"

void seedData(vector<Hall>& halls, vector<Movie>& movies) {
    // مسح أي بيانات موجودة حتى لا نكررها إذا تم استدعاء الدالة أكثر من مرة
    halls.clear();
    movies.clear();

    // 1. إنشاء صالتين تجريبيتين
    Hall hall1 = { 1, "Main Hall", ROWS_DEFAULT, COLS_DEFAULT, false };
    Hall hall2 = { 2, "VIP Hall", 4, 5, true };
    halls.push_back(hall1);
    halls.push_back(hall2);

    // 2. إنشاء فيلمين تجريبيين
    // ملاحظة: نستخدم assign لإنشاء مصفوفة المقاعد 2D مليانة O (فاضي)
    Movie movie1;
    movie1.movieId = 1;
    movie1.name = "Action movie";
    movie1.genre = "action";
    movie1.showtime = "7:00 PM";
    movie1.price = 100.0;
    movie1.hallId = 1;
    movie1.status = "Now Showing";
    movie1.seats.assign(ROWS_DEFAULT, vector<char>(COLS_DEFAULT, 'O'));
    movie1.seats[0][0] = 'X';
    movie1.seats[2][3] = 'X';

    Movie movie2;
    movie2.movieId = 2;
    movie2.name = "Romance film";
    movie2.genre = "romantic";
    movie2.showtime = "9:30 PM";
    movie2.price = 80.0;
    movie2.hallId = 2;
    movie2.status = "Coming Soon";
    movie2.seats.assign(4, vector<char>(5, 'O')); 

    movies.push_back(movie1);
    movies.push_back(movie2);
}