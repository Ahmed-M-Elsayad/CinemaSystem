#include "calculateTotalPrice.h"
#include "CinemaData.h"

double calculateTotalPrice(double pricePerSeat, int numTickets, double& discountAmount) {
    double originalPrice = pricePerSeat * numTickets;
    if (numTickets > DISCOUNT_THRESHOLD) {
        discountAmount = originalPrice * DISCOUNT_RATE;
    }
    else {
        discountAmount = 0.0;
    }
    return originalPrice - discountAmount;
}
