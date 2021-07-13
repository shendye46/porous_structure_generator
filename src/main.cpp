#include "atom.h"
#include "box.h"
#include <iostream>

int main(int argc, char **argv) {

  box *B;
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <box dimension> "
              << "<radius (A)[default r=1]>"
              << " <number of pores> "
              << " <p1 p2 p3 p4 p5...> " << std::endl;
    return 1;
  } else if (argc == 2) {
    float box_dim = std::stof(argv[1]);
    box b = {box_dim, box_dim, box_dim};
    B = &b;
    b.fillBox(1);

  } else if (argc == 3) {
    float box_dim = std::stof(argv[1]);
    float atom_radius = std::stof(argv[2]);
    box b = {box_dim, box_dim, box_dim};
    B = &b;
    b.fillBox(atom_radius);
  } else if (argc == 4) {
    float box_dim = std::stof(argv[1]);
    float atom_radius = std::stof(argv[2]);
    box b = {box_dim, box_dim, box_dim};
    B = &b;
    b.fillBox(atom_radius);
    int number_of_pores = std::stoi(argv[3]);

    b.pores = b.makePores(number_of_pores, 1.0, 2.0, 3.0, 4.0);
    b.deleteAtoms();
  }

  for (auto &atom :B->p_atoms) {
    std::cout<<atom;
  }

  return 0;
}