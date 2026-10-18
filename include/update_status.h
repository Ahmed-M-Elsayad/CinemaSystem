#pragma once
#ifndef UPDATE_STATUS_H                // حماية من التضمين المتكرر
#define UPDATE_STATUS_H

#include "CinemaData.h"               // استيراد الهياكل


void updateMovieStatus(std::vector<Movie>& movies, int movieId, const std::string& newStatus); // إعلان

#endif // UPDATE_STATUS_H
