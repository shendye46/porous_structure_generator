#pragma once

#include <iostream>
#include <math.h>
// #include "box.h"

struct Point3D {
  float x, y, z, radius;

  static float eucledian_dist(const Point3D& point1, const Point3D& point2)
  {
    return std::pow((std::pow((point1.x - point2.x),2)+std::pow((point1.y - point2.y),2), std::pow((point1.x - point2.x),2)),0.5);
  }
};

class atom {
private:
  int p_id, p_mol_id;
  Point3D p_point3D;

public:
  atom();
  atom(float x, float y, float z, float radius);
  atom(int id, int mol_id, float x, float y, float z, float radius);
  atom(int id, int mol_id, Point3D &point);
  ~atom();
  // bool belongsToBox(const atom& atom, const box& box);
  bool belongsToSphere(const Point3D& sphere);
  friend std::ostream &operator<<(std::ostream &os, const atom &atom) {
    os << atom.p_point3D.x << " " << atom.p_point3D.y << " " << atom.p_point3D.z
       << "\n";
    return os;
  };
};
