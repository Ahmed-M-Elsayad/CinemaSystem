#pragma once

#include "CinemaData.h"

int countFreeSeats(const Movie& movie);
void selectSeats(Movie& movie, Booking& booking, int count);
void applyPricing(Booking& booking);
