#include <iostream>
#include <string>

#include "macros.h"
#include "Vertex.h"
#include "Board.h"

#define RECTANGLE       0
#define TRIANGLE        0
#define PARALLELOGRAM   0
#define STAR_OF_DAVID   0

#if RECTANGLE
#include "Rectangle.h"
void drawAndPrint(const Rectangle&, Board&);
#endif

#if TRIANGLE
#include "Triangle.h"
void drawAndPrint(const Triangle&, Board&);
#endif

#if PARALLELOGRAM
#include "Parallelogram.h"
void drawAndPrint(const Parallelogram&, Board&);
#endif

#if STAR_OF_DAVID
#include "StarOfDavid.h"
void drawAndPrint(const StarOfDavid&, Board&);
void readVerticesForStarOfDavid(Vertex vertices[3], int triangle);
#endif

void waitForEnter();
void printVertex(std::ostream& ostr, const Vertex& vertex);
Vertex readVertex(std::istream& istr);

int main()
{
    Board board;

#if RECTANGLE
    {
        board.clear();
        Vertex vertices[2];
        std::cout << "Please enter x and y coordinates for left-down vertex of the rectangle:\n";
        vertices[0] = readVertex(std::cin);
        std::cout << "Please enter x and y coordinates for right-up vertex of the rectangle:\n";
        vertices[1] = readVertex(std::cin);
        std::cin.ignore(); // ignore the enter

        Rectangle rect(vertices);
        drawAndPrint(rect, board);

        board.clear();
        std::cout << "Now scaled by factor of 2:\n\n";
        bool scaling = rect.scale(2);
        if (scaling)
        {
            drawAndPrint(rect, board);
        }
        else
        {
            std::cout << "Scaling failed!\n";
        }
    }
#endif // RECTANGLE

#if TRIANGLE
    {
        board.clear();
        Vertex corners[3];
        std::cout << "Please enter x and y coordinates for the first corner of the triangle:\n";
        corners[0] = readVertex(std::cin);
        std::cout << "Please enter x and y coordinates for the second corner of the triangle:\n";
        corners[1] = readVertex(std::cin);
        std::cout << "Please enter x and y coordinates for the third corner of the triangle:\n";
        corners[2] = readVertex(std::cin);
        std::cin.ignore(); // ignore the enter

        Triangle triangle(corners);
        drawAndPrint(triangle, board);

        board.clear();
        std::cout << "Now scaled by factor of 2:\n\n";
        bool scaling = triangle.scale(2);
        if (scaling)
        {
            drawAndPrint(triangle, board);
        }
        else
        {
            std::cout << "Scaling failed!\n";
        }
    }
#endif // TRIANGLE

#if PARALLELOGRAM
    {
        board.clear();
        std::cout << "Please enter x and y coordinates for bottom-left vertex of the parallelogram:\n";
        Vertex bottomLeft = readVertex(std::cin);
        std::cout << "Please enter x and y coordinates for top-right vertex of the parallelogram:\n";
        Vertex topRight = readVertex(std::cin);
        std::cout << "Please enter x and y coordinates for top-left vertex of the parallelogram:\n";
        Vertex topLeft = readVertex(std::cin);
        std::cin.ignore(); // ignore the enter

        Parallelogram parallelogram(bottomLeft, topRight, topLeft);
        drawAndPrint(parallelogram, board);

        board.clear();
        std::cout << "Now scaled by factor of 2:\n\n";
        bool scaling = parallelogram.scale(2);
        if (scaling)
        {
            drawAndPrint(parallelogram, board);
        }
        else
        {
            std::cout << "Scaling failed!\n";
        }
    }
#endif // PARALLELOGRAM

#if STAR_OF_DAVID
    {
        board.clear();
        Vertex firstTriangle[3];
        Vertex secondTriangle[3];
        readVerticesForStarOfDavid(firstTriangle, 1);
        readVerticesForStarOfDavid(secondTriangle, 2);
        StarOfDavid star(firstTriangle, secondTriangle);
        drawAndPrint(star, board);

        board.clear();
        std::cout << "Now scaled by factor of 2:\n\n";
        bool scaling = star.scale(2);
        if (scaling)
        {
            drawAndPrint(star, board);
        }
        else
        {
            std::cout << "Scaling failed!\n";
        }
    }
#endif // STAR_OF_DAVID
}

#if RECTANGLE
void drawAndPrint(const Rectangle& rect, Board& board)
{
    rect.draw(board);
    board.print();
    waitForEnter();

    std::cout << "Now with the bounding rectangle, too:\n";
    Rectangle boundingRect = rect.getBoundingRectangle();
    boundingRect.draw(board);
    board.print();
    waitForEnter();

    std::cout << "The bottom-left vertex of the rectangle is: ";
    printVertex(std::cout, rect.getBottomLeft());
    std::cout << '\n';

    std::cout << "The top-right vertex is: ";
    printVertex(std::cout, rect.getTopRight());
    std::cout << '\n';

    std::cout << "The perimeter of the rectangle is: "
              << rect.getPerimeter()
              << '\n';

    std::cout << "The area of the rectangle is: "
              << rect.getArea()
              << '\n';

    std::cout << "The center of the Rectangle is: ";
    printVertex(std::cout, rect.getCenter());
    std::cout << '\n';

    waitForEnter();
}
#endif // RECTANGLE

#if TRIANGLE
void drawAndPrint(const Triangle& triangle, Board& board)
{
    triangle.draw(board);
    board.print();
    waitForEnter();

    std::cout << "Now with the bounding rectangle, too:\n";
    Rectangle boundingRect = triangle.getBoundingRectangle();
    boundingRect.draw(board);
    board.print();
    waitForEnter();

    std::cout << "The vertices of the triangle are:\n";
    for (int i = 0; i < 3; ++i)
    {
        printVertex(std::cout, triangle.getVertex(i));
        std::cout << '\n';
    }

    std::cout << "The perimeter of the triangle is: "
              << triangle.getPerimeter()
              << '\n';

    std::cout << "The area of the triangle is: "
              << triangle.getArea()
              << '\n';

    std::cout << "The center of the triangle is: ";
    printVertex(std::cout, triangle.getCenter());
    std::cout << '\n';

    waitForEnter();
}
#endif // TRIANGLE

#if PARALLELOGRAM
void drawAndPrint(const Parallelogram& parallelogram, Board& board)
{
    parallelogram.draw(board);
    board.print();
    waitForEnter();

    std::cout << "Now with the bounding rectangle, too:\n";
    Rectangle boundingRect = parallelogram.getBoundingRectangle();
    boundingRect.draw(board);
    board.print();
    waitForEnter();

    std::cout << "The perimeter of the parallelogram is: "
              << parallelogram.getPerimeter()
              << '\n';

    std::cout << "The area of the parallelogram is: "
              << parallelogram.getArea()
              << '\n';

    std::cout << "The center of the parallelogram is: ";
    printVertex(std::cout, parallelogram.getCenter());
    std::cout << '\n';

    waitForEnter();
}
#endif // PARALLELOGRAM

#if STAR_OF_DAVID
void drawAndPrint(const StarOfDavid& star, Board& board)
{
    star.draw(board);
    board.print();
    waitForEnter();

    std::cout << "Now with the bounding rectangle, too:\n";
    Rectangle boundingRect = star.getBoundingRectangle();
    boundingRect.draw(board);
    board.print();
    waitForEnter();

    std::cout << "The height of the star of David is: "
        << star.getHeight() << '\n';

    std::cout << "The perimeter of the star of David is: "
        << star.getPerimeter()
        << '\n';

    std::cout << "The area of the star of David is: "
        << star.getArea()
        << '\n';

    std::cout << "The center of the star of David is: ";
    printVertex(std::cout, star.getCenter());
    std::cout << '\n';

    waitForEnter();
}

void readVerticesForStarOfDavid(Vertex vertices[3], int triangle)
{
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Please enter x and y coordinates for vertex " << i + 1
                  << " of triangle " << triangle
                  << " of Star of David:\n";
        vertices[i] = readVertex(std::cin);
    }
}
#endif // STAR_OF_DAVID

void waitForEnter()
{
    std::cout << "Press Enter to continue...\n";
    std::string line;
    std::getline(std::cin, line);
}

void printVertex(std::ostream& ostr, const Vertex& vertex)
{
    ostr << "(" << vertex.m_x << ", " << vertex.m_y << ")";
}

Vertex readVertex(std::istream& istr)
{
    Vertex result;
    istr >> result.m_x >> result.m_y;
    return result;
}
