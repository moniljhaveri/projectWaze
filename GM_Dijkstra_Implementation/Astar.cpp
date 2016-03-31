#include <vector>
#include <iostream>
#include <cmath>
#include "Node.h"
#include "SmoothsortPriorityQueue.h"

// h_weight is the amount of weight given to the heuristic (which is the direct 'as-the-crow-flies'
// distance between the node and the end node.) If the h_weight is 0, this function returns the
// same results as Dijkstra's
void Astar(vector<Node>* nodes, vector<Node*>* path, Node *start_node, Node *end_node, float h_weight, bool debug)
{
	if (((*start_node).hasLinkedNodes() == 0) || ((*end_node).hasLinkedNodes() == 0)) return;
	
	if (h_weight > 0)
	{
		// update each node's h_val using 'as-the-crow-flies' method with the lat/lon
		// better solution is probably to do this on-the-fly as we need the values
		// or, better yet, run this in a separate thread and just do any that haven't been
		// done on-the-fly as we need them
		double end_lat = (*end_node).getLat();
		double end_lon = (*end_node).getLon();
		double tmp_lat;
		double tmp_lon;
		for (vector<Node>::iterator it = (*nodes).begin() ; it != (*nodes).end() ; ++it)
		{
			tmp_lat = (*it).getLat();
			tmp_lon = (*it).getLon();
			(*it).setHVal((sqrt(pow(end_lat - tmp_lat, 2) + pow(end_lon - tmp_lon, 2))) * h_weight);
		}
	}

	SmoothsortPriorityQueue q( nodes );
	
	Node *currentNode;
	(*start_node).setDistanceFromStart(0);
	
	bool done[ (*nodes).size() ];
	for (int i=0 ; i<(*nodes).size() ; i++) done[i] = false;
	
	while (q.getQueueSize() > 1)
	{
		q.sort();
		currentNode = q.dequeue();
		if(currentNode == end_node) break;
		done[(*currentNode).getID()] = true;
		if (debug) cout << "Current Node: " << (*currentNode).getID() << endl;
		
		vector<Node::linkedNode> linked = (*currentNode).getLinkedNodes();
		for (vector<Node::linkedNode>::iterator it = linked.begin() ; it != linked.end() ; ++it)
		{	
			// this is like saying "if not in our open list"
			Node *tmp_node_ptr = (*it).node;
			if (debug) cout << "  >Looking at node " << (*tmp_node_ptr).getID() << endl;
			if (debug && done[(*tmp_node_ptr).getID()]) cout << "  >  Node is done" << endl;
			if (done[(*tmp_node_ptr).getID()]) continue;
			
			if ((*tmp_node_ptr).getParent() == nullptr)
			{
				if (debug) cout << "  >  Parent is null" << endl;
				(*tmp_node_ptr).setParent(currentNode);
				if (debug) cout << "  >    Setting parent to node " << (*currentNode).getID() << endl;
				(*tmp_node_ptr).setGVal( (*currentNode).getGVal() + (*it).distance);
				if (debug) cout << "  >    Setting G-val to " << (*currentNode).getGVal() + (*it).distance << endl;
				(*tmp_node_ptr).setDistanceFromStart((*tmp_node_ptr).getGVal() + (*tmp_node_ptr).getHVal());
				if (debug) cout << "  >    Setting total distance to " << (*tmp_node_ptr).getGVal() + (*tmp_node_ptr).getHVal() << endl;
			}
			else
			{
				if (debug) cout << "  >  Parent is not null" << endl;
				if ((*currentNode).getGVal() + (*it).distance < (*tmp_node_ptr).getGVal())
				{
					(*tmp_node_ptr).setParent(currentNode);
					if (debug) cout << "  >    Setting parent to node " << (*currentNode).getID() << endl;
					(*tmp_node_ptr).setGVal((*currentNode).getGVal() + (*it).distance);
					if (debug) cout << "  >    Setting G-val to " << (*currentNode).getGVal() + (*it).distance << endl;
					(*tmp_node_ptr).setDistanceFromStart((*tmp_node_ptr).getGVal() + (*tmp_node_ptr).getHVal());
					if (debug) cout << "  >    Setting total distance to " << (*tmp_node_ptr).getGVal() + (*tmp_node_ptr).getHVal() << endl;
				}
			}
		}
// 		cout << " << done\n";
	}
	
	(*path).push_back( end_node );
	Node* source_node = (*end_node).getParent();
	(*path).push_back( source_node );
	while ( source_node != start_node )
	{
		source_node = (*source_node).getParent();
		(*path).push_back( source_node );
	}
	
	return;
}
