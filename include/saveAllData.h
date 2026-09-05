#pragma once
#ifndef SAVEALLDATA_H
#define SAVEALLDATA_H

#include <vector>
#include "CinemaData.h"

using namespace std;

void saveAllData(const vector<Hall>& halls, const vector<Movie>& movies, const vector<Booking>& bookings);

#endif