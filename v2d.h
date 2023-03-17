#ifndef _v2d_h_
#define _v2d_h_

#include <FixedPoints.h>
#include <FixedPointsCommon.h>


class v2d
{
public:
  UQ8x8     x,
            y;


  v2d() : x(0), y(0) {}
  v2d(UQ8x8 x_val, UQ8x8 y_val) : x(x_val), y(y_val) {}

  void set(UQ8x8 x_val, UQ8x8 y_val) {
    x = x_val;
    y = y_val;
  }

  // operator overload to add a float to both x and y coordinates
  v2d operator+(float value) const {
    return v2d(x + value, y + value);
  }

  // operator overload to add two v2d points
  v2d operator+(const v2d& other) const {
    return v2d(x + other.x, y + other.y);
  }

  // operator overload to subtract a float from both x and y coordinates
  v2d operator-(float value) const {
    return v2d(x - value, y - value);
  }

  // operator overload to subtract one v2d point from another
  v2d operator-(const v2d& other) const {
    return v2d(x - other.x, y - other.y);
  }

  // operator overload to assign one v2d point to another
  v2d& operator=(const v2d& other) {
    x = other.x;
    y = other.y;
    return *this;
  }

  // method to print the x and y coordinates to Serial
  void print(const char* name) {
    Serial.print(name);
    Serial.print("(");
    Serial.print(static_cast<float>(x), 2);
    Serial.print(", ");
    Serial.print(static_cast<float>(y), 2);
    Serial.println(")");
  }
};


#endif 