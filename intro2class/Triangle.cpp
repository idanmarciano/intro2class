#include "Triangle.h"
#include "Vertex.h"
#include "Utilities.h"
#include <cmath>

//----------------------------------------------------------------------------

Triangle::Triangle(const Vertex vertices[3])
{
	if (CheckTriangle(vertices)) {
		n1 = vertices[0];
		n2 = vertices[1];
		n3 = vertices[2];
	}
	else
		Triangle();
}

//----------------------------------------------------------------------------

Vertex Triangle::getVertex(int index) const
{
	if (index == 0)
		return n1;
	else if (index == 1)
		return n2;
	return n3;
}

//----------------------------------------------------------------------------

double Triangle::getLength()
{
	return distance(n1, n2);
}

//----------------------------------------------------------------------------

bool CheckTriangle(const Vertex vertices[3]) 
{
	return (vertices[0].isValid() && vertices[1].isValid() &&
		vertices[2].isValid() && Equilateral_t(vertices) &&
		check_parll(vertices[0].m_y, vertices[1].m_y, vertices[2].m_y));
}

//----------------------------------------------------------------------------

//bool Triangle::check_parll_x(const Vertex vertices[3]) const
//{
//	if (vertices[0].m_y == vertices[1].m_y ||
//		vertices[0].m_y == vertices[2].m_y ||
//		vertices[1].m_y == vertices[2].m_y)
//		return true;
//	return false;
//}

//----------------------------------------------------------------------------

bool Equilateral_t(const Vertex vertices[3]) 
{
	if (distance(vertices[0], vertices[1]) == 
		distance(vertices[0], vertices[2]) &&
		distance(vertices[1], vertices[2]) ==
		distance(vertices[0], vertices[1]) &&
		distance(vertices[0], vertices[2]) ==
		distance(vertices[1], vertices[2]))
		return true;
	return false;
}
