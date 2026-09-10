#pragma once
#ifndef ADD_NEW_MOVIE_H               // حماية من التضمين المتكرر
#define ADD_NEW_MOVIE_H               // تعريف الرمز لمنع التضمين اللاحق

#include "cinema_data.h"              // استيراد هياكل البيانات والثوابت
                 // لتفادي كتابة std:: في الملفات التي تضم هذا الهيدر

// إعلان الدالة: تضيف فيلم جديد وتربطه بصالة وتهيئ مقاعده
void addNewMovie(vector<Movie>& movies, const vector<Hall>& halls); // التواقيع المطلوبة

#endif // ADD_NEW_MOVIE_H
