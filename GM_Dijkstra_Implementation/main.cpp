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

// KNOWN ISSUE:
//	If the graph is partitioned, and start node is in one section and the end node is in
//	another section, this will fail.

int main(int argc, char *argv[])
{	
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	vector<Node> nodes;
	vector<Node*> path;
	int num_nodes;
	int start_node = stoi(argv[3]);
	int end_node = stoi(argv[4]);
	string node_file = argv[1];
	string edge_file = argv[2];
	
	// set up the data structure
	num_nodes = Load( &nodes, node_file, edge_file );
	
	// run the algorithm
	Dijkstra( &nodes, &path, &(nodes[start_node]), &(nodes[end_node]) );
	
	// print the results
	for (vector<Node*>::iterator it = path.begin() ; it != path.end(); ++it) 
		cout << (*(*it)).getID() << endl;
	
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>( t2 - t1 ).count();
	cout << "\nTotal Time: " << duration << endl;
	
	return 0;
}