#include "atom.h"



atom::atom(Point3D point, double radius) : sphere(point,radius)
{
    
}

atom::~atom() 
{
    
}
double atom::surfaceArea() 
{
    return 4*M_PI*pow(this->radius,2);    
}


