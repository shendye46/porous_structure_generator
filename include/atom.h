#pragma once
#include "sphere.h"

class atom : public sphere
{

public:
    atom(Point3D point, double radius);
    ~atom();
    double surfaceArea();
};