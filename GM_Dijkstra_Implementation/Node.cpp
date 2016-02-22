#include <vector>
#include <limits>
#include "Node.h"

using namespace std;

Node::Node(int ID, double lat, double lon)
{
	this->ID = ID;
	this->lat = lat;
	this->lon = lon;
	this->distance_from_start = numeric_limits<double>::infinity();
	this->came_from = nullptr;
}

void Node::addLinkedNode(int ID, Node *node, double distance)
{
	linked_nodes.push_back(linkedNode());
	linked_nodes[linked_nodes.size() - 1].ID = ID;
	linked_nodes[linked_nodes.size() - 1].node = node;
	linked_nodes[linked_nodes.size() - 1].distance = distance;
}

void Node::setID(int ID)
{
	this->ID = ID;
}

void Node::setLatLon(double lat, double lon)
{
	this->lat = lat;
	this->lon = lon;
}

void Node::setDistanceFromStart(double distance)
{
	this->distance_from_start = distance;
}

void Node::setCameFrom(Node *node)
{
	this->came_from = node;
}

int Node::getID()
{
	return this->ID;
}

double Node::getLat()
{
	return this->lat;
}

double Node::getLon()
{
	return this->lon;
}

double Node::getDistanceFromStart()
{
	return this->distance_from_start;
}

Node *Node::getCameFrom()
{
	return this->came_from;
}

vector<Node::linkedNode> Node::getLinkedNodes()
{
	return this->linked_nodes;
}