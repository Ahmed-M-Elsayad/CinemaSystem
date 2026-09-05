#pragma once
#ifndef SAVEBOOKINGSTOFILE_H
#define SAVEBOOKINGSTOFILE_H

#include <vector>
#include "CinemaData.h"

using namespace std;

void saveBookingsToFile(const vector<Booking>& bookings);

#endif