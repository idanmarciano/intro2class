#include "Vertex.h"
#include "macros.h"

bool Vertex::isHigherFrom(const Vertex& rhs) const
{
    return m_y >= rhs.m_y;
}

bool Vertex::isRighterFrom(const Vertex& tr) const
{
    return m_x >= tr.m_x;
}

bool Vertex::isValid() const
{
    return m_x >= 0 && m_x <= MAX_X 
        && m_y >= 0 && m_y <= MAX_Y;
}

bool check_parll(double x, double y, double z){
	return (x == y || y == z || x == z);
}
