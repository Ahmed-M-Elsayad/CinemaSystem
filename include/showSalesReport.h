#pragma once
#ifndef SHOWSALESREPORT_H
#define SHOWSALESREPORT_H

#include <vector>
#include "CinemaData.h"

using namespace std;

// تعريف دالة عرض إجمالي الأرباح وأعلى فيلم مبيعاً
void showSalesReport(const vector<Movie>& movies, const vector<Booking>& bookings);

#endif