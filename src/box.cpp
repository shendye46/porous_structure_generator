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

std::vector<Point3D> box::makePores(int radii, ...) {
  // first randomly spread the spheres making sure no two spheres touch each
  // other check for belongs to sphere for each sphere
  std::vector<Point3D> spheres;
  std::vector<double> radii_input;
  va_list args;
  va_start(args, radii);
  Point3D p;
  for (size_t i = 0; i < radii; i++) {
    double d = va_arg(args, double);
    radii_input.push_back(d);
  }

  va_end(args);
  srand48(static_cast<unsigned>(time(0)));

  for (size_t i = 0; i < radii_input.size(); i++) {
    bool overlapping = true;
    if (spheres.empty()) {
      p = {box::getRandomFloat(p_min_x, p_max_x),
           box::getRandomFloat(p_min_y, p_max_y),
           box::getRandomFloat(p_min_z, p_max_z),
           static_cast<float>(radii_input.at(i))};
      overlapping = false;
    }

    while (overlapping) {
      p = {box::getRandomFloat(p_min_x, p_max_x),
           box::getRandomFloat(p_min_y, p_max_y),
           box::getRandomFloat(p_min_z, p_max_z),
           static_cast<float>(radii_input.at(i))};
      for (size_t i = 0; i < spheres.size(); i++) {
        if (Point3D::eucledian_dist(p, spheres.at(i)) >
            (p.radius, spheres.at(i).radius)) {
          overlapping = false;
          break;
        }
      }
    }
    spheres.push_back(p);
  }
  return spheres;
}

void box::deleteAtoms() {
  std::vector<size_t> indices_to_be_erased;
  for (size_t i = 0; i < p_atoms.size(); i++) {
    for (size_t j = 0; j < pores.size(); j++) {
      if (p_atoms.at(i).belongsToSphere(pores.at(j))) {
        p_atoms.erase(p_atoms.begin() + i); // this is dangerous
      }
    }
  }
}
