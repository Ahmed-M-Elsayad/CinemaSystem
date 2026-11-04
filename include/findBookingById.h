#pragma once

#include "CinemaData.h" 
#include <vector>

Booking* findBookingById(
    std::vector<Booking>& bookingList,
    int bookingId
);
