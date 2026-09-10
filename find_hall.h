#pragma once
#ifndef FIND_HALL_H
#define FIND_HALL_H

#include "cinema_data.h"            // استيراد تعريف Hall و vector


// نسخة للقراءة: تعيد مؤشر ثابت إلى Hall أو nullptr إن لم توجد
const Hall* findHallById(const std::vector<Hall>& halls, int hallId);

// نسخة للتعديل: تعيد مؤشر قابل للتعديل إلى Hall أو nullptr إن لم توجد
Hall* findHallById(std::vector<Hall>& halls, int hallId);

#endif // FIND_HALL_H
