// Rectangle Class definition
// Member functions defined in Rectangle.cpp
#pragma once
#include "Vertex.h"

class Rectangle {

public:
	Rectangle(const Vertex& bottomleft, const Vertex& topright);
	Rectangle(const Vertex vertices[2]);
	Rectangle(double x0, double y0, double x1, double y1);
	Rectangle(const Vertex& start, double width, double height);
	Vertex GetBottomLeft() const;
	Vertex GetTopRight() const;
	double GetWidth() const;
	double GetHeight() const;


private:
	Vertex b_left,
		   t_right;
};