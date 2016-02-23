#include <vector>
#include <iostream>
#include "Node.h"
#include "SmoothsortPriorityQueue.h"

void Dijkstra(vector<Node>* nodes, vector<Node*>* path, int start_node, int end_node)
{
	SmoothsortPriorityQueue q( nodes );
	
	Node *currentNode;
	(*nodes)[start_node].setDistanceFromStart(0);
	
	bool done[ (*nodes).size() ];
	for (int i=0 ; i<(*nodes).size() ; i++) done[i] = false;
	
	while (q.getQueueSize() > 1)
	{
		q.sort();
		currentNode = q.dequeue();
		done[(*currentNode).getID()] = true;
		if(currentNode->getID() == end_node)
			break;
		vector<Node::linkedNode> linked = (*currentNode).getLinkedNodes();
		for (vector<Node::linkedNode>::iterator it = linked.begin() ; it != linked.end(); ++it)
		{
			if (done[(*((*it).node)).getID()]) continue;
			if ((*currentNode).getDistanceFromStart() + (*it).distance < (*((*it).node)).getDistanceFromStart())
			{
				(*((*it).node)).setDistanceFromStart((*currentNode).getDistanceFromStart() + (*it).distance);
				(*((*it).node)).setCameFrom(currentNode);
			}
		}
	}
	
	(*path).push_back( &((*nodes)[end_node]) );
	Node* source_node = (*nodes)[end_node].getCameFrom();
	(*path).push_back( source_node );
	while ( (*source_node).getID() != start_node )
	{
		source_node = (*source_node).getCameFrom();
		(*path).push_back( source_node );
	}
	
// 	cout << "TARGET: " << end_node << endl;
// 	int came_from_ID = (*((*nodes)[end_node].getCameFrom())).getID();
// 	cout << "FROM: " << came_from_ID << endl;
// 	path.push_back( (*nodes)[end_node].getCameFrom() );
// 	while (came_from_ID != start_node)
// 	{
// 		came_from_ID = (*((*nodes)[came_from_ID].getCameFrom())).getID();
// 		cout << "FROM: " << came_from_ID << endl;
// 	}
}