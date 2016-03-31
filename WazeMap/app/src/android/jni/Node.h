#ifndef NODE_H
#define NODE_H

#include <vector>

using namespace std;

class Node
{
	public:
		Node(int ID=0, double lat=0, double lon=0);
		struct linkedNode {
			int ID;
    		Node *node;
    		double distance;
		};
		void addLinkedNode(int ID=0, Node *node=nullptr, double distance=0);
		vector<Node::linkedNode> getLinkedNodes();
		bool hasLinkedNodes();
		void setID(int ID=0);
		int getID();
		void setLatLon(double lat=0, double lon=0);
		double getLat();
		double getLon();
		void setDistanceFromStart(double distance=0);
		double getDistanceFromStart();
		void setParent(Node *node=nullptr);
		Node *getParent();
		void setHVal(double h_val=0);
		double getHVal();
		void setGVal(double g_val=0);
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