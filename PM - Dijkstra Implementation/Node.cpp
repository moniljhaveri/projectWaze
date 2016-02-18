#include "Node.h"
#include <vector>
#include <string>

using namespace std;

Node::Node(string ID, float lattitude, float longitude)
{
nodeID = ID;
lat = lattitude;
longit = longitude;
distance = 10000.00;
}
	
void Node::setDistance(float d)
{distance = d;}

float Node::getDistance() const
{return distance;}

string Node::getNodeFrom() const
{return nodefrom;}

void Node::setNodeFrom(string ID)
{nodefrom = ID;}

void Node::setCoord(float la, float lon)
{lat = la;
longit = lon;}

string Node::getNode() const
{return nodeID;}

float Node::getLat() const
{return lat;}	

float Node::getLongit() const
{return longit;}	

void Node::addRoad(Road road)
{roads.push_back(road);}

vector<Road> Node::getRoads()
{return roads;}

bool Node::operator<(const Node &d)
{
	if(distance < d.getDistance())
		return true;
	else
		return false;
}

bool Node::operator>(const Node &d)
{
	if(distance> d.getDistance())
		return true;
	else
		return false;
}
