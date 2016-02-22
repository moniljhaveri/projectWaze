#include <iostream>
#include <cstring>
#include <vector>
#include "Node.h"
#include "Load.h"
#include "Dijkstra.h"
#include "SmoothsortPriorityQueue.h"

using namespace std;

// KNOWN ISSUES:
//	- If a node is not connected to any other node, this will cause problems
//		- not sure if this is actually an issue in our file, but should fix anyway
//	- If two nodes are next to each other, we should short circuit to get immediate result

int main()
{
	vector<Node> nodes;
	vector<Node*> path;
	int num_nodes;
	int start_node;
	int end_node;
	string node_file = "/Users/gregmerritt/Dropbox/EC504_Advanced_Data_Structures_Spring2016/Project/WazeApp/cal.cnode.txt";
	string edge_file = "/Users/gregmerritt/Dropbox/EC504_Advanced_Data_Structures_Spring2016/Project/WazeApp/cal.cedge.txt";
	
	// set up the data structure
	num_nodes = Load( &nodes, node_file, edge_file );

	// get start and end nodes
	cout << "Enter a start node [0-" << nodes.size() << "]: ";
	cin >> start_node;
	cout << "Enter an end node [0-" << nodes.size() << "]: ";
	cin >> end_node;
	
	// run the algorithm
	Dijkstra( &nodes, &path, start_node, end_node );
	
	// print the results
	for (vector<Node*>::iterator it = path.begin() ; it != path.end(); ++it) 
		cout << (*(*it)).getID() << endl;
	
	return 0;
}