#include "Board.h"
#include "Vertex.h"
#include "Utilities.h"

#include <iostream>
#include <algorithm>
#include <cmath>

// Visual Studio doesn't like the use of std::fill_n. This will make it quiet.
#ifdef _MSC_VER
	#pragma warning(disable:4996)
#endif

Board::Board()
{
	clear();
}

void Board::clear()
{
	std::fill_n(&paintBoard[0][0],
			sizeof (paintBoard) / sizeof (paintBoard[0][0]), false);
}

void Board::print()
{
	for (int j = 0; j <= MAX_Y; j++)
	{
		for (int i = 0; i <= MAX_X; i++)
		{
			if (paintBoard[i][j])
				std::cout << '*';
			else
				std::cout << '#';
		}
		std::cout << std::endl;
	}
}

void Board::addLine(Vertex v1, Vertex v2)
{
	if (v2 < v1)
		std::swap(v1, v2);

	if (sameX(v1, v2))	// parallel to the y axis
	{
		int x = (int) v2.m_x;
		for (int i = (int) v1.m_y; i <= v2.m_y; ++i)
			paintBoard[x][i] = true;
	}
	else if (sameY(v1, v2)) // parallel to the x axis
	{
		int y = (int) v2.m_y;
		for (int i = (int) v1.m_x; i <= v2.m_x; ++i)
			paintBoard[i][y] = true;
	}
	else						// use DDA algorithm to draw
	{
		double slope = (v2.m_y - v1.m_y) / (v2.m_x - v1.m_x);
		int estimateIndex;

		if (abs(slope) < 1)
		{
			if (slope > 0)
				std::swap(v1, v2);

			for (int i = (int) std::min(v1.m_x,v2.m_x); i <= std::max(v1.m_x,v2.m_x); ++i)
			{
				estimateIndex = (int) std::floor(
						v1.m_y + (i - v1.m_x) * slope + 0.5);
				paintBoard[i][estimateIndex] = true;
			}

		}
		else
		{
			if (v1.m_y > v2.m_y)
				std::swap(v1, v2);
			for (int i = (int) v1.m_y; i <= v2.m_y; i++)
			{
				estimateIndex = (int) std::floor(
						v1.m_x + (i - v1.m_y) * (1 / slope) + 0.5);
				paintBoard[estimateIndex][i] = true;
			}
		}
	}
}
