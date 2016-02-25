#include <vector>
#include <iostream>
#include "Node.h"
#include "SmoothsortPriorityQueue.h"

void Dijkstra(vector<Node>* nodes, vector<Node*>* path, Node *start_node, Node *end_node)
{
	if (((*start_node).hasLinkedNodes() == 0) || ((*end_node).hasLinkedNodes() == 0)) return;

	SmoothsortPriorityQueue q( nodes );
	
	Node *currentNode;
	(*start_node).setDistanceFromStart(0);
	
	bool done[ (*nodes).size() ];
	for (int i=0 ; i<(*nodes).size() ; i++) done[i] = false;
	
	while (q.getQueueSize() > 1)
	{
		q.sort();
		currentNode = q.dequeue();
		done[(*currentNode).getID()] = true;
		if(currentNode == end_node)
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
	
	(*path).push_back( end_node );
	Node* source_node = (*end_node).getCameFrom();
	(*path).push_back( source_node );
	while ( source_node != start_node )
	{
		source_node = (*source_node).getCameFrom();
		(*path).push_back( source_node );
	}
	
	return;
}