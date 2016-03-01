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
		vector<Node::linkedNode> getLinkedNodes();
		bool hasLinkedNodes();
		void setID(int ID);
		int getID();
		void setLatLon(double lat, double lon);
		double getLat();
		double getLon();
		void setDistanceFromStart(double distance);
		double getDistanceFromStart();
		void setParent(Node *node);
		Node *getParent();
		void setHVal(double h_val);
		double getHVal();
		void setGVal(double g_val);
		double getGVal();
		
	private:
		int ID;
		double lat;
		double lon;
		double g_val;
		double h_val;
		double distance_from_start;
		Node *parent;
		vector<Node::linkedNode> linked_nodes;
};

#endif