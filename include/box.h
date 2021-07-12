#pragma once
#include "atom.h"
#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <ctime>
#include <initializer_list>
#include <iostream>
#include <vector>

struct box {
  float p_min_x, p_max_x;
  float p_min_y, p_max_y;
  float p_min_z, p_max_z;

  std::vector<atom> p_atoms;
  std::vector<Point3D> pores;

  box() = delete;
  box(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
  box(float dimX, float dimY, float dimZ);
  ~box();

  void fillBox(float radius);
  std::vector<Point3D> makePores(int radii, ...);
  static float getRandomFloat(float LOW, float HIGH) {
    // srand48(static_cast<unsigned>(time(0)));
    return LOW + static_cast<float>(rand()) /
                     (static_cast<float>(RAND_MAX / (HIGH - LOW)));
  }
  void deleteAtoms();
};
