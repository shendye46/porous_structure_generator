#include "sphere.h"


sphere::sphere(Point3D point, double radius):point(point),radius(radius) 
{
    
}

sphere::~sphere() 
{
    
}

bool sphere::isOverlapping(const sphere &other) 
{
    return (this->point - other.point) <= (this->radius + other.radius);
}





