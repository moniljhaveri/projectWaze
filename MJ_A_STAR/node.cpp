#include "Node.h" 
#include <vector>
#include <string> 

Node::Node(int ID, float lat, float longit)
{
	NodeID = ID; 
	latitude = lat; 
	longitude = longit; 
	distance = 30000.00; 
}

void Node::setDistance(float d)
{
	distance = d; 
} 

float Node::getDistance() const
{ 
	return distance; 
}

int Node::getNodeFrom() const 
{ 
	return Nodefrom; 
}

void Node::setNodeFrom(int ID)
{
	Nodefrom = ID; 
} 

void Node::setCoordinate(float la, float lo)
{
	latitude = la; 
	longitude = lo; 
}

int Node::getNode() const 
{
	return NodeID; 
} 

float Node::getLat() const 
{
	return latitude; 
} 

float Node::getLong() const
{
	return longitude; 
} 

void Node::addRoad(Road road)
{
	roads.push_back(road); 
}

std::vector<Road> Node::getRoads()
{
	return roads; 
}
