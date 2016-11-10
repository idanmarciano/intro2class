// Parallelogram Class definition
// Member functions defined in Parallelogram.cpp
#pragma once
#include "Vertex.h"

class Parallelogram {
public:
	Parallelogram() = default;
	Parallelogram(const Vertex& bottomLeft,
		const Vertex& topRight, const Vertex& topLeft);
	double getHeight() const;
	double getWidth() const;
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	Vertex getTopLeft() const;

private:
	Vertex b_left{ 0, 0 },
		   b_right{ 3, 0 },
		   t_left{ 1, 1 },
		   t_right{ 4, 1 };
	bool para2_x = true;
	bool para2_y = false;
};