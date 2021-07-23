#include <iostream>
#include "sphere.h"
#include "atom.h"

int main(int argc, char** argv)
{
	std::cout<<"test creating structure"<<std::endl;
	Point3D p1 = {0,0,0};
	Point3D p2 = {6,6,6};
	atom a1 (p1,2.0);
	atom a2 (p2,2.0);

	std::cout<<a1.isOverlapping(a2)<<std::endl;
	std::cout<<a1.surfaceArea()<<std::endl;
	std::cout<<a2.surfaceArea()<<std::endl;
	return 0;

}
