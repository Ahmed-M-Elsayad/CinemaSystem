#pragma once
#ifndef UPDATE_PRICE_H                 // حماية من التضمين المتكرر
#define UPDATE_PRICE_H

#include "cinema_data.h"               // استيراد الهياكل


void updateMoviePrice(std::vector<Movie>& movies, int movieId, double newPrice); // إعلان الدالة

#endif // UPDATE_PRICE_H
