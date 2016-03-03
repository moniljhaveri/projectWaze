#include <iostream> 
#include <string> 
#include <vector> 
#include <fstream> 
#include "node.h"
#include "load.h"
#include "road.h" 


int main()
{
	std::ifstream testnode = openNode(); 
	std::ifstream testrode = openRoad(); 
	stringVector(testnode, 0); 
	return 0; 
}
