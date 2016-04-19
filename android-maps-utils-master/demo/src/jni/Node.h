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
		void addLinkedNodeRaw(int ID=0, Node *node= nullptr, double distance=0);
		void addLinkedNode(Node::linkedNode node);
		void removeLinkedNode(Node *node= nullptr);
		void restoreLinks();
		void removeNode();
		void addNode();
		bool isInGraph();
		double getDistanceTo(Node *node= nullptr);
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
		bool in_graph;
		Node *parent;
		vector<Node::linkedNode> linked_nodes;
		vector<Node::linkedNode> stashed_linked_nodes;
};

// This is a helper function that resets all of the nodes in the vector
// with a distance of infinity and 'nullptr' parents. This function
// should be run before running Dijkstra's (unless it's the first time
// running Dijkstra's on the nodes.)
void reset_nodes(vector<Node>* nodes);
void restore_all_links(vector<Node>* nodes);

#endif
