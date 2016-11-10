#include "Parallelogram.h"
#include "Vertex.h"
#include "utilities.h"

//----------------------------------------------------------------------------

Parallelogram::Parallelogram(const Vertex & bottomLeft, 
			const Vertex & topRight, const Vertex & topLeft)
{
	para2_x = check_parll(bottomLeft.m_y, topRight.m_y, topLeft.m_y);
	para2_y = check_parll(bottomLeft.m_x, topRight.m_x, topLeft.m_x);

	if ((bottomLeft.isValid() && topRight.isValid() && topLeft.isValid())&&
		(para2_x || para2_y)) {
		b_left = bottomLeft;
		t_right = topRight;
		t_left = topLeft;

		if (para2_x) 
			b_right = { b_left.m_x + getWidth(),bottomLeft.m_y };

		else
			b_right = { topRight.m_x,topRight.m_y - getWidth() };
	}
	else
		Parallelogram();
}

//----------------------------------------------------------------------------

double Parallelogram::getHeight() const
{
	if (para2_x)
		return (t_left.m_y - b_left.m_y);
	return (t_right.m_x - t_left.m_x);
}

//----------------------------------------------------------------------------

double Parallelogram::getWidth() const
{
	if (para2_x)
		return distance(t_left, t_right);
	return distance(t_left,b_left);
}

//----------------------------------------------------------------------------

Vertex Parallelogram::getBottomLeft() const
{
	return b_left;
}

//----------------------------------------------------------------------------

Vertex Parallelogram::getTopRight() const
{
	return t_right;
}

//----------------------------------------------------------------------------

Vertex Parallelogram::getTopLeft() const
{
	return t_left;
}