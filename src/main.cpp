#include <iostream>
#include "box.h"
#include "atom.h"

int main(int argc, char **argv) { 
    box b = {5,5,5};
    b.fillBox(0.5);
    for (auto const& atom : b.p_atoms)
    {
        std::cout<<atom;
    }
    
    return 0; }