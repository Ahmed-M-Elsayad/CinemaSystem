#include "findBookingById.h"

using namespace std;
Booking* findBookingById(
    vector<Booking>& bookingList,
    int bookingId
)
{
    for (auto& booking : bookingList)
    {
        if (booking.bookingId == bookingId)
            return &booking;
    }
    return nullptr;
}
