#ifndef ADD_NEW_HALL_H              // حماية من التضمين المتكرر
#define ADD_NEW_HALL_H

#include "CinemaData.h"             // استيراد هياكل Hall و vector

/*
  دالة: إضافة صالة جديدة
  التوقيع: void (vector<Hall>& halls)
  الهدف: قراءة بيانات الصالة من المستخدم وإضافتها إلى المتجه
*/
void addNewHall(vector<Hall>& halls);

#endif // ADD_NEW_HALL_H
