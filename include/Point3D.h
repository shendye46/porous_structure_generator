#pragma once
#include <cmath>

struct Point3D {
  double x, y, z;
  friend double operator-(const Point3D &self, const Point3D &other) {
    return sqrt(pow((self.x - other.x), 2) + pow((self.y - other.y), 2) +
                pow((self.z - other.z), 2));
  }
};
