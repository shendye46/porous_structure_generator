#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <ctime>
#include "atom.h"

struct box
{
  float p_min_x, p_max_x;
  float p_min_y, p_max_y;
  float p_min_z, p_max_z;

  std::vector<atom> p_atoms;

  box() = delete;
  box(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
  box(float dimX, float dimY, float dimZ);
  ~box();

  void fillBox(float radius);
  void stampholes(const char* radii,...);
};
