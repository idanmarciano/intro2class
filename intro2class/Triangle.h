// Triangle Class definition
// Member functions defined in Triangle.cpp
#pragma once
#include "Vertex.h"
#include <cmath>

class Triangle
{
public:
	Triangle(const Vertex vertices[3]);
	Triangle() = default;

	Vertex getVertex(int index)const;
	double getLength();
	//bool CheckTriangle(const Vertex vertices[3]) const;

private:
	Vertex n1{ 0,0 },
		   n2{ 10,0 },
		   n3{ 5,sqrt(75) };
	//bool Equilateral_t(const Vertex vertices[3]) const;
};
bool CheckTriangle(const Vertex vertices[3]);
bool Equilateral_t(const Vertex vertices[3]);