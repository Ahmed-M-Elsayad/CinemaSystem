#pragma once
#ifndef FIND_MOVIE_H                   // حماية من التضمين المتكرر
#define FIND_MOVIE_H

#include "cinema_data.h"               // استيراد الهياكل


const Movie* findMovieById(const  std::vector<Movie>& movies, int movieId); // نسخة للقراءة
Movie* findMovieById(std::vector<Movie>& movies, int movieId);             // نسخة للتعديل

#endif // FIND_MOVIE_H
