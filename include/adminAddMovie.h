#ifndef ADMINADDMOVIE_H
#define ADMINADDMOVIE_H

#include <vector>
#include "CinemaData.h"

using namespace std;

// تعريف دالة إضافة فيلم (بصلاحية المدير)
void adminAddMovie(vector<Movie>& movies, const vector<Hall>& halls);

#endif