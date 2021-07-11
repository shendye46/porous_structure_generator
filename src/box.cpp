#include "box.h"

box::box(float minX, float maxX, float minY, float maxY, float minZ, float maxZ)
    : p_min_x(minX), p_max_x(maxX), p_min_y(maxY), p_max_y(maxY), p_min_z(minZ),
      p_max_z(maxZ) {}

box::box(float dimX, float dimY, float dimZ)
    : p_min_x(-dimX / 2), p_max_x(dimX / 2), p_min_y(-dimY / 2),
      p_max_y(dimY / 2), p_min_z(-dimZ / 2), p_max_z(dimZ / 2) {}

box::~box() {}

void box::fillBox(float radius) {
  int count_x = (p_max_x - p_min_x) / (2 * radius);
  int count_y = (p_max_y - p_min_y) / (2 * radius);
  int count_z = (p_max_z - p_min_z) / (2 * radius);

  float temp_x = p_min_x + radius;
  float temp_y = p_min_y + radius;
  float temp_z = p_min_z + radius;
  int id = 0;
  while (temp_z < p_max_z) {
    while (temp_y < p_max_y) {
      while (temp_x < p_max_x) {

        Point3D p = {temp_x, temp_y, temp_z, radius};
        id++;
        atom a(id, 1, p);
        p_atoms.push_back(a);
        temp_x = temp_x + 2 * radius;
      }
      temp_x = p_min_x + radius;
      temp_y = temp_y + 2 * radius;
    }
    temp_y = p_min_y + radius;
    temp_z = temp_z + 2 * radius;
  }
}