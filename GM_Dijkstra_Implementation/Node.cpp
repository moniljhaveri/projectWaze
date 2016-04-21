#include <vector>
#include <limits>
#include "Node.h"
#include <iostream>

using namespace std;


Node::Node(int ID, double lat, double lon)
{
	this->ID = ID;
	this->lat = lat;
	this->lon = lon;
	this->distance_from_start = numeric_limits<double>::infinity();
	this->parent = nullptr;
	this->h_val = 0;
	this->in_graph = true;
}

void Node::addLinkedNodeRaw(int ID, Node *node, double distance)
{
	linked_nodes.push_back(linkedNode());
	linked_nodes[linked_nodes.size() - 1].ID = ID;
	linked_nodes[linked_nodes.size() - 1].node = node;
	linked_nodes[linked_nodes.size() - 1].distance = distance;
}

void Node::addLinkedNode(Node::linkedNode node)
{
	linked_nodes.push_back(node);
}

void Node::removeLinkedNode(Node *node)
{
	for (int i=0; i<linked_nodes.size(); i++)
	{
		if (linked_nodes[i].node == node)
		{
			stashed_linked_nodes.push_back(linked_nodes[i]);
			linked_nodes.erase(linked_nodes.begin() + i);
			break;
		}
	}
}

void Node::restoreLinks()
{
	for (vector<Node::linkedNode>::iterator it = stashed_linked_nodes.begin() ; it != stashed_linked_nodes.end(); ++it)
		linked_nodes.push_back( *it );
	stashed_linked_nodes.clear();
}

void Node::removeNode()
{ this->in_graph = false; }

void Node::addNode()
{ this->in_graph = true; }

bool Node::isInGraph()
{ return this->in_graph; }

double Node::getDistanceTo(Node *node)
{
	double dist = 0.0;
	for (vector<Node::linkedNode>::iterator it = linked_nodes.begin() ; it != linked_nodes.end(); ++it)
	{
		if ((*it).node == node)
		{
			dist = (*it).distance;
			break;
		}
	}
	return dist;
}

vector<Node::linkedNode> Node::getLinkedNodes()
{ return this->linked_nodes; }

int Node::getNumberOfLinkedNodes()
{ return this->linked_nodes.size(); }

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

void reset_nodes(vector<Node>* nodes)
{
	for (vector<Node>::iterator it = (*nodes).begin() ; it != (*nodes).end(); ++it)
	{
		(*it).addNode();
		(*it).setDistanceFromStart( numeric_limits<double>::infinity() );
		(*it).setParent( nullptr );
	}
}

void restore_all_links(vector<Node>* nodes)
{
	for (vector<Node>::iterator it = (*nodes).begin() ; it != (*nodes).end(); ++it)
	{
		(*it).restoreLinks();
	}
}
