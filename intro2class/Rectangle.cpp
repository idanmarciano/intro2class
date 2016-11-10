#include "Rectangle.h"
#include "Vertex.h"

Rectangle::Rectangle(const Vertex& bottomleft, const Vertex& topright) {

	if (bottomleft.isValid() && topright.isValid() &&
	   topright.isHigherFrom(bottomleft) && topright.isRighterFrom(bottomleft))
	{
			b_left = bottomleft;
			t_right = topright;
	}
	else {
		b_left.m_x = b_left.m_y = 0;
		t_right.m_x = t_right.m_y = 10;
	}
}

//----------------------------------------------------------------------------

Rectangle::Rectangle(const Vertex vertices[2]) {
	
	Rectangle(vertices[0], vertices[1]);
}

//----------------------------------------------------------------------------

Rectangle::Rectangle(double x0, double y0, double x1, double y1) {
	Vertex n1 = { x0, y0 };
	Vertex n2 = { x1, y1 };

	Rectangle(n1, n2);
}
//----------------------------------------------------------------------------
Rectangle::Rectangle(const Vertex& start, double width, double height) {
	Vertex node = { start.m_x + width,start.m_y + height };
	
	Rectangle(start, node);
}

Vertex Rectangle::GetBottomLeft() const
{	 
	return b_left;
}

Vertex Rectangle::GetTopRight() const
{
	return t_right;
}

double Rectangle::GetWidth() const
{
	return (t_right.m_x - b_left.m_x);
}

double Rectangle::GetHeight() const
{
	return (t_right.m_y - b_left.m_y);
}

