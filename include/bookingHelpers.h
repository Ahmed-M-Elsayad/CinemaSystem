#ifndef BOOKING_HELPERS_H
#define BOOKING_HELPERS_H

#include "CinemaData.h"

// عدد المقاعد الفاضية ('O') في الفيلم
int countFreeSeats(const Movie& movie);

// المستخدم يختار 'count' مقعد، وبيتحجزوا في الفيلم وبيتضافوا للحجز
void selectSeats(Movie& movie, Booking& booking, int count);

// إعادة حساب عدد المقاعد والأسعار والخصم (مشتركة بين createBooking و modifyBooking)
void applyPricing(Booking& booking);

#endif
