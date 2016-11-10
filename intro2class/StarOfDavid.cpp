#include "StarOfDavid.h"
#include "Vertex.h"
#include "utilities.h"
#include "Triangle.h"

StarOfDavid::StarOfDavid(Vertex firstTriangular[3], Vertex secondTriangular[3]){
	
	
	if (CheckTriangle(firstTriangular) && CheckTriangle(secondTriangular)) {

	}

	 Triangle t1(firstTriangular);
	
	
	


}


//----------------------------------------------------------------------------

StarOfDavid::StarOfDavid(const Triangle & t1, const Triangle & t2)
{

}

//----------------------------------------------------------------------------

double StarOfDavid::getTotalHeight()const 
{
	
}
