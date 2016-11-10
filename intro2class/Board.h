#pragma once
#include "macros.h"
#include "Vertex.h"

class Board
{
public:
	Board();

	/*
	 * Clears the board so that a consecutive call to printBoard 
	 * will not print any shape.
	 */
	void clear();

	/*
	 * Prints the current board to the console
	 */
	void print();

	/*
	 * Adds the given line to the board so that a 
	 * consecutive call to print() will print the line to the console.
	 */
	void addLine(Vertex v1, Vertex v2);

private:
	bool paintBoard[MAX_X+1][MAX_Y+1];
};

