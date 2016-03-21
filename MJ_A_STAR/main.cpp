#include <iostream> 
#include <string> 
#include <vector> 
#include <fstream> 
#include "node.h"
#include "load.h"
#include "road.h" 

std::vector<Node> populateVector(std::vector<std::string> x){ 
	int size = x.size(); 
	std::vector<Node> nodeVector;  
	for(int i = 0; i < size; i++){ 
		nodeVector.push_back(makeNode(x[i])); 
	} 
//	std::cout << nodeVector[1].getDistance() << std::endl; 
	return nodeVector;
} 

std::vector<Node> populateRoad(std::vector<Node> node, std::vector<std::string> road){
	int size = node.size();  
	for( int i = 0; i < size; i++){
		node[i].addRoad(makeRoad(road[i])); 
	//	std::cout << node[i].getNode() << std::endl; 
	} 
	return node; 

} 

int main()
{
	std::ifstream testnode = openNode(); 
	std::ifstream testrode = openRoad(); 
	std::vector<std::string> x = stringVector(testnode); 
	std::vector<std::string> roadVector = stringVector(testrode); 
	std::vector<Node> nodeVector = populateVector(x); 
	nodeVector = populateRoad(nodeVector, roadVector); 
	
	return 0; 

} 
