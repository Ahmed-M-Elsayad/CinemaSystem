#pragma once
#ifndef DELETE_MOVIE_H                 // حماية من التضمين المتكرر
#define DELETE_MOVIE_H

#include "cinema_data.h"               // استيراد الهياكل
                 

bool deleteMovie(std::vector<Movie>& movies, int movieId,  const std::vector<Booking>& bookings); // إعلان

#endif // DELETE_MOVIE_H
