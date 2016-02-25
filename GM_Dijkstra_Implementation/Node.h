#ifndef NODE_H
#define NODE_H

#include <vector>

using namespace std;

class Node
{
	public:
		Node(int ID, double lat, double lon);
		struct linkedNode {
			int ID;
    		Node *node;
    		double distance;
		};
		void addLinkedNode(int ID, Node *node, double distance);
		void setID(int ID);
		void setLatLon(double lat, double lon);
		void setDistanceFromStart(double distance);
		void setCameFrom(Node *node);
		int getID();
		double getLat();
		double getLon();
		double getDistanceFromStart();
		bool hasLinkedNodes();
		Node *getCameFrom();
		vector<Node::linkedNode> getLinkedNodes();
		
	private:
		int ID;
		double lat;
		double lon;
		double distance_from_start;
		Node *came_from;
		vector<Node::linkedNode> linked_nodes;
};

#endif