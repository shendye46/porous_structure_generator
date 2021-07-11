#include "atom.h"

atom::atom() {}

atom::atom(float x, float y, float z, float radius) {
  p_point3D.x = x;
  p_point3D.y = y;
  p_point3D.z = z;
  p_point3D.radius = radius;
}

atom::atom(int id, int mol_id, float x, float y, float z, float radius)
    : p_id(id), p_mol_id(mol_id) {
  p_point3D.x = x;
  p_point3D.y = y;
  p_point3D.z = z;
  p_point3D.radius = radius;
}

atom::atom(int id, int mol_id, Point3D& point):p_id(id),p_mol_id(mol_id),p_point3D(point) {}

atom::~atom() { }

bool atom::belongsToSphere(const Point3D& sphere) 
{
  auto diff = Point3D::eucledian_dist(sphere,this->p_point3D);
  return diff<(sphere.radius+this->p_point3D.radius);  
}


// bool atom::belongsToBox(const atom& atom, const box& box) {
//   return (box.p_max_x - atom.p_point3D.x) > atom.p_point3D.radius &&
//          (atom.p_point3D.x - box.p_min_x) > atom.p_point3D.radius &&
//          (box.p_max_y - atom.p_point3D.y) > atom.p_point3D.radius &&
//          (atom.p_point3D.y - box.p_min_y) > atom.p_point3D.radius &&
//          (box.p_max_z - atom.p_point3D.z) > atom.p_point3D.radius &&
//          (atom.p_point3D.z - box.p_min_z) > atom.p_point3D.radius;
// }
