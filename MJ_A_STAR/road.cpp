#include <vector> 
#include <string> 
#include "road.h" 

Road::Road(int ID, int st, int en, float len)
{ 
	roadID = ID; 
	start = st; 
	end = en; 
	length = len; 
} 

int Road::getRoad() const 
{ 
	return roadID; 
}

int Road::getStart() const 
{ 
	return start; 
}
int Road::getEnd() const 
{
	return end; 
}

float Road::getLength() const
{
	return length; 
}

