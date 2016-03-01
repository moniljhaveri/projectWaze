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
	this->parent = nullptr;
	this->h_val = 0;
}

void Node::addLinkedNode(int ID, Node *node, double distance)
{
	linked_nodes.push_back(linkedNode());
	linked_nodes[linked_nodes.size() - 1].ID = ID;
	linked_nodes[linked_nodes.size() - 1].node = node;
	linked_nodes[linked_nodes.size() - 1].distance = distance;
}

vector<Node::linkedNode> Node::getLinkedNodes()
{ return this->linked_nodes; }

bool Node::hasLinkedNodes()
{ return ((this->linked_nodes.size() == 0) ? false : true); }

void Node::setID(int ID)
{ this->ID = ID; }

int Node::getID()
{ return this->ID; }

void Node::setLatLon(double lat, double lon)
{
	this->lat = lat;
	this->lon = lon;
}

double Node::getLat()
{ return this->lat; }

double Node::getLon()
{ return this->lon; }

void Node::setDistanceFromStart(double distance)
{ this->distance_from_start = distance; }

double Node::getDistanceFromStart()
{ return this->distance_from_start; }

void Node::setParent(Node *node)
{ this->parent = node; }

Node *Node::getParent()
{ return this->parent; }

void Node::setHVal(double h_val)
{ this->h_val = h_val; }

double Node::getHVal()
{ return this->h_val; }

void Node::setGVal(double g_val)
{ this->g_val = g_val; }

double Node::getGVal()
{ return this->g_val; }