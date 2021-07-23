#pragma once
#include "Point3D.h"
#include <iostream>

class sphere {
protected:
  Point3D point;
  double radius;

public:
  sphere(Point3D point, double radius);
  ~sphere();
  bool isOverlapping(const sphere &other);
  friend std::ostream &operator<<(std::ostream &os, const sphere &sphere) {
    os << sphere.point.x << ", " << sphere.point.y << ", " << sphere.point.z
       << std::endl;
    return os;
  }
};




