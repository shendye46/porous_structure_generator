#include "atom.h"
#include "box.h"
#include <iostream>

int main(int argc, char **argv) {
  box b = {15, 15, 15};
  b.fillBox(0.5);
  auto spheres = b.makePores(4, 2.0, 2.0, 2.0, 1.0);
  b.pores = spheres;
  // std::cout<<spheres.size();
  // std::cout<<b.p_atoms.size()<<"\n";
  b.deleteAtoms();
  for (auto &s : b.p_atoms) {
    std::cout << s;
  }

  return 0;
}