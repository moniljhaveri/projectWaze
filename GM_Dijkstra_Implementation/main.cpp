#include <iostream>
#include <cstring>
#include <vector>
#include "Node.h"
#include "Load.h"
#include "Dijkstra.h"
#include "SmoothsortPriorityQueue.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

// KNOWN ISSUES:
//	- If a node is not connected to any other node, this will cause problems
//		- not sure if this is actually an issue in our file, but should fix anyway
//	- If two nodes are next to each other, we should short circuit to get immediate result

int main(int argc, char *argv[])
{	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	vector<Node> nodes;
	vector<Node*> path;
	int num_nodes;
	int start_node = stoi(argv[3]);
	int end_node = stoi(argv[4]);
	string node_file = argv[1];
	string edge_file = argv[2];
	// set up the data structure
	num_nodes = Load( &nodes, node_file, edge_file );

	// get start and end nodes
	//cout << "Enter a start node [0-" << nodes.size() << "]: ";
	//cin >> start_node;
	//cout << "Enter an end node [0-" << nodes.size() << "]: ";
	//cin >> end_node;
	
	// run the algorithm
	Dijkstra( &nodes, &path, start_node, end_node );
	
	// print the results
	for (vector<Node*>::iterator it = path.begin() ; it != path.end(); ++it) 
		cout << (*(*it)).getID() << endl;
	
high_resolution_clock::time_point t2 = high_resolution_clock::now();
auto duration = duration_cast<microseconds>( t2 - t1 ).count();
cout << duration << " Time" << endl;
	
	return 0;
}