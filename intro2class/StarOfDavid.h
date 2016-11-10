// StarOfDavid Class definition
// Member functions defined in StarOfDavid.cpp
#pragma once
#include "Vertex.h"
#include "Triangle.h"

class StarOfDavid
{
public:
	StarOfDavid(Vertex firstTriangular[3], Vertex secondTriangular[3]);
	StarOfDavid(const Triangle& t1, const Triangle& t2);
	double getTotalHeight()const ;

private:
	Triangle t1,
			 t2;
};
