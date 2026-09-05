#pragma once
#ifndef ADMINDELETEMOVIE_H
#define ADMINDELETEMOVIE_H

#include <vector>
#include "CinemaData.h"

using namespace std;

// تعريف دالة حذف فيلم (مع التحقق من الحجوزات)
void adminDeleteMovie(vector<Movie>& movies, const vector<Booking>& bookings);

#endif